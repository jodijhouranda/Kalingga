#ifndef VARIABLEVIEW_H
#define VARIABLEVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <spreadsheet.h>
#include <Rcpp.h>
class VariableView : public QWidget
{
Q_OBJECT
public:
    VariableView(Rcpp::DataFrame frame , QWidget *parent = 0);
    QTableWidget* getVariabelViewTable();
    QTableWidget* getSpreadsheetTable();
private:
    Spreadsheet* ss ;
    Rcpp::DataFrame frame;
    QTableWidget* variabelTable;
    QTableWidget* table;

    void getVariabelAttribute();
    QString checkVariableType(QString string);
    void setupAlignment();
private slots:
    void changeVariableName(QTableWidgetItem* item);
};

#endif // VARIABLEVIEW_H
