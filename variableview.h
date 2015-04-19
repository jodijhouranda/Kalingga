#ifndef VARIABLEVIEW_H
#define VARIABLEVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <spreadsheet.h>
#include <Rcpp.h>
#include <RInside.h>
class VariableView : public QWidget
{
Q_OBJECT
public:
    VariableView(Rcpp::DataFrame frame ,RInside &rconn, QWidget *parent = 0);
    QTableWidget* getVariabelViewTable();
    QTableWidget* getSpreadsheetTable();
    RInside& getRObject();
    QList<QString> getAllVariableNames();
    Rcpp::NumericVector getNumericVector(int idx);
    void createNewVariable(QString name,QString type , QString label);
    void deleteVariable(int idx);
private:
    Spreadsheet* ss ;
    Rcpp::DataFrame frame;
    QTableWidget* variabelTable;
    QTableWidget* table;
    RInside &rconn;
    void getVariabelAttribute();
    QString checkVariableType(QString string);
    void setupAlignment();
private slots:
    void changeVariableName(QTableWidgetItem* item);
};

#endif // VARIABLEVIEW_H
