#include "mapfitureinfo.h"
#include "variableview.h"

#include <QTreeView>
#include <QStandardItemModel>

#include <QGridLayout>
#include <QDebug>

MapFitureInfo::MapFitureInfo(int itemClick, double x, double y, VariableView *vv, QList<int> itemList, QWidget *parent) :
    vv(vv),
    itemClick(itemClick),
    x(x),
    y(y),
    itemList(itemList),
    QDialog(parent)
{

    createDialog();

}

MapFitureInfo::~MapFitureInfo()
{

}

void MapFitureInfo::createDialog()
{
    this->setWindowTitle("Map Feature Info");
    this->resize(290, 225);
    gridLayout = new QGridLayout(this);
    treeFiture = new QTreeView(this);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->addWidget(treeFiture, 0, 0, 1, 1);
    tablewidget = vv->getSpreadsheetTable();
    fieldCount  = vv->getColumnCount();
    model = new QStandardItemModel( itemClick, 0 );
    for( int r=0; r<itemClick; r++ )
      {
            QStandardItem *fiture = new QStandardItem( QString("%0 (%1)").arg(tablewidget->horizontalHeaderItem(1)->text())
                                                       .arg(tablewidget->item(itemList.value(r)-1,1)->text()));

            QStandardItem *form = new QStandardItem( QString("Form") );
            form->setEditable( false );
            fiture->appendRow( form );
                QStandardItem *formClick = new QStandardItem(QString("Coordinat : %0 , %1").arg(x).arg(y));
                formClick->setEditable(false);
                form->appendRow(formClick);
                QStandardItem *formId = new QStandardItem(QString("ID Fiture : %0").arg(itemList.value(r)));
                formId->setEditable(false);
                form->appendRow(formId);

            QStandardItem *data = new QStandardItem( QString("Data") );
            data->setEditable( false );
            fiture->appendRow( data );
            for(int i=0; i<fieldCount; i++){
                QStandardItem *dataFiture = new QStandardItem(QString("%0 : %1").arg(tablewidget->horizontalHeaderItem(i)->text())
                                                              .arg(tablewidget->item(itemList.value(r)-1,i)->text()));
                dataFiture->setEditable(false);
                data->appendRow(dataFiture);
            }

            model->setItem(r, 0, fiture);

      }

    model->setHorizontalHeaderItem( 0, new QStandardItem( "Feature" ) );

    treeFiture->setModel( model );
}
