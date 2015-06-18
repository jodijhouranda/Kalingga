#include "chart.h"
#include <mainwindow.h>
#include <QPushButton>
#include <histogramconfig.h>
#include <QDebug>
#include <QScrollArea>
Chart::Chart()
{
}

Chart::~Chart()
{

}

void Chart::filterSVGFile(){
    // cairoDevice creates richer SVG than Qt can display
    // but per Michaele Lawrence, a simple trick is to s/symbol/g/ which we do here
    QFile infile(m_tempfile);
    infile.open(QFile::ReadOnly);
    QFile outfile(m_svgfile);
    outfile.open(QFile::WriteOnly | QFile::Truncate);

    QTextStream in(&infile);
    QTextStream out(&outfile);
    QRegExp rx1("<symbol");
    QRegExp rx2("</symbol");
    while (!in.atEnd()) {
        QString line = in.readLine();
        line.replace(rx1, "<g"); // so '<symbol' becomes '<g ...'
        line.replace(rx2, "</g");// and '</symbol becomes '</g'
        out << line << "\n";
    }
    infile.close();
    outfile.close();
}

void Chart::setupChartView(QString chartName ,QString variable ,QWidget* configWidget){
    QWidget* widget = new QWidget();
    graph = new QSvgWidget(widget);


    QHBoxLayout* layout = new QHBoxLayout();

    QWidget* cWidget = configWidget;
    cWidget->setParent(widget);
    layout->addWidget(graph);
    layout->setMargin(0);
    widget->setLayout(layout);
    graph->setFixedSize(600,600);
    cWidget->setFixedWidth(200);
    cWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    QString var = QString("%1 (%2)").arg(chartName,variable);
    QStringList item;
    QList<QWidget*> list;
    list << widget;
    item << var;
    ResultViewItem* rvi = new ResultViewItem(item,list,var);
    MainWindow::result->setResultViewItem(rvi);
    MainWindow::enableResultView();

}

void Chart::setTempFile(RInside& rconn){
    tfile ="tf" +QString::number(qrand());
    sfile = "sf"+QString::number(qrand());
    qDebug()<<tfile +sfile;
    m_tempfile = QString::fromStdString(Rcpp::as<std::string>(rconn.parseEval(QString("%1 <- tempfile()").arg(tfile).toStdString())));
    m_svgfile = QString::fromStdString(Rcpp::as<std::string>(rconn.parseEval(QString("%1 <- tempfile()").arg(sfile).toStdString())));

    rconn.parseEval("library(ggplot2)");
    rconn.parseEval("library(GGally)");
}

void Chart::printGraph(RInside& rconn){
    rconn.parseEvalQ(QString("svg(width=6,height=6,pointsize=10,filename= %1);").arg(tfile).toStdString());
    rconn.parseEvalQ("print(gr);dev.off();");
    filterSVGFile();
    graph->load(m_svgfile);
}
void Chart::printGraph(RInside& rconn,int width,int height){
    rconn.parseEvalQ(QString("svg(width= %2,height= %3,pointsize=10,filename= %1);").arg(tfile,QString::number(width),QString::number(height)).toStdString());
    rconn.parseEvalQ("print(gr);dev.off();");
    filterSVGFile();
    graph->setFixedSize(width*100,600);
    graph->load(m_svgfile);

}
