/********************************************************************************
** Form generated from reading UI file 'inform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORM_H
#define UI_INFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *inForm)
    {
        if (inForm->objectName().isEmpty())
            inForm->setObjectName(QString::fromUtf8("inForm"));
        inForm->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(160);
        sizePolicy.setVerticalStretch(120);
        sizePolicy.setHeightForWidth(inForm->sizePolicy().hasHeightForWidth());
        inForm->setSizePolicy(sizePolicy);
        inForm->setMinimumSize(QSize(200, 200));
        QFont font;
        font.setPointSize(12);
        inForm->setFont(font);
        verticalLayout = new QVBoxLayout(inForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cButton = new QPushButton(inForm);
        cButton->setObjectName(QString::fromUtf8("cButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cButton->sizePolicy().hasHeightForWidth());
        cButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cButton);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(inForm);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(inForm);

        QMetaObject::connectSlotsByName(inForm);
    } // setupUi

    void retranslateUi(QWidget *inForm)
    {
        inForm->setWindowTitle(QCoreApplication::translate("inForm", "import", nullptr));
        cButton->setText(QCoreApplication::translate("inForm", "\350\247\243\346\236\220c\344\273\243\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inForm: public Ui_inForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORM_H
