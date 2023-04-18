#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <time.h>

#include "QDebug"

void MainWindow::staBarRefresh(bool frameLocked)
{
    const int speedRefreshDms = 2000;
    static int nowCnt = speedRefreshDms / 2;
    static clock_t startT = 0;

    static int lastOkFrameCnt = 0;
    static double pkgDtAvg = 1 / 0.0001;

    // qt的定时器并不精确！！！
    if (startT == 0)
    {
        startT = clock();
    }

    nowCnt += mainMilliSec;
    if (nowCnt > speedRefreshDms)
    {
        double delta = okFrameCnt - lastOkFrameCnt;
        lastOkFrameCnt = okFrameCnt;
        clock_t tmpT = clock();
        pkgDtAvg = (1000.0 * (tmpT - startT)) / CLOCKS_PER_SEC / delta;
        nowCnt = 0;
        startT = tmpT;

        int baudRate = ui->baudrateBox->currentText().toInt();
        const int startBit = 1;
        int dataBit = ui->dataBitsBox->currentText().toInt();
        double stopBit = ui->stopBitsBox->currentText().toDouble();
        int checkBit = ui->ParityBox->currentIndex() ? 1 : 0;
        int byteCnt = (normalPkgSize + 1) * 4;
        double refPkgDt = 1000.0 * byteCnt * (startBit + dataBit + stopBit + checkBit) / baudRate;
        QString showStr = QString("帧锁定：%1；误包：%2；收包：%3；平均包间隔ms：%4（ref：%5）").arg(frameLocked).arg(errFrameCnt, 5).arg(okFrameCnt, 12).arg(pkgDtAvg, 0, 'g', 5).arg(refPkgDt, 0, 'g', 5);
        ui->statusBar->showMessage(showStr, 3000);
    }

}

void MainWindow::on_cfgButton_clicked()
{
    if (isSciOn == false)
    {
        QMessageBox::information(this, QString("错误"), QString("串口没有打开，未修改"), QMessageBox::Ok);
        return;
    }

    varNum->clear();
    int sizex = names->size();
    for (int i = 0; i < sizex; i++)
    {
        if (ui->tableWidget->item(i, 0)->backgroundColor() == highlightColor)
        {
            varNum->append(i);
        }
    }

    int size = varNum->size();
    if (size < 1)
    {
        QMessageBox::information(this, QString("错误"), QString("至少要有一个值"), QMessageBox::Ok);
        return;
    }

    // 让绘图的更新表格
    QVector<QString> plotVarNames;
    for (auto idx : *varNum)
    {
        plotVarNames.append((*names)[idx]);
    }
    scopeForm1->setPlotVars(std::move(plotVarNames));

    // 先写好结尾
    {
        QString cmdStr1("conf" + QString().setNum(size) + "#" + QString().setNum(9999) + "!!!!");

        // 转换成utf8格式的字节流
        QByteArray data = cmdStr1.toUtf8();
        // 写串口,两遍
        tyj_serial->write(data);
        tyj_serial->write(data);
        // 显示命令信息
        ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
        ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
    }

    for (int i = 0; i < size; i++)
    {
        QString cmdStr1("conf" + QString().setNum(i) + "#" + QString().setNum(varNum->at(i)) + "!!!!");

        // 转换成utf8格式的字节流
        QByteArray data = cmdStr1.toUtf8();
        // 写串口,两遍
        tyj_serial->write(data);
        tyj_serial->write(data);
        // 显示命令信息
        ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
        ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
    }
}

void MainWindow::tableDoubleClickedSlot(int row, int column)
{
    if (column == 0)
    {
        if (ui->tableWidget->item(row, 0)->backgroundColor() == highlightColor)
        {

            ui->tableWidget->item(row, 0)->setBackgroundColor(bgColor);
        }
        else
        {
            ui->tableWidget->item(row, 0)->setBackgroundColor(highlightColor);
        }
    }
}
