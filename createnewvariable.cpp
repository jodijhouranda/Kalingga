#include "createnewvariable.h"
#include "ui_createnewvariable.h"
#include <QDebug>
#include <QMessageBox>
CreateNewVariable::CreateNewVariable( VariableView* vv,QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::CreateNewVariable),
    vv(vv)
{
    ui->setupUi(this);

    TEST = false;

    QStringList vars = vv->getAllVariableNames();
    allVar = vars;
    vars << "after last variable";
    ui->comboBoxInsertBefore->addItems(vars);
}

CreateNewVariable::~CreateNewVariable()
{
    delete ui;
}

void CreateNewVariable::on_buttonBox_accepted()
{
    QString name = ui->lineEditName->text();
    QString type = ui->comboBoxType->itemText(ui->comboBoxType->currentIndex());
    QString label = ui->lineEditLabel->text();
    if (validate()) {
        vv->createNewVariable(name,type,label,ui->comboBoxInsertBefore->currentIndex());
        if (TEST) {
            m_combo->insertItem(0,ui->lineEditName->text());
            m_listwidget->insertItem(0,ui->lineEditName->text());
            m_combo->setCurrentIndex(0);
        }
        close();
    }
    else {
        if (ui->lineEditName->text().trimmed().length() <= 0) {
            QMessageBox::information(this,"Create variable error","Input Variable's name first !");
        }else {
            QMessageBox::information(this,"Create variable error","Please use different variable's name !");
        }
        return;
    }
}

void CreateNewVariable::updateQCombox(QListWidget* listwidget , QComboBox* combo){
    TEST = true;
    m_listwidget = listwidget;
    m_combo = combo;
}

void CreateNewVariable::inactivatedIntegerType(){
    ui->comboBoxType->setItemData(1, 0, Qt::UserRole - 1);
}
void CreateNewVariable::inactivatedRealType(){
    ui->comboBoxType->setItemData(0, 0, Qt::UserRole - 1);
}
void CreateNewVariable::inactivatedStringType(){
    ui->comboBoxType->setItemData(2, 0, Qt::UserRole - 1);
}
bool CreateNewVariable::validate(){
    if (ui->lineEditName->text().trimmed().length() <= 0) {
             return false;
    }
    for (int i = 0; i < allVar.length(); ++i) {
        if (ui->lineEditName->text().trimmed() == allVar.at(i).trimmed()) {
                  return false;
        }
    }
    return true;


}

void CreateNewVariable::on_buttonBox_rejected()
{
    close();
}
