#include "mapgraphicslabelitem.h"

#include "mapview.h"
#include <QtGui>
#include <qpainter.h>
#include <QMessageBox>
#include "qdebug.h"

MapGraphicsLabelItem::MapGraphicsLabelItem(QRect rect, QString name) :
    rect(rect), name(name)
{
    penWidth = 1;
    QColor color(255, 235, 123, 127);
    labelColor = color;

    qDebug() << "in graphicLabel";
    setFlags(ItemIsSelectable);
    setAcceptsHoverEvents(true);
    setPlainText("auooooo");
}

QRectF MapGraphicsLabelItem::boundingRect() const
{
    return rect;
}

void MapGraphicsLabelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    //painter->translate(50.0, 50.0);
    //painter->translate(-50.0, -50.0);

    painter->setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    QLinearGradient gradient(0, 0, 0, 100);


    QColor fillColor = (option->state & QStyle::State_Selected) ? labelColor.dark(200) : labelColor;
    if (option->state & QStyle::State_MouseOver){
        fillColor = fillColor.light(150);
        this->setToolTip(QString("%1, %2 : %3, %4")
                         .arg(this->boundingRect().x())
                         .arg(this->boundingRect().y())
                         .arg(this->boundingRect().width())
                         .arg(this->boundingRect().height()));
    }
    gradient.setColorAt(0.0, fillColor1);
    gradient.setColorAt(1.0, fillColor2);
    painter->setBrush(fillColor);
    painter->drawText(rect, "auuoooo");
    painter->drawPoint(rect.x(),rect.y());
}

void MapGraphicsLabelItem::setFillRule(Qt::FillRule rule)
{
    path.setFillRule(rule);
    update();
}

void MapGraphicsLabelItem::setLabelColor(const QColor color)
{
    labelColor = color;
    update();
}

void MapGraphicsLabelItem::setFillGradient(const QColor &color1, const QColor &color2)
{
    fillColor1 = color1;
    fillColor2 = color2;
    update();
}

void MapGraphicsLabelItem::setFillColor(const QColor color)
{
    labelColor = color;
    update();
}

void MapGraphicsLabelItem::setPenWidth(int width)
{
    penWidth = width;
    update();
}

void MapGraphicsLabelItem::setPenColor(const QColor &color)
{
    penColor = color;
    update();
}

int MapGraphicsLabelItem::getNumberLabel()
{
    return numberLabel;
}
