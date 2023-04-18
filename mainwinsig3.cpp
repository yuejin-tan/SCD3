#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "math.h"

#include "string.h"
#include "math.h"

#include "QDebug"

static int isFrameAligned = 0;
static int frameAlignedCnt = 0;
static int floatCnt = 0;
static int floatCntLast = -1;
// 帧过长
const int frameTooLong = 1100;

// 兼容vofa
const uint8_t end_array[4] = { 0x00, 0x00, 0x80, 0x7f };
// 所有变量值协议
const uint8_t end_array2[4] = { 0x00, 0x00, 0x81, 0x7f };
// DUMP协议
const uint8_t end_array3[4] = { 0x00, 0x00, 0x82, 0x7f };
// PRINT协议
const uint8_t end_array4[4] = { 0x00, 0x00, 0x83, 0x7f };

static uint8_t buffer[4] = { 0xaa, 0xaa, 0xaa, 0xaa };

// 针对小端8bit机器
void MainWindow::fpsTimerOut()
{
    if (isSciOn)
    {
        // 串口打开时对状态显示进行更新
        staBarRefresh(isFrameAligned == 2);

        // 需保证串口开启
        if (isFrameAligned == 2)
        {
            // 处于帧对齐状态
            while (tyj_serial->bytesAvailable() > 4)
            {
                tyj_serial->read((char*)(void*)buffer, 4);
                float* tmpFloat = (float*)(void*)buffer;
                if (!isfinite(*tmpFloat))
                {
                    // 非浮点类型，比较是哪种数
                    if (memcmp(buffer, end_array, 4) == 0)
                    {
                        okFrameCnt++;
                        // vofa协议
                        // 检查帧时间一致性
                        if (floatCnt != floatCntLast)
                        {
                            // 帧变长，重新定位
                            // qDebug() << floatCnt << floatCntLast << endl;
                            errFrameCnt++;
                            floatCntLast = floatCnt;
                            isFrameAligned = 0;
                            frameAlignedCnt = 0;
                            valTemp->clear();
                            floatCnt = 0;
                            return;
                        }
                        else
                        {
                            // 真正处理，在非暂停模式下才更新缓冲区
                            scopeForm1->addNewData(valTemp);
                        }
                        // qDebug() << "vofa" << endl;
                    }
                    else if (memcmp(&buffer[2], &end_array2[2], 2) == 0)
                    {
                        okFrameCnt++;
                        // 所有变量包协议
                        // UINT16求和校验
                        uint16_t sum = 0;
                        int sumCheckNum = valTemp->size();
                        for (int jj = 0; jj < sumCheckNum; jj++)
                        {
                            float tmpF = valTemp->at(jj);
                            uint16_t* gTmpU16 = (uint16_t*)(void*)&tmpF;
                            sum += *gTmpU16;
                            sum += *(gTmpU16 + 1);
                        }
                        if (memcmp(buffer, &sum, 2) != 0)
                        {
                            uint16_t* gTmpU16 = (uint16_t*)(void*)buffer;
                            printf("protocol all vars sum check err:rev sum=%d;calc sum=%d @ pkg: %d\n", *gTmpU16, sum, okFrameCnt);
                            errFrameCnt++;
                        }
                        if (names->size() > 0)
                        {
                            // 表格里有值，先拷贝数据，再更新表格。
                            values->swap(*valTemp);
                            // qDebug() << "1:" << floatCnt << endl;
                            // qDebug() << "2:" << valTemp->size() << endl;
                            // qDebug() << "3:" << values->size() << endl;
                            // for (int i = 0; i < values->size(); i++)
                            // {
                            //     qDebug() << values->at(i);
                            // }
                            // 先检查数据数量是否对的上
                            if (values->size() != names->size())
                            {
                                // // 关闭串口
                                // tyj_serial->close();
                                // // 调整ui
                                // setUiAsSciChg(false);
                                // // 关闭定时发送
                                // ui->checkBox->setCheckState(Qt::Unchecked);
                                // QMessageBox::information(this, QString("错误"), "收到" + QString::number(values->size()) + "个数，与表格对不上", QMessageBox::Ok);
                                // return;

                                // 改为只提出警告
                                ui->statusBar->showMessage(QStringLiteral("全局帧接收出错！"), 1000);
                                printf("recv global frame num err!\n");
                            }
                            else
                            {
                                // 修改表格
                                emit tableRefreshSig();
                            }
                        }
                        else
                        {
                            QMessageBox::information(this, QString("错误"), QString("表格未配置却收到全局帧"), QMessageBox::Ok);
                        }
                        // qDebug() << "other" << endl;
                    }
                    else if (memcmp(&buffer[2], &end_array3[2], 2) == 0)
                    {
                        okFrameCnt++;
                        // DUMP协议
                        // UINT16求和校验
                        // 补丁：用来判定连续短包
                        // 默认结束包
                        static int lastDumpPkgType = 2;

                        uint16_t sum = 0;
                        int sumCheckNum = valTemp->size() - 1;
                        for (int jj = 0; jj < sumCheckNum; jj++)
                        {
                            float tmpF = valTemp->at(jj);
                            uint16_t* gTmpU16 = (uint16_t*)(void*)&tmpF;
                            sum += *gTmpU16;
                            sum += *(gTmpU16 + 1);
                        }
                        if (memcmp(buffer, &sum, 2) != 0)
                        {
                            uint16_t* gTmpU16 = (uint16_t*)(void*)buffer;
                            printf("protocol DUMP sum check err:rev sum=%d;calc sum=%d @ pkg: %d\nplottings may have err data\n", *gTmpU16, sum, okFrameCnt);
                            errFrameCnt++;
                        }
                        float dumpPkgLastFloat = valTemp->takeLast();
                        if (dumpPkgLastFloat < 0.5f)
                        {
                            printf("get new dump pkg: %d\n", valTemp->size());
                            // for (float tmp : *valTemp)
                            // {
                            //     printf("%f\n", tmp);
                            // }

                            // 使用该数组
                            dumpBuff->swap(*valTemp);
                            lastDumpPkgType = 0;
                        }
                        else if (dumpPkgLastFloat > 1.5f)
                        {
                            printf("get end dump pkg: %d\n", valTemp->size());
                            // for (float tmp : *valTemp)
                            // {
                            //     printf("%f\n", tmp);
                            // }
                            if (lastDumpPkgType != 2)
                            {
                                // append即可
                                dumpBuff->append(*valTemp);
                            }
                            else
                            {
                                // 使用该数组
                                dumpBuff->swap(*valTemp);
                            }
                            lastDumpPkgType = 2;
                        }
                        else
                        {
                            printf("get conti dump pkg: %d\n", valTemp->size());
                            // for (float tmp : *valTemp)
                            // {
                            //     printf("%f\n", tmp);
                            // }

                            // append即可
                            dumpBuff->append(*valTemp);
                            lastDumpPkgType = 1;
                        }
                    }
                    else if (memcmp(&buffer[2], &end_array4[2], 2) == 0)
                    {
                        okFrameCnt++;
                        // PRINT协议
                        // printf("print pkg reved\n");
                        for (int ii = 0; ii < 2; ii++)
                        {
                            if (buffer[ii] != 0)
                            {
                                printBuff.append(buffer[ii]);
                                // printf("**:%d\n", buffer[ii]);
                                if (buffer[ii] == '\n')
                                {
                                    printBuff.append('\0');
                                    printf("----------get mcu msg----------\n%s----------mcu msg end----------\n", printBuff.data());
                                    QString showStr("Msg$");
                                    showStr.append(printBuff);
                                    ui->revPlainTextEdit->appendPlainText(showStr.trimmed());
                                    printBuff.clear();
                                }
                            }
                        }
                    }
                    else
                    {
                        // 应该是错帧了
                        isFrameAligned = 0;
                        frameAlignedCnt = 0;
                        errFrameCnt++;
                        valTemp->clear();
                        floatCnt = 0;
                        return;
                    }
                    valTemp->clear();
                    floatCnt = 0;
                }
                else
                {
                    // 认为帧正确
                    // qDebug() << *tmpFloat << endl;
                    valTemp->append(*tmpFloat);
                    floatCnt++;
                    if (floatCnt > floatCntLast + frameTooLong)
                    {
                        // 实在太长应该是挂了
                        // qDebug() << "too long break " << floatCnt << endl;
                        printf("err too long break\n");
                        // for (float tmp : *valTemp)
                        // {
                        //     qDebug() << tmp;
                        // }
                        valTemp->clear();
                        floatCnt = 0;
                        isFrameAligned = 0;
                        frameAlignedCnt = 0;
                        errFrameCnt++;
                        // timer1->stop();
                        return;
                    }
                }
            }
        }
        else if (isFrameAligned == 1)
        {
            // 没有帧对齐，即使弃包也先找对齐点,小端模式下，以0x00,0x00,0x80,0x7f为唯一对齐帧
            while (tyj_serial->bytesAvailable() >= 1)
            {
                tyj_serial->getChar((char*)(void*)&buffer[3]);
                frameAlignedCnt++;
                if (memcmp(end_array, buffer, 4) == 0)
                {
                    if (frameAlignedCnt & 0b11)
                    {
                        // 不是4的倍数，说明可能错了，应该只有一个，从这个继续试
                        // qDebug() << "err lock" << endl;
                        frameAlignedCnt = 0;
                        errFrameCnt++;
                    }
                    else
                    {
                        // 下一次还是4倍数，极大概率正确
                        isFrameAligned = 2;
                        frameAlignedCnt = 0;
                        // qDebug() << "locked" << endl;
                        return;
                    }
                }
                else
                {
                    // 不成立
                    memmove(buffer, &buffer[1], 3);
                    // qDebug() << "xxx2" << endl;
                }
            }
        }
        else if (isFrameAligned == 0)
        {
            // 没有帧对齐，即使弃包也先找对齐点,小端模式下，以0x00,0x00,0x80,0x7f为唯一对齐帧
            while (tyj_serial->bytesAvailable() >= 1)
            {
                tyj_serial->getChar((char*)(void*)&buffer[3]);
                if (memcmp(end_array, buffer, 4) == 0)
                {
                    isFrameAligned = 1;
                    frameAlignedCnt = 0;
                    // 未处理完
                    return;
                }
                else
                {
                    // 不成立
                    memmove(buffer, &buffer[1], 3);
                    // qDebug() << "xxx1" << endl;
                }
            }
        }
    }
    else
    {
        // 关闭后需重新对齐
        isFrameAligned = 0;
        frameAlignedCnt = 0;
        // qDebug() << "xxx3" << endl;
    }
}
