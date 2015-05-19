#include "twovariablepicker.h"
#include "ui_twovariablepicker.h"
#include <QDebug>
#include <scatterconfig.h>

TwoVariablePicker::TwoVariablePicker(VariableView* vv ,RInside &rconn,int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoVariablePicker),
    vv(vv),
    rconn(rconn),
    type(type)
{
    ui->setupUi(this);
    setupXYVariable();
    setTempFile(rconn);
}
const int TwoVariablePicker::SCATTER =0;
void TwoVariablePicker::setupXYVariable(){
    QStringList list = vv->getAllVariableNames();
    ui->listWidgetVariablesX->addItems(list);
    ui->listWidgetVariablesY->addItems(list);
    ui->listWidgetVariablesX->setCurrentRow(0);
    ui->listWidgetVariablesY->setCurrentRow(0);

}

TwoVariablePicker::~TwoVariablePicker()
{
    delete ui;
}

void TwoVariablePicker::on_buttonBox_accepted()
{
    switch (type) {
    case SCATTER:


    generateScatterChart();
        break;
    }
}
void TwoVariablePicker::generateScatterChart(){

    vv->sendDataFrame(rconn);

    QString x = ui->listWidgetVariablesX->currentItem()->text();
    QString y = ui->listWidgetVariablesY->currentItem()->text();
    QString var = x +","+y;
    ScatterConfig* sConfig = new ScatterConfig(this,rconn,x,y,vv);
    setupChartView("Scatter",var, sConfig);
    QString command;
    try {
        command = QString("gr<-ggplot(dframe, aes(x=%1, y=%2)) + geom_point();").arg(x,y);
        rconn.parseEvalQ(command.toStdString());

        printGraph(rconn);
    } catch (...) {

    }

}
