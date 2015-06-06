#ifndef HISTOGRAMCONFIG_H
#define HISTOGRAMCONFIG_H

#include <QWidget>
#include <RInside.h>
#include <chartconfig.h>
#include <qtColorpicker.h>
#include <histogramcreator.h>
#include <QComboBox>
namespace Ui {
class HistogramConfig;
}

class HistogramConfig : public QWidget ,public ChartConfig
{
    Q_OBJECT

public:
    explicit HistogramConfig(HistogramCreator* histo,RInside& rconn,QString var,VariableView* vv,QWidget *parent = 0);
    ~HistogramConfig();

    void setVariable(QString var);
private slots:
    void on_comboBox_currentIndexChanged(int index);
private:
    void setupUiLoc();
    void setKernelContent(QComboBox* combo);

    void setParorAesHistogram();
    void setParorAesDensity();

    void drawPlot();
    VariableView* vv;
    QtColorPicker* cp;
    QtColorPicker* cpfill;
    QtColorPicker* cpd;
    QtColorPicker* cpfilld;
    Ui::HistogramConfig *ui;
    RInside& rconn;
    QString variable;
    HistogramCreator* histo;
    QString geomHisto;
    QString geomDensity;

    //parameter histogram
    QString binwidth;
    QString colourh;
    QString fillh;
    QString alphah;
    QString weighth;
    QString linetypeh;
    QString sizeh;
    //parameter density
    QString kerneld;
    QString adjustd;
    QString colourd;
    QString filld;
    QString alphad;
    QString weightd;
    QString linetyped;
    QString sized;
private slots:
    void setColor(QColor Colour);
    void setFill(QColor Colour);
    void setColord(QColor Colour);
    void setFilld(QColor Colour);
    void on_lineEdit_editingFinished();
    void on_horizontalSlider_valueChanged(int value);
    void on_comboBox_2_activated(const QString &arg1);
    void on_comboBox_linetype_activated(const QString &arg1);
    void on_lineEdit_Size_editingFinished();
    void on_comboBox_coloraes_activated(const QString &arg1);
    void on_comboBox_fillaes_activated(const QString &arg1);
    void on_comboBox_kernel_activated(const QString &arg1);
    void on_lineEdit_adjust_editingFinished();
    void on_comboBox_colorDens_activated(const QString &arg1);
    void on_comboBox_fillDens_activated(const QString &arg1);
    void on_horizontalSlider_Dens_valueChanged(int value);
    void on_comboBox_WeightDens_activated(const QString &arg1);
    void on_comboBox_linetype_Dens_activated(const QString &arg1);
    void on_lineEdit_Size_Dens_editingFinished();
    void on_comboBox_activated(int index);
    void on_pushButtonExport_clicked();
};

#endif // HISTOGRAMCONFIG_H
