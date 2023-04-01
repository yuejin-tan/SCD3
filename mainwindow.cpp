#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

#include "main.h"

#include "QDebug"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 串口关闭
    setUiAsSciChg(false);

    // 接收区最大字符块数目
    ui->revPlainTextEdit->document()->setMaximumBlockCount(32);

    // 串口类
    tyj_serial = new QSerialPort(this);
    //接收缓冲设为1M
    tyj_serial->setReadBufferSize(1024 * 1024);

    // 颜色
    bgColor = QColor(QRgb(0x19232D));
    highlightColor = QColor(QRgb(0x455364));

    // 定时器类
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // 变量名数组
    names = new QVector<QString>;
    // 类型数组
    types = new QVector<QString>;
    // 变量值数组
    values = new QVector<float>;
    // 高速值序号表
    varNum = new QVector<int>;
    // 临时记录数组
    valTemp = new QVector<float>;
    // dump缓存
    dumpBuff = new QVector<float>;

    // 高亮器
    highlighterRev = new Highlighter(ui->revPlainTextEdit->document());
    highlighterSend = new Highlighter(ui->sendPlainTextEdit->document());

    // 帧错误计数
    errFrameCnt = 0;
    // 收包计数
    okFrameCnt = 0;

    // 代码导入窗口指针
    inForm1 = new inForm(nullptr, names, types);
    // 绘图窗口指针
    scopeForm1 = new scopeForm(nullptr);

    // lua窗口指针
    luaForm1 = new luaForm(nullptr, this);

    // 连接串口出错的信号
    connect(tyj_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    // 串口处理兼主中断的定时器
    connect(timer1, &QTimer::timeout, this, &MainWindow::fpsTimerOut);
    // 串口定时发送的定时器
    connect(timer2, &QTimer::timeout, this, &MainWindow::sendTimerOut);
    // 代码导入槽函数
    connect(inForm1, &inForm::setOKsig, this, &MainWindow::setOKSlot);
    // 双击表格信号
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &MainWindow::tableDoubleClickedSlot);
    // 更新表格信号
    connect(this, &MainWindow::tableRefreshSig, this, &MainWindow::tableRefreshSlot);

    // 使能串口数据处理函数
    mainMilliSec = 80;
    timer1->start(mainMilliSec);

    // 状态栏显示初始信息
    ui->statusBar->showMessage(QString("use opengl: ") + scopeForm1->openGLsta, 3000);
    // 显示版本号

    // 窗口名加后缀
    setWindowTitle(this->windowTitle() + " " SCD_VERSION);

    // 最后再初始化lua解释器，进行有关脚本的初始值设定
    luaScript1 = new LuaScript(this, this);
}

MainWindow::~MainWindow()
{
    // 由系统自动调用成员变量的析构函数
    // 只回收对象以释放系统资源，数值啥的只占用内存，由操作系统自己回收
    delete ui;
    delete inForm1;
    delete scopeForm1;
    delete luaForm1;
    delete timer1;
    delete timer2;
    // 由qt object机制自己完成
    // delete luaScript1;
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    // 简单的错误处理：给出错误原因，然后关闭串口
    if (error)
    {
        QMessageBox::critical(this, QString("串口出错"), tyj_serial->errorString());
        if (isSciOn)
        {
            // 关闭串口
            tyj_serial->close();
            // 调整ui
            setUiAsSciChg(false);
        }
    }
}

void MainWindow::setOKSlot(void)
{

    // 断开修改事件
    disconnect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::tableChangedSlot);

    // for (int i = 0; i < names->size(); i++)
    // {
    //     qDebug() << "names " << i << " " << names->at(i) << endl;
    // }
    // for (int i = 0; i < types->size(); i++)
    // {
    //     qDebug() << "types " << i << " " << types->at(i) << endl;
    // }

    // 原来的清空
    ui->tableWidget->clear();

    int cnt = names->size();

    QStringList headNameList;
    headNameList << "名称(双击加入高速列表)"
        << "类型"
        << "值"
        << "最大值"
        << "最小值";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, 240);
    ui->tableWidget->setColumnWidth(1, 80);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setHorizontalHeaderLabels(headNameList);
    ui->tableWidget->setRowCount(cnt);
    for (int i = 0; i < cnt; i++)
    {
        // 标题栏不可编辑也不可选择
        QTableWidgetItem* ptr1 = new QTableWidgetItem(names->at(i));
        ptr1->setFlags(ptr1->flags() & (~Qt::ItemIsEditable) & (~Qt::ItemIsSelectable));
        ui->tableWidget->setItem(i, 0, ptr1);

        // 类型栏不可编辑也不可选择
        QTableWidgetItem* ptr2 = new QTableWidgetItem(types->at(i));
        ptr2->setFlags(ptr2->flags() & (~Qt::ItemIsEditable) & (~Qt::ItemIsSelectable));
        ui->tableWidget->setItem(i, 1, ptr2);

        values->append(0.0f);

        QTableWidgetItem* ptr3 = new QTableWidgetItem(QString::number(values->at(i), 'g', 6));
        ui->tableWidget->setItem(i, 2, ptr3);
    }

    // 连接修改事件
    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::tableChangedSlot);

    varNum->clear();

    scopeForm1->setPlotVars({});
}

void MainWindow::setUiAsSciChg(bool ifOn)
{
    isSciOn = ifOn;
    if (ifOn)
    {
        // 下拉菜单控件失能
        ui->portNameBox->setEnabled(false);
        ui->baudrateBox->setEnabled(false);
        ui->dataBitsBox->setEnabled(false);
        ui->ParityBox->setEnabled(false);
        ui->stopBitsBox->setEnabled(false);

        ui->openButton->setText(QString("关闭串口"));
        // 发送按键使能
        ui->sendButton->setEnabled(true);
    }
    else
    {
        // 下拉菜单控件使能
        ui->portNameBox->setEnabled(true);
        ui->baudrateBox->setEnabled(true);
        ui->dataBitsBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->stopBitsBox->setEnabled(true);

        ui->openButton->setText(QString("打开串口"));
        // 发送按键失能
        ui->sendButton->setEnabled(false);
    }
    // qDebug() << "setUiAsSciChg" << ifOn << endl;
}


void MainWindow::closeEvent(QCloseEvent* event)
{
    event->accept();
    QApplication::exit(0);
}

void MainWindow::on_luaButton_clicked()
{
    luaForm1->show();
    luaForm1->raise();
    luaForm1->showNormal();
}
