#ifndef TIMESERIESPICKER_H
#define TIMESERIESPICKER_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>
#include <QGraphicsItem>
#include <chart.h>
namespace Ui {
class TimeSeriesPicker;
}

class TimeSeriesPicker : public QDialog, public Chart
{
    Q_OBJECT

public:
    explicit TimeSeriesPicker(VariableView* vv ,RInside &rconn,int type, QWidget *parent = 0);
    ~TimeSeriesPicker();

private slots:
    void on_buttonBox_accepted();

    void on_comboBoxVariable_currentIndexChanged(int index);

    void on_pushButtonSlectAll_clicked();

    void on_buttonBox_rejected();

private:
    Ui::TimeSeriesPicker *ui;
    VariableView* vv;
    RInside &rconn;
    int type;
};

#endif // TIMESERIESPICKER_H
