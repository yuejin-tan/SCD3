#ifndef TYJPLOT_H
#define TYJPLOT_H

#include "qcp2_1/qcp.h"

class QMenu;
class QAction;

class graphSet;

class tyjPoint
{
public:
    double x;
    double y;

    void setX(double para) { x = para; }
    void setY(double para) { y = para; }

    double getX() { return x; }
    double getY() { return y; }
};

struct pltStruct
{
    QString name;
    QSharedPointer<QCPGraphDataContainer> dataPtrx;
    QCPGraph* graphx;
};

class tyjPlot : public QCustomPlot
{
    Q_OBJECT

public:
    tyjPlot(QWidget* parent);
    ~tyjPlot();

    void mousePressSlotx(QMouseEvent* event);
    void mouseReleaseSlotx(QMouseEvent* event);
    void mouseMoveSlotx(QMouseEvent* event);

    void plottableDoubleClickSlot(QCPAbstractPlottable* plottable, int dataIndex, QMouseEvent* event);
    void axisDoubleClickSlot(QCPAxis* axis, QCPAxis::SelectablePart part, QMouseEvent* event);
    void legendDoubleClickSlot(QCPLegend* legend, QCPAbstractLegendItem* item, QMouseEvent* event);
    void selectionChangedSlot();

    void processRectZoomSlot_tyj(QRect rect, QMouseEvent* event);
    
    void closeEvent(QCloseEvent* event) override;

public:
    void fcnRclkMenu(QMouseEvent* event);
    void fcnGraphSetUtil(QString GraphName);

public:
    QCPItemStraightLine* yL1;
    QCPItemStraightLine* yL2;
    QCPItemStraightLine* xL1;
    QCPItemStraightLine* xL2;

    tyjPoint refPoint1;
    tyjPoint refPoint2;
    QCPItemText* textLabel_mid;

    enum xyLineStatus
    {
        nop,
        firstLinePressed,
        firstLineReleased,
        secondLinePressed,
        secondLineReleased,
    };
    enum xyLineStatus xyLineSta;

    QVector<struct pltStruct> pltItemVect;
    QVector<QPen> penVect;

    QMenu* mainMenu;
    QMenu* rmPltMenu;
    QMenu* paraSetMenu;
    QMenu* uiSetMenu;

    QAction* clearBuffAction;
    QAction* zoomXAxisWhenSelAction;
    QAction* lockXAction;
    QAction* lockYAction;
    QAction* autoScrollXAxisAction;

    // 设置框一幅图配一个算了，摆烂
    graphSet* mGraphSetWin;

public:
    bool ifZoomXAxisWhenSel;
    bool ifLockXAxis;
    bool ifLockYAxis;

    bool ifAutoScrollXAxis;

public:
    void addGraphItem(QString namex, QSharedPointer<QCPGraphDataContainer>& dataPtrx);
    void rmGraphItem(QString namex);

public slots:
    void setRightTimeSlot(double timex);

signals:
    void clearBuffSig();
};

#endif // TYJPLOT_H
