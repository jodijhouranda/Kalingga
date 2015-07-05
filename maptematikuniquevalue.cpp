#include "maptematikuniquevalue.h"

#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>
#include <QtAlgorithms>
#include <QDateTime>

MapTematikUniqueValue::MapTematikUniqueValue(MapView *mview, RInside& rconn, VariableView *vv, QString var):
    MapTematik(mview, rconn, vv, var)
{

}

MapTematikUniqueValue::~MapTematikUniqueValue()
{

}

void MapTematikUniqueValue::createMapTematikUniqueValue()
{
    Rcpp::NumericVector unique ;
    QString command;
    try {
        command = QString("u <- unique(dframe[[\"%1\"]]); ").arg(var);
        rconn.parseEvalQ(command.toStdString());

        unique =  rconn["u"];
    } catch (...) {

    }

    QList<int> temp[unique.size()];

    for(int i=0; i<unique.size(); i++){
        for(int j=0; j<numvar.size(); j++){
            if(unique[i] == numvar[j]){
                temp[i].append(table->verticalHeaderItem(j)->text().toInt());
            }
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<unique.size(); i++){
        temp2.append(temp[i]);
    }

    QColor color[unique.size()];
    for(int i=0; i<unique.size(); i++){
        qsrand(i*QDateTime::currentMSecsSinceEpoch());
        color[i].setRgb(rrrand(0,255),rrrand(0,255),rrrand(0,255));
    }

    for(int i=0; i<unique.size(); i++){
        mviewResult->filterItem(temp[i],color[i]);
    }
    MapTematikConfig* mapconf = new MapTematikConfig(mviewResult,vv,rconn,temp2,var,1);
    setupResultViewVariableChooser("Unique Values Map",var, mapconf);
}

