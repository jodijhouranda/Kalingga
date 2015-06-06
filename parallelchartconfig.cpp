#include "parallelchartconfig.h"
#include "ui_parallelchartconfig.h"

ParallelChartConfig::ParallelChartConfig(ParalleChart* chart,RInside& rconn,QString var,VariableView* vv,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParallelChartConfig),
    rconn(rconn),
    chart(chart),
    var(var),
    vv(vv)
{
    ui->setupUi(this);
    setupUi();
}

ParallelChartConfig::~ParallelChartConfig()
{
    delete ui;
}
void ParallelChartConfig::setupUi(){
    setComboVariable(ui->comboBox_GroupCoolumn,vv);

    QStringList scl;
    scl << "Default" << "std"<< "robust"<< "uniminmax"<< "globalminmax"
    << "center"<< "centerObs";
    ui->comboBox_Scale->addItems(scl);

    QStringList mis;
    mis << "Default" << "exclude"<<"mean"<<"median"<<"min10"<<"random";
    ui->comboBox_Missing->addItems(mis);

    QStringList ord;
    ord << "Default" << "anyClass"<<"allClass"<<"skewness";
    ui->comboBox_Order->addItems(ord);

    theme = "";
}
void ParallelChartConfig::drawPlot(){

    setParorAesParallel();
    QString args = getGraphParameter(par,parAes);
    setBaseCommand(QString("gr<-ggparcoord(dframe,%1, %2)").arg(var,args)+theme);

    try {
        qDebug() << getBaseCommand();
        rconn.parseEvalQ(getBaseCommand().toStdString());

        chart->printGraph(rconn);
    } catch (...) {

    }
}

void ParallelChartConfig::setParorAesParallel(){
    par.clear();
    addParameter(groupColumn);
    addParameter(scale);
    addParameter(missing);
    addParameter(order);
    addParameter(showPoints);
    addParameter(alphaLines);
    addParameter(boxplot);
    addParameter(tittle);
}

void ParallelChartConfig::on_comboBox_GroupCoolumn_activated(const QString &arg1)
{
    if (arg1 == "Default") {
        groupColumn ="";
    } else {
        groupColumn = "groupColumn = " + QString::number(vv->getVariableIndex(arg1)+1);
    }
    drawPlot();
}

void ParallelChartConfig::on_comboBox_Scale_activated(const QString &arg1)
{
    if (arg1 == "Default") {
        scale ="";
    } else {
        scale = "scale = \"" + arg1+"\"";
    }
    drawPlot();
}

void ParallelChartConfig::on_comboBox_Missing_activated(const QString &arg1)
{
    if (arg1 == "Default") {
        missing ="";
    } else {
        missing = "missing = \"" + arg1+"\"";
    }
    drawPlot();
}

void ParallelChartConfig::on_comboBox_Order_activated(const QString &arg1)
{
    if (arg1 == "Default") {
        order ="";
    } else {
        order= "order = \"" + arg1+"\"";
    }
    drawPlot();
}

void ParallelChartConfig::on_horizontalSliderAlp_valueChanged(int value)
{
    alphaLines = "alphaLines = " +QString::number((double)value/10);
    drawPlot();
}

void ParallelChartConfig::on_checkBox_clicked()
{
    if (!ui->checkBox->isChecked()) {
        boxplot ="";
    } else {
        boxplot= "boxplot = TRUE";
    }
    drawPlot();
}

void ParallelChartConfig::on_checkBox_2_clicked()
{
    if (!ui->checkBox_2->isChecked()) {
        showPoints ="";
    } else {
        showPoints= "showPoints = TRUE";
    }
    drawPlot();
}

void ParallelChartConfig::on_lineEdit_editingFinished()
{
    if (ui->lineEdit->text().trimmed().size()>0) {
        tittle  = "title = \"" + ui->lineEdit->text()+"\"";
    } else {
        tittle = "";
    }
    drawPlot();
}

void ParallelChartConfig::on_checkBox_3_clicked()
{

    if (!ui->checkBox_3->isChecked()) {
        theme  = "+theme_minimal()";
    } else {
        theme = "";
    }
    drawPlot();
}

void ParallelChartConfig::on_pushButtonExport_clicked()
{
    drawPlot();
    exportPlot(parentWidget(),rconn);
}
