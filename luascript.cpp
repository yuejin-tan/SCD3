#include "luascript.h"

#include "main.h"
#include "mainwindow.h"
#include "inform.h"
#include "ui_mainwindow.h"
#include "ui_inform.h"
#include <QClipboard>
#include <QFileDialog>

#include <time.h>

#include "tyjplot.h"

#define TYJ_TO_STR(str) #str

static int scd_callTest(lua_State* L)
{
    size_t len;
    const char* ret = lua_tolstring(L, 1, &len);
    printf("%s\nlua call test ok\n", ret);
    return 0;
}

static int scd_delayMs_impl(lua_State* L)
{
    int ms2delay = lua_tointeger(L, 1);

    clock_t startT = clock();
    clock_t tmpT = clock();

    while (((1000.0 * (tmpT - startT)) / CLOCKS_PER_SEC) < ms2delay)
    {
        QApplication::processEvents();
        tmpT = clock();
    }

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
    lua_close(lua_sta_init);
    delete timer1;
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
