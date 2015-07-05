#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H


#include <QGraphicsView>
#include "mapview.h"

class MapGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MapGraphicsView(MapView *v) : QGraphicsView(), view(v) { }

protected:
    void wheelEvent(QWheelEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void drawBackground(QPainter * painter, const QRectF & rect);

private:
    MapView *view;
};

#endif // MAPGRAPHICSVIEW_H
