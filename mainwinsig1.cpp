#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "math.h"

void MainWindow::on_searchButton_clicked()
{
    ui->portNameBox->clear();
    // 通过QSerialPortInfo查找可用串口
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        // 显示windows串口号和描述字符串
        ui->portNameBox->addItem(info.portName() + QString(' ') + info.description());
    }
}

void MainWindow::on_openButton_clicked()
{
    if (!isSciOn)
    {
        // 设置串口名，注意去掉描述字符串
        tyj_serial->setPortName(ui->portNameBox->currentText().split(' ')[0]);
        // 设置波特率
        tyj_serial->setBaudRate(ui->baudrateBox->currentText().toInt());
        // 设置数据位数
        switch (ui->dataBitsBox->currentIndex())
        {
        case 0:
            tyj_serial->setDataBits(QSerialPort::Data8);
            break;
        case 1:
            tyj_serial->setDataBits(QSerialPort::Data7);
            break;
        case 2:
            tyj_serial->setDataBits(QSerialPort::Data6);
            break;
        case 3:
            tyj_serial->setDataBits(QSerialPort::Data5);
            break;
        default:
            tyj_serial->setDataBits(QSerialPort::Data8);
            break;
        }
        // 设置奇偶校验
        switch (ui->ParityBox->currentIndex())
        {
        case 0:
            tyj_serial->setParity(QSerialPort::NoParity);
            break;
        case 1:
            tyj_serial->setParity(QSerialPort::OddParity);
            break;
        case 2:
            tyj_serial->setParity(QSerialPort::EvenParity);
            break;
        default:
            tyj_serial->setParity(QSerialPort::NoParity);
            break;
        }
        // 设置停止位
        switch (ui->stopBitsBox->currentIndex())
        {
        case 0:
            tyj_serial->setStopBits(QSerialPort::OneStop);
            break;
        case 1:
            tyj_serial->setStopBits(QSerialPort::OneAndHalfStop);
            break;
        case 2:
            tyj_serial->setStopBits(QSerialPort::TwoStop);
            break;
        default:
            tyj_serial->setStopBits(QSerialPort::OneStop);
            break;
        }
        // 设置流控制，为了使用简单，强制为无流控制模式
        tyj_serial->setFlowControl(QSerialPort::NoFlowControl);

        // 打开串口
        if (!tyj_serial->open(QIODevice::ReadWrite))
        {
            // 打开失败，直接返回
            // QMessageBox::information(nullptr, QString("错误"), QString("串口打开失败"), QMessageBox::Ok);
            return;
        }

        setUiAsSciChg(true);
    }
    else
    {
        // 关闭串口
        tyj_serial->close();
        // 调整ui
        setUiAsSciChg(false);
    }
}

void MainWindow::on_refreshButton_clicked()
{
    if (isSciOn == false)
    {
        QMessageBox::information(this, QString("错误"), QString("串口没有打开"), QMessageBox::Ok);
        return;
    }
    int size = names->size();
    if (size < 1)
    {
        QMessageBox::information(this, QString("错误"), QString("列表不能为空"), QMessageBox::Ok);
        return;
    }

    QString cmdStr1("chg0#1!!!!");

    // 转换成utf8格式的字节流
    QByteArray data = cmdStr1.toUtf8();
    // 写串口,两遍
    tyj_serial->write(data);
    tyj_serial->write(data);
    // 显示命令信息
    ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
    ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr1);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
    {
        timer2->start(ui->spinBox->value());
        sendTimerOut();
    }
    else
    {
        timer2->stop();
    }
}

void MainWindow::on_fcnButton1_clicked()
{
    scopeForm1->show();
    scopeForm1->raise();
    scopeForm1->showNormal();
    emit startToDrawSig(1);
}

void MainWindow::on_inButton_clicked()
{
    inForm1->show();
    inForm1->raise();
    inForm1->showNormal();
}