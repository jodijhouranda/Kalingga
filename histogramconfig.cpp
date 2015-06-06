#include "histogramconfig.h"
#include "ui_histogramconfig.h"
#include <QDebug>
#include <QColorDialog>

HistogramConfig::HistogramConfig(HistogramCreator* histo,RInside& rconn, QString var,VariableView* vv,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistogramConfig),
    rconn(rconn),
    histo(histo),
    variable(var),
    vv(vv)
{
    ui->setupUi(this);

    setupUiLoc();


 }
void HistogramConfig::setupUiLoc(){
    setAllVar(vv->getAllVariableNames());
    geomHisto = QString("geom_histogram(%1)");
    geomDensity = QString("geom_density(%1)");
    cp = new QtColorPicker(this);
    cp->setStandardColors();
    ui->verticalLayout->addWidget(cp);
    connect(cp,SIGNAL(colorChanged(QColor)),this,SLOT(setColor(QColor)));

    cpd = new QtColorPicker(this);
    cpd->setStandardColors();
    ui->verticalLayout_cpd->addWidget(cpd);
    connect(cpd,SIGNAL(colorChanged(QColor)),this,SLOT(setColord(QColor)));

    cpfill = new QtColorPicker(this);
    cpfill->setStandardColors();
    ui->verticalLayout_2->addWidget(cpfill);
    connect(cpfill,SIGNAL(colorChanged(QColor)),this,SLOT(setFill(QColor)));

    cpfilld = new QtColorPicker(this);
    cpfilld->setStandardColors();
    ui->verticalLayout_cpdfill->addWidget(cpfilld);
    connect(cpfilld,SIGNAL(colorChanged(QColor)),this,SLOT(setFilld(QColor)));

    double rng = rconn.parseEval(QString("(max(%1)-min(%1))/30").arg(variable).toStdString());
    ui->lineEdit->setText(QString::number(rng));
    ui->lineEdit_Size->setText("0.5");
    ui->lineEdit_Size_Dens->setText("0.5");
    setComboContent(ui->comboBox_2,vv);
    setComboContent(ui->comboBox_WeightDens,vv);
    cp->setVisible(false);
    cpfill->setVisible(false);
    cpd->setVisible(false);
    cpfilld->setVisible(false);
    setComboLineContent(ui->comboBox_linetype,vv);
    setComboLineContent(ui->comboBox_linetype_Dens,vv);
    setComboMap(ui->comboBox_coloraes,vv);
    setComboMap(ui->comboBox_fillaes,vv);
    setComboMap(ui->comboBox_colorDens,vv);
    setComboMap(ui->comboBox_fillDens,vv);
    setKernelContent(ui->comboBox_kernel);
    on_comboBox_activated(0);
}

void HistogramConfig::setColor(QColor color){
    colourh = "colour = \"" + color.name()+"\"";
    drawPlot();
}

void HistogramConfig::setFill(QColor color){
    fillh = "fill = \"" + color.name()+"\"";
    drawPlot();
}
void HistogramConfig::setColord(QColor color){
    colourd = "colour = \"" + color.name()+"\"";
    drawPlot();
}

void HistogramConfig::setFilld(QColor color){
    filld = "fill = \"" + color.name()+"\"";
    drawPlot();
}
HistogramConfig::~HistogramConfig()
{
    delete ui;
}

void HistogramConfig::on_comboBox_currentIndexChanged(int index)
{
drawPlot();
}

void HistogramConfig::setVariable(QString var){
    variable = var;
}

void HistogramConfig::drawPlot(){
    setParorAesHistogram();
    setParorAesDensity();
    QString args = getGraphParameter(par,parAes);
    QString args2= getGraphParameter(par2,parAes2);
    switch (ui->comboBox->currentIndex()) {
    case 0:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1)) + ").arg(variable) + geomHisto.arg(args));
        break;
    case 1:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1)) + ").arg(variable) + geomDensity.arg(args2));
        break;
    case 2:
    setBaseCommand(QString("gr<- ggplot(dframe, aes(x=%1)) + ").arg(variable) + geomHisto.arg(args)+"+"+geomDensity.arg(args2));
        break;
    }
    qDebug() << getBaseCommand();
    try {
        rconn.parseEvalQ(getBaseCommand().toStdString());

        histo->printGraph(rconn);
    } catch (...) {

    }
}




void HistogramConfig::on_lineEdit_editingFinished()
{
    binwidth = "binwidth = " +ui->lineEdit->text();
    drawPlot();
}


void HistogramConfig::on_horizontalSlider_valueChanged(int value)
{
    alphah = "alpha = " +QString::number((double)value/10);
    drawPlot();
}






void HistogramConfig::on_comboBox_2_activated(const QString &arg1)
{
    if (getComboValue(arg1)!="") {

        weighth ="weight = "+ getComboValue(arg1);

    }else {
        weighth ="";

    }
drawPlot();
}



void HistogramConfig::on_comboBox_linetype_activated(const QString &arg1)
{
    if (getComboValue(arg1)!="") {

        linetypeh ="linetype = \""+ getComboValue(arg1)+"\"";

    }else {
        linetypeh ="";

    }
drawPlot();
}

void HistogramConfig::on_lineEdit_Size_editingFinished()
{
    sizeh = "size = " +ui->lineEdit_Size->text();
    drawPlot();
}

void HistogramConfig::on_comboBox_coloraes_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cp->setVisible(true);
        colourh = "colour = \"" + cp->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cp->setVisible(false);
        colourh = "";
    }else {
        cp->setVisible(false);
        colourh = arg1;

    }
    drawPlot();
}


void HistogramConfig::on_comboBox_fillaes_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cpfill->setVisible(true);
        fillh = "fill = \"" + cpfill->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cpfill->setVisible(false);
        fillh = "";
    }else {
        cpfill->setVisible(false);
        fillh = arg1;

    }
    drawPlot();
}
void HistogramConfig::setKernelContent(QComboBox *combo){
    QStringList content;
    content <<"gaussian" << "rectangular" << "triangular" <<"cosine"<<"biweight"
           << "epanechnikov"<<"optcosine";
    combo->addItems(content);
}

void HistogramConfig::setParorAesHistogram(){
    par.clear();
    parAes.clear();
    addParameter(binwidth);
    addParameterAes(colourh , "colour =");
    addParameterAes(fillh,"fill =");
    addParameter(alphah);
    addParameter(linetypeh);
    addParameter(sizeh);
    addParameter(weighth);
}
void HistogramConfig::setParorAesDensity(){
    par2.clear();
    parAes2.clear();
    addParameter2(kerneld);
    addParameter2(adjustd);
    addParameterAes2(colourd, "colour =");
    addParameterAes2(filld, "fill =");
    addParameter2(alphad);
    addParameter2(linetyped);
    addParameter2(sized);
    addParameter2(weightd);
}


void HistogramConfig::on_comboBox_kernel_activated(const QString &arg1)
{
    kerneld = "kernel = \"" +arg1+"\"";
    drawPlot();
}

void HistogramConfig::on_lineEdit_adjust_editingFinished()
{
    adjustd = "adjust = " +ui->lineEdit_adjust->text();
    drawPlot();
}



void HistogramConfig::on_comboBox_colorDens_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cpd->setVisible(true);
        colourd = "colour = \"" + cp->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cpd->setVisible(false);
        colourd = "";
    }else {
        cp->setVisible(false);
        colourd = arg1;

    }
    drawPlot();
}

void HistogramConfig::on_comboBox_fillDens_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cpfilld->setVisible(true);
        filld = "fill = \"" + cpfilld->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cpfilld->setVisible(false);
        filld = "";
    }else {
        cpfilld->setVisible(false);
        filld = arg1;

    }
    drawPlot();
}

void HistogramConfig::on_horizontalSlider_Dens_valueChanged(int value)
{
    alphad = "alpha = " +QString::number((double)value/10);
    drawPlot();
}

void HistogramConfig::on_comboBox_WeightDens_activated(const QString &arg1)
{
    if (getComboValue(arg1)!="") {

        weightd ="weight = "+ getComboValue(arg1);

    }else {
        weightd ="";

    }
drawPlot();
}

void HistogramConfig::on_comboBox_linetype_Dens_activated(const QString &arg1)
{
    if (getComboValue(arg1)!="") {

        linetyped ="linetype = \""+ getComboValue(arg1)+"\"";

    }else {
        linetyped ="";

    }
drawPlot();
}

void HistogramConfig::on_lineEdit_Size_Dens_editingFinished()
{
    sized = "size = " +ui->lineEdit_Size_Dens->text();
    drawPlot();
}

void HistogramConfig::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(false);
        break;
    case 1:
        ui->groupBox->setEnabled(false);
        ui->groupBox_2->setEnabled(true);
        break;
    case 2:
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
        break;
    }
}

void HistogramConfig::on_pushButtonExport_clicked()
{
drawPlot();
exportPlot(parentWidget(),rconn);
}
