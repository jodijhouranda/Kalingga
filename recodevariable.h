#ifndef RECODEVARIABLE_H
#define RECODEVARIABLE_H

#include <QDialog>
#include <variableview.h>
#include <createnewvariable.h>
namespace Ui {
class RecodeVariable;
}

class RecodeVariable : public QDialog
{
    Q_OBJECT

public:
    explicit RecodeVariable(VariableView* vv, QString var,QWidget *parent = 0);
    ~RecodeVariable();

private slots:

    void on_pushButtonNewVar_clicked();

private:
    Ui::RecodeVariable *ui;
    VariableView* vv;
    QString var;
    void setupUI();
};

#endif // RECODEVARIABLE_H
