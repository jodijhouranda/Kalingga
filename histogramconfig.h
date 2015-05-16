#ifndef HISTOGRAMCONFIG_H
#define HISTOGRAMCONFIG_H

#include <QWidget>
#include <RInside.h>
#include <chartconfig.h>

#include <histogramcreator.h>
namespace Ui {
class HistogramConfig;
}

class HistogramConfig : public QWidget ,public ChartConfig
{
    Q_OBJECT

public:
    explicit HistogramConfig(HistogramCreator* histo,RInside& rconn,QWidget *parent = 0);
    ~HistogramConfig();

    void setVariable(QString var);
private slots:
    void on_comboBox_currentIndexChanged(int index);


    void on_spinBoxBinwidth_valueChanged(int arg1);

private:
    void drawPlot();
    Ui::HistogramConfig *ui;
    RInside& rconn;
    QString variable;
    HistogramCreator* histo;
    QString geomHisto;
    QString geomDensity;
    QStringList par;
    QStringList parAes;
    QString binwidth;

};

#endif // HISTOGRAMCONFIG_H
