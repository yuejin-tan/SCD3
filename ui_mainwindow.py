# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'd:\qt_msvc_shared\SCD3\mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1000, 800)
        MainWindow.setMinimumSize(QtCore.QSize(800, 600))
        font = QtGui.QFont()
        font.setPointSize(12)
        MainWindow.setFont(font)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setObjectName("centralWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.centralWidget)
        self.horizontalLayout.setContentsMargins(4, 4, 4, 4)
        self.horizontalLayout.setSpacing(0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.widget = QtWidgets.QWidget(self.centralWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.widget.sizePolicy().hasHeightForWidth())
        self.widget.setSizePolicy(sizePolicy)
        self.widget.setObjectName("widget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.widget)
        self.verticalLayout.setContentsMargins(4, 4, 4, 4)
        self.verticalLayout.setSpacing(4)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout_9 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_9.setSpacing(6)
        self.horizontalLayout_9.setObjectName("horizontalLayout_9")
        self.fcnButton1 = QtWidgets.QPushButton(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.fcnButton1.sizePolicy().hasHeightForWidth())
        self.fcnButton1.setSizePolicy(sizePolicy)
        self.fcnButton1.setObjectName("fcnButton1")
        self.horizontalLayout_9.addWidget(self.fcnButton1)
        self.luaButton = QtWidgets.QPushButton(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.luaButton.sizePolicy().hasHeightForWidth())
        self.luaButton.setSizePolicy(sizePolicy)
        self.luaButton.setObjectName("luaButton")
        self.horizontalLayout_9.addWidget(self.luaButton)
        self.verticalLayout.addLayout(self.horizontalLayout_9)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setSpacing(6)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_4 = QtWidgets.QLabel(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_3.addWidget(self.label_4)
        self.baudrateBox = QtWidgets.QComboBox(self.widget)
        self.baudrateBox.setObjectName("baudrateBox")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.baudrateBox.addItem("")
        self.horizontalLayout_3.addWidget(self.baudrateBox)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setSpacing(6)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label_5 = QtWidgets.QLabel(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_5.sizePolicy().hasHeightForWidth())
        self.label_5.setSizePolicy(sizePolicy)
        self.label_5.setObjectName("label_5")
        self.horizontalLayout_4.addWidget(self.label_5)
        self.dataBitsBox = QtWidgets.QComboBox(self.widget)
        self.dataBitsBox.setObjectName("dataBitsBox")
        self.dataBitsBox.addItem("")
        self.dataBitsBox.addItem("")
        self.dataBitsBox.addItem("")
        self.dataBitsBox.addItem("")
        self.dataBitsBox.addItem("")
        self.horizontalLayout_4.addWidget(self.dataBitsBox)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setSpacing(6)
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.label_6 = QtWidgets.QLabel(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_6.sizePolicy().hasHeightForWidth())
        self.label_6.setSizePolicy(sizePolicy)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_5.addWidget(self.label_6)
        self.ParityBox = QtWidgets.QComboBox(self.widget)
        self.ParityBox.setObjectName("ParityBox")
        self.ParityBox.addItem("")
        self.ParityBox.addItem("")
        self.ParityBox.addItem("")
        self.horizontalLayout_5.addWidget(self.ParityBox)
        self.verticalLayout.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_6.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.horizontalLayout_6.setSpacing(6)
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.label_7 = QtWidgets.QLabel(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_7.sizePolicy().hasHeightForWidth())
        self.label_7.setSizePolicy(sizePolicy)
        self.label_7.setObjectName("label_7")
        self.horizontalLayout_6.addWidget(self.label_7)
        self.stopBitsBox = QtWidgets.QComboBox(self.widget)
        self.stopBitsBox.setObjectName("stopBitsBox")
        self.stopBitsBox.addItem("")
        self.stopBitsBox.addItem("")
        self.stopBitsBox.addItem("")
        self.horizontalLayout_6.addWidget(self.stopBitsBox)
        self.verticalLayout.addLayout(self.horizontalLayout_6)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setSpacing(6)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_3 = QtWidgets.QLabel(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_3.sizePolicy().hasHeightForWidth())
        self.label_3.setSizePolicy(sizePolicy)
        self.label_3.setMinimumSize(QtCore.QSize(0, 0))
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_2.addWidget(self.label_3)
        self.portNameBox = QtWidgets.QComboBox(self.widget)
        self.portNameBox.setObjectName("portNameBox")
        self.portNameBox.addItem("")
        self.horizontalLayout_2.addWidget(self.portNameBox)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_8.setSpacing(6)
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.searchButton = QtWidgets.QPushButton(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.searchButton.sizePolicy().hasHeightForWidth())
        self.searchButton.setSizePolicy(sizePolicy)
        self.searchButton.setObjectName("searchButton")
        self.horizontalLayout_8.addWidget(self.searchButton)
        self.openButton = QtWidgets.QPushButton(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.openButton.sizePolicy().hasHeightForWidth())
        self.openButton.setSizePolicy(sizePolicy)
        self.openButton.setObjectName("openButton")
        self.horizontalLayout_8.addWidget(self.openButton)
        self.verticalLayout.addLayout(self.horizontalLayout_8)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setSpacing(6)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label = QtWidgets.QLabel(self.widget)
        self.label.setObjectName("label")
        self.verticalLayout_3.addWidget(self.label)
        self.revPlainTextEdit = QtWidgets.QPlainTextEdit(self.widget)
        self.revPlainTextEdit.setObjectName("revPlainTextEdit")
        self.verticalLayout_3.addWidget(self.revPlainTextEdit)
        self.verticalLayout.addLayout(self.verticalLayout_3)
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setSpacing(6)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.label_2 = QtWidgets.QLabel(self.widget)
        self.label_2.setObjectName("label_2")
        self.verticalLayout_4.addWidget(self.label_2)
        self.sendPlainTextEdit = QtWidgets.QPlainTextEdit(self.widget)
        self.sendPlainTextEdit.setObjectName("sendPlainTextEdit")
        self.verticalLayout_4.addWidget(self.sendPlainTextEdit)
        self.verticalLayout.addLayout(self.verticalLayout_4)
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_7.setSpacing(6)
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.clearButton = QtWidgets.QPushButton(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.clearButton.sizePolicy().hasHeightForWidth())
        self.clearButton.setSizePolicy(sizePolicy)
        self.clearButton.setObjectName("clearButton")
        self.horizontalLayout_7.addWidget(self.clearButton)
        self.sendButton = QtWidgets.QPushButton(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.sendButton.sizePolicy().hasHeightForWidth())
        self.sendButton.setSizePolicy(sizePolicy)
        self.sendButton.setObjectName("sendButton")
        self.horizontalLayout_7.addWidget(self.sendButton)
        self.verticalLayout.addLayout(self.horizontalLayout_7)
        self.horizontalLayout.addWidget(self.widget)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setContentsMargins(4, 4, 4, 4)
        self.verticalLayout_2.setSpacing(4)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout_11 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_11.setSpacing(6)
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.inButton = QtWidgets.QPushButton(self.centralWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.inButton.sizePolicy().hasHeightForWidth())
        self.inButton.setSizePolicy(sizePolicy)
        self.inButton.setObjectName("inButton")
        self.horizontalLayout_11.addWidget(self.inButton)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_11.addItem(spacerItem)
        self.cfgButton = QtWidgets.QPushButton(self.centralWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.cfgButton.sizePolicy().hasHeightForWidth())
        self.cfgButton.setSizePolicy(sizePolicy)
        self.cfgButton.setObjectName("cfgButton")
        self.horizontalLayout_11.addWidget(self.cfgButton)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_11.addItem(spacerItem1)
        self.label_8 = QtWidgets.QLabel(self.centralWidget)
        self.label_8.setObjectName("label_8")
        self.horizontalLayout_11.addWidget(self.label_8)
        self.spinBox = QtWidgets.QSpinBox(self.centralWidget)
        self.spinBox.setMinimum(50)
        self.spinBox.setMaximum(999999)
        self.spinBox.setProperty("value", 666)
        self.spinBox.setObjectName("spinBox")
        self.horizontalLayout_11.addWidget(self.spinBox)
        self.checkBox = QtWidgets.QCheckBox(self.centralWidget)
        self.checkBox.setObjectName("checkBox")
        self.horizontalLayout_11.addWidget(self.checkBox)
        self.refreshButton = QtWidgets.QPushButton(self.centralWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.refreshButton.sizePolicy().hasHeightForWidth())
        self.refreshButton.setSizePolicy(sizePolicy)
        self.refreshButton.setObjectName("refreshButton")
        self.horizontalLayout_11.addWidget(self.refreshButton)
        self.verticalLayout_2.addLayout(self.horizontalLayout_11)
        self.tableWidget = QtWidgets.QTableWidget(self.centralWidget)
        self.tableWidget.setEditTriggers(QtWidgets.QAbstractItemView.DoubleClicked|QtWidgets.QAbstractItemView.EditKeyPressed)
        self.tableWidget.setColumnCount(0)
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setRowCount(0)
        self.verticalLayout_2.addWidget(self.tableWidget)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        MainWindow.setCentralWidget(self.centralWidget)
        self.statusBar = QtWidgets.QStatusBar(MainWindow)
        self.statusBar.setObjectName("statusBar")
        MainWindow.setStatusBar(self.statusBar)

        self.retranslateUi(MainWindow)
        self.baudrateBox.setCurrentIndex(7)
        self.ParityBox.setCurrentIndex(0)
        self.portNameBox.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "SCD"))
        self.fcnButton1.setText(_translate("MainWindow", "绘图窗口"))
        self.luaButton.setText(_translate("MainWindow", "LUA"))
        self.label_4.setText(_translate("MainWindow", "波特率："))
        self.baudrateBox.setCurrentText(_translate("MainWindow", "460800"))
        self.baudrateBox.setItemText(0, _translate("MainWindow", "4800"))
        self.baudrateBox.setItemText(1, _translate("MainWindow", "9600"))
        self.baudrateBox.setItemText(2, _translate("MainWindow", "19200"))
        self.baudrateBox.setItemText(3, _translate("MainWindow", "38400"))
        self.baudrateBox.setItemText(4, _translate("MainWindow", "76800"))
        self.baudrateBox.setItemText(5, _translate("MainWindow", "115200"))
        self.baudrateBox.setItemText(6, _translate("MainWindow", "230400"))
        self.baudrateBox.setItemText(7, _translate("MainWindow", "460800"))
        self.label_5.setText(_translate("MainWindow", "数据位："))
        self.dataBitsBox.setItemText(0, _translate("MainWindow", "8"))
        self.dataBitsBox.setItemText(1, _translate("MainWindow", "7"))
        self.dataBitsBox.setItemText(2, _translate("MainWindow", "6"))
        self.dataBitsBox.setItemText(3, _translate("MainWindow", "5"))
        self.dataBitsBox.setItemText(4, _translate("MainWindow", "绘图时必须为8位"))
        self.label_6.setText(_translate("MainWindow", "校验位："))
        self.ParityBox.setItemText(0, _translate("MainWindow", "0"))
        self.ParityBox.setItemText(1, _translate("MainWindow", "奇校验"))
        self.ParityBox.setItemText(2, _translate("MainWindow", "偶校验"))
        self.label_7.setText(_translate("MainWindow", "停止位："))
        self.stopBitsBox.setItemText(0, _translate("MainWindow", "1"))
        self.stopBitsBox.setItemText(1, _translate("MainWindow", "1.5"))
        self.stopBitsBox.setItemText(2, _translate("MainWindow", "2"))
        self.label_3.setText(_translate("MainWindow", "串口号："))
        self.portNameBox.setItemText(0, _translate("MainWindow", "请先检测串口"))
        self.searchButton.setText(_translate("MainWindow", "检测串口"))
        self.openButton.setText(_translate("MainWindow", "打开串口"))
        self.label.setText(_translate("MainWindow", "信息"))
        self.label_2.setText(_translate("MainWindow", "发送窗口"))
        self.clearButton.setText(_translate("MainWindow", "清空接收信息"))
        self.clearButton.setShortcut(_translate("MainWindow", "Ctrl+L"))
        self.sendButton.setText(_translate("MainWindow", "发送数据"))
        self.sendButton.setShortcut(_translate("MainWindow", "Ctrl+Return"))
        self.inButton.setText(_translate("MainWindow", "导入列表"))
        self.cfgButton.setText(_translate("MainWindow", "配置"))
        self.label_8.setText(_translate("MainWindow", "发送间隔(ms)"))
        self.checkBox.setText(_translate("MainWindow", "定时刷新"))
        self.refreshButton.setText(_translate("MainWindow", "刷新列表"))

