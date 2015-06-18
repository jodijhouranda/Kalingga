#ifndef CHART_H
#define CHART_H
#include <QFile>
#include <QGraphicsSvgItem>
#include <QTextStream>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>
#include <resultviewitem.h>

#include <QHBoxLayout>
#include <QSvgWidget>
#include <RInside.h>
class Chart
{
public:
    Chart();
    ~Chart();
    void setupChartView(QString chartName ,QString variable,QWidget* configWidget);
    void filterSVGFile();
    void setTempFile(RInside& rconn);
    void printGraph(RInside& rconn);
    void printGraph(RInside& rconn,int width,int height);
    QSvgWidget* graph;

private:
    QString m_tempfile;
    QString m_svgfile;
    QString tfile;
    QString sfile;

};

#endif // CHART_H
