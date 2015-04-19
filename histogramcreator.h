#ifndef HISTOGRAMCREATOR_H
#define HISTOGRAMCREATOR_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>
#include <QGraphicsItem>
#include <histogram.h>
namespace Ui {
class HistogramCreator;
}

class HistogramCreator : public QDialog
{
    Q_OBJECT

public:
    explicit HistogramCreator(VariableView* vv ,RInside &rconn, QWidget *parent = 0);
    ~HistogramCreator();

private slots:
    void on_buttonBox_accepted();
    void filterSVGFile();
private:
    Ui::HistogramCreator *ui;
    VariableView* vv;
    RInside& rconn;
    QString m_tempfile;
    QString m_svgfile;
    QString m_cmd;
    QGraphicsItem *m_svgItem;
    QString data;
};

#endif // HISTOGRAMCREATOR_H
