#include "mapgraphicslineitem.h"

#include "mapview.h"
#include <QtGui>
#include <qpainter.h>
#include <QMessageBox>
#include "qdebug.h"


MapGraphicsLineItem::MapGraphicsLineItem(double x1, double y1, double x2, double y2, QPen *pen, QBrush *brush)
    : line(x1,y1,x2,y2), pen(pen), brush(brush)
{
    setFlags(ItemIsSelectable);
    setAcceptsHoverEvents(true);
}

QRectF MapGraphicsLineItem::boundingRect() const
{
    qreal extra = (pen->width() + 20) / 2.0;

    return QRectF(line.p1(), QSizeF(line.p2().x() - line.p1().x(),
                                    line.p2().y() - line.p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

QPainterPath MapGraphicsLineItem::shape() const
{
    qreal extra = (pen->width()) / 2.0;
    QRectF rect(line.p1(), QSizeF(line.p2().x() - line.p1().x(),
                                  line.p2().y() - line.p1().y()));
    QPainterPath path;
    path.addRect(rect.normalized()
                 .adjusted(-extra, -extra, extra, extra));
    return path;
}


void MapGraphicsLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QLinearGradient gradient(0, 0, 0, 100);
    gradient.setColorAt(0.0, fillColor1);
    gradient.setColorAt(1.0, fillColor2);

    QColor fillColor = (option->state & QStyle::State_Selected) ? pen->color().darker(125) : pen->color();

    if (option->state & QStyle::State_MouseOver){
        fillColor = fillColor.lighter(125);
        this->setToolTip(QString("%1, %2 : %3, %4")
                         .arg(this->boundingRect().x())
                         .arg(this->boundingRect().y())
                         .arg(this->boundingRect().width())
                         .arg(this->boundingRect().height()));
    }

    painter->setPen(*pen); //bisa diganti style nya || dilema sama fillColor
    painter->setBrush(*brush);
    painter->drawLine(line);
}


void MapGraphicsLineItem::setFillGradient(const QColor &color1, const QColor &color2)
{
    fillColor1 = color1;
    fillColor2 = color2;
    update();
}

void MapGraphicsLineItem::setFillColor(const QColor color)
{
    brush->setColor(color);
    update();
}

void MapGraphicsLineItem::setPenWidth(int width)
{
    pen->setWidth(width);
    update();
}

void MapGraphicsLineItem::setPenColor(const QColor &color)
{
    pen->setColor(color);
    update();
}
