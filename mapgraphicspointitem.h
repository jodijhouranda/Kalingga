#ifndef MAPGRAPHICSPOINTITEM_H
#define MAPGRAPHICSPOINTITEM_H


#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsView>


class MapGraphicsPointItem : public QGraphicsItem
{
public:
    MapGraphicsPointItem(double x, double y, int numberPoint, int idFeature, int size, QPen *pen, QBrush *brush);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

public slots:
    void setFillGradient(const QColor &color1, const QColor &color2);
    void setFillColor(const QColor color);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    void setSize(int size);
    void setPolygon(QPolygon polygon);
    void setPixmap(QPixmap pixmap);

private:

    QPen *pen;
    QBrush *brush;
    int numberPoint;
    int idFeature;

    double x;
    double y;
    int size;
    int type;
    QPolygon polygon;
    QPixmap pixmap;
    int pointCount;
    QPainterPath path;
    QPointF *points;
    QColor pointColor;
    QColor fillColor1;
    QColor fillColor2;
    int penWidth;
    QColor penColor;
};

#endif // GRAPHICSPOINTITEM_H
