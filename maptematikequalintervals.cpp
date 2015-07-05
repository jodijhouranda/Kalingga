#include "maptematikequalintervals.h"

#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>

MapTematikEqualIntervals::MapTematikEqualIntervals(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap):
    MapTematik(mview, rconn, vv, var, typeMap)
{

}

MapTematikEqualIntervals::~MapTematikEqualIntervals()
{

}

void MapTematikEqualIntervals::createMapTematikEqualValues()
{
    Rcpp::NumericVector equal ;
    QString command;
    try {
        command = QString("e <- classIntervals(dframe[[\"%1\"]], n=%2, style=\"equal\"); "
                          "eq <- e[[2]];").arg(var).arg(typeMap);
        rconn.parseEvalQ(command.toStdString());

        equal =  rconn["eq"];
    } catch (...) {

    }

    QList<int> temp[equal.size()-1];

    for(int i=0; i<numvar.size(); i++){
        if(numvar[i] <= equal[1]){
            temp[0].append(table->verticalHeaderItem(i)->text().toInt());
        }else{
            for(int j=2; j<equal.size(); j++){
                if(numvar[i] > equal[j-1] && numvar[i] <= equal[j]){
                    temp[j-1].append(table->verticalHeaderItem(i)->text().toInt());
                }
            }
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<equal.size()-1; i++){
        temp2.append(temp[i]);
    }

    MapTematikConfig* configWidget = new MapTematikConfig(mviewResult,vv,rconn,temp2,var,typeMap.toInt());
    setupResultViewVariableTypeChooser("Equal Intervals",var, temp2,equal,configWidget);
}

