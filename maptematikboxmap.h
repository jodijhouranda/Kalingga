#ifndef MAPTEMATIKBOXMAP_H
#define MAPTEMATIKBOXMAP_H

#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>


class MapTematikBoxMap : public MapTematik
{
public:
    MapTematikBoxMap(MapView *mview, RInside& rconn, VariableView *vv, QString var);
    ~MapTematikBoxMap();

    void createMapTematikBoxmap();

};

#endif // MAPTEMATIKBOXMAP_H
