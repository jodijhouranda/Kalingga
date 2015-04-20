#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QPainter>

#include "mapglobal.h"
#include <mainwindow.h>

#include <QSplitter>
#include <QListWidget>
#include <QFrame>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QLineEdit>
class QTabWidget;

class Layer;
class MapFrame;
class Projection;
class ShapeMapReader;
class QListWidgetItem;

class mapview: public QWidget
{
    Q_OBJECT

public:
    mapview(MainWindow* MainWindow, QTabWidget* tabView,QWidget* parent = 0);
    ~mapview();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QSplitter *splitter;
    QListWidget *layerList;
    QFrame *mapFrame;

    QAction *actionAddPoint;
    QAction *actionZoom;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionAddLayer;
    QAction *actionSaveMap;
    QAction *actionShapeInfo;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QLabel *statScale;
    QLabel *statCoordinate;
    QLineEdit *lineScale;
    QLineEdit *lineCoordinate;

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
    void addShapeFile();
    void addPointLayer(Layer *layer);
    void addPolylineLayer(Layer *layer);
    void addPolygonLayer(Layer *layer);
    void addPointTriggered(bool checked);
    void saveLayer();
    void zoom();
    void zoomIn();
    void zoomOut();
    void layerListChanged(QListWidgetItem *item);
    void layerListSelected();
    void shapeInfo();

    void enableToolBar(int tab);
};

#endif // MAPVIEW_H
