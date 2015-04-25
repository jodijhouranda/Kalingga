#include "createnewvariable.h"
#include "ui_createnewvariable.h"
#include <QDebug>
CreateNewVariable::CreateNewVariable( VariableView* vv,QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::CreateNewVariable),
    vv(vv)
{
    ui->setupUi(this);
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
    if (m_listwidget->isEnabled()) {
        m_combo->insertItem(0,ui->lineEditName->text());
        m_listwidget->insertItem(0,ui->lineEditName->text());
        m_combo->setCurrentIndex(0);
    }

}

void CreateNewVariable::updateQCombox(QListWidget* listwidget , QComboBox* combo){
    m_listwidget = listwidget;
    m_combo = combo;
}

