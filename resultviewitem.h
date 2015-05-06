#ifndef RESULTVIEWITEM_H
#define RESULTVIEWITEM_H

#include <QWidget>
#include <QList>
#include <QTreeWidgetItem>
#include <QMap>
class ResultViewItem
{
public:
    ResultViewItem(QStringList listItem ,QList<QWidget*> resultWidget, QString tittle );
    ~ResultViewItem();
    QStringList listItem;
    QList<QWidget*> resultWidget;
    QString tittle;

    QStringList getTreeList();
    QList<QWidget*> getResultWidgets();
    QString getTittle();
};

#endif // RESULTVIEWITEM_H
