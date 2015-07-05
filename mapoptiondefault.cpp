#include "mapoptiondefault.h"
#include "ui_mapoptiondefault.h"

MapOptionDefault::MapOptionDefault(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapOptionDefault)
{
    ui->setupUi(this);
}

MapOptionDefault::~MapOptionDefault()
{
    delete ui;
}
