#include "graphset.h"
#include "ui_graphset.h"

#include <QtWidgets/QColorDialog>
#include <QtWidgets/QListView>

graphSet::graphSet(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::graphSet)
{
    ui->setupUi(this);

    mGraphSetStruct.mName = "";
    mGraphSetStruct.mColor = QColor(Qt::red);
    mGraphSetStruct.lineShape = 0;
    mGraphSetStruct.mXmax = 10;
    mGraphSetStruct.mXmin = 0;
    mGraphSetStruct.mYmax = 10;
    mGraphSetStruct.mYmax = 0;

    connect(ui->pushButton_ok, &QPushButton::clicked, [=]() {
        this->mGraphSetStruct.mName = this->ui->label_name->text();
        this->mGraphSetStruct.lineShape = this->ui->comboBox->currentIndex();
        this->mGraphSetStruct.mXmin = this->ui->doubleSpinBox_xmin->value();
        this->mGraphSetStruct.mXmax = this->ui->doubleSpinBox_xmax->value();
        this->mGraphSetStruct.mYmin = this->ui->doubleSpinBox_ymin->value();
        this->mGraphSetStruct.mYmax = this->ui->doubleSpinBox_ymax->value();
        this->hide();
        emit confirmSetting();
        });

    connect(ui->pushButton_cancel, &QPushButton::clicked, [=]() {
        this->hide();
        });

    connect(ui->pushButton_color, &QPushButton::clicked, [=]() {
        QColorDialog dlg(this);
        dlg.setWindowTitle("设置颜色");
        if (dlg.exec() == QColorDialog::Accepted)
        {
            this->mGraphSetStruct.mColor = dlg.selectedColor();
            this->ui->pushButton_color->setText("#" + QString::number(this->mGraphSetStruct.mColor.rgb(), 16));
            this->ui->pushButton_color->setStyleSheet("background-color: #" + QString::number(this->mGraphSetStruct.mColor.rgb(), 16) + ";");
        }
        });

    connect(ui->pushButton_rm, &QPushButton::clicked, [=]() {
        emit rmGraphSig(this->mGraphSetStruct.mName);
        this->hide();
        });

    // 修复qss
    ui->comboBox->setView(new QListView());
}

graphSet::~graphSet()
{
    delete ui;
}

void graphSet::showWindowWithSetting()
{
    this->ui->label_name->setText(this->mGraphSetStruct.mName);
    this->ui->pushButton_color->setText("#" + QString::number(this->mGraphSetStruct.mColor.rgb(), 16));
    this->ui->pushButton_color->setStyleSheet("background-color: #" + QString::number(this->mGraphSetStruct.mColor.rgb(), 16) + ";");
    this->ui->comboBox->setCurrentIndex(this->mGraphSetStruct.lineShape);
    this->ui->doubleSpinBox_xmin->setValue(this->mGraphSetStruct.mXmin);
    this->ui->doubleSpinBox_xmax->setValue(this->mGraphSetStruct.mXmax);
    this->ui->doubleSpinBox_ymin->setValue(this->mGraphSetStruct.mYmin);
    this->ui->doubleSpinBox_ymax->setValue(this->mGraphSetStruct.mYmax);
    this->show();
    this->raise();
}