#include "maptematik.h"

#include "mapcolorreader.h"
#include "maptematikconfig.h"

#include <resultviewitem.h>
#include <mainwindow.h>
#include <QHBoxLayout>
#include <QColor>

MapTematik::MapTematik(MapView *mview, RInside& rconn, VariableView *vv, QString var):
    mview(mview),
    rconn(rconn),
    vv(vv),
    var(var)
{
    initializedVariableChooser();
}

MapTematik::MapTematik(MapView *mview, RInside &rconn, VariableView *vv, QString var, QString typeMap):
    mview(mview),
    rconn(rconn),
    vv(vv),
    var(var),
    typeMap(typeMap)
{
    initializedVariableTypeChooser();
}


MapTematik::~MapTematik()
{

}

void MapTematik::initializedVariableChooser()
{
    mviewResult = new MapView();
    mviewResult->setVariableView(vv);
    mviewResult->setShapePath(this->mview->getShapePath());
    mviewResult->addPolygonLayer(this->mview->GetLayers().first());

    table = vv->getSpreadsheetTable();
    idx = vv->getVariableIndex(var);
    numvar = vv->getNumericVector(idx);

    MapColorReader *mapColor =  new MapColorReader();
    listColor = mapColor->getListColor("RdYlGn", "6");

    vv->sendDataFrame(rconn);
}

void MapTematik::initializedVariableTypeChooser()
{
    mviewResult = new MapView();
    mviewResult->setVariableView(vv);
    mviewResult->setShapePath(this->mview->getShapePath());
    mviewResult->addPolygonLayer(this->mview->GetLayers().first());

    table = vv->getSpreadsheetTable();
    idx = vv->getVariableIndex(var);
    numvar = vv->getNumericVector(idx);

    MapColorReader *mapColor =  new MapColorReader();
    listColor = mapColor->getListColor("YlGn", "9");

    vv->sendDataFrame(rconn);
}

void MapTematik::setupResultViewVariableChooser(QString mapName ,QString variable ,QWidget* configWidget)
{
    QWidget* widget = new QWidget();

    configWidget->setFixedWidth(200);
    mviewResult->setSettingMap(configWidget);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(mviewResult);
    layout->addWidget(configWidget);
    layout->setMargin(0);
    widget->setLayout(layout);

    QString var = QString("%1 (%2)").arg(mapName,variable);
    QStringList item;
    QList<QWidget*> list;
    list << widget;
    item << var;
    ResultViewItem* rvi = new ResultViewItem(item,list,var);
    MainWindow::result->setResultViewItem(rvi);
    MainWindow::enableResultView();
}

void MapTematik::setupResultViewVariableTypeChooser(QString mapName, QString variable, QList<QList<int> > temp,
                                                    Rcpp::NumericVector cluster,QWidget* configWidget)
{
    QWidget* widget = new QWidget();
    //MapTematikConfig* configWidget = new MapTematikConfig(mviewResult,vv,rconn,temp,variable,typeMap.toInt());
    for(int i=0; i<cluster.size()-1; i++){
        mviewResult->filterItem(temp.value(i),listColor.value(i));
    }

    configWidget->setFixedWidth(200);
    mviewResult->setSettingMap(configWidget);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(mviewResult);
    layout->addWidget(configWidget);
    layout->setMargin(0);
    widget->setLayout(layout);

    QString var = QString("%1 (%2)").arg(mapName, variable);
    item.insert(0, var);
    list.insert(0,widget);

    QColor k;
    k.setRgb(232,15,15);

    for(int i=0; i<cluster.size()-1; i++){

        QWidget* widget = new QWidget();
        MapView* mviewResult = new MapView();
        mviewResult->setVariableView(vv);
        mviewResult->setShapePath(this->mview->getShapePath());
        mviewResult->addPolygonLayer(this->mview->GetLayers().first());
        MapTematikConfig* configWidget = new MapTematikConfig(mviewResult,vv,rconn,temp,variable,typeMap.toInt());
        for(int i=0; i<cluster.size()-1; i++){
            mviewResult->filterItem(temp.value(i),listColor.value(i));
        }

        configWidget->setFixedWidth(200);
        mviewResult->setSettingMap(configWidget);

        QHBoxLayout* layout = new QHBoxLayout();
        layout->addWidget(mviewResult);
        layout->addWidget(configWidget);
        layout->setMargin(0);
        widget->setLayout(layout);

        mviewResult->filterItem(temp[i],k);
        if(i==0){
            item << QString("[%1 : %2]").arg(cluster[i]).arg(cluster[i+1]);
            list << widget;
        }else{
            item << QString("(%1 : %2]").arg(cluster[i]).arg(cluster[i+1]);
            list << widget;
        }
    }

    ResultViewItem* rvi = new ResultViewItem(item,list,var);
    MainWindow::result->setResultViewItem(rvi);
    MainWindow::enableResultView();

}
