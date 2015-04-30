#ifndef RANDOMSAMPLEGENARATOR_H
#define RANDOMSAMPLEGENARATOR_H

#include <QDialog>
#include<variableview.h>
#include <RInside.h>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
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

    void on_comboBoxDistributions_activated(const QString &arg1);


    void on_pushButtonApply_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::RandomSampleGenarator *ui;
    VariableView* vv;
    RInside& rconn;
    QStringList distributions;
    QString command;
    int numPar;
    int nRow;
    void hideThirdLayout();
    void hideSecondLayout();
    void showThirdLayout();
    void showSecondLayout();
    void setOneParameterView(QString par1);
    void setTwoParameterView(QString par1 , QString par2);
    void setThreeParameterView(QString par1 , QString par2, QString par3);

    void init();
};

#endif // RANDOMSAMPLEGENARATOR_H
