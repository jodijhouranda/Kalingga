#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QWidget>
#include <QTableWidget>
#include <Rcpp.h>
class Spreadsheet: public QWidget
{
    Q_OBJECT
public:
    Spreadsheet(Rcpp::DataFrame data);
    QTableWidget* getVariabelAttribute();
private:
    void dataFrameIterator();
     QTableWidget *table;
     std::vector <std::string> header ;
     int rows;
     int cols;
    Rcpp::DataFrame frame;

};

#endif // SPREADSHEET_H
