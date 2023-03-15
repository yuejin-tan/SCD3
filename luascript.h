#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include <QObject>
#include <QtCore/QTimer>

#include <QTime>
#include "lua5_4/lua.hpp"

class MainWindow;

class LuaScript : public QObject
{
    Q_OBJECT
public:
    explicit LuaScript(MainWindow *mainWin_init, QObject *parent = nullptr);
    ~LuaScript();

    QString getSaveDir();

signals:

public slots:
    void inter_cmd_timer_out(void);

public:
    void exeStr(QString luaStr);

public:
    lua_State *lua_sta_init;
    MainWindow *mainWin1;

    QTimer *timer1;
    QTime startTime1;
};

#endif // LUASCRIPT_H
