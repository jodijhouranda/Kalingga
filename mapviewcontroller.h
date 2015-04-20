#ifndef MAPVIEWCONTROLLER_H
#define MAPVIEWCONTROLLER_H

#include <QMainWindow>
#include <QPainter>
#include "mapglobal.h"
#include "mapview.h"

class Layer;
class MapFrame;
class Projection;
class ShapeMapReader;
class QListWidgetItem;

class mapviewcontroller: public QWidget
{
    Q_OBJECT

public:
    mapviewcontroller();
    ~mapviewcontroller();

protected:
    void keyPressEvent(QKeyEvent *event);
private:
    mapview *mv;
    MapFrame *mf;
    int newLayerCount;
    Layer *addLayer(const QString &fileName,
                    ShapeMapReader *smr,
                    Projection *proj,
                    QSimpleSpatial::ShapeTypes shapeType = QSimpleSpatial::NullShape);
    QList<QSimpleSpatial::SimplePoint> p_points;

protected slots:
    void paint(QPainter &painter);
    void mapClicked(QMouseEvent *event);
    void mapReleased(QMouseEvent *event);

private slots:
    void addPointLayer();
    void addPolylineLayer();
    void addPolygonLayer();
    void addPointTriggered(bool checked);
    void saveLayer();
    void zoom();
    void zoomIn();
    void zoomOut();
    void layerListChanged(QListWidgetItem *item);
    void layerListSelected();
    void shapeInfo();

};

#endif // MAPVIEWCONTROLLER_H
