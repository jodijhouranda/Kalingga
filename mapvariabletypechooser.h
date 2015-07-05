#ifndef MAPVARIABLETYPECHOOSER_H
#define MAPVARIABLETYPECHOOSER_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>

#include "mapview.h"

namespace Ui {
class MapVariableTypeChooser;
}

class MapVariableTypeChooser : public QDialog
{
    Q_OBJECT

public:
    explicit MapVariableTypeChooser(MapView* mview, VariableView* vv ,RInside &rconn,int type,  QWidget *parent = 0);
    ~MapVariableTypeChooser();

    static const int QUANTILE;
    static const int NATURALBREAKS;
    static const int EQUALINTERVALS;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MapVariableTypeChooser *ui;
    VariableView* vv;
    RInside& rconn;
    MapView *mview;
    MapView *mviewResult;
    int type;

    QString typeMap;
    QString var;

    void setupUi();
    void generateQuantile();
    void generateNaturalBreaks();
    void generateEqualIntervals();
    QList<int> getId(QList<QString> temp, QString var);
};

#endif // MAPVARIABLETYPECHOOSER_H
