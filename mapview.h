/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QFrame>
#include <QGraphicsView>

QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QToolButton)
QT_FORWARD_DECLARE_CLASS(QPushButton)
QT_FORWARD_DECLARE_CLASS(QSpinBox)
QT_FORWARD_DECLARE_CLASS(QLineEdit)
QT_FORWARD_DECLARE_CLASS(QCheckBox)
QT_FORWARD_DECLARE_CLASS(QTableWidget)

class VariableView;
class MapControl;
class MapGraphicsView;
class MapGraphicsPolygonItem;
class MapGraphicsLineItem;
class MapGraphicsPointItem;
class MapGraphicsLabelItem;
class Layer;
class Projection;
class MapTranslator;


class MapView : public QWidget
{
    Q_OBJECT
public:
    MapView(QWidget *parent = 0);
    MapView &operator=(const MapView &other);

    QGraphicsView *view() const;
    QGraphicsScene *getScene() const;

    const QList<Layer *> &GetLayers();
    MapTranslator *GetTranslator();
    Projection *getProjection() const;
    void setProjection(Projection *projection);
    QString getShapePath();
    void setSettingMap(QWidget *mapConfig);
    void setShapePath(QString path);
    void setVariableView(VariableView *vv);
    int getId(QString field, QString itemName);
    VariableView *getVariableView();
    void openShapeFile(QString shpPath, VariableView *vv);
    void addPolygonLayer(Layer *layer);
    void addPolylineLayer(Layer *layer);
    void addPointLayer(Layer *layer);
    QList<MapGraphicsPolygonItem*>* getItemRegion();
    void filterItem(QList<int> listRegion, QColor color);
    void drawRelation(QString field, QString region1, QString region2);
    QTableWidget *getTableLatLon();

public slots:
    void zoomIn(int level = 1);
    void zoomOut(int level = 1);
    void setCoordinateLineEdit(QString output);
    void setScaleLineEdit(QString output);
    bool isCheckedToggleInfo();
    void resetView();

private slots:
    void setupUi();
    void setResetButtonEnabled();
    void setupMatrix();
    void togglePointerMode();
    void toggleAntialiasing();
    void print();    
    void exportMap();
    void SettingMapOriginal();
    void SettingMapResult(bool);

    QPainterPath drawPainterPath(double a, double b, double c, double d);

    //QList<QString > getID(QString field, QString key);
    //int getRowID(QString id);
    //QList<QString > getFeatureItem(QString id);
    //QString getItem(QString id, QString field);

private:
    MapGraphicsView *graphicsView;
    QGraphicsScene *scene;
    MapControl *mapControl;
    VariableView *vv;

    QBrush p_background;
    MapTranslator *p_renderer;
    Projection *p_projection;
    QString path;
    QWidget *configMap;
    qreal scale;

    QList<MapGraphicsPolygonItem*> itemRegion;
    QList<MapGraphicsLineItem*> itemLine;
    QList<MapGraphicsPointItem*> itemPoint;
    QList<MapGraphicsLabelItem*> itemLabel;

    QCheckBox *antialiasingCheckBox;
    QLabel *label;
    QLabel *label2;
    QLabel *rotateLabel;
    QLabel *coordinateLabel;
    QLabel *scaleLabel;
    QLineEdit *coordinateLineEdit;
    QLineEdit *scaleLineEdit;
    QToolButton *selectModeButton;
    QToolButton *dragModeButton;
    QPushButton *antialiasButton;
    QPushButton *infoButton;
    QPushButton *printButton;
    QPushButton *exportButton;
    QPushButton *settingButton;
    QPushButton *resetButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QSpinBox *rotateSpinBox;

};

#endif
