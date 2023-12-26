/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *fcnButton1;
    QPushButton *luaButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *baudrateBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *dataBitsBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *ParityBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *stopBitsBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *portNameBox;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *searchButton;
    QPushButton *openButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QPlainTextEdit *revPlainTextEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QPlainTextEdit *sendPlainTextEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *inButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cfgButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QPushButton *refreshButton;
    QTableWidget *tableWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        MainWindow->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        fcnButton1 = new QPushButton(widget);
        fcnButton1->setObjectName(QString::fromUtf8("fcnButton1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fcnButton1->sizePolicy().hasHeightForWidth());
        fcnButton1->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(fcnButton1);

        luaButton = new QPushButton(widget);
        luaButton->setObjectName(QString::fromUtf8("luaButton"));
        sizePolicy1.setHeightForWidth(luaButton->sizePolicy().hasHeightForWidth());
        luaButton->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(luaButton);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_4);

        baudrateBox = new QComboBox(widget);
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->setObjectName(QString::fromUtf8("baudrateBox"));

        horizontalLayout_3->addWidget(baudrateBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_5);

        dataBitsBox = new QComboBox(widget);
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        horizontalLayout_4->addWidget(dataBitsBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_6);

        ParityBox = new QComboBox(widget);
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));

        horizontalLayout_5->addWidget(ParityBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_7);

        stopBitsBox = new QComboBox(widget);
        stopBitsBox->addItem(QString());
        stopBitsBox->addItem(QString());
        stopBitsBox->addItem(QString());
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        horizontalLayout_6->addWidget(stopBitsBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(label_3);

        portNameBox = new QComboBox(widget);
        portNameBox->addItem(QString());
        portNameBox->setObjectName(QString::fromUtf8("portNameBox"));

        horizontalLayout_2->addWidget(portNameBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        searchButton = new QPushButton(widget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        sizePolicy1.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(searchButton);

        openButton = new QPushButton(widget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        sizePolicy1.setHeightForWidth(openButton->sizePolicy().hasHeightForWidth());
        openButton->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(openButton);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        revPlainTextEdit = new QPlainTextEdit(widget);
        revPlainTextEdit->setObjectName(QString::fromUtf8("revPlainTextEdit"));

        verticalLayout_3->addWidget(revPlainTextEdit);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        sendPlainTextEdit = new QPlainTextEdit(widget);
        sendPlainTextEdit->setObjectName(QString::fromUtf8("sendPlainTextEdit"));

        verticalLayout_4->addWidget(sendPlainTextEdit);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(clearButton);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sizePolicy1.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        inButton = new QPushButton(centralWidget);
        inButton->setObjectName(QString::fromUtf8("inButton"));
        sizePolicy1.setHeightForWidth(inButton->sizePolicy().hasHeightForWidth());
        inButton->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(inButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        cfgButton = new QPushButton(centralWidget);
        cfgButton->setObjectName(QString::fromUtf8("cfgButton"));
        sizePolicy1.setHeightForWidth(cfgButton->sizePolicy().hasHeightForWidth());
        cfgButton->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(cfgButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(50);
        spinBox->setMaximum(999999);
        spinBox->setValue(666);

        horizontalLayout_11->addWidget(spinBox);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_11->addWidget(checkBox);

        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        sizePolicy1.setHeightForWidth(refreshButton->sizePolicy().hasHeightForWidth());
        refreshButton->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(refreshButton);


        verticalLayout_2->addLayout(horizontalLayout_11);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget->setColumnCount(0);

        verticalLayout_2->addWidget(tableWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        baudrateBox->setCurrentIndex(7);
        ParityBox->setCurrentIndex(0);
        portNameBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SCD", nullptr));
        fcnButton1->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276\347\252\227\345\217\243", nullptr));
        luaButton->setText(QCoreApplication::translate("MainWindow", "LUA", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        baudrateBox->setItemText(0, QCoreApplication::translate("MainWindow", "4800", nullptr));
        baudrateBox->setItemText(1, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baudrateBox->setItemText(2, QCoreApplication::translate("MainWindow", "19200", nullptr));
        baudrateBox->setItemText(3, QCoreApplication::translate("MainWindow", "38400", nullptr));
        baudrateBox->setItemText(4, QCoreApplication::translate("MainWindow", "76800", nullptr));
        baudrateBox->setItemText(5, QCoreApplication::translate("MainWindow", "115200", nullptr));
        baudrateBox->setItemText(6, QCoreApplication::translate("MainWindow", "230400", nullptr));
        baudrateBox->setItemText(7, QCoreApplication::translate("MainWindow", "460800", nullptr));
        baudrateBox->setItemText(8, QCoreApplication::translate("MainWindow", "921600", nullptr));
        baudrateBox->setItemText(9, QCoreApplication::translate("MainWindow", "1000000", nullptr));

        baudrateBox->setCurrentText(QCoreApplication::translate("MainWindow", "460800", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        dataBitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        dataBitsBox->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));
        dataBitsBox->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        dataBitsBox->setItemText(3, QCoreApplication::translate("MainWindow", "5", nullptr));
        dataBitsBox->setItemText(4, QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276\346\227\266\345\277\205\351\241\273\344\270\2728\344\275\215", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        ParityBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        ParityBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        ParityBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        stopBitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        stopBitsBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        stopBitsBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        portNameBox->setItemText(0, QCoreApplication::translate("MainWindow", "\350\257\267\345\205\210\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));

        searchButton->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(shortcut)
        clearButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
#if QT_CONFIG(shortcut)
        sendButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Return", nullptr));
#endif // QT_CONFIG(shortcut)
        inButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\345\210\227\350\241\250", nullptr));
        cfgButton->setText(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\351\227\264\351\232\224(ms)", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\210\267\346\226\260", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
