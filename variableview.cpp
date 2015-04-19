#include "variableview.h"
#include <QDebug>

VariableView::VariableView(Rcpp::DataFrame frame,RInside &rconn, QWidget *parent):
    frame(frame),
    rconn(rconn)
{
    ss = new Spreadsheet(frame);
    table = ss->getSpreadsheetTable();
    getVariabelAttribute();
    ss->dataFrameIterator(variabelTable);
    setupAlignment();

    connect(variabelTable , SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(changeVariableName(QTableWidgetItem*)));

}
void VariableView::getVariabelAttribute(){


    variabelTable = new QTableWidget(table->columnCount(), 3, 0);
    variabelTable->setMinimumSize(1365,620);
    variabelTable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    std::string  headerVariabel[] = {"Variable","Type","Label"};
    //create Header
    for (int c = 0; c < variabelTable->columnCount(); ++c) {
        QString character = QString::fromStdString(headerVariabel[c]);
        variabelTable->setHorizontalHeaderItem(c, new QTableWidgetItem(character));


        for (int c = 0; c < frame.size(); ++c) {

            Rcpp::CharacterVector vektor = frame[c];
            QString dataType = checkVariableType(QString::fromUtf8(vektor[0]));
            variabelTable->setItem(c,1, new QTableWidgetItem(dataType));
            qDebug() << dataType;
        }
        for (int r = 0; r < table->columnCount(); ++r) {

            QString x = table->horizontalHeaderItem(r)->text();
            variabelTable->setItem(r,0,new QTableWidgetItem(x));


        }
}
}

QString VariableView::checkVariableType(QString string){
      //check if string real
    bool validate;

    string.toInt(&validate);
    if(validate == true){
    return "Integer";
    }
    string.toDouble(&validate);

    if(validate == true){
        return "Real";
    }

        return "String";


}

QTableWidget* VariableView::getVariabelViewTable(){
    return variabelTable;
}
QTableWidget* VariableView::getSpreadsheetTable(){
    return table;
}
// setting table alignment
void VariableView::setupAlignment(){

    for (int r = 0; r < variabelTable->rowCount(); ++r) {
        QString type = variabelTable->item(r,1)->text();
        if ( type == "Integer" || type == "Real" ) {
            for (int i = 0; i < table->rowCount(); ++i) {
                table->item(i,r)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
            }
        }
    }
}

//Edit Variable names

void VariableView::changeVariableName(QTableWidgetItem* item){
    qDebug() << item->row();
    if (item->column() == 0) {
        table->setHorizontalHeaderItem(item->row(),item);
    }
}

//Create New Variable
void VariableView::createNewVariable(QString name, QString type, QString label){
    int row = variabelTable->rowCount();

    variabelTable->insertRow(row);
    variabelTable->setItem(row,0, new QTableWidgetItem(name) );
    variabelTable->setItem(row,1, new QTableWidgetItem(type) );
    variabelTable->setItem(row,2, new QTableWidgetItem(label) );

    table->insertColumn(row);
    table->setHorizontalHeaderItem(row,new QTableWidgetItem(name) );
    variabelTable->setItem(row,0, new QTableWidgetItem(name) );
}

//get All variable in spreadsheet

QList<QString> VariableView::getAllVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        allVar << variabelTable->item(i,0)->text();
    }
    return allVar;
}

// delete one variable
void VariableView::deleteVariable(int idx){
    table->removeColumn(idx);
    variabelTable->removeRow(idx);
}
// retrive variabel value vector
Rcpp::NumericVector VariableView::getNumericVector(int idx){
    Rcpp::NumericVector vector(table->rowCount());
    for (int i = 0; i < table->rowCount(); ++i) {

        vector(i) = table->item(i,idx)->text().toDouble();
    }

    qDebug()<< "sampai";
    return vector;
}

//get R object
RInside& VariableView::getRObject(){
    return rconn;
}
