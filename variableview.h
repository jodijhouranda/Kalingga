#ifndef VARIABLEVIEW_H
#define VARIABLEVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <spreadsheet.h>
#include <Rcpp.h>
#include <RInside.h>
#include <QPointer>
#include <qdbftablemodel.h>
#include <integerdelegate.h>
#include <doubledelegate.h>
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
    QList<QString> getRealVariableNames();
    Rcpp::NumericVector getNumericVector(int idx);
    Rcpp::CharacterVector getCharacterVector(int idx);
    QString getVariableType(QString var);
    QString getVariableLabel(QString var);
    QString getVariableName(int idx);
    void setShapePath(QString path);
    void setDataPath(QString path);
    QString getShapePath();
    QString getDataPath();
    void sendDataFrame(RInside& m_r);
    void sendDataFrameByVar(QStringList var,RInside& m_r);
    void setNumericVariable(QString name, Rcpp::NumericVector vector );
    void setCharacterVariable(QString name, Rcpp::NumericVector vector );
    void setCharacterVector(QString name, Rcpp::CharacterVector vector );
    void setConstantVariable(QString name, double cons);
    void setIntegerVariable(QString name ,Rcpp::NumericVector vector );
    int getVariableIndex(QString variabel);
    void createNewVariable(QString name,QString type , QString label,int before);
    void deleteVariable(int idx);
    void changeVarName(int idx,QString name);
    int getRowCount();
    int getColumnCount();
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

    QString shapePath;
    QString dataPath;

private slots:
    void changeVariableName(QTableWidgetItem* item);
};

#endif // VARIABLEVIEW_H
