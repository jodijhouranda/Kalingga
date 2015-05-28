#include "histogramcreator.h"
#include "ui_histogramcreator.h"
#include "histogramconfig.h"
#include <recodevariable.h>
HistogramCreator::HistogramCreator(VariableView* vv ,RInside &rconn,int type,QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::HistogramCreator),
    vv(vv),
    rconn(rconn),
    type(type)
{
    ui->setupUi(this);
setupUi();



}

const int HistogramCreator::HISTOGRAM=0;
const int HistogramCreator::RECODEVARIABLE=1;
void HistogramCreator::setupUi(){
    QList<QString> allVar;
    switch (type) {
    case HISTOGRAM:
        allVar = vv->getNumericVariableNames();
        ui->listWidgetVariables->addItems(allVar);
        break;
    case RECODEVARIABLE:
        allVar = vv->getAllVariableNames();
        ui->listWidgetVariables->addItems(allVar);
        break;
    }
}

HistogramCreator::~HistogramCreator()
{
    delete ui;

}
void HistogramCreator::on_buttonBox_accepted()
{
    QList<QString> allVar;
    switch (type) {
    case HISTOGRAM:
        generateHistogram();
        break;
    case RECODEVARIABLE:
        generateRecode();
        break;
    }

}

void HistogramCreator::generateHistogram(){
    setTempFile(rconn);
    vv->sendDataFrame(rconn);

    QString x = ui->listWidgetVariables->currentItem()->text();
    HistogramConfig* conf = new HistogramConfig(this,rconn,x,vv);

    setupChartView("Histogram",x, conf);
    QString command;
    try {
        command = QString("gr<-(ggplot(dframe, aes(x=%1))+ geom_histogram());").arg(x);
        rconn.parseEvalQ(command.toStdString());

        printGraph(rconn);
    } catch (...) {

    }
}
void HistogramCreator::generateRecode(){
    QString x = ui->listWidgetVariables->currentItem()->text();
    RecodeVariable* recode = new RecodeVariable(vv,x);
    recode->show();
}
