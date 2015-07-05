#include "mapitemcolor.h"

#include "mapview.h"
#include <QtGui>

MapItemColor::MapItemColor(QList<QColor> colorList, MapView* mviewResult, QList<QList<int> > temp):
    colorList(colorList),
    mviewResult(mviewResult),
    temp(temp)
{
    setFlags(ItemIsSelectable);
    setAcceptsHoverEvents(true);
}

QRectF MapItemColor::boundingRect() const
{
    return QRectF(0, 0, 15, 90);
}

QPainterPath MapItemColor::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 15, 90);
    return path;
}

void MapItemColor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QColor colorRect1 = colorList.value(0);
    QColor colorRect2 = colorList.value(1);
    QColor colorRect3 = colorList.value(2);
    QColor colorRect4 = colorList.value(3);
    QColor colorRect5 = colorList.value(4);
    QColor colorRect6 = colorList.value(5);

    QColor fillColor1 = colorRect1;
    QColor fillColor2 = colorRect2;
    QColor fillColor3 = colorRect3;
    QColor fillColor4 = colorRect4;
    QColor fillColor5 = colorRect5;
    QColor fillColor6 = colorRect6;

    QPen pen;
    pen.setColor(Qt::gray);

    if(option->state & QStyle::State_Selected) {
        pen.setColor(Qt::gray);
        pen.setWidth(3);
        pen.setJoinStyle(Qt::RoundJoin);
        painter->setPen(pen);

    }else{
        painter->setPen(pen);
        fillColor1 =  colorRect1;
        fillColor2 =  colorRect2;
        fillColor3 =  colorRect3;
        fillColor4 =  colorRect4;
        fillColor5 =  colorRect5;
        fillColor6 =  colorRect6;
    }
    if (option->state & QStyle::State_MouseOver){
        pen.setColor(Qt::lightGray);
        pen.setWidth(3);
        painter->setPen(pen);
        fillColor1 = fillColor1.light(125);
        fillColor2 = fillColor2.light(125);
        fillColor3 = fillColor3.light(125);
        fillColor4 = fillColor4.light(125);
        fillColor5 = fillColor5.light(125);
        fillColor6 = fillColor6.light(125);
        this->setToolTip(QString("%1").arg(getName()));
    }

    painter->setBrush(fillColor1);
    painter->drawRect(QRect(0,0,15,15));
    painter->setBrush(fillColor2);
    painter->drawRect(QRect(0,15,15,15));
    painter->setBrush(fillColor3);
    painter->drawRect(QRect(0,30,15,15));
    painter->setBrush(fillColor4);
    painter->drawRect(QRect(0,45,15,15));
    painter->setBrush(fillColor5);
    painter->drawRect(QRect(0,60,15,15));
    painter->setBrush(fillColor6);
    painter->drawRect(QRect(0,75,15,15));

}

void MapItemColor::setName(QString name)
{
    this->name = name;
}

QString MapItemColor::getName()
{
    return this->name;
}

void MapItemColor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for(int i=0; i<temp.size(); i++){
        mviewResult->filterItem(temp.value(i),colorList.value(i));
    }
    mviewResult->getScene()->update();
    QGraphicsItem::mousePressEvent(event);
}


