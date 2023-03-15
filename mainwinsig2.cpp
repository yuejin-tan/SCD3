#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "math.h"

void MainWindow::sendTimerOut()
{
    if (isSciOn == false)
    {
        QMessageBox::information(this, QString("错误"), QString("定时发送计时器:串口没有打开"), QMessageBox::Ok);
        ui->checkBox->setChecked(false);
        timer2->stop();
        return;
    }

    // 使用最新的间隔值
    if (timer2->interval() != ui->spinBox->value())
    {
        timer2->start(ui->spinBox->value());
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

void MainWindow::tableChangedSlot(int row, int column)
{
    // qDebug() << "changed: " << row << " " << column << endl;
    // qDebug() << ui->tableWidget->item(row, column)->text() << endl;

    if (column == 2)
    {
        // 改目标值
        if (isSciOn)
        // if (1)
        {
            bool ok;
            float tmp = ui->tableWidget->item(row, column)->text().toFloat(&ok);
            if (ok)
            {
                // 浮点可识别
                // qDebug() << "float ok" << endl;

                // 验证最大值
                if (ui->tableWidget->item(row, 3))
                {
                    // 最大值有东西
                    // qDebug() << "have Sth" << endl;

                    if (ui->tableWidget->item(row, 3)->text().trimmed() != QString(""))
                    {
                        // 最大值串非空
                        // qDebug() << "str sth" << endl;

                        float max = ui->tableWidget->item(row, 3)->text().toFloat(&ok);
                        if (ok)
                        {
                            if (tmp > max)
                            {
                                QMessageBox::information(this, QString("错误"), QString("超过最大值，修改命令未发送"), QMessageBox::Ok);
                                return;
                            }
                        }
                        else
                        {
                            QMessageBox::information(this, QString("错误"), QString("对应最大值无法识别为浮点数，修改命令未发送"), QMessageBox::Ok);
                            return;
                        }
                    }
                }

                // 验证最小值
                if (ui->tableWidget->item(row, 4))
                {
                    // 最小值有东西
                    // qDebug() << "have Sth2" << endl;

                    if (ui->tableWidget->item(row, 4)->text().trimmed() != QString(""))
                    {
                        // 最小值串非空
                        // qDebug() << "str sth2" << endl;

                        float min = ui->tableWidget->item(row, 4)->text().toFloat(&ok);
                        if (ok)
                        {
                            if (tmp < min)
                            {
                                QMessageBox::information(this, QString("错误"), QString("低于最小值，修改命令未发送"), QMessageBox::Ok);
                                return;
                            }
                        }
                        else
                        {
                            QMessageBox::information(this, QString("错误"), QString("对应最小值无法识别为浮点数，修改命令未发送"), QMessageBox::Ok);
                            return;
                        }
                    }
                }

                // 根据是否为浮点进行输出
                QString cmdStr;
                if (ui->tableWidget->item(row, 1)->text() == "float")
                {
                    cmdStr = QString("set") + QString().setNum(row) + "#" + QString().setNum(tmp, 'e', 5) + "!!!!";
                }
                else
                {
                    int sendInt = ui->tableWidget->item(row, 2)->text().toInt(&ok);
                    if (ok)
                    {
                        cmdStr = QString("set") + QString().setNum(row) + "#" + QString().setNum(sendInt) + "!!!!";
                    }
                    else
                    {
                        QMessageBox::information(this, QString("错误"), QString("不是标准整数形式，修改命令未发送"), QMessageBox::Ok);
                        return;
                    }
                }

                // 转换成utf8格式的字节流
                QByteArray data = cmdStr.toUtf8();
                // 写串口,两遍
                tyj_serial->write(data);
                tyj_serial->write(data);
                // 显示命令信息
                ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr);
                ui->revPlainTextEdit->appendPlainText("Send$" + cmdStr);
            }
            else
            {
                QMessageBox::information(this, QString("错误"), QString("无法识别为浮点数，修改命令未发送"), QMessageBox::Ok);
                return;
            }
        }
        else
        {
            QMessageBox::information(this, QString("错误"), QString("串口没有打开，修改命令未发送"), QMessageBox::Ok);
            return;
        }
    }
    if (column == 3 || column == 4)
    {
        // 改限制值
        bool ok;
        // float tmp = ui->tableWidget->item(row, column)->text().toFloat(&ok);
        ui->tableWidget->item(row, column)->text().toFloat(&ok);
        if (ok)
        {
            // qDebug() << "float ok2" << tmp << endl;
        }
        else
        {
            QMessageBox::information(this, QString("错误"), QString("无法识别为浮点数"), QMessageBox::Ok);
            return;
        }
    }
}

void MainWindow::tableRefreshSlot(void)
{

    // 断开修改事件
    disconnect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::tableChangedSlot);

    int cnt = names->size();

    for (int i = 0; i < cnt; i++)
    {
        QString objType = ui->tableWidget->item(i, 1)->text();
        if (objType == "function" || objType.startsWith("hex"))
        {
            ui->tableWidget->item(i, 2)->setText("0x" + QString::number((uint32_t)values->at(i), 16));
        }
        else if (objType.startsWith("bin"))
        {
            ui->tableWidget->item(i, 2)->setText("0b" + QString::number((uint32_t)values->at(i), 2));
        }
        else
        {
            ui->tableWidget->item(i, 2)->setText(QString::number(values->at(i), 'g', 6));
        }
    }

    // 连接修改事件
    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::tableChangedSlot);
}

void MainWindow::on_sendButton_clicked()
{
    // 获取界面上的数据并转换
    QByteArray data = ui->sendPlainTextEdit->toPlainText().toLocal8Bit();
    // 写串口
    tyj_serial->write(data);

    // 发送命令
    ui->revPlainTextEdit->appendPlainText("Send$" + ui->sendPlainTextEdit->toPlainText());
}

void MainWindow::on_clearButton_clicked()
{
    ui->revPlainTextEdit->clear();
}
