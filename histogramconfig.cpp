#include "histogramconfig.h"
#include "ui_histogramconfig.h"
#include <QDebug>
#include <QColorDialog>
HistogramConfig::HistogramConfig(HistogramCreator* histo,RInside& rconn,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistogramConfig),
    rconn(rconn),
    histo(histo)
{
    ui->setupUi(this);
    geomHisto = QString("geom_histogram(%1)");
    geomDensity = QString("geom_density(%1)");

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
    par.clear();
    if (binwidth.size()>0) {
       par << binwidth;
    }
    QString aesIterator ="";
    QString args= "";
    if (parAes.size()>0) {
        for (int i = 0; i < parAes.size(); ++i) {
            if (i==0) {
                args += parAes.at(i);
            }
            aesIterator += ("," + parAes.at(i));

        }
    }
    QString aess= QString("aes(%1)").arg(aesIterator);

        if (par.size()>0) {
            for (int i = 0; i < par.size(); ++i) {
                if (i==0) {
                    args += par.at(i);
                }else {

                    args += ("," + par.at(i));
                }

            }
            if (parAes.size()>0) {
                args += ("," +aess);
            }

        }else if(par.size()<=0 && parAes.size()>0){
            args = aess;
        }
    qDebug() <<args;
    switch (ui->comboBox->currentIndex()) {
    case 0:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1)) + ").arg(variable) + geomHisto.arg(args));
        break;
    case 1:
    setBaseCommand(QString("gr<-ggplot(dframe, aes(x=%1)) + ").arg(variable) + geomHisto.arg(args));
        break;
    case 2:
    setBaseCommand(QString("gr<- ggplot(dframe, aes(x=%1)) + ").arg(variable) + geomHisto.arg(args));
        break;
    }
    qDebug() << getBaseCommand();
    rconn.parseEvalQ(getBaseCommand().toStdString());

    histo->printGraph(rconn);
}



void HistogramConfig::on_spinBoxBinwidth_valueChanged(int arg1)
{

    rconn.parseEvalQ(QString("rng <- (max(%1)-min(%1))").arg(variable).toStdString());
    binwidth = "binwidth = rng/30 + ((1/3000)*rng)*" + QString::number(arg1-50);
    drawPlot();
}
