#include "timeseriespicker.h"
#include "ui_timeseriespicker.h"
#include <QDebug>
TimeSeriesPicker::TimeSeriesPicker(VariableView* vv ,RInside &rconn,int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSeriesPicker),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    ui->comboBoxVariable->addItems(vv->getNumericSeriesVariableNames());
    ui->comboBoxVariableID->addItems(vv->getAllVariableNames());
    on_comboBoxVariable_currentIndexChanged(0);
    setTempFile(rconn);
}

TimeSeriesPicker::~TimeSeriesPicker()
{
    delete ui;
}

void TimeSeriesPicker::on_buttonBox_accepted()
{
    QStringList timeList;
    for (int i = 0; i < ui->listWidgetTimes->count(); ++i) {
        if (ui->listWidgetTimes->item(i)->isSelected()) {
            timeList << ui->listWidgetTimes->item(i)->text();
        }
    }
    QString x = ui->comboBoxVariable->currentText();
    vv->sendDataFrameSeriesFormatted(ui->comboBoxVariable->currentText(),ui->comboBoxVariableID->currentText(),timeList,rconn);
      setupChartView("Time Series Plot",x, new QWidget());
      QString command;
      try {
          command = QString("gr<-ggplot(dframe, aes(times, %1 , group = ID, colour = ID)) + geom_line()").arg(x);
          qDebug() << command;
          rconn.parseEvalQ(command.toStdString());
          printGraph(rconn,11,6);
      } catch (...) {

      }
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
