

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE      = lib
CONFIG       += plugin
INCLUDEPATH += ../..
DESTDIR = ../plugins
HEADERS += moranplugins.h \
    dialog.h \
    lib/doubledelegate.h \
    lib/integerdelegate.h \
    lib/resultview.h \
    lib/resultviewitem.h \
    lib/spreadsheet.h \
    lib/variableview.h


SOURCES += moranplugins.cpp \
    dialog.cpp \
    lib/doubledelegate.cpp \
    lib/integerdelegate.cpp \
    lib/resultview.cpp \
    lib/resultviewitem.cpp \
    lib/spreadsheet.cpp \
    lib/variableview.cpp


TARGET  = $$qtLibraryTarget(klg_moranplugins)

target.path = ../plugins
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS MoranPlugin.pro
sources.path = ../MoranPlugin
INSTALLS += target sources

FORMS += \
    dialog.ui
## include headers and libraries for R
R_HOME = 		$$system(R RHOME)

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
QMAKE_CLEAN +=		moranplugins.cpp Makefile
