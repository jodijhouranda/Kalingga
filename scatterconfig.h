#ifndef SCATTERCONFIG_H
#define SCATTERCONFIG_H

#include <QWidget>
#include <twovariablepicker.h>
#include <RInside.h>
#include <chartconfig.h>
#include <qtColorpicker.h>
#include <QComboBox>
namespace Ui {

class ScatterConfig;
}

class ScatterConfig : public QWidget,public ChartConfig
{
    Q_OBJECT

public:
    explicit ScatterConfig(TwoVariablePicker* picker,RInside& rconn,QString x,QString y,VariableView* vv,QWidget *parent = 0);
    ~ScatterConfig();

private:
    void drawPlot();
    void setupUi();
    void setParorAesScatter();
    void setParorAesSmooth();

    //parameter scatter
    QString shape;
    QString size;
    QString colour;
    QString fill;
    QString alpha;
    QString position;
    //parameter smooth
    QString methods;
    QString ses;
    QString colours;
    QString fills;
    QString sizes;
    QString linetypes;
    QString weights;
    QString alphas;

    QString geomPoint;
    QString geomSmooth;
    QtColorPicker* cp;
    QtColorPicker* cpfill;
    QtColorPicker* cpd;
    QtColorPicker* cpfilld;
    Ui::ScatterConfig *ui;
    RInside& rconn;
    TwoVariablePicker* picker;
    QString x;
    QString y;
    VariableView* vv;
private slots:
    void setColor(QColor Colour);
    void setFill(QColor Colour);
    void setColord(QColor Colour);
    void setFilld(QColor Colour);
    void on_comboBox_shape_activated(const QString &arg1);
    void on_comboBox_color_activated(const QString &arg1);
    void on_comboBox_fill_activated(const QString &arg1);
    void on_horizontalSliderAlp_valueChanged(int value);
    void on_comboBox_size_activated(const QString &arg1);
    void on_lineEditSize_editingFinished();
    void on_comboBox_activated(int index);
    void on_comboBox_method_activated(int index);
    void on_checkBox_clicked();
    void on_comboBox_colors_activated(const QString &arg1);
    void on_comboBox_fills_activated(const QString &arg1);
    void on_horizontalSlider_smot_valueChanged(int value);
    void on_comboBox_linetype_s_activated(const QString &arg1);
    void on_comboBox_sizes_activated(const QString &arg1);
    void on_lineEditSize_2_editingFinished();
    void on_pushButtonExport_clicked();
};

#endif // SCATTERCONFIG_H
