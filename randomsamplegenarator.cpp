#include "randomsamplegenarator.h"
#include "ui_randomsamplegenarator.h"
#include <variableview.h>
#include <RInside.h>
#include <createnewvariable.h>
RandomSampleGenarator::RandomSampleGenarator(VariableView* vv ,RInside &rconn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomSampleGenarator),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    init();
}

RandomSampleGenarator::~RandomSampleGenarator()
{
    delete ui;
}

void RandomSampleGenarator::init(){
    QList<QString> allVar = vv->getAllVariableNames();
    ui->comboBoxVariables->addItems(allVar);

    distributions << "Gaussian" << "Exponential" << "Poisson" <<"Gamma" << "Weibull"
                             << "Cauchy" << "Beta" << "Student t" << "Fisher-Snedecor" << "Pearson"
                             << "Binomial" <<"Geometric" <<"Hypergeometric" << "Logistic" << "Lognormal"
                             << "Negative Binomial" << "Uniform" << "Wilcoxon";
    ui->comboBoxDistributions->addItems(distributions);
}

void RandomSampleGenarator::on_pushButtonNewVar_clicked()
{
    CreateNewVariable* cnv = new CreateNewVariable(vv ,this );
    cnv->show();
    cnv->updateQCombox(new QListWidget(),ui->comboBoxVariables);
}
