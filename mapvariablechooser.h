#ifndef MAPVARIABLECHOOSER_H
#define MAPVARIABLECHOOSER_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>

#include "mapview.h"

namespace Ui {
class MapVariableChooser;
}

class MapVariableChooser : public QDialog
{
    Q_OBJECT

public:
    MapVariableChooser(MapView *mview, VariableView* vv ,RInside &rconn,int type,  QWidget *parent = 0);
    ~MapVariableChooser();

    static const int PERCENTIL;
    static const int BOXMAP;
    static const int STANDARDEVIATION;
    static const int UNIQUEVALUE;

private slots:
    void on_buttonBox_accepted();

protected:
    Ui::MapVariableChooser *ui;
    VariableView* vv;
    MapView *mview;
    RInside& rconn;
    int type;
    QString var;

    void setupUi();
    void generatePercentil();
    void generateBoxMap();
    void generateStandarDeviation();
    void generateUniqueValue();
};

#endif // MAPVARIABLECHOOSER_H
