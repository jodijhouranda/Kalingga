#ifndef MAPGRAPHICSLABELITEM_H
#define MAPGRAPHICSLABELITEM_H

#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsTextItem>
#include <QtGui/QGraphicsView>

class MapView;

class MapGraphicsLabelItem : public QGraphicsTextItem
{
public:
    MapGraphicsLabelItem(QRect rect, QString name);

    QRectF boundingRect() const;
//    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

public slots:
    void setFillRule(Qt::FillRule rule);
    void setLabelColor(const QColor color);
    void setFillGradient(const QColor &color1, const QColor &color2);
    void setFillColor(const QColor color);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    int getNumberLabel();

private:

    QRect rect;
    QString name;
    MapView *view;
    int numberLabel;
    int pointCount;
    QPainterPath path;
    QPointF *points;
    QColor labelColor;
    QColor fillColor1;
    QColor fillColor2;
    int penWidth;
    QColor penColor;
};

#endif // GRAPHICSLABELITEM_H
