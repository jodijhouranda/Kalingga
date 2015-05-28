#include "createnewvariable.h"
#include "ui_createnewvariable.h"
#include <QDebug>
CreateNewVariable::CreateNewVariable( VariableView* vv,QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::CreateNewVariable),
    vv(vv)
{
    ui->setupUi(this);

    TEST = false;
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
    vv->createNewVariable(name,type,label);  
    if (TEST) {
        m_combo->insertItem(0,ui->lineEditName->text());
        m_listwidget->insertItem(0,ui->lineEditName->text());
        m_combo->setCurrentIndex(0);
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



