#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QWidget>
#include <QTableWidget>
#include <Rcpp.h>
class Spreadsheet
{
public:
    Spreadsheet(Rcpp::DataFrame data);
    QTableWidget* getVariabelAttribute();
    QString checkVariableType(QString string);
    QTableWidget* getSpreadsheetTable();
    void dataFrameIterator(QTableWidget* typeTable);
private:

     QTableWidget *table;
     std::vector <std::string> header ;
     int rows;
     int cols;
    Rcpp::DataFrame frame;

};

#endif // SPREADSHEET_H
