#include "randomsamplegenerator.h"
#include "ui_randomsamplegenerator.h"

randomSampleGenerator::randomSampleGenerator(VariableView* vv ,RInside &rconn, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::randomSampleGenerator),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    init();
}

randomSampleGenerator::~randomSampleGenerator()
{
    delete ui;
}

void randomSampleGenerator::init(){
    QList<QString> allVar = vv->getNumericVariableNames();;
    ui->comboBoxVariables->addItems(allVar);
}
