#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QWidget>
#include <QTableWidget>
#include <Rcpp.h>
#include <QPointer>
#include <qdbftablemodel.h>
class Spreadsheet
{
public:
    Spreadsheet(Rcpp::DataFrame data);
    Spreadsheet(QDbf::QDbfTableModel* tableModel);
    QTableWidget* getVariabelAttribute();
    QString checkVariableType(QString string);
    QTableWidget* getSpreadsheetTable();
    void dataFrameIterator(QTableWidget* typeTable);
    void dbfIterator(QTableWidget* typeTable);
private:

     QTableWidget *table;
     QDbf::QDbfTableModel* tableModel;
     std::vector <std::string> header ;
     int rows;
     int cols;
    Rcpp::DataFrame frame;

};

#endif // SPREADSHEET_H
