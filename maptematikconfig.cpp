#include "maptematikconfig.h"
#include "ui_maptematikconfig.h"

#include "mapview.h"
#include "mapitemcolor.h"
#include "mapitemcolorgraphicsview.h"
#include "layer.h"
#include "maptranslator.h"
#include "feature.h"
#include "mapgraphicspolygonitem.h"
#include "mapoption.h"

#include <QtGui>
#include <qtColorpicker.h>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <qdebug.h>

const int IdRole = Qt::UserRole;

MapTematikConfig::MapTematikConfig(MapView* mviewResult,VariableView* vv, RInside& rconn,QList<QList<int> > temp,
                                   QString var,int typeMap,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapTematikConfig),
    mviewResult(mviewResult),
    vv(vv),
    rconn(rconn),
    temp(temp),
    var(var),
    typeMap(typeMap)
{
    ui->setupUi(this);
    setupUiInitialized();
}

MapTematikConfig::~MapTematikConfig()
{
    delete ui;
}

void MapTematikConfig::setupUiInitialized()
{

    itemRegion = mviewResult->getItemRegion();
    listCentroid =  new QList<QGraphicsItem*>;

    cpMover = new QtColorPicker(this);
    cpMover->setStandardColors();
    cpMover->setVisible(false);
    ui->verticalLayoutcp->addWidget(cpMover);

    cpSelect = new QtColorPicker(this);
    cpSelect->setStandardColors();
    cpSelect->setVisible(false);
    ui->verticalLayoutcp_2->addWidget(cpSelect);

    MapItemColorGraphicsView* itemGraphcics = new MapItemColorGraphicsView(mviewResult, temp, typeMap);
    ui->gridLayout->addWidget(itemGraphcics, 0, 0, 1, 1);

    if(typeMap != 0)
        ui->labelNumberClass->setText(QString("Number of Data Class %1").arg(typeMap));
    else
        ui->labelNumberClass->setText(QString(""));

    ui->comboBoxSelectBrush->addItem(tr("Default"));
    ui->comboBoxSelectBrush->addItem(tr("Colour"));
    ui->comboBoxSelectBrush->addItem(tr("Solid"), Qt::SolidPattern);
    ui->comboBoxSelectBrush->addItem(tr("Horizontal"), Qt::HorPattern);
    ui->comboBoxSelectBrush->addItem(tr("Vertical"), Qt::VerPattern);
    ui->comboBoxSelectBrush->addItem(tr("Cross"), Qt::CrossPattern);
    ui->comboBoxSelectBrush->addItem(tr("Backward Diagonal"), Qt::BDiagPattern);
    ui->comboBoxSelectBrush->addItem(tr("Forward Diagonal"), Qt::FDiagPattern);
    ui->comboBoxSelectBrush->addItem(tr("Diagonal Cross"), Qt::DiagCrossPattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 1"), Qt::Dense1Pattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 2"), Qt::Dense2Pattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 3"), Qt::Dense3Pattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 4"), Qt::Dense4Pattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 5"), Qt::Dense5Pattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 6"), Qt::Dense6Pattern);
    ui->comboBoxSelectBrush->addItem(tr("Dense 7"), Qt::Dense7Pattern);
    ui->comboBoxSelectBrush->addItem(tr("None"), Qt::NoBrush);

    ui->comboBoxMoverBrush->addItem(tr("Default"));
    ui->comboBoxMoverBrush->addItem(tr("Colour"));
    ui->comboBoxMoverBrush->addItem(tr("Solid"), Qt::SolidPattern);
    ui->comboBoxMoverBrush->addItem(tr("Horizontal"), Qt::HorPattern);
    ui->comboBoxMoverBrush->addItem(tr("Vertical"), Qt::VerPattern);
    ui->comboBoxMoverBrush->addItem(tr("Cross"), Qt::CrossPattern);
    ui->comboBoxMoverBrush->addItem(tr("Backward Diagonal"), Qt::BDiagPattern);
    ui->comboBoxMoverBrush->addItem(tr("Forward Diagonal"), Qt::FDiagPattern);
    ui->comboBoxMoverBrush->addItem(tr("Diagonal Cross"), Qt::DiagCrossPattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 1"), Qt::Dense1Pattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 2"), Qt::Dense2Pattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 3"), Qt::Dense3Pattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 4"), Qt::Dense4Pattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 5"), Qt::Dense5Pattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 6"), Qt::Dense6Pattern);
    ui->comboBoxMoverBrush->addItem(tr("Dense 7"), Qt::Dense7Pattern);
    ui->comboBoxMoverBrush->addItem(tr("None"), Qt::NoBrush);

    ui->spinBoxBorderWith->setRange(0,20);

    ui->comboBoxBorderStyle->addItem(tr("Solid"), Qt::SolidLine);
    ui->comboBoxBorderStyle->addItem(tr("Dash"), Qt::DashLine);
    ui->comboBoxBorderStyle->addItem(tr("Dot"), Qt::DotLine);
    ui->comboBoxBorderStyle->addItem(tr("Dash Dot"), Qt::DashDotLine);
    ui->comboBoxBorderStyle->addItem(tr("Dash Dot Dot"), Qt::DashDotDotLine);
    ui->comboBoxBorderStyle->addItem(tr("None"), Qt::NoPen);

    QStringList allVar;
    allVar = vv->getAllVariableNames();
    ui->comboBoxLabel->addItems(allVar);

    setLabelVisibility(false);

    ui->sliderTransparency->setMinimum(0);
    ui->sliderTransparency->setMaximum(100);

    borderColor = Qt::black;
    backgroundColor = Qt::white;
    labelColor = Qt::black;
    updateColorLabel(ui->textColorBorder, borderColor);
    updateColorLabel(ui->textColorBackground, backgroundColor);
    updateColorLabel(ui->textColorLabel, labelColor);

    connect(cpMover,SIGNAL(colorChanged(QColor)),
            this,SLOT(setColorMover(QColor)));
    connect(cpSelect,SIGNAL(colorChanged(QColor)),
            this,SLOT(setColorSelect(QColor)));
    connect(ui->comboBoxSelectBrush, SIGNAL(activated(int)),
            this, SLOT(selectBrushChange(int)));
    connect(ui->comboBoxMoverBrush, SIGNAL(activated(int)),
            this, SLOT(moverBrushChange(int)));
    connect(ui->comboBoxBorderStyle, SIGNAL(activated(int)),
            this, SLOT(borderStyleChanged()));
    connect(ui->spinBoxBorderWith, SIGNAL(valueChanged(int)),
            this, SLOT(borderWidthChanged(int)));
    connect(ui->checkBoxLabel, SIGNAL(toggled(bool)),
            this, SLOT(labelVisibilityChange(bool)));
    connect(ui->comboBoxLabel, SIGNAL(activated(int)),
            this, SLOT(labelChanged(int)));
    connect(ui->sliderTransparency, SIGNAL(valueChanged(int)),
            this, SLOT(transparencyChanged(int)));
    connect(ui->checkBoxCentroid, SIGNAL(toggled(bool)),
            this, SLOT(centroidChange(bool)));

}


void MapTematikConfig::on_pushButtonBorderColor_clicked()
{
    chooseColor(ui->textColorBorder, &borderColor);

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setPenColor(borderColor);
}

void MapTematikConfig::on_pushButtonBackgroundColor_clicked()
{
    chooseColor(ui->textColorBackground, &backgroundColor);

    mviewResult->getScene()->setBackgroundBrush(backgroundColor);
}

void MapTematikConfig::on_pushButtonLabelColor_clicked()
{
    chooseColor(ui->textColorLabel, &labelColor);

    for(int i=0; i<listLabel->size(); i++){
        QGraphicsItem *gi = listLabel->value(i);
        QGraphicsTextItem *text = static_cast<QGraphicsTextItem *>(gi);
        text->setDefaultTextColor(labelColor);
    }
}

void MapTematikConfig::on_pushButtonAdvance_clicked(){
    MapOption* dialog = new MapOption(mviewResult,vv);
    dialog->show();
}

void MapTematikConfig::setColorMover(QColor color)
{
    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setMoverBrush(QBrush(color));
}

void MapTematikConfig::setColorSelect(QColor color)
{
    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setSelectBrush(QBrush(color));
}

void MapTematikConfig::updateColorLabel(QLabel *label, const QColor &color)
{
    QPixmap pixmap(16, 16);
    pixmap.fill(color);
    label->setPixmap(pixmap);
}

void MapTematikConfig::chooseColor(QLabel *label, QColor *color)
{
    QColor newColor = QColorDialog::getColor(*color, this);
    if (newColor.isValid()) {
        *color = newColor;
        updateColorLabel(label, *color);
    }
}

void MapTematikConfig::setLabelVisibility(bool b)
{
    ui->comboBoxLabel->setEnabled(b);
    ui->label_7->setEnabled(b);
    ui->textColorLabel->setEnabled(b);
    ui->pushButtonLabelColor->setEnabled(b);
}

void MapTematikConfig::labelVisibilityChange(bool value)
{
    if(value){
        setLabelVisibility(true);
        listLabel =  new QList<QGraphicsItem*>;

        mviewResult->resetView();
        QTableWidget *tablewidget = vv->getSpreadsheetTable();
        QString label;
        int idFeature;
        QPoint pointRegion;
        QSimpleSpatial::SimplePoint mapPointReg;
        foreach(Layer *layer, mviewResult->GetLayers()) {
            if(layer->isVisible()) {
                int i=0;
                foreach(Feature *feature, layer->getFeatures()) {
                    QGraphicsItem* temp;
                    idFeature = feature->getIdFeature();
                    mapPointReg = mviewResult->GetTranslator()->Coord2Screen(feature->getCenter());
                    pointRegion.setX(mapPointReg.X);
                    pointRegion.setY(mapPointReg.Y);

                    label = tablewidget->item(idFeature-1,0)->text().trimmed();
                    temp = mviewResult->getScene()->addText(label);
                    static_cast<QGraphicsTextItem *>(temp)->setDefaultTextColor(labelColor);
                    temp->setPos(pointRegion.x(),pointRegion.y());
                    listLabel->insert(i,temp);
                    i++;
                }
            }
        }
    }else{
        setLabelVisibility(false);
        mviewResult->resetView();

        for(int i=0; i<listLabel->size(); i++){
            QGraphicsItem *gi = listLabel->value(i);
                if(gi->parentItem()==NULL) {
                    delete gi;
                }
        }
    }
}

void MapTematikConfig::selectBrushChange(int value)
{
    if (value == 0) {
        cpSelect->setVisible(false);
        for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
            (*it)->setSelectBrush(QBrush(Qt::NoBrush));
    }else if (value == 1) {
        cpSelect->setVisible(true);
        setColorSelect(cpSelect->currentColor());
    }else {
        cpSelect->setVisible(false);
        Qt::BrushStyle style = Qt::BrushStyle(ui->comboBoxSelectBrush->itemData(
                ui->comboBoxSelectBrush->currentIndex(), IdRole).toInt());

        for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
            (*it)->setSelectBrush(QBrush(Qt::green, style));
    }
}

void MapTematikConfig::moverBrushChange(int value)
{
    if (value == 0) {
        cpMover->setVisible(false);
        for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
            (*it)->setMoverBrush(QBrush(Qt::NoBrush));
    }else if (value == 1) {
        cpMover->setVisible(true);
        setColorMover(cpMover->currentColor());
    }else {
        cpMover->setVisible(false);
        Qt::BrushStyle style = Qt::BrushStyle(ui->comboBoxMoverBrush->itemData(
                ui->comboBoxMoverBrush->currentIndex(), IdRole).toInt());

        for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
            (*it)->setMoverBrush(QBrush(Qt::green, style));
    }
}

void MapTematikConfig::borderStyleChanged()
{
    Qt::PenStyle style = Qt::PenStyle(ui->comboBoxBorderStyle->itemData(
            ui->comboBoxBorderStyle->currentIndex(), IdRole).toInt());

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setPenStyle(style);
}

void MapTematikConfig::borderWidthChanged(int width)
{
    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setPenWidth(width);
}

void MapTematikConfig::labelChanged(int value)
{
    mviewResult->resetView();
    QTableWidget *tablewidget = vv->getSpreadsheetTable();
    QString label;
    int idFeature;
    QPoint pointRegion;
    QSimpleSpatial::SimplePoint mapPointReg;
    foreach(Layer *layer, mviewResult->GetLayers()) {
        if(layer->isVisible()) {
            int i=0;
            foreach(Feature *feature, layer->getFeatures()) {
                QGraphicsItem* temp;
                idFeature = feature->getIdFeature();
                mapPointReg = mviewResult->GetTranslator()->Coord2Screen(feature->getCenter());
                pointRegion.setX(mapPointReg.X);
                pointRegion.setY(mapPointReg.Y);

                QGraphicsItem *gi = listLabel->value(i);
                    if(gi->parentItem()==NULL) {
                        delete gi;
                    }

                label = tablewidget->item(idFeature-1,value)->text().trimmed();
                temp = mviewResult->getScene()->addText(label);
                static_cast<QGraphicsTextItem *>(temp)->setDefaultTextColor(labelColor);
                temp->setPos(pointRegion.x(),pointRegion.y());
                listLabel->replace(i,temp);
                i++;
            }
        }
    }
}

void MapTematikConfig::centroidChange(bool value)
{
    if(value){
        mviewResult->resetView();
        int size =3;
        QPoint pointRegion;
        QSimpleSpatial::SimplePoint mapPointReg;
        foreach(Layer *layer, mviewResult->GetLayers()) {
            if(layer->isVisible()) {
                int i=0;
                foreach(Feature *feature, layer->getFeatures()) {
                    QGraphicsItem* temp;
                    mapPointReg = mviewResult->GetTranslator()->Coord2Screen(feature->getCenter());
                    pointRegion.setX(mapPointReg.X);
                    pointRegion.setY(mapPointReg.Y);

                    temp = mviewResult->getScene()->addEllipse(pointRegion.x()-size,pointRegion.y()-size,2*size,2*size,
                                                              QPen(Qt::black),QBrush(Qt::red));
                    listCentroid->insert(i,temp);
                    i++;
                }
            }
        }
    }else{
        mviewResult->resetView();

        for(int i=0; i<listCentroid->size(); i++){
            QGraphicsItem *gi = listCentroid->value(i);
                if(gi->parentItem()==NULL) {
                    delete gi;
                }
        }
        listCentroid =  new QList<QGraphicsItem*>;
    }
}

void MapTematikConfig::transparencyChanged(int value)
{
    qreal x = (qreal) value;
    x = 1-(x/100);

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setTransparency(x);

    mviewResult->getScene()->update();
}

QVariant MapTematikConfig::currentItemData(QComboBox *comboBox)
{
    return comboBox->itemData(comboBox->currentIndex());
}
