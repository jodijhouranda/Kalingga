#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "mapglobal.h"

class MapView;
class VariableView;
class MapGraphicsPolygonItem;
class MapGraphicsLineItem;
class MapGraphicsPointItem;
class MapGraphicsLabelItem;
class MapOption;

class Layer;
class Projection;
class ShapeMapReader;
class QListWidget;

QT_BEGIN_NAMESPACE
class QToolButton;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE


class MapControl
{
public:
    explicit MapControl(MapView *view, QGraphicsScene *scene,
                        QList<MapGraphicsPolygonItem*> *itemRegion,
                        QList<MapGraphicsLineItem*> *itemLine,
                        QList<MapGraphicsPointItem*> *itemPoint,
                        QList<MapGraphicsLabelItem*> *itemLabel
                        );
    ~MapControl();

    void openShapeFile(QString shpPath, VariableView *vv);
    const QList<Layer *> &GetLayers();
    void addPointLayer(Layer *layer);
    void addPolylineLayer(Layer *layer);
    void addPolygonLayer(Layer *layer);

private:
    Layer *AddLayer(Layer *layer = 0);
    void DrawItemRegion(QList<MapGraphicsPolygonItem*> *itemRegion);
    void DrawItemLine(QList<MapGraphicsLineItem*> *itemLine);
    void DrawItemPoint(QList<MapGraphicsPointItem*> *itemPoint);
    void DrawLabel(QList<MapGraphicsLabelItem*> *itemLabel);

private:
    QListWidget *layerList;
    MapOption *option;

    QList<Layer *> p_layers;

    MapView *view;
    QGraphicsScene *scene;
    QList<MapGraphicsPolygonItem*> *itemRegion;
    QList<MapGraphicsLineItem*> *itemLine;
    QList<MapGraphicsPointItem*> *itemPoint;
    QList<MapGraphicsLabelItem*> *itemLabel;

};

#endif // WIDGET_H
