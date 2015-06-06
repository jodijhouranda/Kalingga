#ifndef PARALLELCHARTCONFIG_H
#define PARALLELCHARTCONFIG_H

#include <QWidget>
#include <RInside.h>
#include <chartconfig.h>
#include <qtColorpicker.h>
#include <QComboBox>
#include <parallechart.h>
namespace Ui {
class ParallelChartConfig;
}

class ParallelChartConfig :  public QWidget,public ChartConfig
{

    Q_OBJECT

public:
    explicit ParallelChartConfig(ParalleChart* chart,RInside& rconn,QString var,VariableView* vv,QWidget *parent = 0);
    ~ParallelChartConfig();

private slots:
    void on_comboBox_GroupCoolumn_activated(const QString &arg1);

    void on_comboBox_Scale_activated(const QString &arg1);

    void on_comboBox_Missing_activated(const QString &arg1);

    void on_comboBox_Order_activated(const QString &arg1);

    void on_horizontalSliderAlp_valueChanged(int value);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_lineEdit_editingFinished();

    void on_checkBox_3_clicked();

    void on_pushButtonExport_clicked();

private:
    Ui::ParallelChartConfig *ui;
    void drawPlot();
    void setupUi();
    void setParorAesParallel();
    RInside& rconn;
    ParalleChart* chart;
    QString var;
    VariableView* vv;
    QString groupColumn;
    QString scale;
    QString missing;
    QString order;
    QString showPoints;
    QString alphaLines;
    QString boxplot;
    QString tittle;
    QString theme;
};

#endif // PARALLELCHARTCONFIG_H
