/********************************************************************************
** Form generated from reading UI file 'resboxctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESBOXCTRL_H
#define UI_RESBOXCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_resBoxCtrl
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit;

    void setupUi(QDialog *resBoxCtrl)
    {
        if (resBoxCtrl->objectName().isEmpty())
            resBoxCtrl->setObjectName(QString::fromUtf8("resBoxCtrl"));
        resBoxCtrl->resize(240, 240);
        gridLayout = new QGridLayout(resBoxCtrl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(resBoxCtrl);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(resBoxCtrl);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(resBoxCtrl);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(resBoxCtrl);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(resBoxCtrl);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(resBoxCtrl);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(resBoxCtrl);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(resBoxCtrl);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        pushButton_9 = new QPushButton(resBoxCtrl);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 4, 0, 1, 1);

        pushButton_10 = new QPushButton(resBoxCtrl);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 4, 1, 1, 1);

        pushButton_11 = new QPushButton(resBoxCtrl);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 5, 0, 1, 1);

        pushButton_12 = new QPushButton(resBoxCtrl);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 5, 1, 1, 1);

        lineEdit = new QLineEdit(resBoxCtrl);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 6, 0, 1, 2);


        retranslateUi(resBoxCtrl);

        QMetaObject::connectSlotsByName(resBoxCtrl);
    } // setupUi

    void retranslateUi(QDialog *resBoxCtrl)
    {
        resBoxCtrl->setWindowTitle(QCoreApplication::translate("resBoxCtrl", "\347\224\265\351\230\273\347\256\261\346\216\247\345\210\266\357\274\210\344\273\256", nullptr));
        pushButton->setText(QCoreApplication::translate("resBoxCtrl", "540 on", nullptr));
        pushButton_2->setText(QCoreApplication::translate("resBoxCtrl", "540 off", nullptr));
        pushButton_3->setText(QCoreApplication::translate("resBoxCtrl", "fan on", nullptr));
        pushButton_4->setText(QCoreApplication::translate("resBoxCtrl", "fan off", nullptr));
        pushButton_5->setText(QCoreApplication::translate("resBoxCtrl", "R0 on", nullptr));
        pushButton_6->setText(QCoreApplication::translate("resBoxCtrl", "R0 off", nullptr));
        pushButton_7->setText(QCoreApplication::translate("resBoxCtrl", "R1 on", nullptr));
        pushButton_8->setText(QCoreApplication::translate("resBoxCtrl", "R1 off", nullptr));
        pushButton_9->setText(QCoreApplication::translate("resBoxCtrl", "R2 on", nullptr));
        pushButton_10->setText(QCoreApplication::translate("resBoxCtrl", "R2 off", nullptr));
        pushButton_11->setText(QCoreApplication::translate("resBoxCtrl", "R3 on", nullptr));
        pushButton_12->setText(QCoreApplication::translate("resBoxCtrl", "R3 off", nullptr));
        lineEdit->setText(QCoreApplication::translate("resBoxCtrl", "no sig yet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resBoxCtrl: public Ui_resBoxCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESBOXCTRL_H
