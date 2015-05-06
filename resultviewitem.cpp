#include "resultviewitem.h"

ResultViewItem::ResultViewItem(QStringList listItem ,QList<QWidget*> resultWidget, QString tittle ) :
    listItem(listItem),
    resultWidget(resultWidget),
    tittle(tittle)
{

}

ResultViewItem::~ResultViewItem()
{

}

QStringList ResultViewItem::getTreeList(){
    return listItem;
}

QList<QWidget*> ResultViewItem::getResultWidgets(){
    return resultWidget;
}

QString ResultViewItem::getTittle(){
    return tittle;
}
