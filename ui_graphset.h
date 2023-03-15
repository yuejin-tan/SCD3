/********************************************************************************
** Form generated from reading UI file 'graphset.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHSET_H
#define UI_GRAPHSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphSet
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_name;
    QLabel *label_4;
    QPushButton *pushButton_color;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_xmin;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_xmax;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox_ymin;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_ymax;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_rm;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *graphSet)
    {
        if (graphSet->objectName().isEmpty())
            graphSet->setObjectName(QString::fromUtf8("graphSet"));
        graphSet->resize(360, 250);
        graphSet->setMinimumSize(QSize(320, 220));
        graphSet->setMaximumSize(QSize(400, 280));
        QFont font;
        font.setPointSize(12);
        graphSet->setFont(font);
        verticalLayout = new QVBoxLayout(graphSet);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(graphSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_name = new QLabel(graphSet);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_name, 0, 1, 1, 1);

        label_4 = new QLabel(graphSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        pushButton_color = new QPushButton(graphSet);
        pushButton_color->setObjectName(QString::fromUtf8("pushButton_color"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_color->sizePolicy().hasHeightForWidth());
        pushButton_color->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_color, 1, 1, 1, 1);

        label = new QLabel(graphSet);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        comboBox = new QComboBox(graphSet);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        label_2 = new QLabel(graphSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_xmin = new QDoubleSpinBox(graphSet);
        doubleSpinBox_xmin->setObjectName(QString::fromUtf8("doubleSpinBox_xmin"));
        sizePolicy.setHeightForWidth(doubleSpinBox_xmin->sizePolicy().hasHeightForWidth());
        doubleSpinBox_xmin->setSizePolicy(sizePolicy);
        doubleSpinBox_xmin->setDecimals(3);
        doubleSpinBox_xmin->setMinimum(-999999999.000000000000000);
        doubleSpinBox_xmin->setMaximum(999999999.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_xmin);

        label_7 = new QLabel(graphSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        doubleSpinBox_xmax = new QDoubleSpinBox(graphSet);
        doubleSpinBox_xmax->setObjectName(QString::fromUtf8("doubleSpinBox_xmax"));
        sizePolicy.setHeightForWidth(doubleSpinBox_xmax->sizePolicy().hasHeightForWidth());
        doubleSpinBox_xmax->setSizePolicy(sizePolicy);
        doubleSpinBox_xmax->setDecimals(3);
        doubleSpinBox_xmax->setMinimum(-999999999.000000000000000);
        doubleSpinBox_xmax->setMaximum(99999999.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_xmax);


        gridLayout->addLayout(horizontalLayout_2, 3, 1, 1, 1);

        label_3 = new QLabel(graphSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        doubleSpinBox_ymin = new QDoubleSpinBox(graphSet);
        doubleSpinBox_ymin->setObjectName(QString::fromUtf8("doubleSpinBox_ymin"));
        sizePolicy.setHeightForWidth(doubleSpinBox_ymin->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ymin->setSizePolicy(sizePolicy);
        doubleSpinBox_ymin->setDecimals(3);
        doubleSpinBox_ymin->setMinimum(-999999999.000000000000000);
        doubleSpinBox_ymin->setMaximum(99999999.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_ymin);

        label_6 = new QLabel(graphSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        doubleSpinBox_ymax = new QDoubleSpinBox(graphSet);
        doubleSpinBox_ymax->setObjectName(QString::fromUtf8("doubleSpinBox_ymax"));
        sizePolicy.setHeightForWidth(doubleSpinBox_ymax->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ymax->setSizePolicy(sizePolicy);
        doubleSpinBox_ymax->setDecimals(3);
        doubleSpinBox_ymax->setMinimum(-999999999.000000000000000);
        doubleSpinBox_ymax->setMaximum(999999999.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_ymax);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_rm = new QPushButton(graphSet);
        pushButton_rm->setObjectName(QString::fromUtf8("pushButton_rm"));
        sizePolicy.setHeightForWidth(pushButton_rm->sizePolicy().hasHeightForWidth());
        pushButton_rm->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_rm);

        pushButton_ok = new QPushButton(graphSet);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        sizePolicy.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(graphSet);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);

        retranslateUi(graphSet);

        QMetaObject::connectSlotsByName(graphSet);
    } // setupUi

    void retranslateUi(QWidget *graphSet)
    {
        graphSet->setWindowTitle(QCoreApplication::translate("graphSet", "\345\233\276\345\203\217\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("graphSet", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_name->setText(QCoreApplication::translate("graphSet", "name", nullptr));
        label_4->setText(QCoreApplication::translate("graphSet", "\351\242\234\350\211\262\357\274\232", nullptr));
        pushButton_color->setText(QCoreApplication::translate("graphSet", "100,100,100", nullptr));
        label->setText(QCoreApplication::translate("graphSet", "\347\272\277\345\275\242\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("graphSet", "\347\233\264\347\272\277\350\277\236\346\216\245", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("graphSet", "\344\270\200\351\230\266\344\277\235\346\214\201", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("graphSet", "\347\246\273\346\225\243\347\202\271", nullptr));

        label_2->setText(QCoreApplication::translate("graphSet", "X\350\275\264\350\214\203\345\233\264\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("graphSet", "\345\210\260", nullptr));
        label_3->setText(QCoreApplication::translate("graphSet", "Y\350\275\264\350\214\203\345\233\264\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("graphSet", "\345\210\260", nullptr));
        pushButton_rm->setText(QCoreApplication::translate("graphSet", "\347\247\273\351\231\244\345\233\276\345\203\217", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("graphSet", "\347\241\256\350\256\244", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("graphSet", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphSet: public Ui_graphSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHSET_H
