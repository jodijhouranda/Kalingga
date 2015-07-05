#ifndef MAPITEMCOLORGRAPHICSVIEW_H
#define MAPITEMCOLORGRAPHICSVIEW_H

#include <QGraphicsView>

class MapView;
class QGraphicsScene;
class MapColorReader;

class MapItemColorGraphicsView : public QGraphicsView
{
public:
    MapItemColorGraphicsView(MapView* mviewResult, QList<QList<int> > temp, int typeMap);

private:

    void initializedPickColorScheme();
    void initializedSequentialColor(MapColorReader *color);
    void initializedDivergingColor(MapColorReader *color);
    void initializedQualitativeColor(MapColorReader *color);
    void initializedCustomColor(MapColorReader *color);

    MapView* mviewResult;
    QList<QList<int> > temp;
    int typeMap;

    QGraphicsScene *scene;
};

#endif // MAPITEMCOLORGRAPHICSVIEW_H
