#include "boxconfig.h"
#include "ui_boxconfig.h"
#include <QtColorPicker>
#include <QDebug>
BoxConfig::BoxConfig(TwoVariablePicker* picker,RInside& rconn,QString x,QString y,VariableView* vv,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoxConfig),
    rconn(rconn),
    picker(picker),
    x(x),
    y(y),
    vv(vv)
{
    ui->setupUi(this);
    geomBox = QString("geom_boxplot(%1)");
    geomJitter= QString("geom_jitter()");
    flipcord= QString("coord_flip()");
    setupUi();
}

BoxConfig::~BoxConfig()
{
    delete ui;
}
void BoxConfig::setupUi(){
    cp = new QtColorPicker(this);
    cp->setStandardColors();
    ui->verticalLayout->addWidget(cp);
    connect(cp,SIGNAL(colorChanged(QColor)),this,SLOT(setColor(QColor)));

    cpfill = new QtColorPicker(this);
    cpfill->setStandardColors();
    ui->verticalLayout_2->addWidget(cpfill);
    connect(cpfill,SIGNAL(colorChanged(QColor)),this,SLOT(setFill(QColor)));

    cpout = new QtColorPicker(this);
    cpout->setStandardColors();
    ui->verticalLayoutout->addWidget(cpout);
    connect(cpout,SIGNAL(colorChanged(QColor)),this,SLOT(setColorout(QColor)));


    cpfill->setVisible(false);
    ui->lineEditSize->setVisible(false);
    setComboMap(ui->comboBox_color,vv);
    setComboMap(ui->comboBox_fill,vv);
    setComboContent(ui->comboBox_weight,vv);
    setAllVar(vv->getAllVariableNames());
    setComboSize(ui->comboBox_size,vv);
}
void BoxConfig::setColor(QColor color){
    colour = "colour = \"" + color.name()+"\"";
    drawPlot();
}

void BoxConfig::setFill(QColor color){
    fill = "fill = \"" + color.name()+"\"";
    drawPlot();
}
void BoxConfig::setColorout(QColor color){
    outliercolor = "outlier.colour  = \"" + color.name()+"\"";
    drawPlot();
}
void BoxConfig::drawPlot(){
  setParorAesBoxplot();
    QString args = getGraphParameter(par,parAes);
    if (ui->checkBox->isChecked() && !ui->checkBox_flip->isChecked()) {
        setBaseCommand(QString("gr<-ggplot(dframe, aes(factor(%1), %2))").arg(x,y) +"+"+ geomBox.arg(args)+"+"+geomJitter);

    } else if (!ui->checkBox->isChecked() && ui->checkBox_flip->isChecked()) {
        setBaseCommand(QString("gr<-ggplot(dframe, aes(factor(%1), %2))").arg(x,y) +"+"+ geomBox.arg(args)+"+"+flipcord);

    }else if (ui->checkBox->isChecked() && ui->checkBox_flip->isChecked()) {
        setBaseCommand(QString("gr<-ggplot(dframe, aes(factor(%1), %2))").arg(x,y) +"+"+ geomBox.arg(args)+"+"+geomJitter+"+"+flipcord);

    }else {
        setBaseCommand(QString("gr<-ggplot(dframe, aes(factor(%1), %2))").arg(x,y) +"+"+ geomBox.arg(args));

    }
    try {
        qDebug() << getBaseCommand();
        rconn.parseEvalQ(getBaseCommand().toStdString());
        picker->printGraph(rconn);
    } catch (...) {

    }
}
void BoxConfig::setParorAesBoxplot(){
    par.clear();
    parAes.clear();
    addParameterAes(weight,"weight =");
    addParameterAes(colour , "colour =");
    addParameterAes(fill,"fill =");
    addParameter(alpha);
    addParameterAes(size,"size =");
    addParameter(notch);
    addParameter(outliercolor);
    addParameter(outliersize);
}


void BoxConfig::on_comboBox_color_activated(const QString &arg1)
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

void BoxConfig::on_comboBox_fill_activated(const QString &arg1)
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

void BoxConfig::on_comboBox_weight_activated(const QString &arg1)
{
    if (getComboValue(arg1)!="") {

        weight ="weight = "+ getComboValue(arg1);

    }else {
        weight ="";

    }
drawPlot();
}

void BoxConfig::on_horizontalSliderAlp_valueChanged(int value)
{
    alpha = "alpha = " +QString::number((double)value/10);
    drawPlot();
}

void BoxConfig::on_comboBox_size_activated(const QString &arg1)
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

void BoxConfig::on_lineEditSize_editingFinished()
{
    size = "size = "+ui->lineEditSize->text();
    drawPlot();
}

void BoxConfig::on_checkBox_clicked()
{
    drawPlot();
}

void BoxConfig::on_checkBox_flip_clicked()
{
    drawPlot();
}

void BoxConfig::on_checkBox_notch_clicked()
{
    if (ui->checkBox_notch->isChecked()) {
        notch = "notch = TRUE";
    } else {
        notch = "notch = FALSE";
    }
    drawPlot();
}

void BoxConfig::on_lineEditSize_2_editingFinished()
{
    outliersize = "outlier.size = "+ui->lineEditSize_2->text();
    drawPlot();
}

void BoxConfig::on_pushButtonExport_clicked()
{
    drawPlot();
    exportPlot(parentWidget(),rconn);
}
