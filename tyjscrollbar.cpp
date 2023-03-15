#include "tyjscrollbar.h"

tyjScrollBar::tyjScrollBar(QWidget *parent) : QScrollBar(parent)
{
}

// 重写事件处理函数使之不响应鼠标
void tyjScrollBar::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}
void tyjScrollBar::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}
void tyjScrollBar::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}