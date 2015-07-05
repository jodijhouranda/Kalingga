#include "maptematikboxmap.h"

#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>

MapTematikBoxMap::MapTematikBoxMap(MapView *mview, RInside& rconn, VariableView *vv, QString var):
    MapTematik(mview, rconn, vv, var)
{

}

MapTematikBoxMap::~MapTematikBoxMap()
{

}

void MapTematikBoxMap::createMapTematikBoxmap()
{
    Rcpp::NumericVector boxmap ;
    QString command;
    try {
        command = QString("b <- boxplot(dframe[[\"%1\"]]); "
                          "b <- as.vector(b$stats);"
                          "graphics.off()").arg(var);
        rconn.parseEvalQ(command.toStdString());

        boxmap =  rconn["b"];
    } catch (...) {

    }

    QList<int> temp[6];

    for(int i=0; i<numvar.size(); i++){
        if(numvar[i] < boxmap[0]){
            temp[0].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] >= boxmap[0] && numvar[i] < boxmap[1]){
            temp[1].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] >= boxmap[1] && numvar[i] < boxmap[2]){
            temp[2].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] >= boxmap[2] && numvar[i] <= boxmap[3]){
            temp[3].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > boxmap[3] && numvar[i] <= boxmap[4]){
            temp[4].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > boxmap[4]){
            temp[5].append(table->verticalHeaderItem(i)->text().toInt());
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<6; i++){
        temp2.append(temp[i]);
    }

    for(int i=0; i<=boxmap.size(); i++){
        mviewResult->filterItem(temp[i],listColor.value(i));
    }

    MapTematikConfig* mapconf = new MapTematikConfig(mviewResult,vv,rconn,temp2,var);
    setupResultViewVariableChooser("Box Map",var, mapconf);
}
