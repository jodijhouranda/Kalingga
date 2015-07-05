#include "mapoptionlabel.h"
#include "ui_mapoptionlabel.h"

MapOptionLabel::MapOptionLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapOptionLabel)
{
    ui->setupUi(this);

    QObject::connect(ui->listWidget_2, SIGNAL(currentRowChanged(int)), ui->stackedWidget_2, SLOT(setCurrentIndex(int)));
}

MapOptionLabel::~MapOptionLabel()
{
    delete ui;
}
