#ifndef MAPGRAPHICSPOLYGONITEM_H
#define MAPGRAPHICSPOLYGONITEM_H

#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsView>


class MapGraphicsPolygonItem: public QGraphicsItem
{
public:
    MapGraphicsPolygonItem(const QPainterPath path, int numberRegion,  int idFeature, QPen *pen, QBrush *brush);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

public slots:
    void setFillColor(const QColor color);
    void setSelectBrush(const QBrush &style);
    void setMoverBrush(const QBrush &style);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    void setPenStyle(const Qt::PenStyle &style);
    void setTransparency(const qreal value);
    int getNumberRegion();
    int getIdFeatureRegion();


private:

    QPen *pen;
    QBrush *brush;

    int idFeature;
    int numberRegion;
    const QPainterPath path;
    QColor regionColor;
    QBrush select;
    QBrush mover;
    int penWidth;
    QColor penColor;
    qreal transparancy;
};

#endif // REGION_H
