#include "spreadsheet.h"

Spreadsheet::Spreadsheet(Rcpp::DataFrame data):frame(data)
{

    header = frame.names();
    rows = frame.nrows();
    cols = header.size();
    table = new QTableWidget(rows, cols, this);
        table->setMinimumSize(1365,620);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        for (int c = 0; c < cols; ++c) {
            QString character = QString::fromStdString(header.at(c));
            table->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        }
    dataFrameIterator();
}

void Spreadsheet::dataFrameIterator(){
    for (int c = 0; c < cols; ++c) {
        Rcpp::NumericVector x = frame[header.at(c)];
        for (int r = 0; r < rows; ++r) {
            QString item = QString::number(x[r]);
            table->setItem(r,c,new QTableWidgetItem(item));

        }
    }

}

QTableWidget* Spreadsheet::getVariabelAttribute(){
    QTableWidget* variabelTable = new QTableWidget(table->columnCount(), 2, 0);
        variabelTable->setMinimumSize(1365,620);
        variabelTable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        std::string  headerVariabel[] = {"Variable","Label"};
        //create Header
        for (int c = 0; c < variabelTable->columnCount(); ++c) {
            QString character = QString::fromStdString(headerVariabel[c]);
            variabelTable->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        }
        for (int r = 0; r < table->columnCount(); ++r) {

            QTableWidgetItem* x = table->horizontalHeaderItem(r)->clone();
            variabelTable->setItem(r,0,x);


        }
        return variabelTable;
}




