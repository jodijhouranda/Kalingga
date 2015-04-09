#include "variableview.h"
#include <QDebug>

VariableView::VariableView(QTableWidget* table):table(table)
{
    getVariabelAttribute();
    setupAlignment();

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
    }

        for (int c = 0; c < table->columnCount(); ++c) {

            QString dataType = checkVariableType(table->item(0,c)->text());
            variabelTable->setItem(c,1, new QTableWidgetItem(dataType));
            qDebug() << dataType;
        }
        for (int r = 0; r < table->columnCount(); ++r) {

            QTableWidgetItem* x = table->horizontalHeaderItem(r)->clone();
            variabelTable->setItem(r,0,x);


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
