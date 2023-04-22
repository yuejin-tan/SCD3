#include "scopeform.h"
#include "ui_scopeform.h"
#include "QDebug"
#include "math.h"
#include "QColorDialog"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

#include "mainwindow.h"

scopeForm::scopeForm(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::scopeForm)
{
    ui->setupUi(this);

    isRecording = true;
    deltaPkg = 1;

    ui->tyj_widget->setOpenGl(true);
    if (ui->tyj_widget->openGl())
    {
        openGLsta = QStringLiteral("true");
    }
    else
    {
        openGLsta = QStringLiteral("false");
    }

    // 预分配内存
    pltVarDatas.reserve(8);
    pltVarNames.reserve(8);

    // 清空buffer
    connect(ui->tyj_widget, &tyjPlot::clearBuffSig, [=]() {
        for (auto obj : pltVarDatas) {
            obj->clear();
        }
        });

    // 暂停记录
    connect(ui->pushButton_startstop, &QPushButton::clicked, [=]() {
        isRecording = !isRecording;
        if (isRecording) {
            ui->pushButton_startstop->setText(QStringLiteral("暂停记录"));
        }
        else {
            ui->pushButton_startstop->setText(QStringLiteral("开始记录"));
        }
        });

    // 设置右键菜单项
    mainMenu = new QMenu(this);
    // 加入图像
    connect(ui->pushButton_add, &QPushButton::clicked, [=]() {
        mainMenu->clear();
        int namesCnt = pltVarNames.size();
        for (int ii = 0;ii < namesCnt;ii++)
        {
            auto actionx = mainMenu->addAction(QStringLiteral("加入 ") + pltVarNames[ii]);
            connect(actionx, &QAction::triggered, [=]() {
                ui->tyj_widget->addGraphItem(pltVarNames[ii], pltVarDatas[ii]);
                });
        }
        mainMenu->popup(QCursor::pos());
        });

    // 设置包间隔
    connect(ui->pushButton_pkgdelta, &QPushButton::clicked, [=]() {
        deltaPkg = ui->doubleSpinBox_pkgdelta->value();
        ui->label_pkgdelta->setText(QString::number(deltaPkg));
        });
}

scopeForm::~scopeForm()
{
    delete ui;
}


void scopeForm::closeEvent(QCloseEvent* event)
{
    event->accept();
}

void scopeForm::addNewData(QVector<float>* data)
{
    if (isRecording)
    {
        int revNum = data->size();
        int dataNum = pltVarDatas.size();
        double tNow = 0;
        for (int ii = 0;ii < dataNum;ii++)
        {
            double xVal;
            if (pltVarDatas[ii]->isEmpty())
            {
                xVal = 0;
            }
            else
            {
                xVal = (pltVarDatas[ii]->constEnd() - 1)->key + deltaPkg;
            }

            if (xVal > tNow)
            {
                tNow = xVal;
            }

            if (ii < revNum)
            {
                pltVarDatas[ii]->add(QCPGraphData(xVal, (*data)[ii]));
            }
            else
            {
                pltVarDatas[ii]->add(QCPGraphData(xVal, 0));
            }
        }

        showNormal();
        ui->tyj_widget->setRightTimeSlot(tNow);

        auto xRange = ui->tyj_widget->xAxis->range();
        int leftPart = xRange.lower > 0 ? xRange.lower : 0;
        int rightPart = xRange.upper > tNow ? xRange.upper - tNow : 0;
        int step = xRange.size();

        ui->horizontalScrollBar->setMaximum(leftPart + rightPart);
        ui->horizontalScrollBar->setPageStep(step);
        ui->horizontalScrollBar->setValue(leftPart);
    }
}

void scopeForm::setPlotVars(QVector<QString> names)
{
    QVector<QSharedPointer<QCPGraphDataContainer>> newPltData;
    for (auto newObjName : names)
    {
        bool ifAlreadyHave = false;
        int cnt = 0;
        for (auto oldObjName : pltVarNames)
        {
            if (newObjName == oldObjName)
            {
                ifAlreadyHave = true;
                break;
            }
            cnt++;
        }
        if (ifAlreadyHave)
        {
            newPltData.append(pltVarDatas[cnt]);
            // qDebug()<<"1";
        }
        else
        {
            newPltData.append(QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer()));
            // qDebug()<<"2";
        }
    }

    // 交换数据
    pltVarNames.swap(names);
    pltVarDatas.swap(newPltData);
}

void scopeForm::on_toClipBoardButton_clicked()
{
    QVector<const QCPGraphData*> startIterVect;
    QVector<const QCPGraphData*> endIterVect;
    if (ui->checkBox_onlyshowed->isChecked())
    {
        auto xRange = ui->tyj_widget->xAxis->range();
        for (auto objx : ui->tyj_widget->pltItemVect)
        {
            startIterVect.append(objx.dataPtrx->findBegin(xRange.lower));
            endIterVect.append(objx.dataPtrx->findEnd(xRange.upper));
        }
    }
    else
    {
        for (auto objx : ui->tyj_widget->pltItemVect)
        {
            startIterVect.append(objx.dataPtrx->constBegin());
            endIterVect.append(objx.dataPtrx->constEnd());
        }
    }

    bool ifAddNum = (ui->checkBox_noNum->isChecked() == false);

    QString clipBoardStr;

    QString sepChar = QStringLiteral("\t");
    if (ui->radioButton_comma->isChecked())
    {
        sepChar = QStringLiteral(",");
    }

    if (ui->checkBox_noTitle->isChecked() == false)
    {
        if (ifAddNum) {
            clipBoardStr.append("No.\\name");
            clipBoardStr.append(sepChar);
        }
        int nameCnt = ui->tyj_widget->pltItemVect.size();
        for (int jj = 0;jj < nameCnt - 1;jj++)
        {
            clipBoardStr += ui->tyj_widget->pltItemVect[jj].name;
            clipBoardStr.append(sepChar);
        }
        if (nameCnt > 0)
        {
            clipBoardStr += ui->tyj_widget->pltItemVect[nameCnt - 1].name;
        }
        clipBoardStr.append("\n");
    }

    int rowCnt = 0;

    while (1)
    {
        int loop1cnt = startIterVect.size();
        int ii = 0;
        while (1)
        {
            if (startIterVect[ii] != endIterVect[ii])
            {
                if (ifAddNum && ii == 0)
                {
                    clipBoardStr.append(QString::number(rowCnt)).append(sepChar);
                    rowCnt++;
                }
                clipBoardStr.append(QString::number(startIterVect[ii]->value));
                startIterVect[ii]++;
            }
            else
            {
                goto CBStrFin;
            }
            ii++;
            if (ii == loop1cnt)
            {
                break;
            }
            else
            {
                clipBoardStr.append(sepChar);
            }
        }
        clipBoardStr.append("\n");
    };

CBStrFin:

    QClipboard* sysCB = QApplication::clipboard();
    sysCB->setText(clipBoardStr);
}
