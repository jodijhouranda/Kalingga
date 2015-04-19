#ifndef CREATENEWVARIABLE_H
#define CREATENEWVARIABLE_H

#include <QDialog>
#include <variableview.h>
namespace Ui {
class CreateNewVariable;
}

class CreateNewVariable : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewVariable(VariableView* vv , QWidget *parent = 0);
    ~CreateNewVariable();

private slots:
    void on_buttonBox_accepted();

private:

    Ui::CreateNewVariable *ui;
    VariableView* vv;

};

#endif // CREATENEWVARIABLE_H
