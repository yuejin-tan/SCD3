#include "tyjplot.h"
#include "graphset.h"

#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtCore/QDebug>

// 堆屎加入统计功能
#include "main.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

tyjPlot::tyjPlot(QWidget* parent)
    : QCustomPlot(parent) {
    // 初始化状态量
    xyLineSta = nop;
    ifZoomXAxisWhenSel = false;
    ifLockXAxis = false;
    ifLockYAxis = false;

    ifAutoScrollXAxis = true;

    // 对矢量预分配内存
    pltItemVect.reserve(8);
    penVect.reserve(8);

    QColor frontColorx(QRgb(0xE0E1E3));
    QColor bgColorLight(QRgb(0x455364));
    QColor bgColorDark(QRgb(0x19232D));

    // 中键提示框
    textLabel_mid = new QCPItemText(this);
    textLabel_mid->setPositionAlignment(Qt::AlignTop | Qt::AlignRight);
    textLabel_mid->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel_mid->position->setCoords(0.985, 0.02);
    textLabel_mid->setText("init");
    QFont tmpFont;
    tmpFont.setPixelSize(20);
    textLabel_mid->setColor(frontColorx);
    textLabel_mid->setFont(tmpFont);
    textLabel_mid->setPen(QPen(bgColorLight, 4));
    textLabel_mid->setBrush(QBrush(bgColorLight));
    textLabel_mid->setLayer("overlay");
    textLabel_mid->setVisible(false);

    // 中键辅助线
    QPen midLinePen(frontColorx, 1);
    midLinePen.setStyle(Qt::DashLine);
    yL1 = new QCPItemStraightLine(this);
    yL1->setLayer("overlay");
    yL1->setPen(midLinePen);
    yL1->setVisible(false);

    yL2 = new QCPItemStraightLine(this);
    yL2->setLayer("overlay");
    yL2->setPen(midLinePen);
    yL2->setVisible(false);

    xL1 = new QCPItemStraightLine(this);
    xL1->setLayer("overlay");
    xL1->setPen(midLinePen);
    xL1->setVisible(false);

    xL2 = new QCPItemStraightLine(this);
    xL2->setLayer("overlay");
    xL2->setPen(midLinePen);
    xL2->setVisible(false);

    // 支持鼠标拖拽轴的范围、滚动缩放轴的范围，左键点选图层
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iMultiSelect | QCP::iSelectPlottables | QCP::iSelectAxes | QCP::iSelectLegend);
    // 默认只有水平方向
    axisRect()->setRangeDrag(Qt::Horizontal);
    axisRect()->setRangeZoom(Qt::Horizontal);

    // 设置图例
    legend->setVisible(true);
    QFont legendFont;
    legendFont.setPixelSize(20);
    legend->setFont(legendFont);
    legend->setSelectedFont(legendFont);
    legend->setBrush(QBrush(bgColorLight));
    legend->setSelectedBrush(QBrush(bgColorLight));
    legend->setTextColor(frontColorx);
    legend->setSelectedTextColor(frontColorx);
    legend->setSelectableParts(QCPLegend::spItems);
    legend->setBorderPen(Qt::NoPen);
    legend->setSelectedBorderPen(Qt::NoPen);
    legend->setIconBorderPen(Qt::NoPen);
    legend->setSelectedIconBorderPen(Qt::NoPen);
    // legend box shall not be selectable, only legend items
    legend->setSelectableParts(QCPLegend::spItems);
    axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignLeft);

    // 坐标轴样式
    QPen axisPen_x(frontColorx, 1);
    QPen axisPen_zero(frontColorx, 1, Qt::DotLine);
    QPen gridPen_x(QColor(140, 140, 140), 1, Qt::DotLine);
    QPen gridPen_xx(QColor(80, 80, 80), 1, Qt::DotLine);
    // 主轴样式
    xAxis->setBasePen(axisPen_x);
    yAxis->setBasePen(axisPen_x);
    xAxis->setTickPen(axisPen_x);
    yAxis->setTickPen(Qt::NoPen);
    xAxis->setSubTickPen(axisPen_x);
    yAxis->setSubTickPen(Qt::NoPen);
    xAxis->setTickLabelColor(frontColorx);
    yAxis->setTickLabelColor(frontColorx);
    xAxis->grid()->setPen(gridPen_x);
    yAxis->grid()->setPen(gridPen_x);
    xAxis->grid()->setSubGridPen(gridPen_xx);
    yAxis->grid()->setSubGridPen(gridPen_xx);
    xAxis->grid()->setVisible(true);
    yAxis->grid()->setVisible(true);
    xAxis->grid()->setSubGridVisible(true);
    yAxis->grid()->setSubGridVisible(true);
    xAxis->grid()->setZeroLinePen(Qt::NoPen);
    yAxis->grid()->setZeroLinePen(axisPen_zero);
    // y轴不显示label
    xAxis->setVisible(true);
    xAxis->setTickLabels(true);
    yAxis->setVisible(true);
    yAxis->setTickLabels(false);
    // 次轴
    xAxis2->setBasePen(axisPen_x);
    yAxis2->setBasePen(axisPen_x);
    xAxis2->setTickPen(axisPen_x);
    yAxis2->setTickPen(axisPen_x);
    xAxis2->setSubTickPen(axisPen_x);
    yAxis2->setSubTickPen(axisPen_x);
    xAxis2->setTickLabelColor(frontColorx);
    yAxis2->setTickLabelColor(frontColorx);
    xAxis2->grid()->setPen(Qt::NoPen);
    yAxis2->grid()->setPen(Qt::NoPen);
    xAxis2->grid()->setSubGridPen(Qt::NoPen);
    yAxis2->grid()->setSubGridPen(Qt::NoPen);
    xAxis2->grid()->setVisible(false);
    yAxis2->grid()->setVisible(false);
    xAxis2->grid()->setSubGridVisible(false);
    yAxis2->grid()->setSubGridVisible(false);
    xAxis2->grid()->setZeroLinePen(Qt::NoPen);
    yAxis2->grid()->setZeroLinePen(Qt::NoPen);
    // 边框右侧和上侧均显示刻度线，但不显示刻度值
    xAxis2->setVisible(true);
    xAxis2->setTickLabels(false);
    yAxis2->setVisible(true);
    yAxis2->setTickLabels(true);
    // 原始轴都不可被选择
    xAxis->setSelectableParts(QCPAxis::spNone);
    xAxis2->setSelectableParts(QCPAxis::spNone);
    yAxis->setSelectableParts(QCPAxis::spNone);
    yAxis2->setSelectableParts(QCPAxis::spNone);

    // 设置背景色、样式
    setBackground(QBrush(bgColorDark));
    axisRect()->setBackground(QBrush(bgColorDark));

    // 设置QCPSelectionRect的形式
    QPen selPen(frontColorx, 2, Qt::DashLine);
    QColor selRecColor(bgColorLight);
    selRecColor.setAlphaF(0.5);
    QBrush selBrush(selRecColor);
    mSelectionRect->setPen(selPen);
    mSelectionRect->setBrush(selBrush);

    // 设置默认绘图配色
    penVect << QPen(QColor(Qt::green)) << QPen(QColor(Qt::red)) << QPen(QColor(Qt::blue)) << QPen(QColor(Qt::yellow)) << QPen(QColor(Qt::cyan)) << QPen(QColor(Qt::magenta)) << QPen(QColor(Qt::white));

    // 使图上下两个X轴的范围总是相等，使左右两个Y轴的范围总是相等
    connect(xAxis, qOverload<const QCPRange&>(&QCPAxis::rangeChanged), xAxis2, qOverload<const QCPRange&>(&QCPAxis::setRange));
    connect(yAxis, qOverload<const QCPRange&>(&QCPAxis::rangeChanged), yAxis2, qOverload<const QCPRange&>(&QCPAxis::setRange));

    // 连接鼠标点击信号
    connect(this, &tyjPlot::mousePress, this, &tyjPlot::mousePressSlotx);
    connect(this, &tyjPlot::mouseMove, this, &tyjPlot::mouseMoveSlotx);
    connect(this, &tyjPlot::mouseRelease, this, &tyjPlot::mouseReleaseSlotx);

    // hack掉原来的QCPSelectionRect调用逻辑
    connect(mSelectionRect, &QCPSelectionRect::accepted, this, &tyjPlot::processRectZoomSlot_tyj);

    // 处理用户交互信号
    connect(this, &tyjPlot::plottableDoubleClick, this, &tyjPlot::plottableDoubleClickSlot);
    connect(this, &tyjPlot::axisDoubleClick, this, &tyjPlot::axisDoubleClickSlot);
    connect(this, &tyjPlot::legendDoubleClick, this, &tyjPlot::legendDoubleClickSlot);

    // 处理选择信号
    connect(this, &tyjPlot::selectionChangedByUser, this, &tyjPlot::selectionChangedSlot);

    // 设置右键菜单项
    mainMenu = new QMenu(this);
    rmPltMenu = mainMenu->addMenu("移除图像");
    paraSetMenu = mainMenu->addMenu("绘图设定");
    uiSetMenu = mainMenu->addMenu("交互设定");

    clearBuffAction = mainMenu->addAction("清空数据");

    zoomXAxisWhenSelAction = uiSetMenu->addAction(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton), "选定时也更改X轴");
    lockXAction = uiSetMenu->addAction(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton), "锁定X轴");
    lockYAction = uiSetMenu->addAction(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton), "锁定Y轴");
    autoScrollXAxisAction = uiSetMenu->addAction(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton), "X轴自动跟随");

    connect(zoomXAxisWhenSelAction, &QAction::triggered, [=]() {
        if (this->ifZoomXAxisWhenSel)
        {
            this->ifZoomXAxisWhenSel = false;
            zoomXAxisWhenSelAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton));
        }
        else {
            this->ifZoomXAxisWhenSel = true;
            zoomXAxisWhenSelAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));
        }
        // 直接暴力更新
        selectionChangedSlot();
        });

    connect(lockXAction, &QAction::triggered, [=]() {
        if (this->ifLockXAxis)
        {
            this->ifLockXAxis = false;
            lockXAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton));
        }
        else {
            this->ifLockXAxis = true;
            lockXAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));
        }
        // 直接暴力更新
        selectionChangedSlot();
        });

    connect(lockYAction, &QAction::triggered, [=]() {
        if (this->ifLockYAxis)
        {
            this->ifLockYAxis = false;
            lockYAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton));
        }
        else {
            this->ifLockYAxis = true;
            lockYAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));
        }
        // 直接暴力更新
        selectionChangedSlot();
        });

    connect(clearBuffAction, &QAction::triggered, [=]() {
        emit clearBuffSig();
        // x轴归零
        xAxis->moveRange(-xAxis->range().lower);
        replot(rpQueuedReplot);
        });

    connect(autoScrollXAxisAction, &QAction::triggered, [=]() {
        if (this->ifAutoScrollXAxis)
        {
            this->ifAutoScrollXAxis = false;
            autoScrollXAxisAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton));
        }
        else {
            this->ifAutoScrollXAxis = true;
            autoScrollXAxisAction->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));
        }
        });

    // new个设置框
    mGraphSetWin = new graphSet();

    connect(mGraphSetWin, &graphSet::rmGraphSig, this, &tyjPlot::rmGraphItem);
    connect(mGraphSetWin, &graphSet::confirmSetting, [=]() {
        for (auto tmpObjx : pltItemVect)
        {
            if (mGraphSetWin->mGraphSetStruct.mName == tmpObjx.name)
            {
                // 匹配上了
                QCPGraph* graphx = tmpObjx.graphx;
                QCPPlottableLegendItem* legend_itemx = legend->itemWithPlottable(graphx);
                QCPAxis* axisYx = graphx->valueAxis();
                // color
                QPen graphPen = graphx->pen();
                graphPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                graphx->setPen(graphPen);
                QPen graphPenSel = graphx->selectionDecorator()->pen();
                graphPenSel.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                graphx->selectionDecorator()->setPen(graphPenSel);
                legend_itemx->setSelectedTextColor(mGraphSetWin->mGraphSetStruct.mColor);
                axisYx->setLabelColor(mGraphSetWin->mGraphSetStruct.mColor);
                axisYx->setTickLabelColor(mGraphSetWin->mGraphSetStruct.mColor);
                {
                    QPen axisPen = axisYx->basePen();
                    axisPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                    axisYx->setBasePen(axisPen);
                }
                {
                    QPen axisPen = axisYx->tickPen();
                    axisPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                    axisYx->setTickPen(axisPen);
                }
                {
                    QPen axisPen = axisYx->subTickPen();
                    axisPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                    axisYx->setSubTickPen(axisPen);
                }
                axisYx->setSelectedLabelColor(mGraphSetWin->mGraphSetStruct.mColor);
                axisYx->setSelectedTickLabelColor(mGraphSetWin->mGraphSetStruct.mColor);
                {
                    QPen axisPen = axisYx->selectedBasePen();
                    axisPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                    axisYx->setSelectedBasePen(axisPen);
                }
                {
                    QPen axisPen = axisYx->selectedTickPen();
                    axisPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                    axisYx->setSelectedTickPen(axisPen);
                }
                {
                    QPen axisPen = axisYx->selectedSubTickPen();
                    axisPen.setColor(mGraphSetWin->mGraphSetStruct.mColor);
                    axisYx->setSelectedSubTickPen(axisPen);
                }

                // lineshape
                switch (mGraphSetWin->mGraphSetStruct.lineShape)
                {
                case 1:
                    graphx->setLineStyle(QCPGraph::lsStepLeft);
                    graphx->setScatterStyle(QCPScatterStyle());
                    break;
                case 2:
                    graphx->setLineStyle(QCPGraph::lsImpulse);
                    graphx->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
                    break;
                default:
                    graphx->setLineStyle(QCPGraph::lsLine);
                    graphx->setScatterStyle(QCPScatterStyle());
                    break;
                }
                // x范围
                if (!ifLockXAxis)
                {
                    this->xAxis->setRange(QCPRange(qMin(mGraphSetWin->mGraphSetStruct.mXmin, mGraphSetWin->mGraphSetStruct.mXmax), qMax(mGraphSetWin->mGraphSetStruct.mXmin, mGraphSetWin->mGraphSetStruct.mXmax)));
                }
                // y范围
                if (!ifLockYAxis)
                {
                    axisYx->setRange(QCPRange(qMin(mGraphSetWin->mGraphSetStruct.mYmin, mGraphSetWin->mGraphSetStruct.mYmax), qMax(mGraphSetWin->mGraphSetStruct.mYmin, mGraphSetWin->mGraphSetStruct.mYmax)));
                }

                // 更新界面
                this->replot(rpQueuedReplot);
                break;
            }
        }
        });
}

void tyjPlot::mousePressSlotx(QMouseEvent* event) {
    bool ifReplot = false;

    if (event->button() == Qt::MiddleButton) {
        switch (xyLineSta) {
        case nop: {
            // 当前鼠标位置（像素坐标）
            // 像素坐标转成实际的x,y轴的坐标
            int x_pos = event->pos().x();
            float x_val = xAxis->pixelToCoord(x_pos);
            refPoint1.setX(x_val);
            yL1->point1->setCoords(x_val, yAxis->range().upper);
            yL1->point2->setCoords(x_val, yAxis->range().lower);
            yL1->setVisible(true);

            int y_pos = event->pos().y();
            float y_val = yAxis->pixelToCoord(y_pos);
            refPoint1.setY(y_val);
            xL1->point1->setCoords(xAxis->range().upper, y_val);
            xL1->point2->setCoords(xAxis->range().lower, y_val);
            xL1->setVisible(true);

            textLabel_mid->setText(QStringLiteral("x1：%0\t\ty1：%1")
                .arg(x_val, 0, 'g', 5)
                .arg(y_val, 0, 'g', 5));
            textLabel_mid->setVisible(true);

            xyLineSta = firstLinePressed;

            ifReplot = true;
        } break;

        case firstLineReleased: {
            // 当前鼠标位置（像素坐标）
            // 像素坐标转成实际的x,y轴的坐标
            int x_pos = event->pos().x();
            float x_val = xAxis->pixelToCoord(x_pos);
            refPoint2.setX(x_val);
            yL2->point1->setCoords(x_val, yAxis->range().upper);
            yL2->point2->setCoords(x_val, yAxis->range().lower);
            yL2->setVisible(true);

            int y_pos = event->pos().y();
            float y_val = yAxis->pixelToCoord(y_pos);
            refPoint2.setY(y_val);
            xL2->point1->setCoords(xAxis->range().upper, y_val);
            xL2->point2->setCoords(xAxis->range().lower, y_val);
            xL2->setVisible(true);

            textLabel_mid->setText(QStringLiteral("x1：%0\t\ty1：%1\nx2：%2\t\ty2：%3\ndx：%4\t\tdy：%5\n1000/dx：%6")
                .arg(refPoint1.getX(), 0, 'g', 5)
                .arg(refPoint1.getY(), 0, 'g', 5)
                .arg(x_val, 0, 'g', 5)
                .arg(y_val, 0, 'g', 5)
                .arg(abs(x_val - refPoint1.getX()), 0, 'g', 5)
                .arg(abs(y_val - refPoint1.getY()), 0, 'g', 5)
                .arg(1000.0 / abs(x_val - refPoint1.getX()), 0, 'g', 5));

            xyLineSta = secondLinePressed;

            ifReplot = true;
        } break;

        case secondLineReleased: {
            xL1->setVisible(false);
            xL2->setVisible(false);
            yL1->setVisible(false);
            yL2->setVisible(false);
            textLabel_mid->setVisible(false);
            xyLineSta = nop;

            ifReplot = true;
        } break;

        default:
            break;
        }
    }

    // hack掉原来的QCPSelectionRect调用逻辑
    if (event->button() == Qt::RightButton) {
        if (mSelectionRect)  // a simple click shouldn't successfully finish a selection rect, so cancel it here
            mSelectionRect->startSelection(event);
        ifReplot = true;
    }

    if (ifReplot)
        layer(QStringLiteral("overlay"))->replot();
}

void tyjPlot::mouseReleaseSlotx(QMouseEvent* event) {
    bool ifReplot = false;

    if (event->button() == Qt::MiddleButton) {
        switch (xyLineSta) {
        case firstLinePressed: {
            // 当前鼠标位置（像素坐标）
            // 像素坐标转成实际的x,y轴的坐标
            int x_pos = event->pos().x();
            float x_val = xAxis->pixelToCoord(x_pos);
            refPoint1.setX(x_val);
            yL1->point1->setCoords(x_val, yAxis->range().upper);
            yL1->point2->setCoords(x_val, yAxis->range().lower);
            yL1->setVisible(true);

            int y_pos = event->pos().y();
            float y_val = yAxis->pixelToCoord(y_pos);
            refPoint1.setY(y_val);
            xL1->point1->setCoords(xAxis->range().upper, y_val);
            xL1->point2->setCoords(xAxis->range().lower, y_val);
            xL1->setVisible(true);

            textLabel_mid->setText(QStringLiteral("x1：%0\t\ty1：%1")
                .arg(x_val, 0, 'g', 5)
                .arg(y_val, 0, 'g', 5));

            xyLineSta = firstLineReleased;

            ifReplot = true;
        } break;

        case secondLinePressed: {
            // 当前鼠标位置（像素坐标）
            // 像素坐标转成实际的x,y轴的坐标
            int x_pos = event->pos().x();
            float x_val = xAxis->pixelToCoord(x_pos);
            refPoint2.setX(x_val);
            yL2->point1->setCoords(x_val, yAxis->range().upper);
            yL2->point2->setCoords(x_val, yAxis->range().lower);
            yL2->setVisible(true);

            int y_pos = event->pos().y();
            float y_val = yAxis->pixelToCoord(y_pos);
            refPoint2.setY(y_val);
            xL2->point1->setCoords(xAxis->range().upper, y_val);
            xL2->point2->setCoords(xAxis->range().lower, y_val);
            xL2->setVisible(true);

            ;
            textLabel_mid->setText(QStringLiteral("x1：%0\t\ty1：%1\nx2：%2\t\ty2：%3\ndx：%4\t\tdy：%5\n1000/dx：%6")
                .arg(refPoint1.getX(), 0, 'g', 5)
                .arg(refPoint1.getY(), 0, 'g', 5)
                .arg(x_val, 0, 'g', 5)
                .arg(y_val, 0, 'g', 5)
                .arg(abs(x_val - refPoint1.getX()), 0, 'g', 5)
                .arg(abs(y_val - refPoint1.getY()), 0, 'g', 5)
                .arg(1000.0 / abs(x_val - refPoint1.getX()), 0, 'g', 5));

            xyLineSta = secondLineReleased;

            ifReplot = true;
        } break;
        default:
            break;
        }
    }

    // hack掉原来的QCPSelectionRect调用逻辑
    if (event->button() == Qt::RightButton) {
        if (mSelectionRect && mSelectionRect->isActive()) {
            // Note: if a click was detected above, the selection rect is canceled there
            if (mMouseHasMoved) {
                // finish selection rect, the appropriate action will be taken via signal-slot connection
                mSelectionRect->endSelection(event);
            }
            else {
                // a simple click shouldn't successfully finish a selection rect, so cancel it here
                mSelectionRect->cancel();
                // 松开右键时发现鼠标没动，故认为是单击右键，处理右键菜单
                fcnRclkMenu(event);
            }
        }
        ifReplot = true;
    }

    if (ifReplot)
        layer(QStringLiteral("overlay"))->replot();
}

void tyjPlot::mouseMoveSlotx(QMouseEvent* event) {
    bool ifReplot = false;

    switch (xyLineSta) {
    case firstLinePressed: {
        // 当前鼠标位置（像素坐标）
        // 像素坐标转成实际的x,y轴的坐标
        int x_pos = event->pos().x();
        float x_val = xAxis->pixelToCoord(x_pos);
        refPoint1.setX(x_val);
        yL1->point1->setCoords(x_val, yAxis->range().upper);
        yL1->point2->setCoords(x_val, yAxis->range().lower);

        int y_pos = event->pos().y();
        float y_val = yAxis->pixelToCoord(y_pos);
        refPoint1.setY(y_val);
        xL1->point1->setCoords(xAxis->range().upper, y_val);
        xL1->point2->setCoords(xAxis->range().lower, y_val);

        textLabel_mid->setText(QStringLiteral("x1：%0\t\ty1：%1")
            .arg(x_val, 0, 'g', 5)
            .arg(y_val, 0, 'g', 5));

        ifReplot = true;
    } break;

    case secondLinePressed: {
        // 当前鼠标位置（像素坐标）
        // 像素坐标转成实际的x,y轴的坐标
        int x_pos = event->pos().x();
        float x_val = xAxis->pixelToCoord(x_pos);
        refPoint2.setX(x_val);
        yL2->point1->setCoords(x_val, yAxis->range().upper);
        yL2->point2->setCoords(x_val, yAxis->range().lower);

        int y_pos = event->pos().y();
        float y_val = yAxis->pixelToCoord(y_pos);
        refPoint2.setY(y_val);
        xL2->point1->setCoords(xAxis->range().upper, y_val);
        xL2->point2->setCoords(xAxis->range().lower, y_val);

        textLabel_mid->setText(QStringLiteral("x1：%0\t\ty1：%1\nx2：%2\t\ty2：%3\ndx：%4\t\tdy：%5\n1000/dx：%6")
            .arg(refPoint1.getX(), 0, 'g', 5)
            .arg(refPoint1.getY(), 0, 'g', 5)
            .arg(x_val, 0, 'g', 5)
            .arg(y_val, 0, 'g', 5)
            .arg(abs(x_val - refPoint1.getX()), 0, 'g', 5)
            .arg(abs(y_val - refPoint1.getY()), 0, 'g', 5)
            .arg(1000.0 / abs(x_val - refPoint1.getX()), 0, 'g', 5));

        ifReplot = true;
    } break;
    default:
        break;
    }

    if (ifReplot)
        layer(QStringLiteral("overlay"))->replot();
}

void tyjPlot::addGraphItem(QString namex, QSharedPointer<QCPGraphDataContainer>& dataPtrx) {
    if (namex == "") {
        // 加入的元素不能为空
        qDebug() << __FILE__ << __LINE__ << "add null graphItem, ignored!";
        return;
    }
    else {
        // 先判断是否重复，依据为名称字符串
        for (auto& tmpPltPtr : pltItemVect) {
            if (tmpPltPtr.name == namex) {
                // 已经有了，不用加
                qDebug() << __FILE__ << __LINE__ << "add same plt graphItem, ignored!";
                return;
            }
        }
        // 可以加
        auto yAxisTmp = axisRect()->addAxis(QCPAxis::atLeft);
        // 使得轴联动
        connect(yAxisTmp, qOverload<const QCPRange&>(&QCPAxis::rangeChanged), yAxis, qOverload<const QCPRange&>(&QCPAxis::setRange));
        // 设置轴参数
        auto& graphPen_x = penVect[pltItemVect.size() % penVect.size()];
        QPen axisPen_x = graphPen_x;
        QPen axisPen_sel = axisPen_x;
        axisPen_sel.setWidth(3);
        yAxisTmp->setBasePen(axisPen_x);
        yAxisTmp->setTickPen(axisPen_x);
        yAxisTmp->setSubTickPen(axisPen_x);
        yAxisTmp->setLabelColor(axisPen_x.color());
        yAxisTmp->setTickLabelColor(axisPen_x.color());
        yAxisTmp->setLabelFont(yAxis2->labelFont());
        yAxisTmp->setTickLabelFont(yAxis2->tickLabelFont());
        yAxisTmp->setLayer(QStringLiteral("axes"));
        yAxisTmp->grid()->setLayer(QStringLiteral("grid"));
        yAxisTmp->setSelectedBasePen(axisPen_sel);
        yAxisTmp->setSelectedTickPen(axisPen_sel);
        yAxisTmp->setSelectedSubTickPen(axisPen_sel);
        yAxisTmp->setSelectedLabelFont(yAxisTmp->labelFont());
        yAxisTmp->setSelectedLabelColor(axisPen_sel.color());
        yAxisTmp->setSelectedTickLabelFont(yAxisTmp->tickLabelFont());
        yAxisTmp->setSelectedTickLabelColor(axisPen_sel.color());
        // 加入图像并设置其参数
        auto graphTmp = addGraph(xAxis, yAxisTmp);
        graphTmp->setData(dataPtrx);
        graphTmp->setPen(graphPen_x);
        graphTmp->setName(namex);
        QPen graphPenSel = graphPen_x;
        graphPenSel.setWidth(3);
        graphTmp->selectionDecorator()->setPen(graphPenSel);
        graphTmp->selectionDecorator()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc), QCPScatterStyle::spAll);
        // 设置图例
        QCPPlottableLegendItem* legend_itemx = legend->itemWithPlottable(graphTmp);
        legend_itemx->setSelectedTextColor(graphPen_x.color());
        // 加入数组
        pltItemVect.append(pltStruct{ namex, QSharedPointer<QCPGraphDataContainer>(dataPtrx), graphTmp });
        // 根据当前数据调节y轴的值
        bool ok;
        auto rangeY = dataPtrx->valueRange(ok, QCP::sdBoth, xAxis->range());
        if (!ok)
        {
            rangeY = QCPRange(0, 10);
        }
        rangeY.normalize();
        if (rangeY.size() < 0.5)
        {
            rangeY.lower -= 0.5;
            rangeY.upper += 0.5;
        }
        yAxisTmp->setRange(rangeY);

    }
}

void tyjPlot::rmGraphItem(QString namex) {
    if (namex == "") {
        // 删除的元素不能为空
        qDebug() << __FILE__ << __LINE__ << "remove null graphItem, ignored!";
        return;
    }
    else {
        // 依据为名称字符串遍历寻找目标值
        int idx = 0;
        for (auto& tmpPltPtr : pltItemVect) {
            if (tmpPltPtr.name == namex) {
                // 找到了
                auto yAxisTmp = tmpPltPtr.graphx->valueAxis();
                removeGraph(tmpPltPtr.graphx);
                axisRect()->removeAxis(yAxisTmp);
                pltItemVect.remove(idx);
                // 更新其他状态
                selectionChangedSlot();
                // 重绘界面
                replot(rpQueuedReplot);
                return;
            }
            ++idx;
        }
        // 没找到
        qDebug() << __FILE__ << __LINE__ << "rm graphItem not found, ignored!";
        return;
    }
}

void tyjPlot::plottableDoubleClickSlot(QCPAbstractPlottable* plottable, int dataIndex, QMouseEvent* event) {
    Q_UNUSED(dataIndex);
    Q_UNUSED(event);
    for (auto tmpObjx : pltItemVect)
    {
        QCPGraph* graphx = tmpObjx.graphx;
        if ((void*)graphx == (void*)plottable)
        {
            // 匹配上了
            // 双击图不是弹出设置框，而是将统计信息摆烂显示在发送窗口中
            // fcnGraphSetUtil(tmpObjx.name);

            const QCPGraphData* startIter;
            const QCPGraphData* endIter;
            auto xRange = xAxis->range();
            startIter = tmpObjx.dataPtrx->findBegin(xRange.lower);
            endIter = tmpObjx.dataPtrx->findEnd(xRange.upper);

            double maxx = startIter->value;
            double minx = maxx;
            double sumx = maxx;
            double sumx2 = maxx * maxx;
            int cnt = 1;

            startIter++;
            while (startIter != endIter)
            {
                double val = startIter->value;
                maxx = fmax(maxx, val);
                minx = fmin(minx, val);
                sumx += val;
                sumx2 += val * val;
                cnt++;
                startIter++;
            }
            double avgx = sumx / cnt;
            int cnt2 = cnt > 1 ? cnt : 2;
            double sx = sqrt((sumx2 - avgx * avgx * cnt) / (cnt2 - 1));

            QString dataStr = (QStringLiteral("\n\navg：%0\nsx：%1\nmin：%2\nmax：%3\ncnt：%4")
                .arg(avgx, 0, 'g', 5)
                .arg(sx, 0, 'g', 5)
                .arg(minx, 0, 'g', 5)
                .arg(maxx, 0, 'g', 5)
                .arg(cnt));

            mainWinPtr->ui->sendPlainTextEdit->setPlainText(tmpObjx.name + dataStr);

            break;
        }
    }
}

void tyjPlot::axisDoubleClickSlot(QCPAxis* axis, QCPAxis::SelectablePart part, QMouseEvent* event) {
    Q_UNUSED(part);
    Q_UNUSED(event);
    for (auto tmpObjx : pltItemVect)
    {
        QCPGraph* graphx = tmpObjx.graphx;
        QCPAxis* axisYx = graphx->valueAxis();
        if ((void*)axisYx == (void*)axis)
        {
            // 匹配上了
            fcnGraphSetUtil(tmpObjx.name);
            break;
        }
    }
}

void tyjPlot::legendDoubleClickSlot(QCPLegend* legend, QCPAbstractLegendItem* item, QMouseEvent* event) {
    Q_UNUSED(legend);
    Q_UNUSED(event);
    for (auto tmpObjx : pltItemVect)
    {
        QCPGraph* graphx = tmpObjx.graphx;
        QCPPlottableLegendItem* legend_itemx = legend->itemWithPlottable(graphx);
        if ((void*)legend_itemx == (void*)item)
        {
            // 匹配上了
            fcnGraphSetUtil(tmpObjx.name);
            break;
        }
    }
}

void tyjPlot::selectionChangedSlot() {
    // 遍历寻找被选对象并进行同步及逻辑处理
    // 活跃轴记录
    QList<QCPAxis*> activeYAxis;
    // 提前分配内存
    activeYAxis.reserve(4);
    for (auto& objx : pltItemVect) {
        QCPGraph* graphx = objx.graphx;
        QCPPlottableLegendItem* legend_itemx = legend->itemWithPlottable(graphx);
        QCPAxis* axisYx = graphx->valueAxis();
        if (graphx->selected() || legend_itemx->selected() || axisYx->selectedParts()) {
            graphx->setSelection(QCPDataSelection(graphx->data()->dataRange()));
            legend_itemx->setSelected(true);
            axisYx->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
            // 记录活跃轴
            activeYAxis.append(axisYx);
        }
    }

    if (activeYAxis.size() > 0) {
        // 将yAxis同步到选定曲线的axis上
        for (auto axis_active : activeYAxis) {
            yAxis->setRange(axis_active->range());
        }
        // 设置交互
        axisRect()->setRangeDragAxes(axisRect()->rangeZoomAxes(Qt::Horizontal), activeYAxis);
        axisRect()->setRangeZoomAxes(axisRect()->rangeZoomAxes(Qt::Horizontal), activeYAxis);

        if (ifLockXAxis) {
            if (ifLockYAxis) {
                axisRect()->setRangeDrag(0);
                axisRect()->setRangeZoom(0);
            }
            else {
                axisRect()->setRangeDrag(Qt::Vertical);
                axisRect()->setRangeZoom(Qt::Vertical);
            }
        }
        else {
            if (ifLockYAxis) {
                axisRect()->setRangeDrag(Qt::Horizontal);
                if (ifZoomXAxisWhenSel)
                    axisRect()->setRangeZoom(Qt::Horizontal);
                else
                    axisRect()->setRangeZoom(0);
            }
            else {
                axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
                if (ifZoomXAxisWhenSel)
                    axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
                else
                    axisRect()->setRangeZoom(Qt::Vertical);
            }
        }
    }
    else {
        if (ifLockXAxis) {
            axisRect()->setRangeDrag(0);
            axisRect()->setRangeZoom(0);
        }
        else {
            axisRect()->setRangeDrag(Qt::Horizontal);
            axisRect()->setRangeZoom(Qt::Horizontal);
        }
    }
}

// 加入对缩放使能判断的改进版
void tyjPlot::processRectZoomSlot_tyj(QRect rect, QMouseEvent* event) {
    Q_UNUSED(event)
        if (QCPAxisRect* axisRectx = axisRectAt(rect.topLeft())) {
            auto mRangeZoom = axisRectx->rangeZoom();
            if (mRangeZoom != 0) {
                QRectF rectFx(rect);
                if (mRangeZoom.testFlag(Qt::Horizontal)) {
                    for (QCPAxis* axis : axisRectx->rangeZoomAxes(Qt::Horizontal)) {
                        if (!axis) {
                            qDebug() << Q_FUNC_INFO << "a passed axis was zero";
                            continue;
                        }
                        QCPRange pixelRange;
                        pixelRange = QCPRange(rectFx.left(), rectFx.right());
                        axis->setRange(axis->pixelToCoord(pixelRange.lower), axis->pixelToCoord(pixelRange.upper));
                    }
                }
                if (mRangeZoom.testFlag(Qt::Vertical)) {
                    for (QCPAxis* axis : axisRectx->rangeZoomAxes(Qt::Vertical)) {
                        if (!axis) {
                            qDebug() << Q_FUNC_INFO << "a passed axis was zero";
                            continue;
                        }
                        QCPRange pixelRange;
                        pixelRange = QCPRange(rectFx.top(), rectFx.bottom());
                        axis->setRange(axis->pixelToCoord(pixelRange.lower), axis->pixelToCoord(pixelRange.upper));
                    }
                }
            }
        }
    // always replot to make selection rect disappear
    replot(rpQueuedReplot);
}

void tyjPlot::fcnRclkMenu(QMouseEvent* event) {
    // 创建移除图像的目录
    rmPltMenu->clear();
    for (auto& pltObjx : pltItemVect) {
        auto tmpRmAction = rmPltMenu->addAction(QStringLiteral("移除 ") + pltObjx.name);
        connect(tmpRmAction, &QAction::triggered, [=]() { rmGraphItem(pltObjx.name); });
    }
    // 参数设定的目录
    paraSetMenu->clear();
    for (auto& pltObjx : pltItemVect) {
        auto tmpSetAction = paraSetMenu->addAction(QStringLiteral("设置 ") + pltObjx.name);
        connect(tmpSetAction, &QAction::triggered, [=]() { fcnGraphSetUtil(pltObjx.name); });
    }
    mainMenu->popup(event->globalPos());
}

void tyjPlot::fcnGraphSetUtil(QString GraphName) {
    for (auto tmpObjx : pltItemVect)
    {
        if (GraphName == tmpObjx.name)
        {
            // 匹配上了
            QCPGraph* graphx = tmpObjx.graphx;
            QCPAxis* axisYx = graphx->valueAxis();
            // name
            mGraphSetWin->mGraphSetStruct.mName = tmpObjx.name;
            // color
            mGraphSetWin->mGraphSetStruct.mColor = graphx->pen().color();
            // lineshape
            switch (graphx->lineStyle())
            {
            case QCPGraph::lsStepLeft:
                mGraphSetWin->mGraphSetStruct.lineShape = 1;
                break;
            case QCPGraph::lsImpulse:
                mGraphSetWin->mGraphSetStruct.lineShape = 2;
                break;
            default:
                mGraphSetWin->mGraphSetStruct.lineShape = 0;
                break;
            }
            // x范围
            mGraphSetWin->mGraphSetStruct.mXmin = xAxis->range().lower;
            mGraphSetWin->mGraphSetStruct.mXmax = xAxis->range().upper;
            // y范围
            mGraphSetWin->mGraphSetStruct.mYmin = axisYx->range().lower;
            mGraphSetWin->mGraphSetStruct.mYmax = axisYx->range().upper;

            mGraphSetWin->showWindowWithSetting();
            break;
        }
    }
}

void tyjPlot::setRightTimeSlot(double timex)
{
    if (ifAutoScrollXAxis)
    {
        auto rangeNow = xAxis->range();
        if (timex > rangeNow.upper)
        {
            // 满足条件就自动平移
            xAxis->moveRange(timex - rangeNow.upper);
        }
    }

    replot(rpQueuedReplot);
}

tyjPlot::~tyjPlot()
{
    delete mGraphSetWin;
}

void tyjPlot::closeEvent(QCloseEvent* event)
{
    emit clearBuffSig();
    event->accept();
}
