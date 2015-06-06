#include "scatterconfig.h"
#include "ui_scatterconfig.h"
#include <QtColorPicker>
#include <QDebug>
ScatterConfig::ScatterConfig(TwoVariablePicker* picker,RInside& rconn,QString x,QString y,VariableView* vv,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScatterConfig),
    rconn(rconn),
    picker(picker),
    x(x),
    y(y),
    vv(vv)
{
    ui->setupUi(this);
    geomPoint = QString("geom_point(%1)");
    geomSmooth = QString("geom_smooth(%1)");
    setupUi();
}

ScatterConfig::~ScatterConfig()
{
    delete ui;
}
void ScatterConfig::setupUi(){
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

    cp->setVisible(false);
    cpfill->setVisible(false);
    cpd->setVisible(false);
    cpfilld->setVisible(false);
    ui->lineEditSize->setVisible(false);
    ui->lineEditSize_2->setVisible(false);
    setComboVariable(ui->comboBox_shape,vv);
    setComboMap(ui->comboBox_color,vv);
    setComboMap(ui->comboBox_fill,vv);
    setComboMap(ui->comboBox_colors,vv);
    setComboMap(ui->comboBox_fills,vv);
    setAllVar(vv->getAllVariableNames());
    setComboSize(ui->comboBox_size,vv);

    QStringList methodList ;
    methodList <<"Default" <<"lm"<<"glm"<<"gam"<<"loess";
    ui->comboBox_method->addItems(methodList);
    setComboLineContent(ui->comboBox_linetype_s,vv);
    setComboSize(ui->comboBox_sizes,vv);
    ui->groupBox_2->setEnabled(false);
}
void ScatterConfig::setColor(QColor color){
    colour = "colour = \"" + color.name()+"\"";
    drawPlot();
}

void ScatterConfig::setFill(QColor color){
    fill = "fill = \"" + color.name()+"\"";
    drawPlot();
}
void ScatterConfig::setColord(QColor color){
    colours = "colour = \"" + color.name()+"\"";
    drawPlot();
}

void ScatterConfig::setFilld(QColor color){
    fills = "fill = \"" + color.name()+"\"";
    drawPlot();
}
void ScatterConfig::drawPlot(){
    setParorAesScatter();
    setParorAesSmooth();
    QString args = getGraphParameter(par,parAes);
    QString args2= getGraphParameter(par2,parAes2);
    switch (ui->comboBox->currentIndex()) {
    case 0:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1,y=%2)) + ").arg(x,y) + geomPoint.arg(args));
        break;
    case 1:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1,y=%2)) + ").arg(x,y) + geomSmooth.arg(args2));
        break;
    case 2:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1,y=%2)) + ").arg(x,y) + geomPoint.arg(args)+"+"+geomSmooth.arg(args2));
        break;
    }
    try {
        qDebug() << getBaseCommand();
        rconn.parseEvalQ(getBaseCommand().toStdString());

        picker->printGraph(rconn);
    } catch (...) {

    }
}
void ScatterConfig::setParorAesScatter(){
    par.clear();
    parAes.clear();
    addParameterAes(shape,"shape =");
    addParameterAes(colour , "colour =");
    addParameterAes(fill,"fill =");
    addParameter(alpha);
    addParameter(position);
    addParameterAes(size,"size =");
}
void ScatterConfig::setParorAesSmooth(){
    par2.clear();
    parAes2.clear();
    addParameter2(methods);
    addParameter2(ses);
    addParameterAes2(colours, "colour =");
    addParameterAes2(fills, "fill =");
    addParameter2(linetypes);
    addParameter2(alphas);
    addParameterAes2(sizes,"size =");
}

void ScatterConfig::on_comboBox_shape_activated(const QString &arg1)
{
    if (arg1 =="Default") {

        shape = "";
    } else {

        shape = arg1;
    }
    drawPlot();
}



void ScatterConfig::on_comboBox_color_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cp->setVisible(true);
        colour = "colour = \"" + cp->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cp->setVisible(false);
        colour = "";
    }else {
        cp->setVisible(false);
        colour = arg1;

    }
    drawPlot();
}

void ScatterConfig::on_comboBox_fill_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cpfill->setVisible(true);
        fill = "fill = \"" + cpfill->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cpfill->setVisible(false);
        fill = "";
    }else {
        cpfill->setVisible(false);
        fill = arg1;

    }
    drawPlot();
}

void ScatterConfig::on_horizontalSliderAlp_valueChanged(int value)
{
    alpha = "alpha = " +QString::number((double)value/10);
    drawPlot();
}

void ScatterConfig::on_comboBox_size_activated(const QString &arg1)
{
    if (arg1 == "Value...") {
        ui->lineEditSize->setVisible(true);
        size = "size = " + ui->lineEditSize->text();
    }else if (arg1 == "Default") {
        ui->lineEditSize->setVisible(false);
        size = "";
    }else {
        ui->lineEditSize->setVisible(false);
        size = arg1;

    }
    drawPlot();
}

void ScatterConfig::on_lineEditSize_editingFinished()
{
    size = "size = "+ui->lineEditSize->text();
    drawPlot();
}



void ScatterConfig::on_comboBox_activated(int index)
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
    drawPlot();
}

void ScatterConfig::on_comboBox_method_activated(int index)
{
    if (index ==0) {
        methods = "";
    } else {
        methods = "method = \""+ui->comboBox_method->currentText()+"\"";
    }
    drawPlot();
}



void ScatterConfig::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        ses = "se = TRUE";
    } else {
        ses = "se = FALSE";
    }
    drawPlot();
}

void ScatterConfig::on_comboBox_colors_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cpd->setVisible(true);
        colours = "colour = \"" + cp->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cpd->setVisible(false);
        colours = "";
    }else {
        cpd->setVisible(false);
        colours = arg1;

    }
    drawPlot();
}

void ScatterConfig::on_comboBox_fills_activated(const QString &arg1)
{
    if (arg1 == "Colour") {
        cpfilld->setVisible(true);
        fills = "fill = \"" + cpfill->currentColor().name()+"\"";
    }else if (arg1 == "Default") {
        cpfilld->setVisible(false);
        fills = "";
    }else {
        cpfilld->setVisible(false);
        fills = arg1;

    }
    drawPlot();
}

void ScatterConfig::on_horizontalSlider_smot_valueChanged(int value)
{
    alphas = "alpha = " +QString::number((double)value/10);
    drawPlot();
}



void ScatterConfig::on_comboBox_linetype_s_activated(const QString &arg1)
{
    if (getComboValue(arg1)!="") {

        linetypes ="linetype = \""+ getComboValue(arg1)+"\"";

    }else {
        linetypes ="";

    }
drawPlot();
}

void ScatterConfig::on_comboBox_sizes_activated(const QString &arg1)
{

    if (arg1 == "Value...") {
        ui->lineEditSize_2->setVisible(true);
        sizes = "size = " + ui->lineEditSize->text();
    }else if (arg1 == "Default") {
        ui->lineEditSize_2->setVisible(false);
        sizes = "";
    }else {
        ui->lineEditSize_2->setVisible(false);
        sizes = arg1;

    }
    drawPlot();
}

void ScatterConfig::on_lineEditSize_2_editingFinished()
{
    sizes = "size = "+ui->lineEditSize_2->text();
    drawPlot();
}

void ScatterConfig::on_pushButtonExport_clicked()
{
    drawPlot();
    exportPlot(parentWidget(),rconn);
}
