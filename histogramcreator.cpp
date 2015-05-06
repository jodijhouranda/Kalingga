#include "histogramcreator.h"
#include "ui_histogramcreator.h"
HistogramCreator::HistogramCreator(VariableView* vv ,RInside &rconn, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::HistogramCreator),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    QList<QString> allVar = vv->getNumericVariableNames();
    ui->listWidgetVariables->addItems(allVar);
    m_tempfile = QString::fromStdString(Rcpp::as<std::string>(rconn.parseEval("tfile <- tempfile()")));
    m_svgfile = QString::fromStdString(Rcpp::as<std::string>(rconn.parseEval("sfile <- tempfile()")));

}

HistogramCreator::~HistogramCreator()
{
    delete ui;

}

void HistogramCreator::on_buttonBox_accepted()
{

    QString selectedVar = ui->listWidgetVariables->item(ui->listWidgetVariables->currentRow())->text();
    Rcpp::NumericVector vektor = vv->getNumericVector(vv->getVariableIndex(selectedVar));
    QString x = ui->listWidgetVariables->currentItem()->text();
    QString command;
    rconn[x.toStdString()] = vektor;
    try {


        command = QString("library(ggplot2);svg(width=6,height=6,pointsize=10,filename=tfile);hist(%1);dev.off();").arg(x);
        rconn.parseEvalQ(command.toStdString());
    } catch (...) {

    }
    filterSVGFile(m_tempfile,m_svgfile);
    setupChartView(m_svgfile,"Histogram",x);


}


