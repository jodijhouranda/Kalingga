#include "parallechart.h"
#include "ui_parallechart.h"
#include <QDebug>
#include <parallelchartconfig.h>
ParalleChart::ParalleChart(VariableView* vv ,RInside &rconn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParalleChart),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    ui->listWidget->addItems(vv->getAllVariableNames());
    setTempFile(rconn);
}

ParalleChart::~ParalleChart()
{
    delete ui;
}

void ParalleChart::on_buttonBox_accepted()
{
    vv->sendDataFrame(rconn);
    choose = ui->listWidget->selectedItems();
    QString ch = getChooseVar(choose);
    ParallelChartConfig* pc = new ParallelChartConfig(this,rconn,ch,vv);
    setupChartView("Parallel Plot","var", pc);
    QString command;
    try {
        command = QString("gr<-ggparcoord(dframe, %1)").arg(ch);
        qDebug()<< command;
        rconn.parseEvalQ(command.toStdString());
        printGraph(rconn);
    } catch (...) {
    }
}

QString ParalleChart::getChooseVar(QList<QListWidgetItem*> list){
    QString var = QString("c(%1)");
    QString arg="";

    if (list.count()>0) {

        for (int i = 0; i < list.count(); ++i) {
            if (i==0) {
                arg += QString::number(vv->getVariableIndex(list.at(i)->text())+1);
            }else {
                arg += ","+ QString::number(vv->getVariableIndex(list.at(i)->text())+1);
            }
        }
    }
    return var.arg(arg);
}
