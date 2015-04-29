#ifndef VARIABLEVIEW_H
#define VARIABLEVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <spreadsheet.h>
#include <Rcpp.h>
#include <RInside.h>
#include <QPointer>
#include <qdbftablemodel.h>
class VariableView : public QWidget
{
Q_OBJECT
public:
    VariableView(Rcpp::DataFrame frame ,RInside &rconn, QWidget *parent = 0);
    VariableView(QDbf::QDbfTableModel* tableModel ,RInside &rconn, QWidget *parent = 0);
    QTableWidget* getVariabelViewTable();
    QTableWidget* getSpreadsheetTable();
    RInside& getRObject();
    //setter getter method
    QList<QString> getAllVariableNames();
    QList<QString> getNumericVariableNames();
    Rcpp::NumericVector getNumericVector(int idx);
    QString getVariableType(QString var);
    void setNumericVariable(QString name, Rcpp::NumericVector vector );
    void setCharacterVariable(QString name, Rcpp::NumericVector vector );
    void setConstantVariable(QString name, double cons);
    int getVariableIndex(QString variabel);
    void createNewVariable(QString name,QString type , QString label);
    void deleteVariable(int idx);
private:
    Spreadsheet* ss ;
    Rcpp::DataFrame frame;
    QDbf::QDbfTableModel* tableModel;
    QTableWidget* variabelTable;
    QTableWidget* table;
    RInside &rconn;
    void getVariabelAttribute();
    void getVariabelAttributeDBF();
    QString checkVariableType(int column);
    QString checkVariableTypeDbf(int column);
    void setupAlignment();
private slots:
    void changeVariableName(QTableWidgetItem* item);
};

#endif // VARIABLEVIEW_H
