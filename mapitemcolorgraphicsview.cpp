#include "mapitemcolorgraphicsview.h"

#include "mapview.h"
#include "mapcolorreader.h"
#include "mapitemcolor.h"
#include <QGraphicsItem>

MapItemColorGraphicsView::MapItemColorGraphicsView(MapView* mviewResult, QList<QList<int> > temp, int typeMap) :
    mviewResult(mviewResult),
    temp(temp),
    typeMap(typeMap)
{
    initializedPickColorScheme();
}


void MapItemColorGraphicsView::initializedPickColorScheme()
{
    // 0 = sudah ditentukan jumlah cluster (diverging)
    // 1 = untuk map unique value
    // >1 = untuk clustering map umum
    // <0 = untuk custom

    scene =  new QGraphicsScene();
    MapColorReader *color = new MapColorReader();
    if(typeMap > 1 ){
        initializedSequentialColor(color);
    }
    else if(typeMap == 0 ){
        initializedDivergingColor(color);
    }
    else if(typeMap == 1){
        initializedQualitativeColor(color);
    }else{
        initializedCustomColor(color);
    }

    int range=0;
    for(QList<QGraphicsItem*>::iterator it = scene->items().begin(); it != scene->items().end(); it++)
    {
        (*it)->setPos(QPointF(-80 + range, -60));
        range += 20;
    }
    this->setScene(scene);
}

void MapItemColorGraphicsView::initializedSequentialColor(MapColorReader* color)
{
    //Singgle Hue
    MapItemColor *Blues =  new MapItemColor(color->getListColor("Blues", "10"),mviewResult,temp);
    Blues->setName("Blues");
    scene->addItem(Blues);
    MapItemColor *Greens =  new MapItemColor(color->getListColor("Greens", "10"),mviewResult,temp);
    Greens->setName("Greens");
    scene->addItem(Greens);
    MapItemColor *Greys =  new MapItemColor(color->getListColor("Greys", "10"),mviewResult,temp);
    Greys->setName("Greens");
    scene->addItem(Greys);
    MapItemColor *Oranges =  new MapItemColor(color->getListColor("Oranges", "10"),mviewResult,temp);
    Oranges->setName("Oranges");
    scene->addItem(Oranges);
    MapItemColor *Purples =  new MapItemColor(color->getListColor("Purples", "10"),mviewResult,temp);
    Purples->setName("Purples");
    scene->addItem(Purples);
    MapItemColor *Reds =  new MapItemColor(color->getListColor("Reds", "10"),mviewResult,temp);
    Reds->setName("Reds");
    scene->addItem(Reds);

    //Multi Hue
    MapItemColor *BuGn =  new MapItemColor(color->getListColor("BuGn", "10"),mviewResult,temp);
    BuGn->setName("BuGn");
    scene->addItem(BuGn);
    MapItemColor *BuPu =  new MapItemColor(color->getListColor("BuPu", "10"),mviewResult,temp);
    BuPu->setName("BuPu");
    scene->addItem(BuPu);
    MapItemColor *GnBu =  new MapItemColor(color->getListColor("GnBu", "10"),mviewResult,temp);
    GnBu->setName("GnBu");
    scene->addItem(GnBu);
    MapItemColor *OrRd =  new MapItemColor(color->getListColor("OrRd", "10"),mviewResult,temp);
    OrRd->setName("OrRd");
    scene->addItem(OrRd);
    MapItemColor *PuBu =  new MapItemColor(color->getListColor("PuBu", "10"),mviewResult,temp);
    PuBu->setName("PuBu");
    scene->addItem(PuBu);
    MapItemColor *PuBuGn =  new MapItemColor(color->getListColor("PuBuGn", "10"),mviewResult,temp);
    PuBuGn->setName("PuBuGn");
    scene->addItem(PuBuGn);
    MapItemColor *PuRd =  new MapItemColor(color->getListColor("PuRd", "10"),mviewResult,temp);
    PuRd->setName("PuRd");
    scene->addItem(PuRd);
    MapItemColor *RdPu =  new MapItemColor(color->getListColor("RdPu", "10"),mviewResult,temp);
    RdPu->setName("RdPu");
    scene->addItem(RdPu);
    MapItemColor *YlGn =  new MapItemColor(color->getListColor("YlGn", "10"),mviewResult,temp);
    YlGn->setName("YlGn");
    scene->addItem(YlGn);
    MapItemColor *YlGnBu =  new MapItemColor(color->getListColor("YlGnBu", "10"),mviewResult,temp);
    YlGnBu->setName("YlGnBu");
    scene->addItem(YlGnBu);
    MapItemColor *YlOrBr =  new MapItemColor(color->getListColor("YlOrBr", "10"),mviewResult,temp);
    YlOrBr->setName("YlOrBr");
    scene->addItem(YlOrBr);
    MapItemColor *YlOrRd =  new MapItemColor(color->getListColor("YlOrRd", "10"),mviewResult,temp);
    YlOrRd->setName("YlOrRd");
    scene->addItem(YlOrRd);

}

void MapItemColorGraphicsView::initializedDivergingColor(MapColorReader* color)
{
    MapItemColor *BrBG =  new MapItemColor(color->getListColor("BrBG", "6"),mviewResult,temp);
    BrBG->setName("BrBG");
    scene->addItem(BrBG);
    MapItemColor *PiYG =  new MapItemColor(color->getListColor("PiYG", "6"),mviewResult,temp);
    PiYG->setName("PiYG");
    scene->addItem(PiYG);
    MapItemColor *PRGn =  new MapItemColor(color->getListColor("PRGn", "6"),mviewResult,temp);
    PRGn->setName("PRGn");
    scene->addItem(PRGn);
    MapItemColor *PuOr =  new MapItemColor(color->getListColor("PuOr", "6"),mviewResult,temp);
    PuOr->setName("PuOr");
    scene->addItem(PuOr);
    MapItemColor *RdBu =  new MapItemColor(color->getListColor("RdBu", "6"),mviewResult,temp);
    RdBu->setName("RdBu");
    scene->addItem(RdBu);
    MapItemColor *RdGy =  new MapItemColor(color->getListColor("RdGy", "6"),mviewResult,temp);
    RdGy->setName("RdGy");
    scene->addItem(RdGy);
    MapItemColor *RdYlBu =  new MapItemColor(color->getListColor("RdYlBu", "6"),mviewResult,temp);
    RdYlBu->setName("RdYlBu");
    scene->addItem(RdYlBu);
    MapItemColor *RdYlGn =  new MapItemColor(color->getListColor("RdYlGn", "6"),mviewResult,temp);
    RdYlGn->setName("RdYlGn");
    scene->addItem(RdYlGn);
    MapItemColor *Spectral =  new MapItemColor(color->getListColor("Spectral", "6"),mviewResult,temp);
    Spectral->setName("Spectral");
    scene->addItem(Spectral);

}

void MapItemColorGraphicsView::initializedQualitativeColor(MapColorReader* color)
{
    // 8 class
    if(typeMap <= 8){
        MapItemColor *Accent =  new MapItemColor(color->getListColor("Accent", "8"),mviewResult,temp);
        Accent->setName("Accent");
        scene->addItem(Accent);
        MapItemColor *Dark2 =  new MapItemColor(color->getListColor("Dark2", "8"),mviewResult,temp);
        Dark2->setName("Dark2");
        scene->addItem(Dark2);
        MapItemColor *Pastel2 =  new MapItemColor(color->getListColor("Pastel2", "8"),mviewResult,temp);
        Pastel2->setName("Pastel2");
        scene->addItem(Pastel2);
        MapItemColor *Set2 =  new MapItemColor(color->getListColor("Set2", "8"),mviewResult,temp);
        Set2->setName("Set2");
        scene->addItem(Set2);
    }

    // 9 class
    if(typeMap <= 9){
        MapItemColor *Pastel1 =  new MapItemColor(color->getListColor("Pastel1", "9"),mviewResult,temp);
        Pastel1->setName("Pastel1");
        scene->addItem(Pastel1);
        MapItemColor *Set1 =  new MapItemColor(color->getListColor("Set1", "9"),mviewResult,temp);
        Set1->setName("Set1");
        scene->addItem(Set1);
    }

    // 12 class
    if(typeMap <= 12){
        MapItemColor *Paired =  new MapItemColor(color->getListColor("Paired", "12"),mviewResult,temp);
        Paired->setName("Paired");
        scene->addItem(Paired);
        MapItemColor *Set3 =  new MapItemColor(color->getListColor("Set3", "12"),mviewResult,temp);
        Set3->setName("Set3");
        scene->addItem(Set3);
    }
}

void MapItemColorGraphicsView::initializedCustomColor(MapColorReader* color)
{

}
