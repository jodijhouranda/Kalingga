#ifndef PARALLECHART_H
#define PARALLECHART_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>
#include <QGraphicsItem>
#include <chart.h>
#include <QListWidgetItem>
namespace Ui {
class ParalleChart;
}

class ParalleChart : public QDialog, public Chart
{
    Q_OBJECT

public:
    explicit ParalleChart(VariableView* vv ,RInside &rconn, QWidget *parent = 0);
    ~ParalleChart();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ParalleChart *ui;
    VariableView* vv;
    RInside &rconn;
    QList<QListWidgetItem*> choose;
    QString getChooseVar(QList<QListWidgetItem*>  list);



};

#endif // PARALLECHART_H
