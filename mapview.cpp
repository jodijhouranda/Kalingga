#include "mapview.h"
#include "mapgraphicsview.h"
#include "mapgraphicspolygonitem.h"
#include "mapgraphicslineitem.h"
#include "mapgraphicspointitem.h"
#include "mapgraphicslabelitem.h"
#include "variableview.h"
#include "mapcontrol.h"
#include "mapoption.h"

#include "maptranslator.h"
#include "layer.h"
#include "projection.h"
#include "projection_wgs84_worldmercator.h"

#include <QtGui>
#include <qmath.h>
#include "qdebug.h"


MapView::MapView(QWidget *parent)
    : QWidget(parent), p_renderer(new MapTranslator)
{
    setupUi();
    connect(settingButton, SIGNAL(clicked()), this, SLOT(SettingMapOriginal()));
}

MapView &MapView::operator=(const MapView &other)
{
    if (this == &other)
        return *this;

    graphicsView = other.graphicsView;
    scene = other.scene;
    mapControl = other.mapControl;
    vv = other.vv;

    p_background = other.p_background;
    p_renderer = other.p_renderer;
    p_projection = other.p_projection;
    path = other.path;
    configMap = other.configMap;

    itemRegion = other.itemRegion;
    itemLine = other.itemLine;
    itemPoint = other.itemPoint;
    itemLabel = other.itemLabel;

    antialiasingCheckBox = other.antialiasingCheckBox;
    label = other.label;
    label2 = other.label2;
    rotateLabel = other.rotateLabel;
    coordinateLabel = other.coordinateLabel;
    scaleLabel = other.scaleLabel;
    coordinateLineEdit = other.coordinateLineEdit;
    scaleLineEdit = other.scaleLineEdit;
    selectModeButton = other.selectModeButton;
    dragModeButton = other.dragModeButton;
    antialiasButton = other.antialiasButton;
    infoButton = other.infoButton;
    printButton = other.printButton;
    exportButton = other.exportButton;
    settingButton = other.settingButton;
    resetButton = other.resetButton;
    zoomInButton = other.zoomInButton;
    zoomOutButton = other.zoomOutButton;
    rotateSpinBox = other.rotateSpinBox;

    return *this;
}


void MapView::setupUi()
{
    graphicsView = new MapGraphicsView(this);
    graphicsView->setRenderHint(QPainter::Antialiasing, true);
    graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    p_renderer->setFrameSize(graphicsView->width(),graphicsView->height());
    p_renderer->updateSize();
    qDebug() << QString("width %1 heigh %2").arg(graphicsView->width()).arg(graphicsView->height());
    qDebug() << QString("%1,%2 - %3,%4")
                .arg(p_renderer->getViewport().p1().X)
                .arg(p_renderer->getViewport().p1().Y)
                .arg(p_renderer->getViewport().p2().X)
                .arg(p_renderer->getViewport().p2().Y);
    qDebug() << QString("%1,%2 - %3,%4")
                .arg(p_renderer->getBaseExtent().p1().X)
                .arg(p_renderer->getBaseExtent().p1().Y)
                .arg(p_renderer->getBaseExtent().p2().X)
                .arg(p_renderer->getBaseExtent().p2().Y);

    scene = new QGraphicsScene();
    Projection_WGS84_WorldMercator *proj = new Projection_WGS84_WorldMercator;
    setProjection(proj);
    graphicsView->setScene(scene);
    mapControl = new MapControl(this, scene, &itemRegion, &itemLine, &itemPoint, &itemLabel);



    QPainterPath reg = drawPainterPath(0.0,0.0,60.0,40.0);
    QPainterPath reg2 = drawPainterPath(60,0,120,40);
    QPainterPath reg3 = drawPainterPath(60,40,120,80);
    QPainterPath reg4 = drawPainterPath(0,40,60,80);
    QPainterPath reg5 = drawPainterPath(0,80,120,120);
    QPainterPath elip;
    elip.addEllipse(120,120,30,40);

//        itemRegion.push_back(new MapGraphicsPolygonItem(reg,0, new QPen(), new QBrush));
//        itemRegion.push_back(new MapGraphicsPolygonItem(reg2,1, new QPen(), new QBrush));
//        itemRegion.push_back(new MapGraphicsPolygonItem(reg3,2, new QPen(), new QBrush));
//        itemRegion.push_back(new MapGraphicsPolygonItem(reg4,3, new QPen(), new QBrush));
//        itemRegion.push_back(new MapGraphicsPolygonItem(reg5,4, new QPen(), new QBrush));
//        itemRegion.push_back(new MapGraphicsPolygonItem(elip,5, new QPen(), new QBrush));



//        //QGraphicsItemGroup * cliGroup = scene->createItemGroup(itemRegion);
//        //cliGroup->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
//        //scene->addItem(reg);
//        //scene->addItem(reg2);
//        //scene->addItem(reg3);
//        //scene->addItem(reg4);
//        //scene->addItem(reg5);

//        QGraphicsItemGroup *group = new QGraphicsItemGroup;

//        for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion.begin(); it != itemRegion.end(); it++)
//            group->addToGroup((*it));

//        group->setHandlesChildEvents(false);
//        scene-> addItem(group);


//        int a = 0;
//        int b = 3;
//        int c = 5;
//        QList<int> listRegion;
//        listRegion.append(a);
//        listRegion.append(b);
//        listRegion.append(c);
//        filterItem(listRegion, QColor(Qt::blue));


    //int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
    //QSize iconSize(size, size);

    zoomInButton = new QPushButton;
    QIcon icon2;
    icon2.addFile(QString::fromUtf8("./images/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
    zoomInButton->setIcon(icon2);
    zoomInButton->setToolTip("Zoom In");

    resetButton = new QPushButton;
    resetButton->setEnabled(false);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8("./images/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
    resetButton->setIcon(icon1);
    resetButton->setToolTip("Zoom to layer extent");

    zoomOutButton = new QPushButton;
    QIcon icon3;
    icon3.addFile(QString::fromUtf8("./images/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
    zoomOutButton->setIcon(icon3);
    zoomOutButton->setToolTip("Zoom out");

    label = new QLabel();

    coordinateLineEdit = new QLineEdit;
    coordinateLineEdit->setEnabled(false);
    coordinateLabel = new QLabel(tr("&Coordinate :"));
    coordinateLabel->setBuddy(coordinateLineEdit);

    scaleLabel = new QLabel;
    scaleLabel->setText(tr("Scale :"));
    scaleLineEdit = new QLineEdit;
    coordinateLineEdit->setEnabled(false);

    antialiasingCheckBox = new QCheckBox;
    antialiasingCheckBox->setText(tr("Antialiasing"));
    antialiasingCheckBox->setChecked(true);

    rotateSpinBox = new QSpinBox;
    rotateSpinBox->setRange(-180, 180);
    rotateSpinBox->setSingleStep(5);
    rotateSpinBox->setWrapping(true);
    rotateSpinBox->setSuffix("\xB0");
    rotateLabel = new QLabel(tr("&Rotation :"));
    rotateLabel->setBuddy(rotateSpinBox);

    // Navigation layout
    QHBoxLayout *navigationLayout = new QHBoxLayout;
    navigationLayout->addWidget(label);
    navigationLayout->addStretch();
    navigationLayout->addWidget(coordinateLabel);
    navigationLayout->addWidget(coordinateLineEdit);
    navigationLayout->addWidget(scaleLabel);
    navigationLayout->addWidget(scaleLineEdit);
    navigationLayout->addWidget(antialiasingCheckBox);
    navigationLayout->addWidget(rotateLabel);
    navigationLayout->addWidget(rotateSpinBox);

    // Label layout
    QHBoxLayout *labelLayout = new QHBoxLayout;
    selectModeButton = new QToolButton;
    selectModeButton->setText(tr("Select"));
    selectModeButton->setCheckable(true);
    selectModeButton->setChecked(true);
    QIcon icon4;
    icon4.addFile(QString::fromUtf8("./images/selectcursor"), QSize(), QIcon::Normal, QIcon::Off);
    selectModeButton->setIcon(icon4);
    selectModeButton->setToolTip("Select Feature");

    dragModeButton = new QToolButton;
    dragModeButton->setText(tr("Drag"));
    dragModeButton->setCheckable(true);
    dragModeButton->setChecked(false);
    QIcon icon5;
    icon5.addFile(QString::fromUtf8("./images/movecursor"), QSize(), QIcon::Normal, QIcon::Off);
    dragModeButton->setIcon(icon5);
    dragModeButton->setToolTip("Move Feature");

    infoButton= new QPushButton;
    infoButton->setCheckable(true);
    infoButton->setChecked(false);
    QIcon icon6;
    icon6.addFile(QString::fromUtf8("./images/mapinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    infoButton->setIcon(icon6);
    infoButton->setToolTip("Shape Info");

    printButton = new QPushButton;
    QIcon icon7;
    icon7.addFile(QString::fromUtf8("./images/fileprint.png"), QSize(), QIcon::Normal, QIcon::Off);
    printButton->setIcon(icon7);
    printButton->setToolTip("Print Shape Layer");

    exportButton = new QPushButton;
    QIcon icon8;
    icon8.addFile(QString::fromUtf8("./images/export.png"), QSize(), QIcon::Normal, QIcon::Off);
    exportButton->setIcon(icon8);
    exportButton->setToolTip("Export Layer to Image");

    settingButton =  new QPushButton;
    QIcon icon9;
    icon9.addFile(QString::fromUtf8("./images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
    settingButton->setIcon(icon9);
    settingButton->setToolTip("Setting Map View");

    QButtonGroup *pointerModeGroup = new QButtonGroup;
    pointerModeGroup->setExclusive(true);
    pointerModeGroup->addButton(selectModeButton);
    pointerModeGroup->addButton(dragModeButton);

    labelLayout->addWidget(selectModeButton);
    labelLayout->addWidget(dragModeButton);
    labelLayout->addStretch();
    labelLayout->addWidget(zoomInButton);
    labelLayout->addWidget(resetButton);
    labelLayout->addWidget(zoomOutButton);
    labelLayout->addStretch();
    labelLayout->addWidget(infoButton);
    labelLayout->addWidget(printButton);
    labelLayout->addWidget(exportButton);
    labelLayout->addWidget(settingButton);

    QGridLayout *topLayout = new QGridLayout;
    topLayout->addLayout(labelLayout, 0, 0);
    topLayout->addWidget(graphicsView, 1, 0);
    topLayout->addLayout(navigationLayout, 2, 0);
    setLayout(topLayout);

    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetView()));
    connect(rotateSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
    connect(graphicsView->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
    connect(graphicsView->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
    connect(selectModeButton, SIGNAL(toggled(bool)), this, SLOT(togglePointerMode()));
    connect(dragModeButton, SIGNAL(toggled(bool)), this, SLOT(togglePointerMode()));
    connect(antialiasingCheckBox, SIGNAL(toggled(bool)), this, SLOT(toggleAntialiasing()));
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(printButton, SIGNAL(clicked()), this, SLOT(print()));
    connect(exportButton, SIGNAL(clicked()), this, SLOT(exportMap()));

    scale = 1.0;
    setupMatrix();
}


QGraphicsView *MapView::view() const
{
    return static_cast<QGraphicsView *>(graphicsView);
}

QGraphicsScene *MapView::getScene() const
{
    return static_cast<QGraphicsScene *>(scene);
}

const QList<Layer *> &MapView::GetLayers()
{
    return mapControl->GetLayers();
}

MapTranslator *MapView::GetTranslator()
{
    return p_renderer;
}

Projection *MapView::getProjection() const
{
    return p_projection;
}

void MapView::setProjection(Projection *projection)
{
    p_projection = projection;
}

void MapView::openShapeFile(QString shpPath, VariableView *vv)
{
    setShapePath(shpPath);
    mapControl->openShapeFile(shpPath, vv);

//        drawRelation("DESA", "MENTENG", "CIKINI");
//        drawRelation("DESA", "MENTENG", "GONDANGDIA");
//        drawRelation("DESA", "KEBON SIRIH", "GONDANGDIA");

//            int a = 0;
//            int b = 3;
//            int c = 5;
//            QList<int> listRegion;
//            listRegion.append(a);
//            listRegion.append(b);
//            listRegion.append(c);
//            filterItem(listRegion, QColor(Qt::red));
}

void MapView::addPolygonLayer(Layer *layer)
{
    mapControl->addPolygonLayer(layer);
}

void MapView::addPolylineLayer(Layer *layer)
{
    mapControl->addPolylineLayer(layer);
}

void MapView::addPointLayer(Layer *layer)
{
    mapControl->addPointLayer(layer);
}

QList<MapGraphicsPolygonItem *> *MapView::getItemRegion()
{
    return &itemRegion;
}

void MapView::filterItem(QList<int> listFeature, QColor color)
{
    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion.begin(); it != itemRegion.end(); it++){
        for(int i = 0; i < listFeature.size(); ++i){
        //for(QList<int>::iterator reg = listRegion.begin(); reg != listRegion.end(); reg++){
            if(listFeature.at(i) == (*it)->getIdFeatureRegion()){
            //if(*reg == (*it)->getNumberRegion()){
                (*it)->setFillColor(color);
            }
        }
    }
}

void MapView::drawRelation(QString field, QString region1, QString region2)
{
    int size =5;
    QPoint pointRegion1;
    QPoint pointRegion2;
    QSimpleSpatial::SimplePoint mapPointReg1;
    QSimpleSpatial::SimplePoint mapPointReg2;

    int idRegion1 = getId(field, region1);
    int idRegion2 = getId(field, region2);

    foreach(Layer *layer, this->GetLayers()) {
        if(layer->isVisible()) {
            foreach(Feature *feature, layer->getFeatures()) {
                //QString &type = feature->GetFieldValue(field);
                //    if(type == "town")
                int idFeature = feature->getIdFeature();
                if(idFeature == idRegion1) {
                    mapPointReg1 = this->GetTranslator()->Coord2Screen(feature->getCenter());
                    pointRegion1.setX(mapPointReg1.X);
                    pointRegion1.setY(mapPointReg1.Y);
                }else if(idFeature == idRegion2){
                    mapPointReg2 = this->GetTranslator()->Coord2Screen(feature->getCenter());
                    pointRegion2.setX(mapPointReg2.X);
                    pointRegion2.setY(mapPointReg2.Y);
                }
            }
        }
    }
    scene->addEllipse(pointRegion1.x()-size,pointRegion1.y()-size,2*size,2*size,QPen(Qt::black),QBrush(Qt::red));
    scene->addEllipse(pointRegion2.x()-size,pointRegion2.y()-size,2*size,2*size,QPen(Qt::black),QBrush(Qt::red));\
    scene->addLine(pointRegion1.x(),pointRegion1.y(),pointRegion2.x(),pointRegion2.y(),QPen(Qt::green));
}

QTableWidget *MapView::getTableLatLon()
{
    QTableWidget *tablewidget = vv->getSpreadsheetTable();
    Projection_WGS84_WorldMercator *p = new Projection_WGS84_WorldMercator;
    QTableWidget *tableLatLong = new QTableWidget(vv->getRowCount(), 3);
    QSimpleSpatial::SimplePoint centroid;
    QSimpleSpatial::SimplePoint latlonCoor;

    foreach(Layer *layer, this->GetLayers()) {
        if(layer->isVisible()) {
            int i=0;
            foreach(Feature *feature, layer->getFeatures()) {

                centroid = feature->getCenter();
                latlonCoor = p->toGeodetic(centroid.X,centroid.Y);

                QTableWidgetItem *idFeature = new QTableWidgetItem(QString("%0").arg(tablewidget->verticalHeaderItem(i)->text()));
                tableLatLong->setItem(i,0,idFeature);

                QTableWidgetItem *latitude = new QTableWidgetItem(QString("%0").arg(latlonCoor.X));
                tableLatLong->setItem(i,1,latitude);

                QTableWidgetItem *longitude = new QTableWidgetItem(QString("%0").arg(latlonCoor.Y));
                tableLatLong->setItem(i,2,longitude);
                i++;

            }
        }

    }

    QStringList label;
    label << "ID" << "Latitude" << "Longitude";
    tableLatLong->setHorizontalHeaderLabels(label);

    return tableLatLong;
}


void MapView::resetView()
{
    rotateSpinBox->setValue(0);
    scale = 1.0;
    this->GetTranslator()->ZoomTo(1.0);
    setupMatrix();
    graphicsView->ensureVisible(QRectF(0, 0, 0, 0));

    resetButton->setEnabled(false);
}

void MapView::setResetButtonEnabled()
{
    resetButton->setEnabled(true);
}

QString MapView::getShapePath()
{
    return path;
}

void MapView::setSettingMap(QWidget *mapConfig)
{
    this->configMap = mapConfig;
    this->configMap->hide();
    disconnect(settingButton, SIGNAL(clicked()), 0, 0);
    this->settingButton->setCheckable(true);
    this->settingButton->setChecked(false);
    connect(settingButton, SIGNAL(clicked(bool)), this, SLOT(SettingMapResult(bool)));
}

void MapView::setShapePath(QString path)
{
    this->path = path;
    label->setText(path);
    label->setToolTip(path);
}

void MapView::setVariableView(VariableView *vv)
{
    this->vv = vv;
}

int MapView::getId(QString field, QString itemName)
{
    int idx = vv->getVariableIndex(field);
    int row = vv->getRowCount();
    QTableWidget *tablewidget = vv->getSpreadsheetTable();
    int id;
    QString item;
    for(int i=0; i<row; i++){
        item = tablewidget->item(i,idx)->text();
        if(item == itemName){
            id = tablewidget->verticalHeaderItem(i)->text().toInt();
        }
    }
    return id;
}

VariableView *MapView::getVariableView()
{
    return this->vv;
}

void MapView::setupMatrix()
{
    QMatrix matrix;
    matrix.scale(1 * scale, 1 * scale);
    matrix.rotate(rotateSpinBox->value());

    graphicsView->setMatrix(matrix);
    setResetButtonEnabled();
}

void MapView::togglePointerMode()
{
    graphicsView->setDragMode(selectModeButton->isChecked()
                              ? QGraphicsView::RubberBandDrag
                              : QGraphicsView::ScrollHandDrag);
    graphicsView->setInteractive(selectModeButton->isChecked());
}


void MapView::toggleAntialiasing()
{
    graphicsView->setRenderHint(QPainter::Antialiasing, antialiasingCheckBox->isChecked());
}

void MapView::print()
{
#ifndef QT_NO_PRINTER
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        graphicsView->render(&painter);
    }
#endif
}

void MapView::exportMap()
{
    QString fileName= QFileDialog::getSaveFileName(this, "Save image", QCoreApplication::applicationDirPath(), "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)" );

    if (fileName.isNull())
        return;

    if (! (fileName.endsWith(".png", Qt::CaseInsensitive) ) )

    scene->clearSelection();                                                  // Selections would also render to the file
    scene->setSceneRect(scene->itemsBoundingRect());                          // Re-shrink the scene to it's bounding contents
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
    image.fill(Qt::transparent);                                              // Start all pixels transparent

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter);
    image.save(fileName);
}

void MapView::SettingMapOriginal()
{
    MapOption* dialog = new MapOption(this, vv);
    dialog->show();
}

void MapView::SettingMapResult(bool value)
{
    if(value)
        configMap->show();
    else
        configMap->hide();
}

void MapView::zoomIn(int level)
{
    scale*=2;
    this->GetTranslator()->ZoomIn();
    this->setupMatrix();
}

void MapView::zoomOut(int level)
{
    scale/=2;
    this->GetTranslator()->ZoomOut();
    this->setupMatrix();
}

void MapView::setCoordinateLineEdit(QString output)
{
    coordinateLineEdit->setText(output);
}

void MapView::setScaleLineEdit(QString output)
{
    scaleLineEdit->setText(output);
}

bool MapView::isCheckedToggleInfo()
{
    return infoButton->isChecked();
}

QPainterPath MapView::drawPainterPath(double a, double b, double c, double d)
{
    QPainterPath rectPath;
        rectPath.moveTo(a, b);
        rectPath.lineTo(c, b);
        rectPath.lineTo(c, d);
        rectPath.lineTo(a, d);
        rectPath.closeSubpath();
    return rectPath;
}
