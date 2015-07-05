#ifndef MAPITEMCOLOR_H
#define MAPITEMCOLOR_H

#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsView>

class MapView;

class MapItemColor: public QGraphicsItem
{
public:
    MapItemColor(QList<QColor> colorList, MapView* mviewResult, QList<QList<int> > temp);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
    void setName(QString name);
    QString getName();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QList<QColor> colorList;
    MapView *mviewResult;
    QList<QList<int> > temp;
    QString name;
};

#endif // MAPITEMCOLOR_H
