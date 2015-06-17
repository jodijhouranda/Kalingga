#include "timeseriespicker.h"
#include "ui_timeseriespicker.h"

TimeSeriesPicker::TimeSeriesPicker(VariableView* vv ,RInside &rconn,int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSeriesPicker),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    ui->comboBoxVariable->addItems(vv->getNumericSeriesVariableNames());
    on_comboBoxVariable_currentIndexChanged(0);
}

TimeSeriesPicker::~TimeSeriesPicker()
{
    delete ui;
}

void TimeSeriesPicker::on_buttonBox_accepted()
{
    QStringList timeList;
    for (int i = 0; i < ui->listWidgetTimes->count(); ++i) {
       timeList << ui->listWidgetTimes->item(i)->text();
    }
      vv->sendDataFrameSeries(ui->comboBoxVariable->currentText(),timeList,rconn);
      rconn.parseEvalQ("print(dframe)");
      close();
}

void TimeSeriesPicker::on_comboBoxVariable_currentIndexChanged(int index)
{
    while (ui->listWidgetTimes->count()> 0) {
        ui->listWidgetTimes->takeItem(0);
    }
    ui->listWidgetTimes->addItems(vv->getAllTimesByVariableName(ui->comboBoxVariable->currentText()));
}

void TimeSeriesPicker::on_pushButtonSlectAll_clicked()
{
    for (int i = 0; i < ui->listWidgetTimes->count(); ++i) {
        ui->listWidgetTimes->item(i)->setSelected(true);
    }
}

void TimeSeriesPicker::on_buttonBox_rejected()
{
    close();
}
