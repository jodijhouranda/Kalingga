#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T20:15:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KalinggaSoft

## build an app based on the one headers and two source files
SOURCES += main.cpp \
    mainwindow.cpp \
    spreadsheet.cpp \
    mapview.cpp \
    createnewvariable.cpp \
    deletevariable.cpp \
    dialog.cpp \
    histogramcreator.cpp \
    variableview.cpp \
    computevariable.cpp \
    randomsamplegenarator.cpp \
    recodevariable.cpp \
    resultview.cpp \
    resultviewitem.cpp \
    resultindex.cpp \
    chart.cpp \
    chartconfig.cpp \
    histogramconfig.cpp \
    twovariablepicker.cpp \
    scatterconfig.cpp \
    boxconfig.cpp \
    parallechart.cpp \
    parallelchartconfig.cpp \
    integerdelegate.cpp \
    doubledelegate.cpp \
    modifyvariable.cpp \
    descriptivestat.cpp \
    mergedatatable.cpp \
    duplicatevariablledialog.cpp \
    plugindialog.cpp \
    timeseriespicker.cpp \
    labelscheme.cpp \
    mapcolorreader.cpp \
    mapcontrol.cpp \
    mapfitureinfo.cpp \
    mapgraphicslabelitem.cpp \
    mapgraphicslineitem.cpp \
    mapgraphicspointitem.cpp \
    mapgraphicspolygonitem.cpp \
    mapgraphicsview.cpp \
    mapitemcolor.cpp \
    mapitemcolorgraphicsview.cpp \
    mapoption.cpp \
    mapoptiondefault.cpp \
    mapoptiongeneral.cpp \
    mapoptionlabel.cpp \
    mapoptionstyle.cpp \
    maptematik.cpp \
    maptematikboxmap.cpp \
    maptematikconfig.cpp \
    maptematikequalintervals.cpp \
    maptematiknaturalbreaks.cpp \
    maptematikpercentil.cpp \
    maptematikquantile.cpp \
    maptematikstandarddeviation.cpp \
    maptematikuniquevalue.cpp \
    mapvariablechooser.cpp \
    mapvariabletypechooser.cpp \
    paintscheme.cpp \
    paintschemepoint.cpp \
    paintschemepolygon.cpp \
    paintschemepolyline.cpp

HEADERS  += \
    mainwindow.h \
    spreadsheet.h \
    mapview.h \
    createnewvariable.h \
    deletevariable.h \
    dialog.h \
    histogramcreator.h \
    variableview.h \
    computevariable.h \
    randomsamplegenarator.h \
    recodevariable.h \
    resultview.h \
    resultviewitem.h \
    resultindex.h \
    chart.h \
    chartconfig.h \
    histogramconfig.h \
    twovariablepicker.h \
    scatterconfig.h \
    boxconfig.h \
    parallechart.h \
    parallelchartconfig.h \
    integerdelegate.h \
    doubledelegate.h \
    modifyvariable.h \
    descriptivestat.h \
    mergedatatable.h \
    duplicatevariablledialog.h \
    plugindialog.h \
    timeseriespicker.h \
    labelscheme.h \
    mapcolorreader.h \
    mapcontrol.h \
    mapfitureinfo.h \
    mapgraphicslabelitem.h \
    mapgraphicslineitem.h \
    mapgraphicspointitem.h \
    mapgraphicspolygonitem.h \
    mapgraphicsview.h \
    mapitemcolor.h \
    mapitemcolorgraphicsview.h \
    mapoption.h \
    mapoptiondefault.h \
    mapoptiongeneral.h \
    mapoptionlabel.h \
    mapoptionstyle.h \
    maptematik.h \
    maptematikboxmap.h \
    maptematikconfig.h \
    maptematikequalintervals.h \
    maptematiknaturalbreaks.h \
    maptematikpercentil.h \
    maptematikquantile.h \
    maptematikstandarddeviation.h \
    maptematikuniquevalue.h \
    mapvariablechooser.h \
    mapvariabletypechooser.h \
    paintscheme.h \
    paintschemepoint.h \
    paintschemepolygon.h \
    paintschemepolyline.h \
    ui_mapoption.h \
    ui_mapoptiondefault.h \
    ui_mapoptiongeneral.h \
    ui_mapoptionlabel.h \
    ui_mapoptionstyle.h \
    ui_maptematikconfig.h \
    ui_mapvariablechooser.h \
    ui_mapvariabletypechooser.h \
    interfaces.h \
    includes.h


FORMS    += \
    createnewvariable.ui \
    deletevariable.ui \
    dialog.ui \
    histogramcreator.ui \
    computevariable.ui \
    randomsamplegenarator.ui \
    recodevariable.ui \
    histogramconfig.ui \
    twovariablepicker.ui \
    scatterconfig.ui \
    boxconfig.ui \
    parallechart.ui \
    parallelchartconfig.ui \
    modifyvariable.ui \
    descriptivestat.ui \
    mergedatatable.ui \
    duplicatevariablledialog.ui \
    plugindialog.ui \
    timeseriespicker.ui \
    mapoption.ui \
    mapoptiondefault.ui \
    mapoptiongeneral.ui \
    mapoptionlabel.ui \
    mapoptionstyle.ui \
    maptematikconfig.ui \
    mapvariablechooser.ui \
    mapvariabletypechooser.ui

## beyond the default configuration, also use SVG graphics
QT += 			svg

DISTFILES += \
    images/addlayer.png \
    images/addpoint.png \
    images/mapinfo.png \
    images/point.png \
    images/polygon.png \
    images/polyline.png \
    images/savemap.png \
    images/zoom.png \
    images/zoomin.png \
    images/zoomout.png \
    images/arrow.png \
    images/analysis.png \
    images/tools.png \
    color-breawer.csv \


DESTDIR = $$PWD


include (./qsimplespatial/qsimplespatial_static.pri)
include (./qtcolorpicker/src/qtcolorpicker.pri)
## comment this out if you need a different version of R,
## and set set R_HOME accordingly as an environment variable
R_HOME = 		$$system(R RHOME)
#message("R_HOME is" $$R_HOME)

## include headers and libraries for R
RCPPFLAGS = 		$$system($$R_HOME/bin/R CMD config --cppflags)
RLDFLAGS = 		$$system($$R_HOME/bin/R CMD config --ldflags)
RBLAS = 		$$system($$R_HOME/bin/R CMD config BLAS_LIBS)
RLAPACK = 		$$system($$R_HOME/bin/R CMD config LAPACK_LIBS)

## if you need to set an rpath to R itself, also uncomment
RRPATH =		-Wl,-rpath,$$R_HOME/lib

## include headers and libraries for Rcpp interface classes
RCPPINCL = 		$$system($$R_HOME/bin/Rscript -e \"Rcpp:::CxxFlags\(\)\")
RCPPLIBS = 		$$system($$R_HOME/bin/Rscript -e \"Rcpp:::LdFlags\(\)\")

## for some reason when building with Qt we get this each time
##   /usr/local/lib/R/site-library/Rcpp/include/Rcpp/module/Module_generated_ctor_signature.h:25: warning: unused parameter ‘classname
## so we turn unused parameter warnings off
## no longer needed with Rcpp 0.9.3 or later
#RCPPWARNING =		-Wno-unused-parameter

## include headers and libraries for RInside embedding classes
RINSIDEINCL = 		$$system($$R_HOME/bin/Rscript -e \"RInside:::CxxFlags\(\)\")
RINSIDELIBS = 		$$system($$R_HOME/bin/Rscript -e \"RInside:::LdFlags\(\)\")

## compiler etc settings used in default make rules
QMAKE_CXXFLAGS +=	$$RCPPWARNING $$RCPPFLAGS $$RCPPINCL $$RINSIDEINCL
QMAKE_LIBS +=           $$RLDFLAGS $$RBLAS $$RLAPACK $$RINSIDELIBS $$RCPPLIBS

## addition clean targets
QMAKE_CLEAN +=		mainwindow.cpp Makefile

RESOURCES += \
    myfiles.qrc





