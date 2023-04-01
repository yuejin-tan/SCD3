#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include <QObject>
#include <QtCore/QTimer>

#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialPort/QSerialPort>

#include <QTime>
#include "lua5_4/lua.hpp"

class MainWindow;

class LuaScript: public QObject
{
    Q_OBJECT
public:

    explicit LuaScript(MainWindow* mainWin_init, QObject* parent = nullptr);
    ~LuaScript();

    QString getSaveDir();

signals:

public slots:
    void inter_cmd_timer_out(void);

public:
    void exeStr(QString luaStr);

public:
    lua_State* lua_sta_init;
    MainWindow* mainWin1;

    QTimer* timer1;
    bool isDurDelay;
    QTime startTime1;

    // 加入modbus功能
    int mPortNum;
    QString mPortNumStr;
    QModbusRtuSerialMaster* mClient;
    int staReplied;
    uint16_t mdbAns;
    uint16_t mdbAns2;

};

#endif // LUASCRIPT_H
