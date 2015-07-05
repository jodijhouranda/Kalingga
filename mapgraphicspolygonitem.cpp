#include "mapgraphicspolygonitem.h"

#include "mapview.h"
#include <QtGui>
#include <qpainter.h>
#include <QMessageBox>
#include "qdebug.h"


MapGraphicsPolygonItem::MapGraphicsPolygonItem(const QPainterPath path, int numberRegion, int idFeature, QPen *pen, QBrush *brush)
    : path(path), numberRegion(numberRegion), idFeature(idFeature), pen(pen), brush(brush)
{
    //itemisSelecteble kalo mode group dia ga aktif, tapi kalo moveable masih bisa
    qDebug() << "zzz" << numberRegion;
    transparancy = 1.0;
    setFlags(ItemIsSelectable);
    setAcceptsHoverEvents(true);
}

QRectF MapGraphicsPolygonItem::boundingRect() const
{
    return path.boundingRect();
}

QPainterPath MapGraphicsPolygonItem::shape() const
{
    return path;
}

void MapGraphicsPolygonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (option->state & QStyle::State_Selected) ? brush->color().darker(125) : brush->color();
    painter->setBrush(fillColor);

    if(option->state & QStyle::State_Selected){
        if(select == Qt::NoBrush){
            fillColor = fillColor.darker(125);
            painter->setBrush(fillColor);
        }else
            painter->setBrush(select);
    }else{
        painter->setBrush(*brush);
    }

    if (option->state & QStyle::State_MouseOver){
        if(mover == Qt::NoBrush){
            fillColor = fillColor.lighter(125);
            painter->setBrush(fillColor);
        }else
            painter->setBrush(mover);
        this->setToolTip(QString("Observasi %1").arg(getIdFeatureRegion()));
    }


    painter->setOpacity(transparancy);

    painter->setPen(*pen);
    //bisa gradien, texture, texture image, atau mungkin style jg ganti
    painter->drawPath(path);

}


void MapGraphicsPolygonItem::setFillColor(const QColor color)
{
    brush->setColor(color);
    update();
}

void MapGraphicsPolygonItem::setSelectBrush(const QBrush &style)
{
    select = style;
}

void MapGraphicsPolygonItem::setMoverBrush(const QBrush &style)
{
    mover = style;
}

void MapGraphicsPolygonItem::setPenWidth(int width)
{
    pen->setWidth(width);
    update();
}

void MapGraphicsPolygonItem::setPenColor(const QColor &color)
{
    pen->setColor(color);
    update();
}

void MapGraphicsPolygonItem::setPenStyle(const Qt::PenStyle &style)
{
    pen->setStyle(style);
    update();
}

void MapGraphicsPolygonItem::setTransparency(const qreal value)
{
    transparancy = value;
}

int MapGraphicsPolygonItem::getNumberRegion()
{
    return numberRegion;
}

int MapGraphicsPolygonItem::getIdFeatureRegion()
{
    return idFeature;
}
