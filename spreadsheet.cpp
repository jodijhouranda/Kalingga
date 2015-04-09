#include "spreadsheet.h"

Spreadsheet::Spreadsheet(Rcpp::DataFrame data):frame(data)
{

    header = frame.names();
    rows = frame.nrows();
    cols = header.size();
    table = new QTableWidget(rows, cols, 0);
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

        Rcpp::CharacterVector x = frame[header.at(c)];
        for (int r = 0; r < rows; ++r) {
            QString item = QString::fromUtf8(x[r]);
            table->setItem(r,c,new QTableWidgetItem(item));


        }
    }

}

QTableWidget* Spreadsheet::getSpreadsheetTable(){
    return table;
}
