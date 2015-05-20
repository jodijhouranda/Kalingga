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
    layerproperties.cpp \
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
    boxconfig.cpp

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
    layerproperties.h \
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
    boxconfig.h


FORMS    += \
    createnewvariable.ui \
    deletevariable.ui \
    dialog.ui \
    histogramcreator.ui \
    computevariable.ui \
    layerproperties.ui \
    randomsamplegenarator.ui \
    recodevariable.ui \
    histogramconfig.ui \
    twovariablepicker.ui \
    scatterconfig.ui \
    boxconfig.ui

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
    images/arrow.png

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
    icon.qrc
