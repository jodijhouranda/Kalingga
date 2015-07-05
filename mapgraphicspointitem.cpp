#include "mapgraphicspointitem.h"

#include "mapview.h"
#include <QtGui>
#include <qpainter.h>
#include <QMessageBox>
#include "qdebug.h"

MapGraphicsPointItem::MapGraphicsPointItem(double x, double y, int numberPoint, int idFeature,  int size, QPen *pen, QBrush *brush) :
    x(x), y(y), numberPoint(numberPoint), idFeature(idFeature), size(size), pen(pen), brush(brush)
{
    qDebug() << "in graphicPoint";
    setFlags(ItemIsSelectable);
    setAcceptsHoverEvents(true);
}


QRectF MapGraphicsPointItem::boundingRect() const
{
    return QRectF(x-(size/2), y-(size/2), size, size);
}

QPainterPath MapGraphicsPointItem::shape() const
{
    QPainterPath path;
    path.addRect(x-(size/2), y-(size/2), size, size);
    return path;
}

void MapGraphicsPointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QLinearGradient gradient(0, 0, 0, 100);
    gradient.setColorAt(0.0, fillColor1);
    gradient.setColorAt(1.0, fillColor2);

    QColor fillColor = (option->state & QStyle::State_Selected) ? brush->color().darker(200) : brush->color();
    if (option->state & QStyle::State_MouseOver){
        fillColor = fillColor.lighter(150);
        this->setToolTip(QString("%1, %2 : %3, %4")
                         .arg(this->boundingRect().x())
                         .arg(this->boundingRect().y())
                         .arg(this->boundingRect().width())
                         .arg(this->boundingRect().height()));
    }

    if(type != 3) {
        painter->setPen(*pen);
        painter->setBrush(fillColor);
    }

    switch(type) {
    case 1:
        painter->drawEllipse(QRectF(x-(size/2), y-(size/2), size, size));
        break;
    case 2:
        painter->drawPolygon(polygon.translated(x, y));
        break;
    case 3:
        painter->drawPixmap(x, y, pixmap);
        break;
    default:        
        painter->drawEllipse(QRectF(x-(size/2), y-(size/2), size, size));
        break;
    }
}


void MapGraphicsPointItem::setFillGradient(const QColor &color1, const QColor &color2)
{
    fillColor1 = color1;
    fillColor2 = color2;
    update();
}

void MapGraphicsPointItem::setFillColor(const QColor color)
{
    brush->setColor(color);
    update();
}

void MapGraphicsPointItem::setPenWidth(int width)
{
    pen->setWidth(width);
    update();
}

void MapGraphicsPointItem::setPenColor(const QColor &color)
{
    pen->setColor(color);
    update();
}

void MapGraphicsPointItem::setSize(int size)
{
    this->type =  1;
    this->size =  size;
}

void MapGraphicsPointItem::setPolygon(QPolygon polygon)
{
    this->type = 2;
    this->polygon =  polygon;
}

void MapGraphicsPointItem::setPixmap(QPixmap pixmap)
{
    this->type = 3;
    this->pixmap =  pixmap;
}

