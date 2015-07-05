#include "mapcontrol.h"

#include "mapview.h"
#include "variableview.h"
#include "mapgraphicspolygonitem.h"
#include "mapgraphicslineitem.h"
#include "mapgraphicspointitem.h"
#include "mapgraphicslabelitem.h"
#include "mapoption.h"

#include "shapemapreader.h"
#include "layer.h"
#include "paintscheme.h"
#include "paintschemepoint.h"
#include "paintschemepolygon.h"
#include "paintschemepolyline.h"
#include "projection_wgs84_worldmercator.h"

#include <QGraphicsView>
#include <QtGui>
#include <QMessageBox>

class LayerListItem : public QListWidgetItem
{
public:
    LayerListItem(QListWidget *parent = 0) :
        QListWidgetItem(parent),
        p_layer(NULL)
    {}
    Layer *getLayer()
    {
        return p_layer;
    }

    void setLayer(Layer *layer)
    {
        p_layer = layer;
    }

protected:
    Layer *p_layer;
};

MapControl::MapControl(MapView *view, QGraphicsScene *scene,
                       QList<MapGraphicsPolygonItem*> *itemRegion,
                       QList<MapGraphicsLineItem*> *itemLine,
                       QList<MapGraphicsPointItem*> *itemPoint,
                       QList<MapGraphicsLabelItem*> *itemLabel):
    view(view), scene(scene), itemRegion(itemRegion), itemLine(itemLine), itemPoint(itemPoint), itemLabel(itemLabel)
{
    layerList = new QListWidget();
}

MapControl::~MapControl()
{
}


void MapControl::openShapeFile(QString shpPath, VariableView *vv)
{
    QString filename = shpPath;
    if(!filename.isEmpty()){
        ShapeMapReader * smr = new ShapeMapReader(vv, view);

        Layer *layer;

        if(QFile::exists(filename)){
            layer = smr->ReadFile(filename,view->getProjection());
        }
        else {
            layer = new Layer(QSimpleSpatial::NullShape,view);
            layer->setName(filename);
        }

        layer->setSource(filename);

        QString name = filename.mid(filename.lastIndexOf("/")+1,filename.lastIndexOf(".")-filename.lastIndexOf("/")-1);
        layer->setName(name);

        qDebug() << "tes1";

        switch(layer->GetShapeType()){
        case 1:
            addPointLayer(layer);
            break;
        case 3:
            addPolylineLayer(layer);
            break;
        case 5:
            addPolygonLayer(layer);
            break;
        case 13:
            addPolylineLayer(layer);
            break;
        case 15:
            addPolygonLayer(layer);
            break;
        default:
            QMessageBox::information(view,"ShapeFile Type unidentified","Shapefile type unidentified");
        }
    }
    qDebug() << "test3";


    qDebug() << QString("%1,%2 - %3,%4")
                .arg(view->GetTranslator()->getViewport().p1().X)
                .arg(view->GetTranslator()->getViewport().p1().Y)
                .arg(view->GetTranslator()->getViewport().p2().X)
                .arg(view->GetTranslator()->getViewport().p2().Y);
    qDebug() << "test4";
}


void MapControl::addPointLayer(Layer *layer)
{
    PaintSchemePoint *schemeCustom = new PaintSchemePoint(QPen(Qt::black),QBrush(Qt::red),5);
    layer->AddScheme(schemeCustom);
    //layer->setMaxZoom(0.01);
    LabelScheme *labelScheme = new LabelScheme("name",QFont("Tahoma",8),QPen(Qt::darkGray));
    QSimpleSpatial::SimplePoint offset;
    offset.X = 0;
    offset.Y = 20;
    labelScheme->setLabelOffset(offset);
    layer->AddLabelScheme(labelScheme);
    AddLayer(layer);
    view->GetTranslator()->updateSize();
    DrawItemPoint(itemPoint);

    for(QList<MapGraphicsPointItem*>::iterator it = itemPoint->begin(); it != itemPoint->end(); it++){
        scene->addItem((*it));
    }
}

void MapControl::addPolylineLayer(Layer *layer)
{
    PaintSchemePolyline *schemeCustom = new PaintSchemePolyline(QPen(qRgb(255,128,0)),QBrush(Qt::yellow),5);
    layer->AddScheme(schemeCustom);
    LabelScheme *labelScheme = new LabelScheme("name",QFont("Tahoma",9),QPen(Qt::magenta));
    layer->AddLabelScheme(labelScheme);
    AddLayer(layer);
    view->GetTranslator()->updateSize();
    DrawItemLine(itemLine);

    for(QList<MapGraphicsLineItem*>::iterator it = itemLine->begin(); it != itemLine->end(); it++){
        scene->addItem((*it));
    }
}

void MapControl::addPolygonLayer(Layer *layer)
{
    PaintSchemePolygon *schemeCustom = new PaintSchemePolygon();
    layer->AddScheme(schemeCustom);
    LabelScheme * labelScheme = new LabelScheme("name",QFont("Tahoma",9),QPen(Qt::darkGreen));
    layer->AddLabelScheme(labelScheme);
    AddLayer(layer);
    view->GetTranslator()->updateSize();
    DrawItemRegion(itemRegion);
    //view->DrawLabel(&itemLabel);

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++){
        scene->addItem((*it));
    }

    option = new MapOption(view, view->getVariableView());
}


Layer *MapControl::AddLayer(Layer *layer)
{
    if(layer == 0)
        layer = new Layer();
    QSimpleSpatial::Extent e = view->GetTranslator()->getBaseExtent();
    e.correctSize(layer->GetExtent());
    view->GetTranslator()->SetExtent(e);
    p_layers.append(layer);
    return layer;
}

const QList<Layer *> &MapControl::GetLayers()
{
    return p_layers;
}


void MapControl::DrawItemRegion(QList<MapGraphicsPolygonItem*> *itemRegion)
{
    QPainter painter(new QPixmap);
    for(int i = 0;i < p_layers.count();i ++) {
        qDebug() << "layer";
        if(p_layers[i]->isVisible()){
            p_layers[i]->DrawItemRegion(view->GetTranslator(), &painter, itemRegion);
            qDebug() <<"layer visible";
        }
    }
}

void MapControl::DrawItemLine(QList<MapGraphicsLineItem*> *itemLine)
{
    QPainter painter(new QPixmap);
    for(int i = 0;i < p_layers.count();i ++) {
        if(p_layers[i]->isVisible()){
            p_layers[i]->DrawItemLine(view->GetTranslator(), &painter, itemLine);
        }
    }
}

void MapControl::DrawItemPoint(QList<MapGraphicsPointItem *> *itemPoint)
{
    QPainter painter(new QPixmap);
    for(int i = 0;i < p_layers.count();i ++) {
        if(p_layers[i]->isVisible()){
            p_layers[i]->DrawItemPoint(view->GetTranslator(), &painter, itemPoint);
        }
    }
}

void MapControl::DrawLabel(QList<MapGraphicsLabelItem*> *itemLabel)
{
    QPainter painter(new QPixmap);
    view->GetTranslator()->CleanLabelsRegion();
    for(int i = 0;i < p_layers.count();i++) {
        if(p_layers[i]->isVisible())
            p_layers[i]->DrawLabel(view->GetTranslator(), &painter, itemLabel);
    }
}
