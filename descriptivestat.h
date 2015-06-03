#ifndef DESCRIPTIVESTAT_H
#define DESCRIPTIVESTAT_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>
#include <QListWidgetItem>
#include <QTextTable>

#include <QTextBrowser>
namespace Ui {
class DescriptiveStat;
}

class DescriptiveStat : public QDialog
{
    Q_OBJECT

public:
    explicit DescriptiveStat(VariableView* vv ,RInside &rconn,QWidget *parent = 0);
    ~DescriptiveStat();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::DescriptiveStat *ui;
    VariableView* vv;
    RInside &rconn;
    QList<QListWidgetItem*> choose;
    QString getChooseVar(QList<QListWidgetItem*>  list);
    void showResult();
    QStringList listItem;
    QList<QWidget*> resultWidget;
    QString tittle;
    QStringList statistics;
    QStringList variables;
    QString functionMean;
    QString functionMedian;
    QString functionSum;

    QString functionStdev;
    QString functionVariance;
    QString functionRange;
    QString functionMaximum;
    QString functionMinimum;
    QString functionSEMean;

    QString functionKurtosis;
    QString functionSkewness;

    QStringList meanValue;
    QStringList medianValue;
    QStringList sumValue;
    QStringList stdevValue;
    QStringList varianceValue;
    QStringList rangeValue;
    QStringList maximumValue;
    QStringList minimumValue;
    QStringList SEmeanValue;
    QStringList kurtosisValue;
    QStringList skewnessValue;
    QTextTable *statTable;
    void countVariable(QString function, QStringList result,int col);
    void summaryVariable();
    void fivenumVariable();
    QTextBrowser* descText;

};

#endif // DESCRIPTIVESTAT_H
