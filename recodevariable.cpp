#include "recodevariable.h"
#include "ui_recodevariable.h"

RecodeVariable::RecodeVariable(VariableView* vv, QString var,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecodeVariable),
    vv(vv),
    var(var)
{
    ui->setupUi(this);
    ui->label_variable->setText(var);
    setupUI();
}
void RecodeVariable::setupUI(){
    QList<QString> allVar = vv->getAllVariableNames();
    ui->comboBoxVariables->addItems(allVar);
}

RecodeVariable::~RecodeVariable()
{
    delete ui;
}

void RecodeVariable::on_pushButtonNewVar_clicked()
{
    CreateNewVariable* cnv = new CreateNewVariable(vv ,this );

    cnv->show();
    cnv->updateQCombox(new QListWidget(),ui->comboBoxVariables);
}
