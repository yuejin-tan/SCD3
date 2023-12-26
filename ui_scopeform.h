/********************************************************************************
** Form generated from reading UI file 'scopeform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOPEFORM_H
#define UI_SCOPEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tyjplot.h"
#include "tyjscrollbar.h"

QT_BEGIN_NAMESPACE

class Ui_scopeForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_onlyshowed;
    QCheckBox *checkBox_noTitle;
    QCheckBox *checkBox_noNum;
    QRadioButton *radioButton_comma;
    QRadioButton *radioButton_tab;
    QPushButton *toClipBoardButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_startstop;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_pkgdelta;
    QPushButton *pushButton_pkgdelta;
    QLabel *label;
    QLabel *label_pkgdelta;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_add;
    tyjPlot *tyj_widget;
    tyjScrollBar *horizontalScrollBar;

    void setupUi(QWidget *scopeForm)
    {
        if (scopeForm->objectName().isEmpty())
            scopeForm->setObjectName(QString::fromUtf8("scopeForm"));
        scopeForm->resize(1000, 750);
        scopeForm->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(12);
        scopeForm->setFont(font);
        verticalLayout = new QVBoxLayout(scopeForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_onlyshowed = new QCheckBox(scopeForm);
        checkBox_onlyshowed->setObjectName(QString::fromUtf8("checkBox_onlyshowed"));
        checkBox_onlyshowed->setChecked(true);

        horizontalLayout->addWidget(checkBox_onlyshowed);

        checkBox_noTitle = new QCheckBox(scopeForm);
        checkBox_noTitle->setObjectName(QString::fromUtf8("checkBox_noTitle"));

        horizontalLayout->addWidget(checkBox_noTitle);

        checkBox_noNum = new QCheckBox(scopeForm);
        checkBox_noNum->setObjectName(QString::fromUtf8("checkBox_noNum"));

        horizontalLayout->addWidget(checkBox_noNum);

        radioButton_comma = new QRadioButton(scopeForm);
        radioButton_comma->setObjectName(QString::fromUtf8("radioButton_comma"));
        radioButton_comma->setChecked(false);

        horizontalLayout->addWidget(radioButton_comma);

        radioButton_tab = new QRadioButton(scopeForm);
        radioButton_tab->setObjectName(QString::fromUtf8("radioButton_tab"));
        radioButton_tab->setChecked(true);

        horizontalLayout->addWidget(radioButton_tab);

        toClipBoardButton = new QPushButton(scopeForm);
        toClipBoardButton->setObjectName(QString::fromUtf8("toClipBoardButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toClipBoardButton->sizePolicy().hasHeightForWidth());
        toClipBoardButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(toClipBoardButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_startstop = new QPushButton(scopeForm);
        pushButton_startstop->setObjectName(QString::fromUtf8("pushButton_startstop"));
        sizePolicy.setHeightForWidth(pushButton_startstop->sizePolicy().hasHeightForWidth());
        pushButton_startstop->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_startstop);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_pkgdelta = new QDoubleSpinBox(scopeForm);
        doubleSpinBox_pkgdelta->setObjectName(QString::fromUtf8("doubleSpinBox_pkgdelta"));
        sizePolicy.setHeightForWidth(doubleSpinBox_pkgdelta->sizePolicy().hasHeightForWidth());
        doubleSpinBox_pkgdelta->setSizePolicy(sizePolicy);
        doubleSpinBox_pkgdelta->setDecimals(4);
        doubleSpinBox_pkgdelta->setMinimum(0.000100000000000);
        doubleSpinBox_pkgdelta->setMaximum(99.999899999999997);
        doubleSpinBox_pkgdelta->setSingleStep(0.001000000000000);
        doubleSpinBox_pkgdelta->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_pkgdelta);

        pushButton_pkgdelta = new QPushButton(scopeForm);
        pushButton_pkgdelta->setObjectName(QString::fromUtf8("pushButton_pkgdelta"));
        sizePolicy.setHeightForWidth(pushButton_pkgdelta->sizePolicy().hasHeightForWidth());
        pushButton_pkgdelta->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_pkgdelta);

        label = new QLabel(scopeForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_pkgdelta = new QLabel(scopeForm);
        label_pkgdelta->setObjectName(QString::fromUtf8("label_pkgdelta"));

        horizontalLayout_2->addWidget(label_pkgdelta);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_add = new QPushButton(scopeForm);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        horizontalLayout_2->addWidget(pushButton_add);


        verticalLayout->addLayout(horizontalLayout_2);

        tyj_widget = new tyjPlot(scopeForm);
        tyj_widget->setObjectName(QString::fromUtf8("tyj_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tyj_widget->sizePolicy().hasHeightForWidth());
        tyj_widget->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(18);
        tyj_widget->setFont(font1);

        verticalLayout->addWidget(tyj_widget);

        horizontalScrollBar = new tyjScrollBar(scopeForm);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        retranslateUi(scopeForm);

        QMetaObject::connectSlotsByName(scopeForm);
    } // setupUi

    void retranslateUi(QWidget *scopeForm)
    {
        scopeForm->setWindowTitle(QCoreApplication::translate("scopeForm", "scope", nullptr));
        checkBox_onlyshowed->setText(QCoreApplication::translate("scopeForm", "\344\273\205\345\257\274\345\207\272\347\252\227\345\217\243\345\206\205\347\232\204\346\225\260\346\215\256", nullptr));
        checkBox_noTitle->setText(QCoreApplication::translate("scopeForm", "\344\270\215\345\270\246\346\240\207\351\242\230", nullptr));
        checkBox_noNum->setText(QCoreApplication::translate("scopeForm", "\344\270\215\345\270\246\345\272\217\345\217\267", nullptr));
        radioButton_comma->setText(QCoreApplication::translate("scopeForm", "\351\200\227\345\217\267\345\210\206\351\232\224", nullptr));
        radioButton_tab->setText(QCoreApplication::translate("scopeForm", "\345\210\266\350\241\250\347\254\246\345\210\206\351\232\224", nullptr));
        toClipBoardButton->setText(QCoreApplication::translate("scopeForm", "\350\207\263\345\211\252\350\264\264\346\235\277", nullptr));
        pushButton_startstop->setText(QCoreApplication::translate("scopeForm", "\346\232\202\345\201\234\350\256\260\345\275\225", nullptr));
        pushButton_pkgdelta->setText(QCoreApplication::translate("scopeForm", "\350\256\276\347\275\256\345\214\205\351\227\264\351\232\224", nullptr));
        label->setText(QCoreApplication::translate("scopeForm", "\344\275\277\347\224\250\345\214\205\351\227\264\351\232\224\357\274\232", nullptr));
        label_pkgdelta->setText(QCoreApplication::translate("scopeForm", "1", nullptr));
        pushButton_add->setText(QCoreApplication::translate("scopeForm", "\345\212\240\345\205\245\345\233\276\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scopeForm: public Ui_scopeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPEFORM_H
