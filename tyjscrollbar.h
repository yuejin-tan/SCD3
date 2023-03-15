#ifndef TYJSCROLLBAR_H
#define TYJSCROLLBAR_H

#include <QScrollBar>
#include <QWidget>

class tyjScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    tyjScrollBar(QWidget *parent);

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // TYJSCROLLBAR_H
