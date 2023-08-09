#include "luascript.h"

#include "main.h"
#include "mainwindow.h"
#include "scopeform.h"
#include "inform.h"
#include "ui_mainwindow.h"
#include "ui_inform.h"
#include "ui_scopeform.h"
#include <QClipboard>
#include <QFileDialog>

#include <time.h>

#include "tyjplot.h"

#include "resboxctrl.h"

#define TYJ_TO_STR(str) #str

// 继续堆屎，增加LUA 的包间隔设定API
static int scd_deltaPkgSet_impl(lua_State* L)
{
    double deltaPkgX = lua_tonumber(L, 1);

    mainWinPtr->scopeForm1->ui->doubleSpinBox_pkgdelta->setValue(deltaPkgX);
    mainWinPtr->scopeForm1->deltaPkg = deltaPkgX;
    mainWinPtr->scopeForm1->ui->label_pkgdelta->setText(QString::number(deltaPkgX));

    return 0;
}

// 继续堆屎，增加LUA 的绘图方面API
static int scd_tabItemSelect_impl(lua_State* L)
{
    size_t len;
    const char* hNameChr = lua_tolstring(L, 1, &len);

    QString tarNameStr(hNameChr);

    int cnt = mainWinPtr->names->size();
    for (int ii = 0;ii < cnt;ii++)
    {
        if (mainWinPtr->ui->tableWidget->item(ii, 0)->text() == tarNameStr)
        {
            if (mainWinPtr->ui->tableWidget->item(ii, 0))
            {
                mainWinPtr->ui->tableWidget->item(ii, 0)->setBackgroundColor(mainWinPtr->highlightColor);
            }
            break;
        }
    }

    return 0;
}

static int scd_plotItemSelect_impl(lua_State* L)
{
    size_t len;
    const char* hNameChr = lua_tolstring(L, 1, &len);

    QString tarNameStr(hNameChr);

    int ii = 0;
    for (auto namex : mainWinPtr->scopeForm1->pltVarNames)
    {
        if (namex == tarNameStr)
        {
            mainWinPtr->scopeForm1->ui->tyj_widget->addGraphItem(namex, mainWinPtr->scopeForm1->pltVarDatas[ii]);
            break;
        }
        ii++;
    }

    return 0;
}

static int scd_plotCfg(lua_State* L)
{
    Q_UNUSED(L);
    mainWinPtr->on_cfgButton_clicked();

    return 0;
}

// 继续堆屎，通过脚本设置绘图的坐标轴范围
static int scd_YaxisSet_impl(lua_State* L)
{
    size_t len;
    const char* hNameChr = lua_tolstring(L, 1, &len);
    double low = lua_tonumber(L, 2);
    double up = lua_tonumber(L, 3);

    QString tarNameStr(hNameChr);

    for (auto pltx : mainWinPtr->scopeForm1->ui->tyj_widget->pltItemVect)
    {
        if (pltx.name == tarNameStr)
        {
            pltx.graphx->valueAxis()->setRange(low, up);
            break;
        }
    }

    return 0;
}

// 通过脚本设置值范围
static int scd_valRangeSet_impl(lua_State* L)
{
    size_t len;
    const char* hNameChr = lua_tolstring(L, 1, &len);
    double max1 = lua_tonumber(L, 2);
    double min1 = lua_tonumber(L, 3);

    QString tarNameStr(hNameChr);

    int cnt = mainWinPtr->names->size();
    for (int ii = 0;ii < cnt;ii++)
    {
        if (mainWinPtr->ui->tableWidget->item(ii, 0)->text() == tarNameStr)
        {
            if (mainWinPtr->ui->tableWidget->item(ii, 3))
            {
                mainWinPtr->ui->tableWidget->item(ii, 3)->setText(QString::number(max1));
            }
            else
            {
                QTableWidgetItem* ptrx = new QTableWidgetItem(QString::number(max1, 'g', 6));
                mainWinPtr->ui->tableWidget->setItem(ii, 3, ptrx);
            }
            if (mainWinPtr->ui->tableWidget->item(ii, 4))
            {
                mainWinPtr->ui->tableWidget->item(ii, 4)->setText(QString::number(min1));
            }
            else
            {
                QTableWidgetItem* ptrx = new QTableWidgetItem(QString::number(min1, 'g', 6));
                mainWinPtr->ui->tableWidget->setItem(ii, 4, ptrx);
            }
            break;
        }
    }

    return 0;
}

// 堆屎一把梭
resBoxCtrl* hrbc1 = nullptr;

// 新增 电阻箱控制 函数簇
static int scd_rBox_init_impl(lua_State* L)
{
    int portNum = lua_tointeger(L, 1);

    if (hrbc1 == nullptr)
    {
        hrbc1 = new resBoxCtrl(nullptr, portNum);
        hrbc1->show();
    }
    else
    {
        hrbc1->show();
        hrbc1->raise();
    }

    return 0;
}

static int scd_rBox_ctrl(lua_State* L)
{
    int rNo = lua_tointeger(L, 1);
    int sta = lua_tointeger(L, 2);

    if (hrbc1)
    {
        hrbc1->resCtrl(rNo, sta);
    }

    return 0;
}

// 新增modbus函数簇
static int scd_mdbNewPort_impl(lua_State* L)
{
    int portNum = lua_tointeger(L, 1);
    int baud = lua_tointeger(L, 2);
    int timeout = lua_tointeger(L, 3);
    int retryNum = lua_tointeger(L, 4);

    mainWinPtr->luaScript1->mPortNum = portNum;
    mainWinPtr->luaScript1->mPortNumStr = QStringLiteral("COM%1").arg(portNum);

    if (mainWinPtr->luaScript1->mClient)
    {
        if (mainWinPtr->luaScript1->mClient->state() != QModbusDevice::UnconnectedState)
        {
            printf("COM%d:warning, multi connect\n", mainWinPtr->luaScript1->mPortNum);
            mainWinPtr->luaScript1->mClient->disconnectDevice();
        }
    }
    else
    {
        mainWinPtr->luaScript1->mClient = new QModbusRtuSerialMaster();
    }

    mainWinPtr->luaScript1->mClient->setConnectionParameter(QModbusDevice::SerialPortNameParameter, mainWinPtr->luaScript1->mPortNumStr);
    mainWinPtr->luaScript1->mClient->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    mainWinPtr->luaScript1->mClient->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, baud);
    mainWinPtr->luaScript1->mClient->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    mainWinPtr->luaScript1->mClient->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);
    mainWinPtr->luaScript1->mClient->setTimeout(timeout);
    mainWinPtr->luaScript1->mClient->setNumberOfRetries(retryNum);

    if (!mainWinPtr->luaScript1->mClient->connectDevice())
    {
        printf("COM%d:connection err\n", mainWinPtr->luaScript1->mPortNum);
    }

    printf("COM%d:modbus master start script end.\n", mainWinPtr->luaScript1->mPortNum);
    return 0;
}

static int scd_mdbClosePort_impl(lua_State* L)
{
    Q_UNUSED(L);
    if (mainWinPtr->luaScript1->mClient)
    {
        if (mainWinPtr->luaScript1->mClient->state() != QModbusDevice::UnconnectedState)
        {
            mainWinPtr->luaScript1->mClient->disconnectDevice();
        }
    }
    else
    {
        printf("COM%d:no client but close\n", mainWinPtr->luaScript1->mPortNum);
        return 0;
    }

    printf("COM%d:modbus master closed.\n", mainWinPtr->luaScript1->mPortNum);
    return 0;
}

static int scd_mdbReadRegF32_impl(lua_State* L)
{
    int mdbAddr = lua_tointeger(L, 1);
    int regAddr = lua_tointeger(L, 2);
    double retVal = -1;

    QModbusDataUnit pkg1(QModbusDataUnit::HoldingRegisters, regAddr, 2);

    if (mainWinPtr->luaScript1->mClient)
    {
        if (mainWinPtr->luaScript1->mClient->state() != QModbusDevice::ConnectedState)
        {
            printf("COM%d:no connect but send\n", mainWinPtr->luaScript1->mPortNum);
            goto scd_mdbReadRegF32_impl_err;
        }
    }
    else
    {
        printf("COM%d:no client but send\n", mainWinPtr->luaScript1->mPortNum);
        goto scd_mdbReadRegF32_impl_err;
    }

    mainWinPtr->luaScript1->staReplied = 0;

    if (QModbusReply* reply = mainWinPtr->luaScript1->mClient->sendReadRequest(pkg1, mdbAddr))
    {
        if (!reply->isFinished())
        {
            QObject::connect(reply, &QModbusReply::finished, [=]()
                {
                    mainWinPtr->luaScript1->staReplied = 1;

                    if (!reply) {
                        printf("COM%d:Read no reply err\n", mainWinPtr->luaScript1->mPortNum);
                        mainWinPtr->luaScript1->staReplied = -1;
                        return;
                    }

                    if (reply->error() == QModbusDevice::NoError)
                    {
                        const QModbusDataUnit unit = reply->result();
                        mainWinPtr->luaScript1->mdbAns = unit.value(0);
                        mainWinPtr->luaScript1->mdbAns2 = unit.value(1);
                    }
                    else if (reply->error() == QModbusDevice::ProtocolError)
                    {
                        qDebug() << (QStringLiteral("%1:Read response error: %2 (Mobus exception: 0x%3)")
                            .arg(mainWinPtr->luaScript1->mPortNumStr)
                            .arg(reply->errorString())
                            .arg(reply->rawResult().exceptionCode(), -1, 16));
                        mainWinPtr->luaScript1->staReplied = -1;
                    }
                    else
                    {
                        qDebug() << (QStringLiteral("%1:Read response error: %2 (code: 0x%3)")
                            .arg(mainWinPtr->luaScript1->mPortNumStr)
                            .arg(reply->errorString())
                            .arg(reply->error(), -1, 16));
                        mainWinPtr->luaScript1->staReplied = -1;
                    }
                    reply->deleteLater();
                });
        }
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        qDebug() << (QStringLiteral("%1:Read no reply err2")
            .arg(mainWinPtr->luaScript1->mPortNumStr)
            );
    }

    mainWinPtr->luaScript1->isDurDelay = true;
    while (mainWinPtr->luaScript1->staReplied == 0)
    {
        QApplication::processEvents();
    }
    mainWinPtr->luaScript1->isDurDelay = false;

    if (mainWinPtr->luaScript1->staReplied > 0)
    {
        // 得到正确信息
        union mdb_float_dec
        {
            float f32;
            struct
            {
                uint32_t u32_1 : 8;
                uint32_t u32_2 : 8;
                uint32_t u32_3 : 8;
                uint32_t u32_4 : 8;
            }u32_div4;
            struct
            {
                uint16_t u16_1;
                uint16_t u16_2;
            }u16_t2;
        }dec1;
        dec1.u16_t2.u16_1 = mainWinPtr->luaScript1->mdbAns;
        dec1.u16_t2.u16_2 = mainWinPtr->luaScript1->mdbAns2;
        retVal = dec1.f32;

        printf("COM%d:modbus get %f\n", mainWinPtr->luaScript1->mPortNum, retVal);
    }

scd_mdbReadRegF32_impl_err:

    lua_pushnumber(L, retVal);
    return 1;
}
// 原函数簇

static int scd_callTest(lua_State* L)
{
    size_t len;
    const char* ret = lua_tolstring(L, 1, &len);
    printf("%s\nlua call test ok\n", ret);
    return 0;
}

static int scd_delayMs_impl(lua_State* L)
{
    mainWinPtr->luaScript1->isDurDelay = true;

    int ms2delay = lua_tointeger(L, 1);

    clock_t startT = clock();
    clock_t tmpT = clock();

    while (((1000.0 * (tmpT - startT)) / CLOCKS_PER_SEC) < ms2delay)
    {
        QApplication::processEvents();
        tmpT = clock();
    }

    mainWinPtr->luaScript1->isDurDelay = false;
    return 0;
}

static int scd_getVar_impl(lua_State* L)
{
    int listNum = lua_tointeger(L, 1);

    float ans = mainWinPtr->values->at(listNum - 1);

    lua_pushnumber(L, ans);
    return 1;
}

static int scd_sendStr_impl(lua_State* L)
{
    size_t len;
    const char* ret = lua_tolstring(L, 1, &len);

    if (mainWinPtr->isSciOn)
    {
        QString strToShow = "Send$" + QString(ret);
        mainWinPtr->ui->revPlainTextEdit->appendPlainText(strToShow);

        mainWinPtr->tyj_serial->write(ret, len);
    }
    else
    {
        printf("serial port open err, cmd not sended\n");
    }

    return 0;
}

static int scd_dump_impl(lua_State* L)
{
    int dumpTarget = lua_tointeger(L, 1);
    int dumpNums = lua_tointeger(L, 2);

    QString cmdStr1 = QString("dump%1#%2!!!!").arg(dumpTarget - 1).arg(dumpNums);
    // 获取界面上的数据并转换
    QByteArray data1 = cmdStr1.toLocal8Bit();

    for (int i = 0; i < 2; i++)
    {
        // 写串口
        mainWinPtr->tyj_serial->write(data1);
        // 发送命令
        mainWinPtr->ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
    }

    QString cmdStr2 = QString("chg0#3!!!!");
    // 获取界面上的数据并转换
    QByteArray data2 = cmdStr2.toLocal8Bit();

    for (int i = 0; i < 2; i++)
    {
        // 写串口
        mainWinPtr->tyj_serial->write(data2);
        // 发送命令
        mainWinPtr->ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr2);
    }

    return 0;
}

static int scd_dumpOut_impl(lua_State* L)
{
    int dumpCol = lua_tointeger(L, 1);
    if (dumpCol < 1)
    {
        dumpCol = 1;
    }
    QString dumpMethod(lua_tostring(L, 2));
    QVector<float>* tempBuffPtr = mainWinPtr->dumpBuff;
    int totalNum = tempBuffPtr->size();

    if (dumpMethod == "csv")
    {
        // 输出为csv文件
        QString saveDir = mainWinPtr->luaScript1->getSaveDir();
        QString fileName = QFileDialog::getSaveFileName(nullptr,
            "保存数据为csv", saveDir, "csv (*.csv)");

        // qDebug() << saveDir;
        if (fileName == "")
        {
            // 未选择
            // qDebug() << "cancel";
            return 0;
        }

        QString csvStr;

        int ii = 0;
        for (; ii < totalNum - dumpCol;)
        {
            for (int jj = 0; jj < dumpCol - 1; jj++)
            {
                csvStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\t");
                ii++;
            }
            csvStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\n");
            ii++;
        }
        for (; ii < totalNum - 1; ii++)
        {
            csvStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\t");
        }
        csvStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\n");

        QByteArray fileName2 = fileName.toLocal8Bit();
        FILE* fileHandle = fopen(fileName2.data(), "w");

        QByteArray nameChars = csvStr.toLocal8Bit();
        fputs(nameChars.data(), fileHandle);

        fclose(fileHandle);

        printf("total %d dump datas to csv\n", totalNum);
    }
    else if (dumpMethod == "cb")
    {
        printf("total %d dump datas to clipboard\n", totalNum);
        // 复制到剪贴板
        QString clipBoardStr;

        int ii = 0;
        for (; ii < totalNum - dumpCol;)
        {
            for (int jj = 0; jj < dumpCol - 1; jj++)
            {
                clipBoardStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\t");
                ii++;
            }
            clipBoardStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\n");
            ii++;
        }
        for (; ii < totalNum - 1; ii++)
        {
            clipBoardStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\t");
        }
        clipBoardStr.append(QString::number(tempBuffPtr->at(ii), 'g', 5)).append("\n");

        QClipboard* sysCB = QApplication::clipboard();
        sysCB->setText(clipBoardStr);
    }
    else if (dumpMethod == "cmd")
    {
        // 直接cmd输出
        printf("total %d dump datas\n=====start dump=====\n", totalNum);
        int ii = 0;
        for (; ii < totalNum - dumpCol;)
        {
            for (int jj = 0; jj < dumpCol - 1; jj++)
            {
                printf("%.5g\t", tempBuffPtr->at(ii));
                ii++;
            }
            printf("%.5g\n", tempBuffPtr->at(ii));
            ii++;
        }
        for (; ii < totalNum - 1; ii++)
        {
            printf("%.5g\t", tempBuffPtr->at(ii));
        }
        printf("%.5g\n", tempBuffPtr->at(ii));
        printf("=====end dump=====\n");
    }
    else
    {
        // 新建窗口打开dump内容
        tyjPlot* newPlotWin = new tyjPlot(nullptr);
        newPlotWin->resize(800, 600);
        newPlotWin->setWindowTitle(QStringLiteral("dump result"));
        newPlotWin->show();
        QObject::connect(newPlotWin, &tyjPlot::clearBuffSig, [=]()
            {
                newPlotWin->deleteLater();
            });
        QVector<QSharedPointer<QCPGraphDataContainer>> dataContVect;
        dataContVect.reserve(dumpCol);
        for (int jj = 0;jj < dumpCol;jj++)
        {
            dataContVect.append(std::move(QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer())));
            newPlotWin->addGraphItem(QString::number(jj), dataContVect.last());
        }
        int rowCnt = 0;
        for (int ii = 0; ii < totalNum;)
        {
            for (int jj = 0; (jj < dumpCol) && (ii < totalNum); jj++)
            {
                dataContVect[jj].data()->add(QCPGraphData(rowCnt, tempBuffPtr->at(ii)));
                ii++;
            }
            rowCnt++;
        }

        for (int jj = 0;jj < dumpCol;jj++)
        {
            newPlotWin->graph(jj)->setLineStyle(QCPGraph::lsStepLeft);
            newPlotWin->graph(jj)->rescaleAxes(true);
        }
    }

    return 0;
}

LuaScript::LuaScript(MainWindow* mainWin_init, QObject* parent)
    : QObject{ parent }
{
    mainWin1 = mainWin_init;

    printf("start lua script init\n");

    // 新建实例
    lua_sta_init = luaL_newstate();

    // 中断定时
    timer1 = new QTimer(this);
    // delay状态
    isDurDelay = false;

    // 回复状态
    staReplied = 0;
    mdbAns = 0;
    mdbAns2 = 0;
    mPortNum = 0;
    mClient = nullptr;

    // 打开基本库
    luaopen_base(lua_sta_init);
    luaL_openlibs(lua_sta_init);

    // 注册调用函数
    lua_register(lua_sta_init, TYJ_TO_STR(scd_callTest), scd_callTest);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_dump_impl), scd_dump_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_dumpOut_impl), scd_dumpOut_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_getVar_impl), scd_getVar_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_sendStr_impl), scd_sendStr_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_delayMs_impl), scd_delayMs_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_mdbNewPort_impl), scd_mdbNewPort_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_mdbClosePort_impl), scd_mdbClosePort_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_mdbReadRegF32_impl), scd_mdbReadRegF32_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_rBox_init_impl), scd_rBox_init_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_rBox_ctrl), scd_rBox_ctrl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_YaxisSet_impl), scd_YaxisSet_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_valRangeSet_impl), scd_valRangeSet_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_tabItemSelect_impl), scd_tabItemSelect_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_plotItemSelect_impl), scd_plotItemSelect_impl);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_plotCfg), scd_plotCfg);
    lua_register(lua_sta_init, TYJ_TO_STR(scd_deltaPkgSet_impl), scd_deltaPkgSet_impl);

    //传递全局变量
    lua_pushstring(lua_sta_init, "SCD " SCD_VERSION " @ " LUA_VERSION);
    lua_setglobal(lua_sta_init, "mainVer");

    // 打开脚本
    // if (luaL_loadfile(lua_sta_init, "./config/scd_cfg_win64.lua"))
    if (luaL_loadfile(lua_sta_init, "./scd_cfg_win64.lua"))
    {
        const char* error = lua_tostring(lua_sta_init, -1);
        printf("cfgLua load err:%s\n", error);
        lua_pop(lua_sta_init, 1);
        return;
    }

    // 调用脚本
    if (lua_pcall(lua_sta_init, 0, 0, 0))
    {
        const char* error = lua_tostring(lua_sta_init, -1);
        printf("cfgLua exe err:%s\n", error);
        lua_pop(lua_sta_init, 1);
        return;
    }

    // 打印参数情况
    int retType = lua_getglobal(lua_sta_init, "scd_save_dir");
    if (retType == LUA_TNIL)
    {
        printf("save dir not specified\n");
    }
    else
    {
        QByteArray tmp = (QString::fromLocal8Bit(lua_tostring(lua_sta_init, -1)).trimmed()).toLocal8Bit();
        printf("use save dir: %s\n", tmp.data());
    }
    lua_pop(lua_sta_init, 1);

    // 判定载入C脚本
    bool ifPreloadCCode = false;
    retType = lua_getglobal(lua_sta_init, "scd_preload_init_c_code_in_script");
    if (retType == LUA_TBOOLEAN)
    {
        ifPreloadCCode = lua_toboolean(lua_sta_init, -1);
    }
    lua_pop(lua_sta_init, 1);
    if (ifPreloadCCode)
    {
        printf("use c code in lua script\n");

        retType = lua_getglobal(lua_sta_init, "scd_init_c_code");
        if (retType == LUA_TSTRING)
        {
            QString cCode(lua_tostring(lua_sta_init, -1));
            mainWin1->inForm1->ui->plainTextEdit->setPlainText(cCode);
            mainWin1->inForm1->on_cButton_clicked();
        }
        lua_pop(lua_sta_init, 1);
    }
    else
    {
        printf("not preload c code\n");
    }

    // 是否启用定时运行特性
    bool ifUseInterCmd = false;
    retType = lua_getglobal(lua_sta_init, "scd_enable_periodically_run_feature");
    if (retType == LUA_TBOOLEAN)
    {
        ifUseInterCmd = lua_toboolean(lua_sta_init, -1);
    }
    lua_pop(lua_sta_init, 1);
    if (ifUseInterCmd)
    {
        printf("enable periodically run\n");

        // 开始毫秒计数
        startTime1 = QTime::currentTime();

        connect(timer1, &QTimer::timeout, this, &LuaScript::inter_cmd_timer_out);
        // 使能lua 控制台处理函数，10Hz运行
        timer1->start(100);
    }
    else
    {
        printf("disable periodically run\n");
    }

    printf("lua script init end\n");
}

LuaScript::~LuaScript()
{
    scd_mdbClosePort_impl(nullptr);

    if (mClient)
        delete mClient;

    if (hrbc1)
        delete hrbc1;

    lua_close(lua_sta_init);

    // 对象树自己管理
    // delete timer1;
}

QString LuaScript::getSaveDir()
{
    int retType = lua_getglobal(lua_sta_init, "scd_save_dir");

    if (retType == LUA_TNIL)
    {
        lua_pop(lua_sta_init, 1);
        return QString(".");
    }

    QString retStr = QString::fromLocal8Bit(lua_tostring(lua_sta_init, -1)).trimmed();
    lua_pop(lua_sta_init, 1);
    return retStr;
}

void LuaScript::inter_cmd_timer_out()
{
    if (isDurDelay)
    {
        // 为避免冲突，在scd_delay期间不执行周期调用功能
        printf("during scd_delay, scd period run cancel once\n");
        return;
    }

    int elapsedMs = startTime1.msecsTo(QTime::currentTime());
    // 调用lua函数
    lua_getglobal(lua_sta_init, "scd_periodRun");
    lua_pushinteger(lua_sta_init, elapsedMs);
    if (lua_pcall(lua_sta_init, 1, 0, 0) != 0)
    {
        const char* error = lua_tostring(lua_sta_init, -1);
        printf("scd_periodRun err:%s\n", error);
        lua_pop(lua_sta_init, 1);
    }
    else
    {
        // ok
    }
}

void LuaScript::exeStr(QString luaStr)
{
    if (isDurDelay)
    {
        // 为避免冲突，在scd_delay期间不执行周期调用功能
        printf("during scd_delay, scd exeStr cancel once\n");
        return;
    }

    QByteArray tmp = luaStr.toLocal8Bit();
    luaL_loadstring(lua_sta_init, tmp.data());

    // printf("exe lua src:\n%s\n", tmp.data());

    // 调用脚本
    if (lua_pcall(lua_sta_init, 0, 0, 0))
    {
        const char* error = lua_tostring(lua_sta_init, -1);
        printf("lua exe err:%s\n", error);
        lua_pop(lua_sta_init, 1);
        return;
    }
}
