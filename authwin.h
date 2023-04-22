#ifndef AUTHWIN_H
#define AUTHWIN_H

#include <QtWidgets/QDialog>

namespace Ui {
    class authWin;
}

class authWin: public QDialog
{
    Q_OBJECT

public:
    explicit authWin(QWidget* parent = nullptr);
    ~authWin();

    void setUIDStr(QString UID);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    void closeEvent(QCloseEvent* event) override;
    
private:
    Ui::authWin* ui;
};

#endif // AUTHWIN_H
