#ifndef SCOPEFORM_H
#define SCOPEFORM_H

#include <QtWidgets/QWidget>

#include "qcp2_1/qcp.h"

#include "main.h"

class MainWindow;

namespace Ui
{
    class scopeForm;
}

class scopeForm : public QWidget
{
    Q_OBJECT

public:
    explicit scopeForm(QWidget* parent);
    ~scopeForm();

    QString openGLsta;

public:
    void addNewData(QVector<float>* data);

    void setPlotVars(QVector<QString> names);

protected:
    void closeEvent(QCloseEvent* event) override;

public:
    Ui::scopeForm* ui;
    // 是否记录
    bool isRecording;
    // 数据记录
    QVector<QSharedPointer<QCPGraphDataContainer>> pltVarDatas;
    // 名字记录
    QVector<QString> pltVarNames;
    // 包间隔
    double deltaPkg;
    // 加入图像的弹出菜单
    QMenu* mainMenu;
private slots:
    void on_toClipBoardButton_clicked();
};

#endif // SCOPEFORM_H
