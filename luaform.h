#ifndef LUAFORM_H
#define LUAFORM_H

#include <QtWidgets/QWidget>

namespace Ui
{
    class luaForm;
}

class MainWindow;

class luaForm : public QWidget
{
    Q_OBJECT

public:
    explicit luaForm(QWidget *parent, MainWindow *mainWindow_init);
    ~luaForm();

public:
    Ui::luaForm *ui;
    MainWindow *mainWin1;
private slots:
    void on_exeButton_clicked();
    void on_clearButton_clicked();
    void on_loadButton1_clicked();
    void on_loadButton2_clicked();
    void on_exe_clr_Button_clicked();
    void on_loadButton3_clicked();
    void on_loadButton_clicked();
    void on_srcButton_clicked();
};

#endif // LUAFORM_H
