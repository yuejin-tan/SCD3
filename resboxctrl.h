#ifndef RESBOXCTRL_H
#define RESBOXCTRL_H

#include <QDialog>

#include <QtCore/QTimer>

#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialPort/QSerialPort>

namespace Ui {
    class resBoxCtrl;
}

class resBoxCtrl: public QDialog
{
    Q_OBJECT

public:
    explicit resBoxCtrl(QWidget* parent, int portNum);
    ~resBoxCtrl();

public:
    QModbusRtuSerialMaster* mClient;

    void resCtrl(int resNo, int sta);

    void mdbWriteUtil(int addr, int val);

    QTimer* timer1;

private:
    Ui::resBoxCtrl* ui;
};

#endif // RESBOXCTRL_H
