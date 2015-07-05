#include "mapoptiongeneral.h"
#include "ui_mapoptiongeneral.h"

#include "mapview.h"
#include "layer.h"
#include "variableview.h"
#include "QTableWidget";

#include "qdebug.h"

MapOptionGeneral::MapOptionGeneral(MapView *mview, VariableView *vv, QWidget *parent) :
    mview(mview), vv(vv), QWidget(parent),
    ui(new Ui::MapOptionGeneral)
{
    ui->setupUi(this);
    this->show();

    setLineEditLayerName();
    setLineEditLayerSource();
    setLineEditLayerType();
    setScaleDependentVisibility(false);

    int observation = vv->getRowCount();
    int field = vv->getColumnCount();

    setLineEditObservation(QString("%1").arg(observation));
    setLineEditField(QString("%1").arg(field));

    QObject::connect(ui->checkBoxScaleDependentVisibility, SIGNAL(toggled(bool)), this, SLOT(ScaleDependentVisibilityChange(bool)));

}

MapOptionGeneral::~MapOptionGeneral()
{
    delete ui;
}

QString MapOptionGeneral::getLineEditLayerName() const
{
    return ui->lineEditLayerName->text();
}

void MapOptionGeneral::setLineEditLayerName()
{
    ui->lineEditLayerName->setText(mview->GetLayers().first()->getName());
}

QString MapOptionGeneral::getLineEditLayerSource() const
{
    return ui->lineEditLayerSource->text();
}

void MapOptionGeneral::setLineEditLayerSource()
{
    ui->lineEditLayerSource->setText(mview->GetLayers().first()->getSource());
}

QString MapOptionGeneral::getLineEditLayerType() const
{
    return ui->lineEditLayerType->text();
}

void MapOptionGeneral::setLineEditLayerType()
{
    QString shapeType;
    switch(mview->GetLayers().first()->GetShapeType()){
    case 1:
        shapeType = "Points";
        break;
    case 3:
        shapeType = "Lines";
        break;
    case 5:
        shapeType = "Polygons";
        break;
    default:
        shapeType = "Unknown";
    }

    ui->lineEditLayerType->setText(shapeType);
}

QString MapOptionGeneral::getLineEditObservation() const
{
    return ui->lineEditObservation->text();
}

void MapOptionGeneral::setLineEditObservation(QString value)
{
    ui->lineEditObservation->setText(value);
}

QString MapOptionGeneral::getLineEditField() const
{
    return ui->lineEditField->text();
}

void MapOptionGeneral::setLineEditField(QString value)
{
    ui->lineEditField->setText(value);
}

void MapOptionGeneral::setScaleDependentVisibility(bool value)
{
    ui->labelMaximumScale->setEnabled(value);
    ui->labelMinimumScale->setEnabled(value);
    ui->comboBoxMaximumScale->setEnabled(value);
    ui->comboBoxMinimumScale->setEnabled(value);
}

void MapOptionGeneral::ScaleDependentVisibilityChange(bool value)
{
    if(value){
        setScaleDependentVisibility(true);
    }else{
        setScaleDependentVisibility(false);
    }
}
