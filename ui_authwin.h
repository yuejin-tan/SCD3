/********************************************************************************
** Form generated from reading UI file 'authwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWIN_H
#define UI_AUTHWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_authWin
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *authWin)
    {
        if (authWin->objectName().isEmpty())
            authWin->setObjectName(QString::fromUtf8("authWin"));
        authWin->resize(666, 500);
        authWin->setModal(true);
        verticalLayout = new QVBoxLayout(authWin);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(authWin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: wheat;font: bold 40px;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(authWin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 20px;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(authWin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setStyleSheet(QString::fromUtf8("font-size: 20px; padding: 6px;"));
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(authWin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setStyleSheet(QString::fromUtf8("font: bold 24px; padding: 8px;"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(authWin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setStyleSheet(QString::fromUtf8("font: bold 24px; padding: 8px;"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(authWin);

        QMetaObject::connectSlotsByName(authWin);
    } // setupUi

    void retranslateUi(QDialog *authWin)
    {
        authWin->setWindowTitle(QCoreApplication::translate("authWin", "\347\224\251\351\224\205\345\243\260\346\230\216", nullptr));
        label->setText(QCoreApplication::translate("authWin", "\344\275\277(shuai)\347\224\250(guo)\346\217\220\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("authWin", "\346\254\242\350\277\216\344\275\277\347\224\250SCD3\357\274\201\346\243\200\346\265\213\345\210\260\345\271\266\351\235\236\345\234\250tyj\347\232\204\347\224\265\350\204\221\344\270\212\350\277\220\350\241\214\357\274\201\n"
"\350\257\267\346\263\250\346\204\217\350\257\245\350\275\257\344\273\266\346\230\257tyj\345\234\250\344\270\232\344\275\231\346\227\266\351\227\264\345\206\231\347\235\200\347\216\251\347\232\204\357\274\214\350\277\230\346\234\211\345\276\210\345\244\232bug\346\262\241\346\224\271\345\256\214\357\274\214\345\234\250\351\203\250\345\210\206\346\203\205\345\206\265\344\270\213\345\217\257\350\203\275\344\274\232\345\215\241\346\255\273\351\200\200\345\207\272\357\274\214\351\227\256\345\260\261\346\230\257\350\246\201\351\207\215\345\220\257\350\275\257\344\273\266\343\200\202\n"
"\344\270\212\345\212\237\347\216\207\345\211\215\350\257\267\345\234\250\345\274\261\347\224\265\347\216\257\345\242\203\344\270\213\350\277\233\350\241\214\345\205\205\345\210\206\346\265\213\350\257\225\357\274"
                        "\214\344\270\215\350\246\201\344\276\235\350\265\226\346\234\254\347\250\213\345\272\217\345\256\236\347\216\260\344\277\235\346\212\244\345\201\234\346\234\272\357\274\214\350\246\201\344\277\235\350\257\201\346\216\247\345\210\266\345\231\250\350\207\252\350\272\253\350\203\275\345\256\236\347\216\260\345\274\202\345\270\270\344\277\235\346\212\244\344\270\224\346\234\211\345\205\266\344\273\226\345\217\257\351\235\240\346\211\213\346\256\265\344\275\277\346\216\247\345\210\266\345\231\250\345\201\234\346\234\272\343\200\202\346\234\254\350\275\257\344\273\266\344\274\232\345\257\271\345\206\205\345\255\230\345\217\230\351\207\217\345\200\274\350\277\233\350\241\214\347\233\264\346\216\245\350\257\273\345\217\226\345\222\214\344\277\256\346\224\271\357\274\214\347\202\270\345\217\252\345\233\240\345\220\216\346\236\234\350\207\252\350\264\237\343\200\202\n"
"\346\234\254\350\275\257\344\273\266\350\226\205\344\272\206\344\270\200\345\240\206\345\274\200\346\272\220\345\272\223\357\274\214\345\233\240\346\255"
                        "\244\344\271\237\345\274\200\346\272\220\357\274\214\350\257\267\345\256\232\346\234\237\346\243\200\346\237\245\344\270\213\351\235\242\347\275\221\347\253\231\347\234\213\346\230\257\345\220\246\346\234\211bug\344\277\256\345\244\215\347\232\204\346\226\260\347\211\210\346\234\254\343\200\202", nullptr));
        lineEdit->setText(QCoreApplication::translate("authWin", "https://github.com/yuejin-tan/SCD3", nullptr));
        pushButton->setText(QCoreApplication::translate("authWin", "\345\223\224\345\223\224\350\265\226\350\265\226\357\274\214\344\270\215\347\234\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("authWin", "\350\265\204\347\223\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authWin: public Ui_authWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWIN_H
