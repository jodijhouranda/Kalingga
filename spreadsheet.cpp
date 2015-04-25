#include "spreadsheet.h"
#include <QDebug>
Spreadsheet::Spreadsheet(Rcpp::DataFrame data ):frame(data)
{

    header = frame.names();
    rows = frame.nrows();
    cols = header.size();
    table = new QTableWidget(rows, cols, 0);
        table->setMaximumSize(1365,595);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        for (int c = 0; c < cols; ++c) {
            QString character = QString::fromStdString(header.at(c));
            table->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        }

}

Spreadsheet::Spreadsheet(QDbf::QDbfTableModel* tableModel) : tableModel(tableModel){
    rows = tableModel->rowCount();
    cols = tableModel->columnCount();

   table = new QTableWidget(rows, cols, 0);
   for (int c = 0; c < cols; ++c) {
       table->setHorizontalHeaderItem(c, new QTableWidgetItem(tableModel->headerData(c,Qt::Horizontal).toString()));
   }
}

void Spreadsheet::dataFrameIterator(QTableWidget* typeTable){

    QTableWidgetItem* item = new QTableWidgetItem();
    for (int c = 0; c < typeTable->rowCount(); ++c) {
        if (typeTable->item(c,1)->text() == "String") {
                Rcpp::CharacterVector x = frame[header.at(c)];
                for (int r = 0; r < rows; ++r) {
                    item->setText(QString::fromUtf8(x[r]));
                    table->setItem(r,c, item->clone());


                }
            }

        else {
                Rcpp::NumericVector x = frame[header.at(c)];
                for (int r = 0; r < rows; ++r) {
                    item->setText(QString::number(x[r]));
                    table->setItem(r,c, item->clone());
                    table->item(r,c)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
                }
            }



}
}

void Spreadsheet::dbfIterator(QTableWidget* typeTable){
    for (int c = 0; c < typeTable->rowCount(); ++c) {

                for (int r = 0; r < rows; ++r) {
                    QString item = tableModel->index(r,c).data().toString();
                    table->setItem(r,c,new QTableWidgetItem(item));


                }
}
}

QTableWidget* Spreadsheet::getSpreadsheetTable(){
    return table;
}
