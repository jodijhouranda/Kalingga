#ifndef MAPTEMATIK_H
#define MAPTEMATIK_H


#include <QDialog>
#include <mapview.h>
#include <variableview.h>
#include <RInside.h>

class MapTematik
{
public:
    MapTematik(MapView *mview, RInside& rconn, VariableView *vv, QString var);
    MapTematik(MapView *mview, RInside& rconn, VariableView *vv, QString var, QString typeMap);
    ~MapTematik();

protected:
    void initializedVariableChooser();
    void initializedVariableTypeChooser();
    void setupResultViewVariableChooser(QString mapName ,QString variable ,QWidget* configWidget);
    void setupResultViewVariableTypeChooser(QString mapName, QString variable, QList<QList<int> > temp,
                                            Rcpp::NumericVector cluster,QWidget* configWidget);

    MapView *mview;
    MapView *mviewResult;
    VariableView *vv;
    RInside& rconn;
    QString var;

    QString typeMap;

    QTableWidget *table;
    int idx;
    Rcpp::NumericVector numvar;
    QList<QColor> listColor;
    QStringList item;
    QList<QWidget*> list;
};

#endif // MAPTEMATIK_H
