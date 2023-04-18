#include "resboxctrl.h"
#include "ui_resboxctrl.h"

#include "QDebug"

#include "main.h"

resBoxCtrl::resBoxCtrl(QWidget* parent, int portNum):
    QDialog(parent),
    ui(new Ui::resBoxCtrl)
{
    ui->setupUi(this);

    mClient = new QModbusRtuSerialMaster();

    mClient->setConnectionParameter(QModbusDevice::SerialPortNameParameter, QStringLiteral("COM%1").arg(portNum));
    mClient->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    mClient->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, 38400);
    mClient->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    mClient->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);
    mClient->setTimeout(200);
    mClient->setNumberOfRetries(1);

    if (!mClient->connectDevice())
    {
        printf("resBox COM%d:connection err\n", portNum);
        return;
    }

    printf("resBox COM%d:modbus master start script end.\n", portNum);

    // 540V
    QObject::connect(ui->pushButton, &QPushButton::clicked, [=]() {
        mdbWriteUtil(5, 1);
        });
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, [=]() {
        mdbWriteUtil(5, 0);
        });

    // fan
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, [=]() {
        mdbWriteUtil(6, 1);
        });
    QObject::connect(ui->pushButton_4, &QPushButton::clicked, [=]() {
        mdbWriteUtil(6, 0);
        });

    // R1
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, [=]() {
        mdbWriteUtil(0, 1);
        });
    QObject::connect(ui->pushButton_6, &QPushButton::clicked, [=]() {
        mdbWriteUtil(0, 0);
        });

    // R2
    QObject::connect(ui->pushButton_7, &QPushButton::clicked, [=]() {
        mdbWriteUtil(1, 1);
        });
    QObject::connect(ui->pushButton_8, &QPushButton::clicked, [=]() {
        mdbWriteUtil(1, 0);
        });

    // R3
    QObject::connect(ui->pushButton_9, &QPushButton::clicked, [=]() {
        mdbWriteUtil(2, 1);
        });
    QObject::connect(ui->pushButton_10, &QPushButton::clicked, [=]() {
        mdbWriteUtil(2, 0);
        });

    // R4
    QObject::connect(ui->pushButton_11, &QPushButton::clicked, [=]() {
        mdbWriteUtil(3, 1);
        });
    QObject::connect(ui->pushButton_12, &QPushButton::clicked, [=]() {
        mdbWriteUtil(3, 0);
        });

    // 定时读取
    timer1 = new QTimer(this);
    QObject::connect(timer1, &QTimer::timeout, [=]() {

        QModbusDataUnit pkg1(QModbusDataUnit::HoldingRegisters, 0, 7);

        if (QModbusReply* reply = mClient->sendReadRequest(pkg1, 1))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, [=]()
                    {
                        if (!reply) {
                            qDebug() << QStringLiteral("resBox com:Read no reply err");
                            return;
                        }
                        if (reply->error() == QModbusDevice::NoError)
                        {
                            const QModbusDataUnit unit = reply->result();
                            QString showStr;
                            if (unit.value(0))
                            {
                                showStr += "R0 ";
                            }
                            if (unit.value(1))
                            {
                                showStr += "R1 ";
                            }
                            if (unit.value(2))
                            {
                                showStr += "R2 ";
                            }
                            if (unit.value(3))
                            {
                                showStr += "R3 ";
                            }
                            if (unit.value(4))
                            {
                                showStr += "270 ";
                            }
                            if (unit.value(5))
                            {
                                showStr += "540 ";
                            }
                            if (unit.value(6))
                            {
                                showStr += "fan ";
                            }
                            if (showStr == "")
                            {
                                showStr += "all off";
                            }
                            ui->lineEdit->setText(showStr);
                        }
                        else if (reply->error() == QModbusDevice::ProtocolError)
                        {
                            qDebug() << QStringLiteral("resBox com:Read no reply err");
                            qDebug() << (QStringLiteral("resBox com:Read response error: %1 (Mobus exception: 0x%2)")
                                .arg(reply->errorString())
                                .arg(reply->rawResult().exceptionCode(), -1, 16));
                        }
                        else
                        {
                            qDebug() << (QStringLiteral("resBox com:Read response error: %1 (code: 0x%2)")
                                .arg(reply->errorString())
                                .arg(reply->error(), -1, 16));
                        }
                        reply->deleteLater();
                    });
            }
            else
                delete reply; // broadcast replies return immediately
        }
        else
        {
            qDebug() << (QStringLiteral("resBox com:Read no reply err2"));
        }

        });
    timer1->start(500);
}

resBoxCtrl::~resBoxCtrl()
{
    if (mClient->state() != QModbusDevice::UnconnectedState)
    {
        mClient->disconnectDevice();
    }
    if (mClient)
    {
        delete mClient;
    }

    delete ui;
}

void resBoxCtrl::resCtrl(int resNo, int sta)
{
    if (resNo > 3)
    {
        resNo = 3;
    }
    if (resNo < 0)
    {
        resNo = 0;
    }

    if (sta)
    {
        mdbWriteUtil(resNo, 1);
    }
    else
    {
        mdbWriteUtil(resNo, 0);
    }
}

void resBoxCtrl::mdbWriteUtil(int addr, int val)
{
    if (addr > 6)
    {
        addr = 6;
    }
    if (addr < 0)
    {
        addr = 0;
    }
    QModbusDataUnit pkg1(QModbusDataUnit::HoldingRegisters, addr, 1);
    pkg1.setValue(0, val);

    if (QModbusReply* reply = mClient->sendWriteRequest(pkg1, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, [=]()
                {
                    if (!reply) {
                        qDebug() << (QStringLiteral("resBox com:Write no reply err"));
                        return;
                    }

                    if (reply->error() == QModbusDevice::ProtocolError)
                    {
                        qDebug() << (QStringLiteral("resBox com:Write response error: %1 (Mobus exception: 0x%2)")
                            .arg(reply->errorString())
                            .arg(reply->rawResult().exceptionCode(), -1, 16));
                    }
                    else if (reply->error() != QModbusDevice::NoError)
                    {
                        qDebug() << (QStringLiteral("resBox com:Write response error: %1 (code: 0x%2)")
                            .arg(reply->errorString())
                            .arg(reply->error(), -1, 16));
                    }

                    reply->deleteLater();
                });
        }
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        qDebug() << QStringLiteral("resBox com:Write no reply err2");
    }
}
