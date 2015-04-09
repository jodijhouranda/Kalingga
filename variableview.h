#ifndef VARIABLEVIEW_H
#define VARIABLEVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <spreadsheet.h>
class VariableView
{
public:
    VariableView(QTableWidget* table);
    QTableWidget* getVariabelViewTable();
private:

    QTableWidget* variabelTable;
    QTableWidget* table;
    void getVariabelAttribute();
    QString checkVariableType(QString string);
    void setupAlignment();

};

#endif // VARIABLEVIEW_H
