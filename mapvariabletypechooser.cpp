#include "mapvariabletypechooser.h"
#include "ui_mapvariabletypechooser.h"

#include "maptematikquantile.h"
#include "maptematiknaturalbreaks.h"
#include "maptematikequalintervals.h"

MapVariableTypeChooser::MapVariableTypeChooser(MapView* mview, VariableView* vv ,RInside &rconn,int type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapVariableTypeChooser),
    mview(mview),
    vv(vv),
    rconn(rconn),
    type(type)
{
    ui->setupUi(this);
    setupUi();
    rconn.parseEvalQ("library(classInt)");
}


const int MapVariableTypeChooser::QUANTILE=0;
const int MapVariableTypeChooser::NATURALBREAKS=1;
const int MapVariableTypeChooser::EQUALINTERVALS=2;

MapVariableTypeChooser::~MapVariableTypeChooser()
{
    delete ui;
}

void MapVariableTypeChooser::on_buttonBox_accepted()
{
    if (!ui->listWidgetVariables->selectedItems().length() == 0) {

        typeMap = ui->comboBox->currentText();
        var = ui->listWidgetVariables->currentItem()->text();

        switch (type) {
        case QUANTILE:
            generateQuantile();
            break;
        case NATURALBREAKS:
            generateNaturalBreaks();
            break;
        case EQUALINTERVALS:
            generateEqualIntervals();
            break;
        }
    }
}

void MapVariableTypeChooser::setupUi()
{
    QList<QString> allType;
    for(int i=2; i<11; i++)
        allType << QString("%1").arg(i) ;
    ui->comboBox->addItems(allType);
    QList<QString> allVar;
    allVar = vv->getNumericVariableNames();
    ui->listWidgetVariables->addItems(allVar);
}


void MapVariableTypeChooser::generateQuantile()
{
    MapTematikQuantile *quantil = new MapTematikQuantile(mview,rconn,vv,var,typeMap);
    quantil->createMapTematikQuantile();
}

void MapVariableTypeChooser::generateNaturalBreaks()
{
    MapTematikNaturalBreaks *naturalBreaks = new MapTematikNaturalBreaks(mview,rconn,vv,var,typeMap);
    naturalBreaks->createMapTematikNaturalBreaks();
}

void MapVariableTypeChooser::generateEqualIntervals()
{
    MapTematikEqualIntervals *equalIntervals =  new MapTematikEqualIntervals(mview,rconn,vv,var,typeMap);
    equalIntervals->createMapTematikEqualValues();
}


QList<int> MapVariableTypeChooser::getId(QList<QString> temp, QString var)
{
    int idx = vv->getVariableIndex(var);
    int row = vv->getRowCount();
    QTableWidget *tablewidget = vv->getSpreadsheetTable();
    QList<int> listId;
    QString item;
    for(int i=0; i<row; i++){
        item = tablewidget->item(i,idx)->text();
        for(int j=0; j<temp.size(); j++){
            if(item == temp[j]){
                listId.append(tablewidget->verticalHeaderItem(i)->text().toInt());
            }
        }
    }
    return listId;
}

