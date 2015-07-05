#include "mapoptionstyle.h"
#include "ui_mapoptionstyle.h"

MapOptionStyle::MapOptionStyle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapOptionStyle)
{
    ui->setupUi(this);
}

MapOptionStyle::~MapOptionStyle()
{
    delete ui;
}
