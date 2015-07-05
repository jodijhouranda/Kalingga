#ifndef MAPCOLORREADER_H
#define MAPCOLORREADER_H

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStandardItemModel>

class MapColorReader
{
public:
    MapColorReader();
    ~MapColorReader();

    QList<QColor> getListColor(QString colorName,  QString numOfColor);

private slots:
    void readCsv(QString fileName);
    void checkString(QString &temp, QChar character = 0);

private:
    QStandardItemModel *model;
    QList<QStandardItem*> standardItemList;
};

#endif // MAPCOLORREADER_H
