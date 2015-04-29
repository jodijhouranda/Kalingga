#include "layerproperties.h"
#include "ui_layerproperties.h"

LayerProperties::LayerProperties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LayerProperties)
{
    ui->setupUi(this);
}

LayerProperties::~LayerProperties()
{
    delete ui;
}
