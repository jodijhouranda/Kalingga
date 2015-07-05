#ifndef MAPTEMATIKPERCENTIL_H
#define MAPTEMATIKPERCENTIL_H


#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>

class MapTematikPercentil  : public MapTematik
{
public:
    explicit MapTematikPercentil(MapView *mview, RInside& rconn, VariableView *vv, QString var);
    ~MapTematikPercentil();

    void createMapTematikPercentil();

};

#endif // MAPTEMATIKPERCENTIL_H
