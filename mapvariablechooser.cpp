#include "mapvariablechooser.h"
#include "ui_mapvariablechooser.h"

#include "maptematikpercentil.h"
#include "maptematikboxmap.h"
#include "maptematikstandarddeviation.h"
#include "maptematikuniquevalue.h"

MapVariableChooser::MapVariableChooser(MapView *mview, VariableView* vv ,RInside &rconn,int type,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapVariableChooser),
    mview(mview),
    vv(vv),
    rconn(rconn),
    type(type)
{
    ui->setupUi(this);
    setupUi();
}

const int MapVariableChooser::PERCENTIL=0;
const int MapVariableChooser::BOXMAP=1;
const int MapVariableChooser::STANDARDEVIATION=2;
const int MapVariableChooser::UNIQUEVALUE=3;

MapVariableChooser::~MapVariableChooser()
{
    delete ui;
}

void MapVariableChooser::on_buttonBox_accepted()
{
    if (!ui->listWidgetVariables->selectedItems().length() == 0) {

        var = ui->listWidgetVariables->currentItem()->text();

        switch (type) {
        case PERCENTIL:
            generatePercentil();
            break;
        case BOXMAP:
            generateBoxMap();
            break;
        case STANDARDEVIATION:
            generateStandarDeviation();
            break;
        case UNIQUEVALUE:
            generateUniqueValue();
        }
    }
}

void MapVariableChooser::setupUi()
{
    QList<QString> allVar;
    allVar = vv->getNumericVariableNames();
    ui->listWidgetVariables->addItems(allVar);
}


void MapVariableChooser::generatePercentil()
{
    MapTematikPercentil *percentil =  new MapTematikPercentil(mview,rconn,vv,var);
    percentil->createMapTematikPercentil();
}

void MapVariableChooser::generateBoxMap()
{
    MapTematikBoxMap *boxmap = new MapTematikBoxMap(mview,rconn,vv,var);
    boxmap->createMapTematikBoxmap();
}

void MapVariableChooser::generateStandarDeviation()
{
    MapTematikStandardDeviation *standardDeviaton = new MapTematikStandardDeviation(mview,rconn,vv,var);
    standardDeviaton->createMapTematikStandardDeviation();
}

void MapVariableChooser::generateUniqueValue()
{
    MapTematikUniqueValue *uniqueValue = new MapTematikUniqueValue(mview,rconn,vv,var);
    uniqueValue->createMapTematikUniqueValue();
}
