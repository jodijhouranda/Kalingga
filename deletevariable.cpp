#include "deletevariable.h"
#include "ui_deletevariable.h"
#include <QDebug>
DeleteVariable::DeleteVariable(VariableView* vv,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteVariable),
    vv(vv)
{
    ui->setupUi(this);
    QList<QString> allVar = vv->getAllVariableNames();

        ui->comboBoxVariables->addItems(allVar);

}

DeleteVariable::~DeleteVariable()
{
    delete ui;
}

void DeleteVariable::on_buttonBox_accepted()
{
    vv->deleteVariable(ui->comboBoxVariables->currentIndex());
}
