#include "maptematikquantile.h"

#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>

MapTematikQuantile::MapTematikQuantile(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap):
    MapTematik(mview, rconn, vv, var, typeMap)
{

}

MapTematikQuantile::~MapTematikQuantile()
{

}

void MapTematikQuantile::createMapTematikQuantile()
{
    Rcpp::NumericVector quantile ;
    QString command;
    try {
        command = QString("q <- quantile(dframe[[\"%1\"]], prob = seq(0, 1, length = (%2 + 1)), type = 7);").arg(var).arg(typeMap);
        rconn.parseEvalQ(command.toStdString());

        quantile =  rconn["q"];
    } catch (...) {

    }

    QList<int> temp[quantile.size()-1];

    for(int i=0; i<numvar.size(); i++){
        if(numvar[i] <= quantile[1]){
            temp[0].append(table->verticalHeaderItem(i)->text().toInt());
        }else{
            for(int j=2; j<quantile.size(); j++){
                if(numvar[i] > quantile[j-1] && numvar[i] <= quantile[j]){
                    temp[j-1].append(table->verticalHeaderItem(i)->text().toInt());
                }
            }
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<quantile.size()-1; i++){
        temp2.append(temp[i]);
    }

    MapTematikConfig* configWidget = new MapTematikConfig(mviewResult,vv,rconn,temp2,var,typeMap.toInt());
    setupResultViewVariableTypeChooser("Quantile Map",var, temp2,quantile,configWidget);
}

