#include "luaform.h"
#include "ui_luaform.h"

#include <QFileDialog>

#include "mainwindow.h"
#include "lua5_4/lua.hpp"
#include "luascript.h"

luaForm::luaForm(QWidget* parent, MainWindow* mainWindow_init) : QWidget(parent),
ui(new Ui::luaForm)
{
    ui->setupUi(this);

    mainWin1 = mainWindow_init;
}

luaForm::~luaForm()
{
    delete ui;
}

void luaForm::on_exeButton_clicked()
{
    // 确保只有一个脚本运行
    ui->exeButton->setEnabled(false);
    ui->exe_clr_Button->setEnabled(false);

    // 调用脚本
    mainWin1->luaScript1->exeStr(ui->plainTextEdit->toPlainText().append("\n"));

    // 恢复运行按钮
    ui->exeButton->setEnabled(true);
    ui->exe_clr_Button->setEnabled(true);
}

void luaForm::on_clearButton_clicked()
{
    ui->plainTextEdit->clear();
}

void luaForm::on_loadButton1_clicked()
{
    QString strLua = QString("scd_dump(") + ui->lineEdit1_1->text().trimmed() + QString(", ") + ui->lineEdit1_2->text().trimmed() + QString(");\n");
    ui->plainTextEdit->insertPlainText(strLua);
}

void luaForm::on_loadButton2_clicked()
{
    QString strLua = QString("scd_dumpOut(") + ui->lineEdit2_1->text().trimmed() + QString(", [[") + ui->lineEdit2_2->text().trimmed() + QString("]]);\n");
    ui->plainTextEdit->insertPlainText(strLua);
}

void luaForm::on_exe_clr_Button_clicked()
{
    on_exeButton_clicked();
    on_clearButton_clicked();
}

void luaForm::on_loadButton3_clicked()
{
    QString strLua = QString("scd_call(") + ui->lineEdit3_1->text().trimmed() + QString(", ") + ui->lineEdit3_2->text().trimmed() + QString(");\n");
    ui->plainTextEdit->insertPlainText(strLua);
}

void luaForm::on_loadButton_clicked()
{

    QString saveDir = mainWin1->luaScript1->getSaveDir();
    QString fileName = QFileDialog::getOpenFileName(this,
        "打开LUA脚本", saveDir, "lua scripts (*.lua *.txt)");
    if (fileName == "")
    {
        // 未选择
        // qDebug() << "cancel";
        return;
    }

    size_t fileLength = 0;
    char* fileBuffer = nullptr;

    {
        QByteArray fileName2 = fileName.toLocal8Bit();
        FILE* fileHandle = fopen(fileName2.data(), "rb");

        if (fileHandle)
        {
            fseek(fileHandle, 0, SEEK_END);
            fileLength = ftell(fileHandle);
            fileBuffer = (char*)malloc((fileLength + 1) * sizeof(char));
            rewind(fileHandle);
            fileLength = fread(fileBuffer, 1, fileLength, fileHandle);
            fileBuffer[fileLength] = '\0';
            fclose(fileHandle);

            ui->plainTextEdit->setPlainText(QString::fromLocal8Bit(fileBuffer));
        }
        else
        {
            printf("lua file open err\n");
        }
    }

    if (fileBuffer)
    {
        free(fileBuffer);
    }
}

void luaForm::on_srcButton_clicked()
{
    //打开资源管理器并高亮文件
    const QString explorer = "explorer";
    QStringList param;
    param << QLatin1String("/select,");
    param << QDir::toNativeSeparators("./scd_cfg_win64.lua");
    QProcess::startDetached(explorer, param);
}

