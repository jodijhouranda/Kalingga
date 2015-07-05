#ifndef MAPFITUREINFO_H
#define MAPFITUREINFO_H

#include <QDialog>

class VariableView;
class QGridLayout;
class QTreeView;
class QTableWidget;
class QStandardItemModel;

class MapFitureInfo : public QDialog
{
    Q_OBJECT
public:
    explicit MapFitureInfo(int itemClick, double x, double y, VariableView *vv, QList<int> item, QWidget *parent = 0);
    ~MapFitureInfo();

signals:

public slots:

private:

    void createDialog();

    QGridLayout *gridLayout;
    QTreeView *treeFiture;
    VariableView *vv;
    int itemClick;
    double x;
    double y;
    QList<int> itemList;
    QTableWidget *tablewidget;
    int fieldCount;
    QStandardItemModel *model;
};

#endif // MAPFITUREINFO_H
