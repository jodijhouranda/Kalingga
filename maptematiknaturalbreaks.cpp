#include "maptematiknaturalbreaks.h"

#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>

MapTematikNaturalBreaks::MapTematikNaturalBreaks(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap):
    MapTematik(mview, rconn, vv, var, typeMap)
{

}

MapTematikNaturalBreaks::~MapTematikNaturalBreaks()
{

}

void MapTematikNaturalBreaks::createMapTematikNaturalBreaks()
{
    Rcpp::NumericVector naturalBreaks ;

    QString command;
    try {
        command = QString("n <- classIntervals(dframe[[\"%1\"]], n=%2, style=\"jenks\"); "
                          "nat <- n[[2]];").arg(var).arg(typeMap);
        rconn.parseEvalQ(command.toStdString());

        naturalBreaks =  rconn["nat"];
    } catch (...) {

    }

    QList<int> temp[naturalBreaks.size()-1];

    for(int i=0; i<numvar.size(); i++){
        if(numvar[i] <= naturalBreaks[1]){
            temp[0].append(table->verticalHeaderItem(i)->text().toInt());
        }else{
            for(int j=2; j<naturalBreaks.size(); j++){
                if(numvar[i] > naturalBreaks[j-1] && numvar[i] <= naturalBreaks[j]){
                    temp[j-1].append(table->verticalHeaderItem(i)->text().toInt());
                }
            }
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<naturalBreaks.size()-1; i++){
        temp2.append(temp[i]);
    }

    MapTematikConfig* configWidget = new MapTematikConfig(mviewResult,vv,rconn,temp2,var,typeMap.toInt());
    setupResultViewVariableTypeChooser("Natural Breaks",var, temp2,naturalBreaks,configWidget);
}

