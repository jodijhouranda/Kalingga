#ifndef COMPUTEVARIABLE_H
#define COMPUTEVARIABLE_H

#include <QDialog>
#include<variableview.h>
#include <RInside.h>
#include <QListWidgetItem>
namespace Ui {
class ComputeVariable;
}

class ComputeVariable : public QDialog
{
    Q_OBJECT

public:
    explicit ComputeVariable(VariableView* vv ,RInside &rconn, QWidget *parent = 0);
    ~ComputeVariable();

private slots:
    void on_pushButtonNewVar_clicked();

    void on_pushButton1_clicked();

    void on_pushButton1_2_clicked();

    void on_pushButton1_3_clicked();

    void on_pushButton1_4_clicked();

    void on_pushButton1_5_clicked();

    void on_pushButton1_6_clicked();

    void on_pushButton1_7_clicked();

    void on_pushButton1_8_clicked();

    void on_pushButton1_9_clicked();

    void on_pushButton1_0_clicked();

    void on_pushButtonPoint_clicked();

    void on_pushButtondelete_clicked();

    void on_pushButtonplus_clicked();

    void on_pushButtonsubtract_clicked();

    void on_pushButtonMultiply_clicked();

    void on_pushButtonDevide_clicked();

    void on_listWidgetVariables_itemDoubleClicked(QListWidgetItem *item);


    void on_pushButtonApply_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonlbrac_clicked();

    void on_pushButtonrbrac_clicked();


    void on_listWidgetfunction_doubleClicked(const QModelIndex &index);



    void on_comboBoxFGroup_currentIndexChanged(int index);

    void on_pushButtondelete_2_clicked();

private:
    Ui::ComputeVariable *ui;
    VariableView* vv;
    RInside& rconn;
    void init();
    void setFormulaViewText(QString string);
    QList<QString> getChoosenAttribute();
    QStringList functionGroup;
    QMap<QString,QString> trigonometryMap;
    QMap<QString,QString> mathMap;
    QMap<QString,QString> statisticMap;
};

#endif // COMPUTEVARIABLE_H
