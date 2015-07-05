#ifndef MAPOPTION_H
#define MAPOPTION_H

#include <QDialog>

class MapView;
class VariableView;
class QGridLayout;

namespace Ui {
class MapOption;
}

class MapOption : public QDialog
{
    Q_OBJECT

public:
    explicit MapOption(MapView* mview, VariableView* vv, QWidget *parent = 0);
    ~MapOption();

private:
    Ui::MapOption *ui;
    MapView* mview;
    VariableView* vv;
    QGridLayout *gridLayout;

};

#endif // MAPOPTION_H
