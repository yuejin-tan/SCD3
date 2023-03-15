#ifndef GRAPHSET_H
#define GRAPHSET_H

#include <QtWidgets/QWidget>

namespace Ui {
    class graphSet;
}

struct graphSetStruct
{
    QString mName;
    QColor mColor;
    double mXmin;
    double mXmax;
    double mYmin;
    double mYmax;
    int lineShape;
};

class graphSet : public QWidget
{
    Q_OBJECT

public:
    explicit graphSet(QWidget* parent = nullptr);
    ~graphSet();

private:
    Ui::graphSet* ui;

public:
    struct graphSetStruct mGraphSetStruct;

public:
    void showWindowWithSetting();

signals:
    void confirmSetting();
    void rmGraphSig(QString namex);
};

#endif // GRAPHSET_H
