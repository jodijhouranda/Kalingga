#ifndef MAPTEMATIKEQUALINTERVALS_H
#define MAPTEMATIKEQUALINTERVALS_H

#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>

class MapTematikEqualIntervals : public MapTematik
{
public:
    MapTematikEqualIntervals(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap);
    ~MapTematikEqualIntervals();

    void createMapTematikEqualValues();
};

#endif // MAPTEMATIKEQUALINTERVALS_H
