#include "inform.h"
#include "ui_inform.h"

#include "QDebug"
#include "QMessageBox"

inForm::inForm(QWidget *parent,
               QVector<QString> *names_in,
               QVector<QString> *types_in) : QWidget(parent),
                                             ui(new Ui::inForm)
{
    ui->setupUi(this);
    names = names_in;
    types = types_in;

}

inForm::~inForm()
{
    delete ui;
}

void inForm::on_cButton_clicked()
{
    QString cCode = ui->plainTextEdit->toPlainText();

    QString keyword("SCD_REG_ADD");
    QString keyword1("(");
    QString keyword2(",");
    QString keyword3(")");

    int pos = 0;

    // 删除原来的
    names->clear();
    types->clear();

    // 防卡死
    int cnt = 0;

    while (cnt++ < 999)
    {
        int ans = cCode.indexOf(keyword, pos);
        if (ans < 0)
        {
            break;
        }
        int ans1 = cCode.indexOf(keyword1, ans);
        int ans2 = cCode.indexOf(keyword2, ans);
        int ans3 = cCode.indexOf(keyword3, ans);

        QString nameStr = cCode.mid(ans1 + keyword1.length(), ans2 - ans1 - keyword1.length()).trimmed();
        QString typeStr = cCode.mid(ans2 + keyword2.length(), ans3 - ans2 - keyword2.length()).trimmed();

        names->append(nameStr);
        types->append(typeStr);

        // qDebug() << "at" << ans << endl;
        // qDebug() << nameStr << endl;
        // qDebug() << typeStr << endl
        //          << endl;

        pos = ans + 1;
    }

    emit setOKsig();
}
