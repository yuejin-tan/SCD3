#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtCore/QTimer>
#include <QtCore/QVector>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QtCore/QFile>

#include <deque>

#include <QtCore/QDebug>

#include "inform.h"
#include "scopeform.h"
#include "highlighter.h"
#include "luaform.h"

#include "luascript.h"

#include "main.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent);
    ~MainWindow();

signals:
    void startToDrawSig(int num);

    void syncTableSig(int highSpeedBufferSize);

    void tableRefreshSig();

public slots:
    void setOKSlot(void);

    void tableChangedSlot(int row, int column);

    void tableDoubleClickedSlot(int row, int column);

    void tableRefreshSlot(void);

    void on_searchButton_clicked();

    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_clearButton_clicked();

    void on_inButton_clicked();

    void on_cfgButton_clicked();

    void on_refreshButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_fcnButton1_clicked();

    void on_luaButton_clicked();

    void fpsTimerOut();

    void sendTimerOut();

    void handleError(QSerialPort::SerialPortError error);

public:
    void setUiAsSciChg(bool ifOn);

    void closeEvent(QCloseEvent* event);

    void staBarRefresh(bool frameLocked);

    void pauseFcn();

    Ui::MainWindow* ui;
    // 串口类
    QSerialPort* tyj_serial;
    // 串口定时任务计时器
    QTimer* timer1;
    // 定时刷新任务计时器
    QTimer* timer2;

    // 代码导入窗口指针
    inForm* inForm1;
    // 绘图窗口指针
    scopeForm* scopeForm1;
    // 高亮器
    Highlighter* highlighterRev;
    Highlighter* highlighterSend;
    // lua解释器
    LuaScript* luaScript1;
    // lua窗口指针
    luaForm* luaForm1;

    // 变量名数组
    QVector<QString>* names;
    // 类型数组
    QVector<QString>* types;
    // 变量值数组
    QVector<float>* values;
    // 高速值序号表
    QVector<int>* varNum;
    // 供收包时临时记录
    QVector<float>* valTemp;
    // 常规包大小
    int normalPkgSize = 1;
    // dump缓存
    QVector<float>* dumpBuff;
    // print协议字符串储存
    QByteArray printBuff;

    // 帧错误数
    int errFrameCnt;
    // 收包计数
    int okFrameCnt;
    // 主循环毫秒值
    int mainMilliSec;

    // 串口是否开启
    bool isSciOn;

    // 背景色
    QColor bgColor;
    // 高亮色
    QColor highlightColor;
};

#endif // MAINWINDOW_H
