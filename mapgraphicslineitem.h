#ifndef MAPGRAPHICSLINEITEM_H
#define MAPGRAPHICSLINEITEM_H

#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsLineItem>
#include <QtGui/QGraphicsView>


class MapGraphicsLineItem : public QGraphicsLineItem
{
public:
    MapGraphicsLineItem(double x1, double y1, double x2, double y2, QPen *pen, QBrush *brush);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

public slots:
    void setFillRule(Qt::FillRule rule);
    void setFillGradient(const QColor &color1, const QColor &color2);
    void setFillColor(const QColor color);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);

private:

    QPen *pen;
    QBrush *brush;

    QLine line;
    double x1;
    double y1;
    double x2;
    double y2;
    QColor lineColor;
    QColor fillColor1;
    QColor fillColor2;
    int penWidth;
    QColor penColor;
};

#endif // GRAPHICSLINEITEM_H
