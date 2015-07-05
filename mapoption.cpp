#include "mapoption.h"
#include "ui_mapoption.h"

#include "mapview.h"
#include "variableview.h"
#include "mapoptiongeneral.h"
#include "mapoptionstyle.h"
#include "mapoptionlabel.h"
#include "mapoptiondefault.h"
#include <QtGui>

MapOption::MapOption(MapView* mview, VariableView* vv, QWidget *parent) :
    mview(mview),
    vv(vv),
    QDialog(parent),
    ui(new Ui::MapOption)
{
    ui->setupUi(this);

    MapOptionGeneral *generalPage = new MapOptionGeneral(mview,vv,this);
    MapOptionStyle *stylePage = new MapOptionStyle(this);
    MapOptionLabel *labelPage = new MapOptionLabel(this);
    MapOptionDefault *defaultPage = new MapOptionDefault(this);

    gridLayout = new QGridLayout(generalPage);

    ui->stackedWidget->addWidget(generalPage);
    ui->stackedWidget->addWidget(stylePage);
    ui->stackedWidget->addWidget(labelPage);
    ui->stackedWidget->addWidget(defaultPage);

    ui->stackedWidget->setCurrentIndex(0);

    QObject::connect(ui->listWidget, SIGNAL(currentRowChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

}

MapOption::~MapOption()
{
    delete ui;
}
