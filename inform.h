#ifndef INFORM_H
#define INFORM_H

#include <QtWidgets/QWidget>

namespace Ui
{
    class inForm;
}

class inForm : public QWidget
{
    Q_OBJECT

public:
    explicit inForm(QWidget *parent,
                    QVector<QString> *names_in,
                    QVector<QString> *types_in);
    ~inForm();

public slots:

    void on_cButton_clicked();

signals:
    void setOKsig(void);

public:
    Ui::inForm *ui;

    // 变量名数组
    QVector<QString> *names;
    // 类型数组
    QVector<QString> *types;
};

#endif // INFORM_H
