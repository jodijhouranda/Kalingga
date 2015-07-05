#include "maptematikstandarddeviation.h"

#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>

MapTematikStandardDeviation::MapTematikStandardDeviation(MapView *mview, RInside& rconn, VariableView *vv, QString var):
    MapTematik(mview, rconn, vv, var)
{

}

MapTematikStandardDeviation::~MapTematikStandardDeviation()
{

}

void MapTematikStandardDeviation::createMapTematikStandardDeviation()
{
    double m, sd;
    QString command;

    try {
        command = QString("m <- mean(dframe[[\"%1\"]]); "
                          "sd <- sd(dframe[[\"%2\"]]);").arg(var).arg(var);
        rconn.parseEvalQ(command.toStdString());
        m = rconn["m"];
        sd = rconn["sd"];
    } catch (...) {

    }

    QList<double> standDev ;
    standDev.append(m-2*sd);
    standDev.append(m-sd);
    standDev.append(m);
    standDev.append(m+sd);
    standDev.append(m+2*sd);

    QList<int> temp[6];

    for(int i=0; i<numvar.size(); i++){
        if(numvar[i] < standDev[0]){
            temp[0].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] >= standDev[0] && numvar[i] <= standDev[1]){
            temp[1].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > standDev[1] && numvar[i] <= standDev[2]){
            temp[2].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > standDev[2] && numvar[i] <= standDev[3]){
            temp[3].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > standDev[3] && numvar[i] <= standDev[4]){
            temp[4].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > standDev[4]){
            temp[5].append(table->verticalHeaderItem(i)->text().toInt());
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<6; i++){
        temp2.append(temp[i]);
    }

    for(int i=0; i<=standDev.size(); i++){
        mviewResult->filterItem(temp[i],listColor.value(i));
    }

    MapTematikConfig* mapconf = new MapTematikConfig(mviewResult,vv,rconn,temp2,var);
    setupResultViewVariableChooser("Standard Deviation Map",var, mapconf);
}
