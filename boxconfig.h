#ifndef BOXCONFIG_H
#define BOXCONFIG_H

#include <QWidget>
#include <twovariablepicker.h>
#include <RInside.h>
#include <chartconfig.h>
#include <qtColorpicker.h>
#include <QComboBox>
#include <twovariablepicker.h>
namespace Ui {
class BoxConfig;
}

class BoxConfig : public QWidget , public ChartConfig
{
    Q_OBJECT

public:
    explicit BoxConfig(TwoVariablePicker* picker,RInside& rconn,QString x,QString y,VariableView* vv,QWidget *parent = 0);
    ~BoxConfig();

private:
    Ui::BoxConfig *ui;
    void drawPlot();
    void setupUi();
    void setParorAesBoxplot();

    //parameter scatter
    QString weight;
    QString size;
    QString colour;
    QString fill;
    QString alpha;
    QString notch;
    QString outliercolor;
    QString outliersize;
    QString geomBox;
    QString geomJitter;
     QString flipcord;
    QtColorPicker* cp;
    QtColorPicker* cpout;
    QtColorPicker* cpfill;
    RInside& rconn;
    TwoVariablePicker* picker;
    QString x;
    QString y;
    VariableView* vv;
private slots:
    void setColor(QColor Colour);
    void setColorout(QColor Colour);
    void setFill(QColor Colour);
    void on_comboBox_color_activated(const QString &arg1);
    void on_comboBox_fill_activated(const QString &arg1);
    void on_comboBox_weight_activated(const QString &arg1);
    void on_horizontalSliderAlp_valueChanged(int value);
    void on_comboBox_size_activated(const QString &arg1);
    void on_lineEditSize_editingFinished();
    void on_checkBox_clicked();
    void on_checkBox_flip_clicked();
    void on_checkBox_notch_clicked();
    void on_lineEditSize_2_editingFinished();
    void on_pushButtonExport_clicked();
};

#endif // BOXCONFIG_H
