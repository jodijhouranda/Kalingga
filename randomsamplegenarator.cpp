#include "randomsamplegenarator.h"
#include "ui_randomsamplegenarator.h"
#include <variableview.h>
#include <RInside.h>
#include <createnewvariable.h>
#include <QDebug>
#include <QMessageBox>
RandomSampleGenarator::RandomSampleGenarator(VariableView* vv ,RInside &rconn,QWidget *parent) :
    QDialog(parent),
    ui(
new Ui::RandomSampleGenarator),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    init();
    numPar = 2;
    setTwoParameterView("Mean" , "Standard Deviation");
}

RandomSampleGenarator::~RandomSampleGenarator()
{
    delete ui;
}

void RandomSampleGenarator::init(){
    QList<QString> allVar = vv->getRealVariableNames();
    ui->comboBoxVariables->addItems(allVar);

    distributions << "Gaussian" << "Exponential" << "Poisson" <<"Gamma" << "Weibull"
                             << "Cauchy" << "Beta" << "Student t" << "Fisher-Snedecor" << "Pearson"
                             << "Binomial" <<"Geometric" << "Logistic" << "Lognormal"
                             << "Negative Binomial" << "Uniform" ;
    ui->comboBoxDistributions->addItems(distributions);

    nRow = vv->getRowCount();
    command = QString("rnorm(%1,%2,%3)");
}

void RandomSampleGenarator::on_pushButtonNewVar_clicked()
{
    CreateNewVariable* cnv = new CreateNewVariable(vv ,this );
    cnv->inactivatedIntegerType();
    cnv->inactivatedStringType();
    cnv->show();

    cnv->updateQCombox(new QListWidget(),ui->comboBoxVariables);

}

void RandomSampleGenarator::on_comboBoxDistributions_activated(const QString &arg1)
{
    ui->firstParameter->setText("");
    ui->secondParameter->setText("");
    ui->thirdParameter->setText("");
    if (arg1 == "Gaussian") {
    numPar = 2;
    setTwoParameterView("Mean" , "Standard Deviation");
    command = QString("rnorm(%1,%2,%3)");
    }else if (arg1 == "Exponential") {
        numPar = 1;
        setOneParameterView("Rate");
        command = QString("rexp(%1,%2)");
    }else if (arg1 == "Gamma") {
        numPar = 2;
        setTwoParameterView("Shape" , "Scale");
        command = QString("rgamma(%1,%2,%3)");
    }else if (arg1 == "Poisson") {
        numPar = 1;
        setOneParameterView("Lamda");
        command = QString("rpois(%1,%2)");
    }else if (arg1 == "Weibull") {
        numPar = 2;
        setTwoParameterView("Shape" , "Scale");
        command = QString("rweibull(%1,%2,%3)");
    }else if (arg1 == "Cauchy") {
        numPar = 2;
        setTwoParameterView("Location" , "Scale");
        command = QString("rcauchy(%1,%2,%3)");
    }else if (arg1 == "Beta") {
        numPar = 2;
        setTwoParameterView("Shape 1" , "Shape 2");
        command = QString("rbeta(%1,%2,%3)");
    }else if (arg1 == "Student t") {
        numPar = 1;
        setOneParameterView("Dof");
        command = QString("rt(%1,%2)");
    }else if (arg1 == "Fisher-Snedecor") {
        numPar = 2;
        setTwoParameterView("Dof 1" , "Dof 2");
        command = QString("rf(%1,%2,%3)");
    }else if (arg1 == "Pearson") {
        numPar = 1;
        setOneParameterView("Dof");
        command = QString("rchisq(%1,%2)");
    }else if (arg1 == "Binomial") {
        numPar = 2;
        setTwoParameterView("Size" , "Probability");
        command = QString("rbinom(%1,%2,%3)");
    }else if (arg1 == "Geometric") {
        numPar = 1;
        setOneParameterView("Probability");
        command = QString("rgeom(%1,%2)");
    }else if (arg1 == "Logistic") {
        numPar = 2;
        setTwoParameterView("Location" , "Scale");
    command = QString("rlogis(%1,%2,%3)");
    }else if (arg1 == "Lognormal") {
        numPar = 2;
        setTwoParameterView("Meanlog" , "Sdlog");
        command = QString("rlnorm(%1,%2,%3)");
    }else if (arg1 == "Negative Binomial") {
        numPar = 2;
        setTwoParameterView("Size" , "Probability");
        command = QString("rnbinom(%1,%2,%3)");
    }else if (arg1 == "Uniform") {
        numPar = 2;
        setTwoParameterView("Min" , "Max");
        command = QString("runif(%1,%2,%3)");
    }
}
 void RandomSampleGenarator::hideThirdLayout(){
    setUpdatesEnabled(true);
     ui->thirdLabel->setVisible(false);
     ui->thirdParameter->setVisible(false);

 }
 void RandomSampleGenarator::hideSecondLayout(){
     setUpdatesEnabled(true);
     ui->secondLabel->setVisible(false);
     ui->secondParameter->setVisible(false);

 }
 void RandomSampleGenarator::showThirdLayout(){
     setUpdatesEnabled(true);
     ui->thirdLabel->setVisible(true);
     ui->thirdParameter->setVisible(true);

 }
 void RandomSampleGenarator::showSecondLayout(){
     setUpdatesEnabled(true);
     ui->secondLabel->setVisible(true);
     ui->secondParameter->setVisible(true);

 }
void RandomSampleGenarator::setOneParameterView(QString par1){
    hideSecondLayout();
    hideThirdLayout();
   ui->firstLabel->setText(par1);
}

void RandomSampleGenarator::setTwoParameterView(QString par1, QString par2){
    hideThirdLayout();
    showSecondLayout();
    ui->firstLabel->setText(par1);
    ui->secondLabel->setText(par2);
}

void RandomSampleGenarator::setThreeParameterView(QString par1, QString par2, QString par3){
    showSecondLayout();
    showThirdLayout();
}



void RandomSampleGenarator::on_pushButtonApply_clicked()
{
    QString cmdPar;
    switch (numPar) {
    case 1:
        cmdPar = command.arg(QString::number(nRow),ui->firstParameter->text());
        break;
    case 2:
        cmdPar = command.arg(QString::number(nRow),ui->firstParameter->text(),ui->secondParameter->text());
        break;

    case 3:
        cmdPar = command.arg(QString::number(nRow),ui->firstParameter->text(),ui->secondParameter->text(),ui->thirdParameter->text());
        break;
    }
    try {
        Rcpp::NumericVector x = rconn.parseEval(cmdPar.toStdString());
        vv->setNumericVariable(ui->comboBoxVariables->itemText(ui->comboBoxVariables->currentIndex()),x);



    } catch (std::exception& ex) {

        QMessageBox x;
        x.critical(this , "Generating Error" , "Please insert real number into paramater.");
    }
}

void RandomSampleGenarator::on_pushButtonCancel_clicked()
{
    RandomSampleGenarator::close();
}
