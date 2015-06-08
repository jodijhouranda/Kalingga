#include "duplicatevariablledialog.h"
#include "ui_duplicatevariablledialog.h"
#include <QDebug>
#include <QMessageBox>
DuplicateVariablleDialog::DuplicateVariablleDialog(QList<int> indexToImport,QStringList duplicateVar,VariableView* vv,VariableView* vvImport,int mode,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DuplicateVariablleDialog),
    duplicateVar(duplicateVar),
    vv(vv),
    vvImport(vvImport),
    mode(mode),
    indexToImport(indexToImport)
{
    ui->setupUi(this);
    init();
}

DuplicateVariablleDialog::~DuplicateVariablleDialog()
{
    delete ui;
}

void DuplicateVariablleDialog::init(){

    for (int i = 0; i < duplicateVar.length(); ++i) {
    qDebug()<<duplicateVar.at(i);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(duplicateVar.at(i)));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(duplicateVar.at(i)+"_1"));
    }
}

void DuplicateVariablleDialog::on_pushButton_2_clicked()
{
    int columnCK = vv->getVariableIndex(currentKey);
    int importCK = vvImport->getVariableIndex(importKey);
    for (int j = 0; j < vv->getColumnCount(); ++j) {
        for (int k = 0; k < ui->tableWidget->rowCount(); ++k) {
            if (ui->tableWidget->item(k,1)->text().trimmed() == "") {
            QMessageBox::information(this,"Merging error","Can't use empty string for variable name");
            return;
            }
            if (ui->tableWidget->item(k,1)->text() == vv->getVariableName(j)) {
            QMessageBox::information(this,"Merging error","Can't use variable "+vv->getVariableName(j));
            return;
            }

        }
    }
    for (int i = 0; i < duplicateVar.length(); ++i) {
    vvImport->changeVarName(vvImport->getVariableIndex(duplicateVar.at(i)),ui->tableWidget->item(i,1)->text());
    }
    QStringList varToImport;
    for (int i = 0; i < indexToImport.length(); ++i) {
        varToImport << vvImport->getVariableName(indexToImport.at(i));
    }

    if (mode == 0) {


        for (int i = 0; i < varToImport.length(); ++i) {
            QString var = varToImport.at(i);
            vv->createNewVariable(var,vvImport->getVariableType(var),"",vv->getColumnCount());
        }
        for (int i = 0; i < vvImport->getRowCount(); ++i) {
            for (int j = 0; j < vv->getRowCount(); ++j) {
                if (vv->getSpreadsheetTable()->item(j,columnCK)->text() == vvImport->getSpreadsheetTable()->item(i,importCK)->text()) {
                    for (int k = 0; k < varToImport.length(); ++k) {
                        vv->getSpreadsheetTable()->setItem(j,vv->getVariableIndex(varToImport.at(k)),new QTableWidgetItem(vvImport->getSpreadsheetTable()->item(i,vvImport->getVariableIndex(varToImport.at(k)))->text()));
                    }
                }
            }
        }
        for (int r = 0; r < varToImport.length();++r) {
            QString type = vv->getVariableType(varToImport.at(r));
            if ( type == "Integer" || type == "Real" ) {
                for (int i = 0; i < vv->getRowCount(); ++i) {
                    vv->getSpreadsheetTable()->item(i,vv->getVariableIndex(varToImport.at(r)))->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
                }
            }
        }

    } else if (mode == 1) {
        for (int j = 0; j < varToImport.length(); ++j) {
            QString var = varToImport.at(j);
            vv->createNewVariable(var,vvImport->getVariableType(var),"",vv->getColumnCount());
            if (vv->getVariableType(var) != "String") {
                vv->setNumericVariable(var,Rcpp::na_omit(vvImport->getNumericVector(vvImport->getVariableIndex(var))));
                }else {
                   vv->setCharacterVector(var,Rcpp::na_omit(vvImport->getCharacterVector(vvImport->getVariableIndex(var))));
                }
        }
    }

    close();
    parentWidget()->close();
}

void DuplicateVariablleDialog::setCurrentKey(QString key){
    currentKey = key;
}

void DuplicateVariablleDialog::setImportKey(QString key){
    importKey = key;
}

void DuplicateVariablleDialog::on_pushButton_clicked()
{
    close();
    parentWidget()->close();
}

