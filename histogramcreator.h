#ifndef HISTOGRAMCREATOR_H
#define HISTOGRAMCREATOR_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>
#include <QGraphicsItem>
#include <chart.h>
namespace Ui {
class HistogramCreator;
}

class HistogramCreator : public QDialog ,public Chart
{
    Q_OBJECT

public:
    explicit HistogramCreator(VariableView* vv ,RInside &rconn,int type,QWidget *parent = 0);
    ~HistogramCreator();
    static const int HISTOGRAM;
    static const int RECODEVARIABLE;
private slots:
    void on_buttonBox_accepted();
private:
    Ui::HistogramCreator *ui;
    VariableView* vv;
    RInside& rconn;
    QString m_cmd;
    QString data;
    int type;
    void generateHistogram();
    void generateRecode();
};

#endif // HISTOGRAMCREATOR_H
