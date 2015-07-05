#ifndef MAPTEMATIKSTANDARDDEVIATION_H
#define MAPTEMATIKSTANDARDDEVIATION_H

#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>

class MapTematikStandardDeviation : public MapTematik
{
public:
    MapTematikStandardDeviation(MapView *mview, RInside& rconn, VariableView *vv, QString var);
    ~MapTematikStandardDeviation();

    void createMapTematikStandardDeviation();

};

#endif // MAPTEMATIKSTANDARDDEVIATION_H
