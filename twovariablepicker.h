#ifndef TWOVARIABLEPICKER_H
#define TWOVARIABLEPICKER_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>
#include <QGraphicsItem>
#include <chart.h>

namespace Ui {
class TwoVariablePicker;
}

class TwoVariablePicker : public QDialog, public Chart
{
    Q_OBJECT

public:
    explicit TwoVariablePicker(VariableView* vv ,RInside &rconn,int type, QWidget *parent = 0);
    ~TwoVariablePicker();
    static const int SCATTER;
    static const int BOXPLOT;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::TwoVariablePicker *ui;
    void setupXYVariable();
    VariableView* vv;
    RInside &rconn;
    int type;
    void generateScatterChart();
    void generateBoxChart();
};

#endif // TWOVARIABLEPICKER_H
