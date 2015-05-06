#ifndef CHART_H
#define CHART_H

#include <QGraphicsItem>
class Chart
{
public:
    Chart();
    ~Chart();
    void setupChartView(QString m_svgfile ,QString chartName ,QString variable);
    void filterSVGFile(QString m_tempfile , QString m_svgfile);
private:
    QGraphicsItem *m_svgItem;
};

#endif // CHART_H
