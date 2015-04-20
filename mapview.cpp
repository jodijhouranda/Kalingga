#include "mapview.h"

#include "mapframe.h"
#include "shapemapreader.h"
#include "maptranslator.h"
#include "feature.h"
#include "pointfeature.h"
#include "polylinefeature.h"
#include "polygonfeature.h"
#include "layer.h"
#include "paintschemepoint.h"
#include "paintschemepolygon.h"
#include "paintschemepolyline.h"
#include "labelscheme.h"
#include "projection_wgs84_sphericalmercator.h"
#include "projection_wgs84_worldmercator.h"

#include <QMouseEvent>
#include <QMenu>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>


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


mapview::mapview(MainWindow *mw, QTabWidget *tabView ,QWidget* parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("MapView"));

    splitter = new QSplitter(this);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setGeometry(QRect(0, 0, 1365,620));
    splitter->setOrientation(Qt::Horizontal);
    splitter->setHandleWidth(3);

    layerList = new QListWidget(splitter);
    layerList->setObjectName(QString::fromUtf8("layerList"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(layerList->sizePolicy().hasHeightForWidth());
    layerList->setSizePolicy(sizePolicy);
    splitter->addWidget(layerList);

    mapFrame = new QFrame();
    mapFrame->setObjectName(QString::fromUtf8("mapFrame"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(2);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(mapFrame->sizePolicy().hasHeightForWidth());
    mapFrame->setSizePolicy(sizePolicy1);
    mapFrame->setFrameShape(QFrame::StyledPanel);
    mapFrame->setFrameShadow(QFrame::Raised);

    actionAddPoint = new QAction(mw);
    actionAddPoint->setObjectName(QString::fromUtf8("actionAddPoint"));
    actionAddPoint->setCheckable(true);
    actionAddPoint->setEnabled(false);
    QIcon icon;
    icon.addFile(QString::fromUtf8("./images/addpoint.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionAddPoint->setIcon(icon);
    actionAddPoint->setToolTip("Add a point to current layer");

    actionZoom = new QAction(mw);
    actionZoom->setObjectName(QString::fromUtf8("actionZoom"));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8("./images/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionZoom->setIcon(icon1);
    actionZoom->setToolTip("Zoom to layer extent");

    actionZoomIn = new QAction(mw);
    actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
    QIcon icon2;
    icon2.addFile(QString::fromUtf8("./images/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionZoomIn->setIcon(icon2);
    actionZoomIn->setToolTip("Zoom in");

    actionZoomOut = new QAction(mw);
    actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
    QIcon icon3;
    icon3.addFile(QString::fromUtf8("./images/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionZoomOut->setIcon(icon3);
    actionZoomOut->setToolTip("Zoom out");

    actionAddLayer = new QAction(mw);
    actionAddLayer->setObjectName(QString::fromUtf8("actionAddLayer"));
    QIcon icon4;
    icon4.addFile(QString::fromUtf8("./images/addlayer.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionAddLayer->setIcon(icon4);
    actionAddLayer->setToolTip("MainWindow");

    actionSaveMap = new QAction(mw);
    actionSaveMap->setObjectName(QString::fromUtf8("actionSaveMap"));
    actionSaveMap->setEnabled(false);
    QIcon icon5;
    icon5.addFile(QString::fromUtf8("./images/savemap.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionSaveMap->setIcon(icon5);
    actionSaveMap->setToolTip("Save current layer");

    actionShapeInfo = new QAction(mw);
    actionShapeInfo->setObjectName(QString::fromUtf8("actionShapeInfo"));
    actionShapeInfo->setCheckable(true);
    QIcon icon6;
    icon6.addFile(QString::fromUtf8("./images/mapinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionShapeInfo->setIcon(icon6);
    actionShapeInfo->setToolTip("Shape Info");

    toolBar = new QToolBar(mw);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));

    mw->addToolBar(Qt::TopToolBarArea, toolBar);

    toolBar->addAction(actionAddLayer);
    toolBar->addAction(actionAddPoint);
    toolBar->addAction(actionSaveMap);
    toolBar->addSeparator();
    toolBar->addAction(actionZoom);
    toolBar->addAction(actionZoomIn);
    toolBar->addAction(actionZoomOut);
    toolBar->addAction(actionShapeInfo);
    toolBar->setEnabled(false);

    statScale = new QLabel(mw);
    statScale->setText("Scale");
    lineScale = new QLineEdit(mw);
    lineScale->setFixedWidth(80);

    statCoordinate = new QLabel(mw);
    statCoordinate->setText("Coordinates");
    lineCoordinate = new QLineEdit(mw);
    lineCoordinate->setFixedWidth(120);

    statusBar = new QStatusBar(mw);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    statusBar->addPermanentWidget(statCoordinate);
    statusBar->addPermanentWidget(lineCoordinate);
    statusBar->addPermanentWidget(statScale);
    statusBar->addPermanentWidget(lineScale);
    statusBar->setEnabled(false);
    mw->setStatusBar(statusBar);


    QObject::connect(actionAddLayer, SIGNAL(triggered()), this, SLOT(addShapeFile()));
    QObject::connect(actionAddPoint, SIGNAL(triggered(bool)), this, SLOT(addPointTriggered(bool)));
    QObject::connect(actionZoom, SIGNAL(triggered()), this, SLOT(zoom()));
    QObject::connect(actionZoomIn, SIGNAL(triggered()), this, SLOT(zoomIn()));
    QObject::connect(actionZoomOut, SIGNAL(triggered()), this, SLOT(zoomOut()));
    QObject::connect(actionSaveMap, SIGNAL(triggered()), this, SLOT(saveLayer()));
    QObject::connect(actionShapeInfo, SIGNAL(triggered()), this, SLOT(shapeInfo()));
    QObject::connect(layerList, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(layerListChanged(QListWidgetItem*)));
    QObject::connect(layerList, SIGNAL(itemSelectionChanged()), this, SLOT(layerListSelected()));
    QObject::connect(tabView, SIGNAL(currentChanged(int)), this, SLOT(enableToolBar(int)));

    mf = new MapFrame();
    QBrush bg(QPixmap("./images/cell.png"));
    mf->setBackground(bg);

    connect(mf,SIGNAL(paint(QPainter&)),this,SLOT(paint(QPainter&)));
    connect(mf,SIGNAL(clicked(QMouseEvent*)),this,SLOT(mapClicked(QMouseEvent*)));
    connect(mf,SIGNAL(released(QMouseEvent*)),this,SLOT(mapReleased(QMouseEvent*)));

    splitter->addWidget(mf);

    //Projection_WGS84_SphericalMercator *proj = new Projection_WGS84_SphericalMercator;
    Projection_WGS84_WorldMercator *proj = new Projection_WGS84_WorldMercator;
    mf->setProjection(proj);

}

mapview::~mapview()
{

}

void mapview::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return && (mf->getState() & MapFrame::MapStateEdit)) {
        LayerListItem *item = static_cast<LayerListItem *>(this->layerList->currentItem());
        QSimpleSpatial::ShapeTypes type =  item->getLayer()->GetShapeType();
        {
            if(type == QSimpleSpatial::PolyLine ||type == QSimpleSpatial::Polygon) {
                Points *points = new Points;
                points->count = p_points.count();
                points->x = new double[points->count];
                points->y = new double[points->count];
                for(int i = 0;i < p_points.count(); i ++) {
                    QSimpleSpatial::SimplePoint &point = p_points[i];
                    point = mf->GetTranslator()->Screen2Coord(point);
                    points->x[i] = point.X;
                    points->y[i] = point.Y;
                }
                p_points.clear();

                if(type == QSimpleSpatial::PolyLine) {
                    PolylineFeature *feature = new PolylineFeature(item->getLayer());
                    feature->AddField("name","Test line");
                    feature->AddPoints(points);
                    item->getLayer()->AddFeature(feature);
                } else {
                    PolygonFeature *feature = new PolygonFeature(item->getLayer());
                    feature->AddField("name","Test polygon");
                    feature->AddPoints(points);
                    item->getLayer()->AddFeature(feature);
                }
            }
        }
        mf->setDirty();
        mf->setState(MapFrame::MapStateMove);
        actionAddPoint->setChecked(false);
        mf->update();
    }
}

Layer *mapview::addLayer(const QString &fileName, ShapeMapReader *smr, Projection *proj,QSimpleSpatial::ShapeTypes shapeType)
{
    Layer *layer;
    if(QFile::exists(fileName))
        layer = smr->ReadFile(fileName,proj);
    else {
        layer = new Layer(shapeType,this);
        layer->setName(fileName);
    }
    QIcon icon;
    switch(layer->GetShapeType())
    {
        case QSimpleSpatial::Point:
            icon.addPixmap(QPixmap("./images/point.png"));
            break;
        case QSimpleSpatial::PolyLine:
            icon.addPixmap(QPixmap("./images/polyline.png"));
            break;
        case QSimpleSpatial::Polygon:
            icon.addPixmap(QPixmap("./images/polygon.png"));
            break;
        default:
            break;
    }
    LayerListItem *item = new LayerListItem(this->layerList);
    item->setCheckState(Qt::Checked);
    item->setIcon(icon);
    item->setText(fileName);
    item->setLayer(layer);
    layerList->addItem(item);
    return layer;
}

void mapview::paint(QPainter &painter)
{
    MapFrame *mf = dynamic_cast<MapFrame *>(sender());
    painter.setPen(Qt::black);
    double X = mf->width() - 110;
    double Y = mf->height() - 50;
    painter.drawLine(X,Y,X + 100,Y);
    painter.drawLine(X + 50,Y,X + 50,Y + 10);
    for(double xx = X;xx <= X + 100;xx += 10)
    {
        painter.drawLine(xx,Y,xx,Y - 5);
    }
    double factor = 1.0 / mf->GetTranslator()->getScaleFactor();
    factor /= 10.0;
    QString postfix;
    if(factor < 2.0)
    {
        postfix = "m";
        factor *= 1000.0;
    }
    else
    {
        postfix = "km";
    }
    painter.drawText(QRectF(X,Y - 30,100,25),
                     Qt::AlignCenter,
                     QString("%1 %2").arg(QString::number(factor,'f',2)).arg(postfix));
    double zoom = mf->GetTranslator()->getZoom();
    painter.drawText(QRectF(X,Y + 5,50,25),
                     Qt::AlignLeft,
                     QString::number(zoom,'f',5));

    lineScale->setText(QString("%1:%2 %3").arg(zoom).arg(QString::number(factor,'f',2)).arg(postfix));

    if(p_points.count() > 0) {
        painter.setPen(Qt::blue);
        for(int i = 1;i < p_points.count();i ++) {
            painter.drawLine(p_points[i - 1].X,p_points[i - 1].Y,p_points[i].X,p_points[i].Y);
        }
        painter.setPen(Qt::green);
        for(int i = 0;i < p_points.count();i ++) {
            painter.drawEllipse(p_points[i].X - 5,p_points[i].Y - 5,10,10);
        }
    }

}

void mapview::mapClicked(QMouseEvent *event)
{
    if(actionShapeInfo->isChecked()) {
        QPoint clickPoint = event->pos();
        QSimpleSpatial::SimplePoint mapPointTopLeft = mf->GetTranslator()->Screen2Coord(clickPoint.x() - 10, clickPoint.y() - 10);
        QSimpleSpatial::SimplePoint mapPointBottomRight = mf->GetTranslator()->Screen2Coord(clickPoint.x() + 10, clickPoint.y() + 10);
        QSimpleSpatial::Extent extent(mapPointTopLeft,mapPointBottomRight);
        QString output;
        foreach(Layer *layer, mf->GetLayers()) {
            if(layer->isVisible()) {
                foreach(Feature *feature, layer->getFeatures()) {
                    if(extent.IsIntersect(feature->GetExtent())) {
                        DataFields data = feature->GetDataFields();
                        QMapIterator<QString, QString> i(data);
                        output += QString("%1\n==============\n").arg(layer->getName());
                        while (i.hasNext()) {
                            i.next();
                            output +=  QString("%1:%2; ").arg(i.key()).arg(i.value());
                        }
                        output += QString("\n------------------\n");
                    }
                }
            }
        }
        QMessageBox::information(this,"Found shapes",output);
    }
}

void mapview::mapReleased(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(mf->getState() & MapFrame::MapStateEdit)
    {
        LayerListItem *item = static_cast<LayerListItem *>(this->layerList->currentItem());
        if(item && item->getLayer()) {
            double x = event->x();
            double y = event->y();
            QSimpleSpatial::SimplePoint point;
            switch(item->getLayer()->GetShapeType())
            {
                case QSimpleSpatial::Point:
                {
                    PointFeature *feature = new PointFeature(item->getLayer(),mf->GetTranslator()->Screen2Coord(x,y));
                    feature->AddField("name","Test point");
                    item->getLayer()->AddFeature(feature);
                }
                    break;
                case QSimpleSpatial::PolyLine:
                case QSimpleSpatial::Polygon:
                    point.X = x;
                    point.Y = y;
                    p_points.append(point);
                    mf->update();
                    break;
                default:
                    break;
            }
            if(item->getLayer()->GetShapeType() == QSimpleSpatial::Point) {
                actionAddPoint->setChecked(false);
                mf->setState(MapFrame::MapStateMove);
            }
            mf->update();
        }
    }
}

void mapview::addShapeFile()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open Shapefile"),
                "",
                "ShapeFile (*.shp)"
                );
    if(!filename.isEmpty()){
        ShapeMapReader * smr = new ShapeMapReader(this);
        Layer *layer = addLayer(filename,
                                smr,
                                mf->getProjection());

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
        default:
            QMessageBox::information(this,"ShapeFile Type unidentified","Shapefile type unidentified");
        }
    }
}

void mapview::addPointLayer(Layer *layer)
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
        mf->AddLayer(layer);
        zoom();
}

void mapview::addPolylineLayer(Layer *layer)
{
        PaintSchemePolyline *schemeCustom = new PaintSchemePolyline(QPen(qRgb(255,128,0)),QBrush(Qt::yellow),5);
        layer->AddScheme(schemeCustom);
        LabelScheme *labelScheme = new LabelScheme("name",QFont("Tahoma",9),QPen(Qt::magenta));
        layer->AddLabelScheme(labelScheme);
        mf->AddLayer(layer);
        zoom();
}

void mapview::addPolygonLayer(Layer *layer)
{
        PaintSchemePolygon *schemeCustom = new PaintSchemePolygon();
        layer->AddScheme(schemeCustom);
        LabelScheme * labelScheme = new LabelScheme("name",QFont("Tahoma",9),QPen(Qt::darkGreen));
        layer->AddLabelScheme(labelScheme);
        mf->AddLayer(layer);
        zoom();
}

void mapview::addPointTriggered(bool checked)
{
    if(checked)
        mf->setState(MapFrame::MapStateEdit);
    else
        mf->setState(MapFrame::MapStateMove);
}

void mapview::saveLayer()
{

}

void mapview::zoom()
{
    mf->GetTranslator()->ZoomTo(1.0);
    mf->updateMap();
}

void mapview::zoomIn()
{
    mf->GetTranslator()->ZoomIn();
    mf->updateMap();
}

void mapview::zoomOut()
{
    mf->GetTranslator()->ZoomOut();
    mf->updateMap();
}

void mapview::layerListChanged(QListWidgetItem *item)
{
    LayerListItem *listItem = static_cast<LayerListItem *>(item);
    if(listItem) {
        if(listItem->checkState() == Qt::Unchecked && listItem->getLayer() && listItem->getLayer()->isVisible()) {
            listItem->getLayer()->setVisible(false);
            mf->updateMap();
        }
        else if(listItem->checkState() == Qt::Checked && listItem->getLayer() && !listItem->getLayer()->isVisible()) {
            listItem->getLayer()->setVisible(true);
            mf->updateMap();
        }
    }
}

void mapview::layerListSelected()
{
    if(this->layerList->currentItem())
    {
        actionAddPoint->setEnabled(true);
    }
}

void mapview::shapeInfo()
{
    if(!actionShapeInfo->isChecked()) {
        mf->setState(MapFrame::MapStateMove);
        mf->setCursor(Qt::ArrowCursor);
    } else {
        mf->setState(MapFrame::MapStateFixed);
        mf->setCursor(Qt::WhatsThisCursor);
    }
}

void mapview::enableToolBar(int tab)
{    
    if(tab == 2){
        toolBar->setEnabled(true);
        statusBar->setEnabled(true);
    }else{
        toolBar->setEnabled(false);
        statusBar->setEnabled(false);
    }
}

