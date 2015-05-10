#include "histogramcreator.h"
#include "ui_histogramcreator.h"
#include "histogramconfig.h"
HistogramCreator::HistogramCreator(VariableView* vv ,RInside &rconn, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::HistogramCreator),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    QList<QString> allVar = vv->getNumericVariableNames();
    ui->listWidgetVariables->addItems(allVar);

    setTempFile(rconn);

}

HistogramCreator::~HistogramCreator()
{
    delete ui;

}

void HistogramCreator::on_buttonBox_accepted()
{

    QString x = ui->listWidgetVariables->currentItem()->text();
    HistogramConfig* conf = new HistogramConfig(this,rconn);
    conf->setVariable(x);
    setupChartView("Histogram",x, conf);
    QString command;
    try {
        vv->sendDataFrame(rconn);
        command = QString("gr<-(ggplot(dframe, aes(x=%1))+ geom_histogram());").arg(x);
        rconn.parseEvalQ(command.toStdString());

        printGraph(rconn);
    } catch (...) {

    }





}


