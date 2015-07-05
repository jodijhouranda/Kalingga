#ifndef MAPTEMATIKQUANTILE_H
#define MAPTEMATIKQUANTILE_H

#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>


class MapTematikQuantile : public MapTematik
{
public:
    MapTematikQuantile(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap);
    ~MapTematikQuantile();

    void createMapTematikQuantile();
};

#endif // MAPTEMATIKQUANTILE_H
