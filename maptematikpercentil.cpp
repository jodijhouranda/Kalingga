#include "maptematikpercentil.h"

#include "maptematikconfig.h"

MapTematikPercentil::MapTematikPercentil(MapView *mview, RInside& rconn, VariableView *vv, QString var) :
    MapTematik(mview, rconn, vv, var)
{
}

MapTematikPercentil::~MapTematikPercentil()
{

}

void MapTematikPercentil::createMapTematikPercentil()
{
    Rcpp::NumericVector percentil ;
    QString command;
    try {
        command = QString("p <- quantile(dframe[[\"%1\"]], c(.01, .10, .50, .90, .99), type=7)").arg(var);
        rconn.parseEvalQ(command.toStdString());

        percentil =  rconn["p"];
    } catch (...) {

    }

    QList<int> temp[percentil.size()+1];

    for(int i=0; i<numvar.size(); i++){
        if(numvar[i] < percentil[0]){
            temp[0].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] > percentil[percentil.size()-1]){
            temp[percentil.size()].append(table->verticalHeaderItem(i)->text().toInt());
        }else if(numvar[i] >= percentil[0] && numvar[i] <= percentil[1]){
            temp[1].append(table->verticalHeaderItem(i)->text().toInt());
        }else{
            for(int j=2; j<percentil.size(); j++){
                if(numvar[i] > percentil[j-1] && numvar[i] <= percentil[j]){
                    temp[j].append(table->verticalHeaderItem(i)->text().toInt());
                }
            }
        }
    }

    QList<QList<int> > temp2;
    for(int i=0; i<percentil.size()+1; i++){
        temp2.append(temp[i]);
    }

    for(int i=0; i<=percentil.size(); i++){
        mviewResult->filterItem(temp[i],listColor.value(i));
    }

    MapTematikConfig* mapconf = new MapTematikConfig(mviewResult,vv,rconn,temp2,var);
    setupResultViewVariableChooser("Percentil Map",var, mapconf);
}

