#include "computevariable.h"
#include "ui_computevariable.h"
#include <createnewvariable.h>
#include <QDebug>
#include <QTextCursor>
#include <QMessageBox>
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
    ui->formulaText->setReadOnly(false);
    functionGroup <<  "Math" << "Statistics" << "Trigonometry";
    ui->comboBoxFGroup->addItems(functionGroup);
    trigonometryMap.insert("sin" , "sin(var)");
    trigonometryMap.insert("cos" , "cos(var)");
    trigonometryMap.insert("tan" , "tan(var)");
    trigonometryMap.insert("asin" , "asin(var)");
    trigonometryMap.insert("acos" , "acos(var)");
    trigonometryMap.insert("atan" , "atan(var)");
    trigonometryMap.insert("atan2" , "atan2(var)");
    trigonometryMap.insert("log" , "log(var)");
    trigonometryMap.insert("log10" , "log10(var)");
    trigonometryMap.insert("exponensial" , "exp(var)");

    mathMap.insert("Maximum","max(var)");
    mathMap.insert("Minimum","min(var)");
    mathMap.insert("Sum","sum(var)");
    mathMap.insert("Product","prod(var)");
    mathMap.insert("Cummulative Sum","cumsum(var)");
    mathMap.insert("Cummulative Product","cumprod(var)");
    mathMap.insert("Cummulative Minimum","cummin(var)");
    mathMap.insert("Cumulative Maximum","cummax(var)");
    mathMap.insert("Real","Re(var)");
    mathMap.insert("Imaginary","Im(var)");
    mathMap.insert("Modulus","Mod(var)");
    mathMap.insert("Angel In Radian","Arg(var)");
    mathMap.insert("Fast Fourier Transform","fft(var)");

    statisticMap.insert("Range","range(var)");
    statisticMap.insert("Mean","mean(var)");
    statisticMap.insert("Median","median(var)");
    statisticMap.insert("Varians","var(var)");
    statisticMap.insert("Standard Deviation","sd(var)");
    ui->listWidgetfunction->addItems(mathMap.keys());

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
    ui->formulaText->textCursor().deletePreviousChar();
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


     ui->formulaText->textCursor().insertText(string);


}

void ComputeVariable::on_listWidgetVariables_itemDoubleClicked(QListWidgetItem *item)
{
    setFormulaViewText(item->text());
    QTextCursor x = ui->formulaText->textCursor();
    x.movePosition(QTextCursor::NextWord,QTextCursor::MoveAnchor);
    ui->formulaText->setTextCursor(x);
}




void ComputeVariable::on_pushButtonApply_clicked()
{
    QString typeChoosen = vv->getVariableType(ui->comboBoxVariables->currentText());

    if (ui->formulaText->toPlainText().replace(" ","").length()==0) {
        return;
    }
    QList<QString> var = getChoosenAttribute();
    if (var.count()>0) {
        for (int i = 0; i <  var.count(); ++i) {
            rconn[var.at(i).toStdString()] = vv->getNumericVectorIgnoreNa(vv->getVariableIndex(var.at(i)));
        }
    }

        try {
        Rcpp::NumericVector compu = rconn.parseEval(ui->formulaText->toPlainText().replace(" ","").toStdString());
            if (typeChoosen == "String") {
                if (var.count()==0 || compu.length()==1) {
                    double computed = rconn.parseEval(ui->formulaText->toPlainText().replace(" ","").toStdString());
                    vv->setConstantVariable(ui->comboBoxVariables->itemText(ui->comboBoxVariables->currentIndex()),computed);
                }else {
                    Rcpp::NumericVector computed = rconn.parseEval(ui->formulaText->toPlainText().replace(" ","").toStdString());
                    vv->setCharacterVariable(ui->comboBoxVariables->itemText(ui->comboBoxVariables->currentIndex()),computed);
                }


            }else if (var.count()==0 || compu.length()==1) {

                double computed = rconn.parseEval(ui->formulaText->toPlainText().replace(" ","").toStdString());
                vv->setConstantVariable(ui->comboBoxVariables->itemText(ui->comboBoxVariables->currentIndex()),computed);
                }
            else {
                Rcpp::NumericVector computed = rconn.parseEval(ui->formulaText->toPlainText().replace(" ","").toStdString());
                vv->setNumericVariable(ui->comboBoxVariables->itemText(ui->comboBoxVariables->currentIndex()),computed);

            }
            } catch (std::exception& ex) {

            QMessageBox x;
            x.critical(this , "Formula error" , ex.what());
        }
    }




void ComputeVariable::on_pushButtonCancel_clicked()
{
    ComputeVariable::close();
}

QList<QString> ComputeVariable::getChoosenAttribute(){
    QList<QString> var = vv->getNumericVariableNames();
    QRegExp rx("(\\-|\\+|\\/|\\*|\\(|\\)|\\^)");
    QList<QString> fromText = ui->formulaText->toPlainText().replace(" ", "").split(rx);

    QStringList toturn;

    for (int i = 0; i < fromText.count() ; ++i) {
        for (int j = 0; j < var.count(); ++j) {
            if (var.at(j) == fromText.at(i)) {
                toturn << fromText.at(i);
                continue;
            }
        }
    }
    toturn.removeDuplicates();
    return toturn;
}

void ComputeVariable::on_pushButtonlbrac_clicked()
{
    setFormulaViewText("(");
}

void ComputeVariable::on_pushButtonrbrac_clicked()
{
    setFormulaViewText(")");
}




void ComputeVariable::on_listWidgetfunction_doubleClicked(const QModelIndex &index)
{

    switch (ui->comboBoxFGroup->currentIndex()) {
    case 0:
        setFormulaViewText(mathMap[ui->listWidgetfunction->item(index.row())->text()]);
        break;
    case 1:
        setFormulaViewText(statisticMap[ui->listWidgetfunction->item(index.row())->text()]);
        break;
    case 2:
       setFormulaViewText(trigonometryMap[ui->listWidgetfunction->item(index.row())->text()]);
        break;
    }
    QTextCursor c = ui->formulaText->textCursor();
     c.setPosition(c.position()-1);
     c.setPosition(c.position()-3, QTextCursor::KeepAnchor);
    ui->formulaText->setTextCursor(c);
    ui->formulaText->setFocus();
}




void ComputeVariable::on_comboBoxFGroup_currentIndexChanged(int index)
{
    while (ui->listWidgetfunction->count()>0 ) {
      ui->listWidgetfunction->takeItem(0);
    }
    switch (index) {
    case 0:
        ui->listWidgetfunction->addItems(mathMap.keys());
        break;
    case 1:
        ui->listWidgetfunction->addItems(statisticMap.keys());
        break;
    case 2:
        ui->listWidgetfunction->addItems(trigonometryMap.keys());
        break;
    }
}

void ComputeVariable::on_pushButtondelete_2_clicked()
{
    setFormulaViewText("^");
}
