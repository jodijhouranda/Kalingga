#ifndef DELETEVARIABLE_H
#define DELETEVARIABLE_H

#include <QDialog>
#include <variableview.h>
namespace Ui {
class DeleteVariable;
}

class DeleteVariable : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteVariable(VariableView* vv , QWidget *parent = 0);
    ~DeleteVariable();

private slots:
    void on_buttonBox_accepted();

private:

    Ui::DeleteVariable *ui;
    VariableView* vv;
};

#endif // DELETEVARIABLE_H
