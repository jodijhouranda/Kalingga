#include "computevariable.h"
#include "ui_computevariable.h"
#include <createnewvariable.h>
#include <QDebug>
#include <QTextCursor>
ComputeVariable::ComputeVariable(VariableView* vv ,RInside &rconn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputeVariable),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    init();
}

ComputeVariable::~ComputeVariable()
{
    delete ui;
}

void ComputeVariable::init(){
    QList<QString> allVar = vv->getNumericVariableNames();
    ui->listWidgetVariables->addItems(allVar);
    ui->comboBoxVariables->addItems(allVar);


}

void ComputeVariable::on_pushButtonNewVar_clicked()
{
    CreateNewVariable* cnv = new CreateNewVariable(vv ,this );

    cnv->show();
    cnv->updateQCombox(ui->listWidgetVariables,ui->comboBoxVariables);

}

void ComputeVariable::on_pushButton1_clicked()
{
   setFormulaViewText("1");
}

void ComputeVariable::on_pushButton1_2_clicked()
{
    setFormulaViewText("2");
}

void ComputeVariable::on_pushButton1_3_clicked()
{
    setFormulaViewText("3");
}

void ComputeVariable::on_pushButton1_4_clicked()
{
    setFormulaViewText("4");
}

void ComputeVariable::on_pushButton1_5_clicked()
{
    setFormulaViewText("5");
}

void ComputeVariable::on_pushButton1_6_clicked()

{
    setFormulaViewText("6");
}

void ComputeVariable::on_pushButton1_7_clicked()
{
    setFormulaViewText("7");
}

void ComputeVariable::on_pushButton1_8_clicked()
{
   setFormulaViewText("8");
}

void ComputeVariable::on_pushButton1_9_clicked()
{
    setFormulaViewText("9");
}

void ComputeVariable::on_pushButton1_0_clicked()
{
    setFormulaViewText("0");
}

void ComputeVariable::on_pushButtonPoint_clicked()
{
    setFormulaViewText(".");
}

void ComputeVariable::on_pushButtondelete_clicked()
{
}

void ComputeVariable::on_pushButtonplus_clicked()
{
   setFormulaViewText(" + ");
}

void ComputeVariable::on_pushButtonsubtract_clicked()
{
    setFormulaViewText(" - ");
}
void ComputeVariable::on_pushButtonMultiply_clicked()
{
    setFormulaViewText(" * ");
}

void ComputeVariable::on_pushButtonDevide_clicked()
{
    setFormulaViewText(" / ");
}

void ComputeVariable::setFormulaViewText(QString string){

    ui->formulaText->moveCursor(QTextCursor::End);
     ui->formulaText->textCursor().insertText(string);
     ui->formulaText->moveCursor(QTextCursor::End);

}

void ComputeVariable::on_listWidgetVariables_itemDoubleClicked(QListWidgetItem *item)
{
    setFormulaViewText(item->text());
    ui->listWidgetVariables->removeItemWidget(item);
   delete  ui->listWidgetVariables->item(ui->listWidgetVariables->currentIndex().row());
}



void ComputeVariable::on_pushButtonApply_clicked()
{
    QList<QString> var = getChoosenAttribute();
    for (int i = 0; i <  var.count(); ++i) {
        rconn[var.at(i).toStdString()] = vv->getNumericVector(vv->getVariableIndex(var.at(i)));
    }

    Rcpp::NumericVector computed = rconn.parseEval(ui->formulaText->toPlainText().toStdString());
    vv->setNumericVariable(ui->comboBoxVariables->itemText(ui->comboBoxVariables->currentIndex()),computed);
}

void ComputeVariable::on_pushButtonCancel_clicked()
{
    ComputeVariable::close();
}

QList<QString> ComputeVariable::getChoosenAttribute(){
    QList<QString> var = vv->getNumericVariableNames();
    QList<QString> toturn = vv->getNumericVariableNames();
    int last = ui->listWidgetVariables->count();

    for (int i = 0; i <last ; ++i) {
        for (int j = 0; j < var.count(); ++j) {
            if (var.at(j)== ui->listWidgetVariables->item(i)->text()) {
                toturn.removeAt(var.indexOf(var.at(j)));
            }
        }
    }
    return toturn;
}
