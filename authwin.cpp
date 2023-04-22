#include "authwin.h"
#include "ui_authwin.h"

#include <QtWidgets/QApplication>
#include <QtGui/QCloseEvent>

authWin::authWin(QWidget* parent):
    QDialog(parent),
    ui(new Ui::authWin)
{
    ui->setupUi(this);
}

authWin::~authWin()
{
    delete ui;
}

void authWin::setUIDStr(QString UID)
{
    ui->lineEdit->setText(UID);
}

void authWin::on_pushButton_clicked()
{
    qApp->quit();
}

void authWin::closeEvent(QCloseEvent* event)
{
    event->accept();
    qApp->quit();
}

void authWin::on_pushButton_2_clicked()
{
    hide();
}

