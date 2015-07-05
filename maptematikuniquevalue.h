#ifndef MAPTEMATIKUNIQUEVALUE_H
#define MAPTEMATIKUNIQUEVALUE_H

#include "maptematik.h"

#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>

class MapTematikUniqueValue : public MapTematik
{
public:
    MapTematikUniqueValue(MapView *mview, RInside& rconn, VariableView *vv, QString var);
    ~MapTematikUniqueValue();

    void createMapTematikUniqueValue();

};

inline int rrrand(unsigned int min, unsigned int max){
   return (qrand() % (max-min)+1) + min;
}

#endif // MAPTEMATIKUNIQUEVALUE_H
