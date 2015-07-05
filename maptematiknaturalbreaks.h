#ifndef MAPTEMATIKNATURALBREAKS_H
#define MAPTEMATIKNATURALBREAKS_H

#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>


class MapTematikNaturalBreaks : public MapTematik
{
public:
    MapTematikNaturalBreaks(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap);
    ~MapTematikNaturalBreaks();

    void createMapTematikNaturalBreaks();
};

#endif // MAPTEMATIKNATURALBREAKS_H
