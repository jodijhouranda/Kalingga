#include "modifyvariable.h"
#include "ui_modifyvariable.h"
#include <QDebug>
#include <QMessageBox>
ModifyVariable::ModifyVariable(VariableView* vv,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyVariable),
    vv(vv)
{
    ui->setupUi(this);  
    ui->tableWidgetValue->setFocusPolicy(Qt::NoFocus);
    ui->tableWidgetVariable->setFocusPolicy(Qt::NoFocus);
    setupUiContent(0);
}

ModifyVariable::~ModifyVariable()
{
    delete ui;
}

void ModifyVariable::setupUiContent(int row){
    vars = vv->getAllVariableNames();
    allVar = vars;
    vars << "after last variable";
     for (int i = 0; i < allVar.length(); ++i) {
        ui->tableWidgetVariable->insertRow(i);
        ui->tableWidgetVariable->setItem(i,0,new QTableWidgetItem(allVar.at(i)));
        ui->tableWidgetVariable->setItem(i,1,new QTableWidgetItem(vv->getVariableType(allVar.at(i))));
        ui->tableWidgetVariable->setItem(i,2,new QTableWidgetItem(vv->getVariableLabel(allVar.at(i))));

    }
    ui->tableWidgetVariable->resizeColumnsToContents();
    on_tableWidgetVariable_cellClicked(row,0);
}

void ModifyVariable::on_tableWidgetVariable_cellClicked(int row, int column)
{
    removeTableValueContents();
    vec = vv->getCharacterVector(row);
    for (int i = 0; i < vec.length(); ++i) {
        ui->tableWidgetValue->insertRow(i);
        ui->tableWidgetValue->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
        ui->tableWidgetValue->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(vec[i])));
    }

    ui->tableWidgetValue->resizeColumnsToContents();
    ui->lineEditName->setText(ui->tableWidgetVariable->item(row,0)->text());
    ui->lineEditLabel->setText(ui->tableWidgetVariable->item(row,2)->text());


    removeComboContents();
    ui->comboBoxVariablesInsertBefore->addItems(vars);
    ui->comboBoxVariablesInsertBefore->removeItem(row);
    ui->comboBoxVariablesInsertBefore->setCurrentIndex(row);

    if (ui->tableWidgetVariable->item(row,1)->text() == "String") {
        ui->comboBoxVariablesType->setCurrentIndex(2);
    }else if (ui->tableWidgetVariable->item(row,1)->text() == "Real") {
        ui->comboBoxVariablesType->setCurrentIndex(0);
    }
    else {
        ui->comboBoxVariablesType->setCurrentIndex(1);
    }

}

void ModifyVariable::removeTableValueContents(){
    while( ui->tableWidgetValue->rowCount()>0) {
      ui->tableWidgetValue->removeRow(0);
    }

}

void ModifyVariable::removeTableVariableContents(){
    while( ui->tableWidgetVariable->rowCount()>0) {
     ui->tableWidgetVariable->removeRow(0);
    }

}
void ModifyVariable::removeComboContents(){
    if (ui->comboBoxVariablesType->count()>0) {
         ui->comboBoxVariablesInsertBefore->clear();
    }
}

void ModifyVariable::on_pushButtonApply_clicked()
{
    vv->deleteVariable(ui->tableWidgetVariable->currentRow());
    QString name = ui->lineEditName->text();
    QString type = ui->comboBoxVariablesType->itemText(ui->comboBoxVariablesType->currentIndex());
    QString label = ui->lineEditLabel->text();
    if (validate()) {
        vv->createNewVariable(name,type,label,ui->comboBoxVariablesInsertBefore->currentIndex());
    }
    else {
        if (ui->lineEditName->text().trimmed().length() <= 0) {
            QMessageBox::information(this,"Create variable error","Input Variable's name first !");
        }
        return;
    }
    if (type == "String") {
        vv->setCharacterVector(name,vec);
    }
    else if(type == "Real") {
        vv->setNumericVariable(name,convertReal(vec));
    }else {
        vv->setNumericVariable(name,convertInt(vec));
    }
    removeTableVariableContents();
    setupUiContent(vv->getVariableIndex(name));
}
bool ModifyVariable::validate(){
    if (ui->lineEditName->text().trimmed().length() <= 0) {
             return false;
    }
    return true;


}
Rcpp::NumericVector ModifyVariable::convertReal(Rcpp::CharacterVector vec){
   Rcpp::NumericVector res(vec.length());
    for (int i = 0; i < vec.length(); ++i) {
        res[i] = QString::fromUtf8(vec[i]).toDouble();
    }
    return res;
}
Rcpp::NumericVector ModifyVariable::convertInt(Rcpp::CharacterVector vec){
   Rcpp::NumericVector res(vec.length());
    for (int i = 0; i < vec.length(); ++i) {
        double x = QString::fromUtf8(vec[i]).toDouble();
        res[i] = (int)x;
    }
    return res;
}

void ModifyVariable::on_pushButtonCancel_clicked()
{
    close();
}
