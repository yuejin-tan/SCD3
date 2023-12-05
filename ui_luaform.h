/********************************************************************************
** Form generated from reading UI file 'luaform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUAFORM_H
#define UI_LUAFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_luaForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit1_1;
    QLabel *label_2;
    QLineEdit *lineEdit1_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loadButton1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit2_1;
    QLabel *label_6;
    QLineEdit *lineEdit2_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *loadButton2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit3_1;
    QLabel *label_8;
    QLineEdit *lineEdit3_2;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *loadButton3;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *srcButton;
    QPushButton *loadButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QPushButton *exeButton;
    QPushButton *exe_clr_Button;

    void setupUi(QWidget *luaForm)
    {
        if (luaForm->objectName().isEmpty())
            luaForm->setObjectName(QString::fromUtf8("luaForm"));
        luaForm->resize(800, 600);
        luaForm->setMinimumSize(QSize(400, 300));
        QFont font;
        font.setPointSize(12);
        luaForm->setFont(font);
        verticalLayout_3 = new QVBoxLayout(luaForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(luaForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 16, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit1_1 = new QLineEdit(groupBox);
        lineEdit1_1->setObjectName(QString::fromUtf8("lineEdit1_1"));

        horizontalLayout_2->addWidget(lineEdit1_1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit1_2 = new QLineEdit(groupBox);
        lineEdit1_2->setObjectName(QString::fromUtf8("lineEdit1_2"));

        horizontalLayout_2->addWidget(lineEdit1_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        loadButton1 = new QPushButton(groupBox);
        loadButton1->setObjectName(QString::fromUtf8("loadButton1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loadButton1->sizePolicy().hasHeightForWidth());
        loadButton1->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(loadButton1);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(3, 3);
        horizontalLayout_2->setStretch(5, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit2_1 = new QLineEdit(groupBox);
        lineEdit2_1->setObjectName(QString::fromUtf8("lineEdit2_1"));

        horizontalLayout_3->addWidget(lineEdit2_1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit2_2 = new QLineEdit(groupBox);
        lineEdit2_2->setObjectName(QString::fromUtf8("lineEdit2_2"));

        horizontalLayout_3->addWidget(lineEdit2_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        loadButton2 = new QPushButton(groupBox);
        loadButton2->setObjectName(QString::fromUtf8("loadButton2"));
        sizePolicy.setHeightForWidth(loadButton2->sizePolicy().hasHeightForWidth());
        loadButton2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(loadButton2);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(3, 3);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(luaForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 16, -1, -1);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        lineEdit3_1 = new QLineEdit(groupBox_2);
        lineEdit3_1->setObjectName(QString::fromUtf8("lineEdit3_1"));

        horizontalLayout_4->addWidget(lineEdit3_1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit3_2 = new QLineEdit(groupBox_2);
        lineEdit3_2->setObjectName(QString::fromUtf8("lineEdit3_2"));

        horizontalLayout_4->addWidget(lineEdit3_2);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        loadButton3 = new QPushButton(groupBox_2);
        loadButton3->setObjectName(QString::fromUtf8("loadButton3"));
        sizePolicy.setHeightForWidth(loadButton3->sizePolicy().hasHeightForWidth());
        loadButton3->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(loadButton3);


        verticalLayout_3->addWidget(groupBox_2);

        plainTextEdit = new QPlainTextEdit(luaForm);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_3->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        srcButton = new QPushButton(luaForm);
        srcButton->setObjectName(QString::fromUtf8("srcButton"));

        horizontalLayout->addWidget(srcButton);

        loadButton = new QPushButton(luaForm);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        sizePolicy.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(loadButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(luaForm);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(clearButton);

        exeButton = new QPushButton(luaForm);
        exeButton->setObjectName(QString::fromUtf8("exeButton"));
        sizePolicy.setHeightForWidth(exeButton->sizePolicy().hasHeightForWidth());
        exeButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(exeButton);

        exe_clr_Button = new QPushButton(luaForm);
        exe_clr_Button->setObjectName(QString::fromUtf8("exe_clr_Button"));
        sizePolicy.setHeightForWidth(exe_clr_Button->sizePolicy().hasHeightForWidth());
        exe_clr_Button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(exe_clr_Button);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(luaForm);

        QMetaObject::connectSlotsByName(luaForm);
    } // setupUi

    void retranslateUi(QWidget *luaForm)
    {
        luaForm->setWindowTitle(QCoreApplication::translate("luaForm", "lua script", nullptr));
        groupBox->setTitle(QCoreApplication::translate("luaForm", "DUMP", nullptr));
        label->setText(QCoreApplication::translate("luaForm", "scd_dump(", nullptr));
        lineEdit1_1->setPlaceholderText(QCoreApplication::translate("luaForm", "listNum", nullptr));
        label_2->setText(QCoreApplication::translate("luaForm", ",", nullptr));
        lineEdit1_2->setPlaceholderText(QCoreApplication::translate("luaForm", "dumpNums", nullptr));
        label_3->setText(QCoreApplication::translate("luaForm", ");", nullptr));
        loadButton1->setText(QCoreApplication::translate("luaForm", "\346\217\222\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("luaForm", "scd_dumpOut(", nullptr));
        lineEdit2_1->setPlaceholderText(QCoreApplication::translate("luaForm", "colCnt", nullptr));
        label_6->setText(QCoreApplication::translate("luaForm", ",\"", nullptr));
        lineEdit2_2->setPlaceholderText(QCoreApplication::translate("luaForm", "win(default)/cb/cmd/csv", nullptr));
        label_5->setText(QCoreApplication::translate("luaForm", "\");", nullptr));
        loadButton2->setText(QCoreApplication::translate("luaForm", "\346\217\222\345\205\245", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("luaForm", "CALL", nullptr));
        label_7->setText(QCoreApplication::translate("luaForm", "scd_call(", nullptr));
        lineEdit3_1->setPlaceholderText(QCoreApplication::translate("luaForm", "listNum", nullptr));
        label_8->setText(QCoreApplication::translate("luaForm", ",", nullptr));
        lineEdit3_2->setPlaceholderText(QCoreApplication::translate("luaForm", "int32_t para", nullptr));
        label_9->setText(QCoreApplication::translate("luaForm", ");", nullptr));
        loadButton3->setText(QCoreApplication::translate("luaForm", "\346\217\222\345\205\245", nullptr));
        srcButton->setText(QCoreApplication::translate("luaForm", "\347\274\226\350\276\221\345\210\235\345\247\213\345\214\226LUA src", nullptr));
        loadButton->setText(QCoreApplication::translate("luaForm", "\350\275\275\345\205\245", nullptr));
        clearButton->setText(QCoreApplication::translate("luaForm", "\346\270\205\351\231\244", nullptr));
        exeButton->setText(QCoreApplication::translate("luaForm", "\346\211\247\350\241\214", nullptr));
        exe_clr_Button->setText(QCoreApplication::translate("luaForm", "\346\211\247\350\241\214\345\271\266\346\270\205\351\231\244", nullptr));
#if QT_CONFIG(shortcut)
        exe_clr_Button->setShortcut(QCoreApplication::translate("luaForm", "Ctrl+Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class luaForm: public Ui_luaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUAFORM_H
