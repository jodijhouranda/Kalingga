#include "spreadsheet.h"
#include <QDebug>
#include <integerdelegate.h>
#include <doubledelegate.h>
Spreadsheet::Spreadsheet(Rcpp::DataFrame data ):frame(data)
{

    header = frame.names();
    rows = frame.nrows();
    cols = header.size();
    table = new QTableWidget(rows, cols, 0);
        table->setMaximumSize(1365,685);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        for (int c = 0; c < cols; ++c) {
            QString character = QString::fromStdString(header.at(c));
            table->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        }

        for (int i = 0; i < rows; ++i) {
            QString s = QString::number(i+1);
            table->setVerticalHeaderItem(i, new QTableWidgetItem(s));
        }

}

//Spreadsheet::Spreadsheet(QDbf::QDbfTableModel* tableModel) : tableModel(tableModel){
//    rows = tableModel->rowCount();
//    cols = tableModel->columnCount();

//   table = new QTableWidget(rows, cols, 0);
//   for (int c = 0; c < cols; ++c) {
//       table->setHorizontalHeaderItem(c, new QTableWidgetItem(tableModel->headerData(c,Qt::Horizontal).toString()));
//   }
//}

void Spreadsheet::dataFrameIterator(QTableWidget* typeTable){

    QTableWidgetItem* item = new QTableWidgetItem();
    for (int c = 0; c < typeTable->rowCount(); ++c) {
        if (typeTable->item(c,1)->text() == "String") {
                Rcpp::CharacterVector x = frame[header.at(c)];
                for (int r = 0; r < rows; ++r) {
                    if (x[r] == NA_STRING) {

                        item->setText("");
                        table->setItem(r,c, item->clone());

                    }else {

                        item->setText(QString::fromUtf8(x[r]));
                        table->setItem(r,c, item->clone());

                    }

                }
            }

        else if(typeTable->item(c,1)->text() == "Real") {
            table->setItemDelegateForColumn(c ,new DoubleDelegate);
            Rcpp::CharacterVector x = frame[header.at(c)];
            for (int r = 0; r < rows; ++r) {
                if (x[r] == NA_STRING) {

                    item->setText("");
                    table->setItem(r,c, item->clone());

                }else {

                    item->setText(QString::fromUtf8(x[r]));
                    table->setItem(r,c, item->clone());

                }
                       table->item(r,c)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
                }
        }else {
            table->setItemDelegateForColumn(c ,new IntegerDelegate);
            Rcpp::CharacterVector x = frame[header.at(c)];
            for (int r = 0; r < rows; ++r) {
                if (x[r] == NA_STRING) {

                    item->setText("");
                    table->setItem(r,c, item->clone());

                }else {

                    item->setText(QString::fromUtf8(x[r]));
                    table->setItem(r,c, item->clone());

                }
                table->item(r,c)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
            }
        }



}
}

//void Spreadsheet::dbfIterator(QTableWidget* typeTable){
//    QTableWidgetItem* item = new QTableWidgetItem();
//    for (int c = 0; c < typeTable->rowCount(); ++c) {

//                if (typeTable->item(c,1)->text() == "String") {
//                        for (int r = 0; r < rows; ++r) {
//                            QString str = tableModel->index(r,c).data().toString();
//                            if (str.trimmed().length()==0) {

//                                item->setText("");
//                                table->setItem(r,c, item->clone());

//                            }else {
//                                item->setText(str);
//                                table->setItem(r,c, item->clone());
//                            }                     }
//                    }

//                else if(typeTable->item(c,1)->text() == "Real") {
//                        table->setItemDelegateForColumn(c ,new DoubleDelegate);
//                        for (int r = 0; r < rows; ++r) {
//                            QString str = tableModel->index(r,c).data().toString();
//                            if (str.trimmed().length()==0) {

//                                item->setText("");
//                                table->setItem(r,c, item->clone());

//                            }else {
//                                item->setText(str);
//                                table->setItem(r,c, item->clone());
//                            }
//                            table->item(r,c)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
//                        }
//                }else {
//                    table->setItemDelegateForColumn(c ,new IntegerDelegate);
//                    for (int r = 0; r < rows; ++r) {
//                        QString str = tableModel->index(r,c).data().toString();
//                        if (str.trimmed().length()==0) {

//                            item->setText("");
//                            table->setItem(r,c, item->clone());

//                        }else {
//                            item->setText(str);
//                            table->setItem(r,c, item->clone());
//                        }
//                        table->item(r,c)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
//                    }
//                }

//}
//}

QTableWidget* Spreadsheet::getSpreadsheetTable(){
    return table;
}
