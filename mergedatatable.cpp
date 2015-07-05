#include "mergedatatable.h"
#include "ui_mergedatatable.h"
#include <QFileDialog>
#include <QMessageBox>
#include <duplicatevariablledialog.h>
MergeDataTable::MergeDataTable(VariableView* vv ,RInside &rconn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MergeDataTable),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    init();
}

MergeDataTable::~MergeDataTable()
{
    delete ui;
}

void MergeDataTable::init(){
    ui->comboBoxKeyCurrent->addItems(vv->getAllVariableNames());
    setButtonMenu();
}

void MergeDataTable::setButtonMenu() {
    QMenu *menu = new QMenu();

    openCSV = new QAction(tr("Comma Separated Value (*.csv)"),ui->pushButton);
    connect(openCSV, SIGNAL(triggered()),this,SLOT(openCSVSlot()));

    openDBF = new QAction(tr("dBase Database File (*.dbf)"),ui->pushButton);
    connect(openDBF, SIGNAL(triggered()),this,SLOT(openDBFSlot()));

    menu->addAction(openCSV);
    menu->addAction(openDBF);
    ui->pushButton->setMenu(menu);
   }
void MergeDataTable::openCSVSlot(){
    QString csvPath = QFileDialog::getOpenFileName(this,"Open",QString(),tr("Separate Comma Value (*.csv)"));
    std::string cmd0 ="data<- read.csv(\"" ;
    std::string cmd1 = "\")";
    std::string cmd = cmd0 + csvPath.toStdString() + cmd1 ;
    Rcpp::DataFrame data = rconn.parseEval(cmd);
    vvImport = new VariableView(data,rconn);
    setImportContent();
    ui->lineEditSource->setText(csvPath);
  }

void MergeDataTable::openDBFSlot(){
    QString dbfPath = QFileDialog::getOpenFileName(this,"Open",QString(),tr("dBase Database File (*.dbf)"));


    if (dbfPath.isEmpty()) {
        QMessageBox::information(this,"Error opening shapefile" ,"dbf file not found");
        return;
    }
    rconn.parseEvalQ("library(foreign)");
    QString cmd = QString("read.dbf(\"%1\")").arg(dbfPath);
    Rcpp::DataFrame data = rconn.parseEval(cmd.toStdString());
   vvImport = new VariableView(data,rconn);
   setImportContent();
    ui->lineEditSource->setText(dbfPath);
}

void MergeDataTable::setImportContent(){
    if (ui->comboBoxKeyImport>0) {
        ui->comboBoxKeyImport->clear();
    }
    while (ui->listWidget->count()>0) {
        ui->listWidget->takeItem(0);
    }while (ui->listWidget_2->count()>0) {
        ui->listWidget_2->takeItem(0);
    }
    ui->comboBoxKeyImport->addItems(vvImport->getAllVariableNames());
    ui->listWidget->addItems(vvImport->getAllVariableNames());
}

void MergeDataTable::on_radioButtonByValue_clicked()
{
    ui->comboBoxKeyCurrent->setEnabled(true);
    ui->comboBoxKeyImport->setEnabled(true);
}

void MergeDataTable::on_radioButtonRecordOrder_clicked()
{
    ui->comboBoxKeyCurrent->setEnabled(false);
    ui->comboBoxKeyImport->setEnabled(false);
}

void MergeDataTable::on_pushButtonRightTwo_clicked()
{
        while (ui->listWidget->count()>0) {
            ui->listWidget_2->addItem(ui->listWidget->takeItem(0));
        }
}

void MergeDataTable::on_pushButtonLeftTwo_clicked()
{
    while (ui->listWidget_2->count()>0) {
        ui->listWidget->addItem(ui->listWidget_2->takeItem(0));
    }
}

void MergeDataTable::on_pushButtonRight_clicked()
{

    ui->listWidget_2->addItem(ui->listWidget->takeItem(ui->listWidget->currentRow()));
}

void MergeDataTable::on_pushButtonLeft_clicked()
{
    ui->listWidget->addItem(ui->listWidget_2->takeItem(ui->listWidget_2->currentRow()));

}

void MergeDataTable::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget_2->addItem(ui->listWidget->takeItem(ui->listWidget->currentRow()));
}

void MergeDataTable::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
   ui->listWidget->addItem(ui->listWidget_2->takeItem(ui->listWidget_2->currentRow()));
}

void MergeDataTable::on_pushButton_3_clicked()
{
    close();
}

void MergeDataTable::on_pushButton_2_clicked()
{
    if (ui->listWidget_2->count()==0) {
        QMessageBox::information(this,"Merging Error","At least choose one variable to merge.");
        return;
    }
    QStringList varToImport;
    for (int i = 0; i < ui->listWidget_2->count(); ++i) {
    varToImport << ui->listWidget_2->item(i)->text();
    indexToImport << vvImport->getVariableIndex(ui->listWidget_2->item(i)->text());
    }
    if (nameCheckEdit(varToImport)) {
        return;
    }
    if (ui->radioButtonRecordOrder->isChecked()) {
        if (vv->getRowCount() != vvImport->getRowCount()) {
            QMessageBox::information(this,"Merging Error","Please Import data with equal row number");
            return;
        }else {
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
    }else {
        int columnCK = vv->getVariableIndex(ui->comboBoxKeyCurrent->currentText());
        int importCK = vvImport->getVariableIndex(ui->comboBoxKeyImport->currentText());
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
    }
}

bool MergeDataTable::nameCheckEdit(QStringList var){
    QStringList currentVar = vv->getAllVariableNames();
    QStringList importVar = var;
    QStringList duplicateVar;
    for (int i = 0; i < currentVar.length(); ++i) {
        for (int j = 0; j < importVar.length(); ++j) {
            if (currentVar.at(i)==importVar.at(j)) {
            duplicateVar << importVar.at(j);
            }
        }
    }
    if (duplicateVar.length()>0) {


        if (ui->radioButtonRecordOrder->isChecked()) {
            DuplicateVariablleDialog* dialog = new DuplicateVariablleDialog(indexToImport,duplicateVar,vv,vvImport,1,this);
            dialog->show();
        }else if(ui->radioButtonByValue->isChecked()) {


            DuplicateVariablleDialog* dialog = new DuplicateVariablleDialog(indexToImport,duplicateVar,vv,vvImport,0,this);
            dialog->setCurrentKey(ui->comboBoxKeyCurrent->currentText());
            dialog->setImportKey(ui->comboBoxKeyImport->currentText());
            dialog->show();
        }
    return true;
    }else {
        return false;
    }
}
