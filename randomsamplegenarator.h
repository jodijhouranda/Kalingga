#ifndef RANDOMSAMPLEGENARATOR_H
#define RANDOMSAMPLEGENARATOR_H

#include <QDialog>
#include<variableview.h>
#include <RInside.h>
namespace Ui {
class RandomSampleGenarator;
}

class RandomSampleGenarator : public QDialog
{
    Q_OBJECT

public:
    explicit RandomSampleGenarator(VariableView* vv ,RInside &rconn,QWidget *parent = 0);
    ~RandomSampleGenarator();

private slots:
    void on_pushButtonNewVar_clicked();

private:
    Ui::RandomSampleGenarator *ui;
    VariableView* vv;
    RInside& rconn;
    QStringList distributions;
    void init();
};

#endif // RANDOMSAMPLEGENARATOR_H
