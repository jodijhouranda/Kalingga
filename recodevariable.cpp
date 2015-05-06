#include "recodevariable.h"
#include "ui_recodevariable.h"

RecodeVariable::RecodeVariable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecodeVariable)
{
    ui->setupUi(this);
}

RecodeVariable::~RecodeVariable()
{
    delete ui;
}
