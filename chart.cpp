#include "chart.h"
#include <QFile>
#include <QGraphicsSvgItem>
#include <QTextStream>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>
#include <resultviewitem.h>
#include <mainwindow.h>
#include <QVBoxLayout>
Chart::Chart()
{

}

Chart::~Chart()
{

}

void Chart::filterSVGFile(QString m_tempfile , QString m_svgfile){
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

void Chart::setupChartView(QString m_svgfile ,QString chartName ,QString variable){

    m_svgItem = new QGraphicsSvgItem(m_svgfile);
    QGraphicsScene *s = new QGraphicsScene();
    s->addItem(m_svgItem);
    QWidget* widget = new QWidget();
    QGraphicsView* graph = new QGraphicsView(widget);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(graph);
    layout->setMargin(0);
    widget->setLayout(layout);
    graph->setScene(s);
    graph->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QString var = QString("%1(%2)").arg(chartName,variable);
    QStringList item;
    QList<QWidget*> list;
    list << widget;
    item << var;
    ResultViewItem* rvi = new ResultViewItem(item,list,chartName+" Result");
    MainWindow::result->setResultViewItem(rvi);
    MainWindow::enableResultView();

}
