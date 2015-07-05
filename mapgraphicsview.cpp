#include "mapgraphicsview.h"

#include "maptranslator.h"
#include "layer.h"
#include "projection.h"
#include "projection_wgs84_worldmercator.h"
#include "mapfitureinfo.h"
#include "mapgraphicspolygonitem.h"

#include <QtGui>

void MapGraphicsView::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0){
        view->zoomIn();
    }else{
        view->zoomOut();
    }
    e->accept();
    QGraphicsView::wheelEvent(e);
}

void MapGraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    Projection_WGS84_WorldMercator *p = new Projection_WGS84_WorldMercator;
    QSimpleSpatial::SimplePoint coord = view->GetTranslator()->Screen2Coord(e->pos().x(), e->pos().y());
    QSimpleSpatial::SimplePoint co = p->toGeodetic(coord.X,coord.Y);
    QString output;
    output =  QString("%1 , %2 ").arg(static_cast<double>(co.X)).arg(static_cast<double>(co.Y));
    view->setCoordinateLineEdit(output);

    QGraphicsView::mouseMoveEvent(e);
}

void MapGraphicsView::mousePressEvent(QMouseEvent *e)
{
    if(view->isCheckedToggleInfo() && e->button() == Qt::LeftButton){

        int itemClick;
        double coorx;
        double coory;
        QList<int> *item = new QList<int>();
        VariableView *vv = view->getVariableView();

        if(!items(e->pos()).size() == 0){

            centerOn(items(e->pos()).first());
            itemClick = items(e->pos()).size();

            Projection_WGS84_WorldMercator *p = new Projection_WGS84_WorldMercator;
            QSimpleSpatial::SimplePoint coord = view->GetTranslator()->Screen2Coord(e->pos().x(), e->pos().y());
            QSimpleSpatial::SimplePoint co = p->toGeodetic(coord.X,coord.Y);
            coorx = co.X;
            coory = co.Y;

            for(int i=0; i<itemClick; i++){
                MapGraphicsPolygonItem *polygon = static_cast<MapGraphicsPolygonItem *>(items(e->pos()).value(i));
                qDebug() << itemClick;
                item->append(polygon->getNumberRegion());
                qDebug() <<polygon->getNumberRegion();
            }
            MapFitureInfo *dialog = new MapFitureInfo(itemClick, coorx, coory, vv, *item);
            dialog->show();
        }
    }

    QGraphicsView::mousePressEvent(e);
}

void MapGraphicsView::drawBackground(QPainter * painter, const QRectF & rect){
    double faktorLain;
    faktorLain = 0.5;

    double factor = 1.0 / view->GetTranslator()->getScaleFactor();
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
    double zoom = view->GetTranslator()->getZoom();
    view->setScaleLineEdit(QString("%1 : %2%3").arg(zoom).arg(QString::number(factor,'f',2)).arg(postfix));

    QGraphicsView::drawBackground(painter,rect);
}
