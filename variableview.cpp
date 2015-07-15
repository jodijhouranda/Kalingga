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
    connect(variabelTable , SIGNAL(itemEntered(QTableWidgetItem*)),this,SLOT(changeVariableName(QTableWidgetItem*)));

}

//VariableView::VariableView(QDbf::QDbfTableModel* tableModel ,RInside &rconn, QWidget *parent):
//tableModel(tableModel),
//rconn(rconn)
//{
//    ss = new Spreadsheet(tableModel);
//    table = ss->getSpreadsheetTable();
//    getVariabelAttributeDBF();
//    ss->dbfIterator(variabelTable);
//    setupAlignment();
//    connect(variabelTable , SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(changeVariableName(QTableWidgetItem*)));

//}

void VariableView::getVariabelAttribute(){


    variabelTable = new QTableWidget(table->columnCount(), 3, 0);
    variabelTable->setMaximumSize(1365,685);
    variabelTable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    std::string  headerVariabel[] = {"Variable","Type","Label"};
    //create Header
    for (int c = 0; c < variabelTable->columnCount(); ++c) {
        QString character = QString::fromStdString(headerVariabel[c]);
        variabelTable->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        if (c==0) {
            for (int r = 0; r < table->columnCount(); ++r) {

                QString x = table->horizontalHeaderItem(r)->text();
                variabelTable->setItem(r,0,new QTableWidgetItem(x));


            }
        }
        else if (c == 1) {
            for (int r = 0; r < variabelTable->rowCount(); ++r) {
                QString dataType = checkVariableType(r);
                QTableWidgetItem* item = new QTableWidgetItem(dataType);
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                variabelTable->setItem(r,1,item );

            }
        }
        else if(c==2) {
            for (int r = 0; r < table->columnCount(); ++r) {
                variabelTable->setItem(r,2,new QTableWidgetItem());
            }
        }


}
}

//void VariableView::getVariabelAttributeDBF(){

//    variabelTable = new QTableWidget(table->columnCount(), 3, 0);
//    variabelTable->setMinimumSize(1365,620);
//    variabelTable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    std::string  headerVariabel[] = {"Variable","Type","Label"};
//    //create Header
//    for (int c = 0; c < variabelTable->columnCount(); ++c) {
//        QString character = QString::fromStdString(headerVariabel[c]);
//        variabelTable->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
//        if (c == 0) {
//            for (int r = 0; r < table->columnCount(); ++r) {

//                QString x = tableModel->headerData(r,Qt::Horizontal).toString();
//                variabelTable->setItem(r,0,new QTableWidgetItem(x));


//            }
//        }else if (c == 1) {
//            for (int c = 0; c < variabelTable->rowCount(); ++c) {

//                QString dataType = checkVariableTypeDbf(c);
//                QTableWidgetItem* item = new QTableWidgetItem(dataType);
//                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
//                variabelTable->setItem(c,1,item );

//            }
//        }
//        else if(c==2) {
//            for (int r = 0; r < table->columnCount(); ++r) {
//                variabelTable->setItem(r,2,new QTableWidgetItem());
//            }
//        }



//}
//}

QString VariableView::checkVariableType(int column){
      //check if string real
    QRegExp re("[+-]?\\d*\\.?\\d+");
    Rcpp::CharacterVector vektor = frame[column];
    QString string =QString::fromUtf8(vektor[0]);

    if (!re.exactMatch(string) && string.trimmed().length()>0 && vektor[0] != NA_STRING)
        return "String";

    bool validate;
    int lastIndex = 0;
    int result = 0;
    for (int i = 0; i < vektor.length(); ++i) {
        lastIndex = i;
        QString string = QString::fromUtf8(vektor[i]);
        if (!string.trimmed().length()>0 || vektor[i] == NA_STRING) continue;
        string.toInt(&validate);

        if(validate == false){
            if (!re.exactMatch(string))
                return "String";

            lastIndex = i;
            break;
        }


        result = 1;
    }
    if (lastIndex+1 != vektor.length()) {
        for (int j = lastIndex; j <  vektor.length(); ++j) {
            QString string = QString::fromUtf8(vektor[0]);
            if (!string.trimmed().length()>0 || vektor[j] == NA_STRING) continue;
            string.toDouble(&validate);
            if(validate == false){

                if (!re.exactMatch(string))
                    return "String";
                break;
            }

        result = 2;
        }

    }

    switch (result) {
case 0:
        return "String";
        break;
case 1:
    return "Integer";
    break;
case 2:
    return "Real";
    break;
}

}

//QString VariableView::checkVariableTypeDbf(int column){
//      //check if string real
//    QRegExp re("[+-]?\\d*\\.?\\d+");
//    if (!re.exactMatch(tableModel->index(0,column).data().toString()) && tableModel->index(0,column).data().toString().trimmed().length()>0)
//        return "String";

//    bool validate;
//    int lastIndex = 0;
//    int result = 0;
//    for (int i = 0; i < tableModel->rowCount(); ++i) {
//        lastIndex = i;
//        QString string = tableModel->index(i,column).data().toString();
//        if (string.trimmed().length()<=0) continue;
//        string.toInt(&validate);

//        if(validate == false){
//            if (!re.exactMatch(string))
//                return "String";

//            lastIndex = i;
//            break;
//        }


//        result = 1;
//    }
//    if (lastIndex+1 != tableModel->rowCount()) {
//        for (int j = lastIndex; j < tableModel->rowCount(); ++j) {
//            QString string = tableModel->index(j,column).data().toString();
//            if (string.trimmed().length()<=0) continue;
//            string.toDouble(&validate);
//            if(validate == false){

//                if (!re.exactMatch(string))
//                    return "String";
//                break;
//            }

//        result = 2;
//        }

//    }

//    switch (result) {

//    case 0:
//            return "String";
//            break;
//    case 1:
//        return "Integer";
//        break;
//    case 2:
//        return "Real";
//        break;
//}
//    return "String";
//}

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


    if (item->column() == 0) {
        table->setHorizontalHeaderItem(item->row(),item);
    }
}

//Create New Variable
void VariableView::createNewVariable(QString name, QString type, QString label, int before){

    int row = before;

    variabelTable->insertRow(row);
    variabelTable->setItem(row,0, new QTableWidgetItem(name) );
    QTableWidgetItem* itemType = new QTableWidgetItem(type);
    itemType->setFlags(itemType->flags() ^ Qt::ItemIsEditable);
    variabelTable->setItem(row,1, itemType);
    variabelTable->setItem(row,2, new QTableWidgetItem(label) );
    table->insertColumn(row);
    table->setHorizontalHeaderItem(row,new QTableWidgetItem(name) );
    QTableWidgetItem* item = new QTableWidgetItem();
    for (int i = 0; i < table->rowCount(); ++i) {
        if (type == "String") {
            table->setItem(i,row, item->clone());

        } else if(type == "Real") {
            table->setItemDelegateForColumn(row,new DoubleDelegate);
            table->setItem(i,row, item->clone());
            table->item(i,row)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        }else {
            table->setItemDelegateForColumn(row,new IntegerDelegate);
            table->setItem(i,row, item->clone());
            table->item(i,row)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        }
    }
}

//get All variable in spreadsheet
QList<QString> VariableView::getAllVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        allVar << variabelTable->item(i,0)->text();
    }
    return allVar;
}
QList<QString> VariableView::getAllSeriesVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        QString varName = variabelTable->item(i,0)->text().split("_").at(0);
        if (allVar.length()==0) {
            allVar << varName;
        }else {
            for (int n = 0; n < allVar.length(); ++n) {
                if (n == allVar.length()-1 && varName != allVar.at(allVar.length()-1)) {
                   allVar << varName;
                }
                if (allVar.at(n) == varName) {
                   break;
                }
            }
        }

    }
    return allVar;
}

//get All numeric variable in spreadsheet
QList<QString> VariableView::getNumericVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        if (variabelTable->item(i,1)->text() != "String") {
            allVar << variabelTable->item(i,0)->text();
        }

    }
    return allVar;
}
QList<QString> VariableView::getNumericSeriesVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        if (variabelTable->item(i,1)->text() != "String") {
            QString varName = variabelTable->item(i,0)->text().split("_").at(0);
            if (allVar.length()==0) {
                allVar << varName;
            }else {
                for (int n = 0; n < allVar.length(); ++n) {
                    if (n == allVar.length()-1 && varName != allVar.at(allVar.length()-1)) {
                       allVar << varName;
                    }
                    if (allVar.at(n) == varName) {
                       break;
                    }
                }
            }

        }

    }
    return allVar;
}
//get All numeric variable in spreadsheet
QList<QString> VariableView::getRealSeriesVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        if (variabelTable->item(i,1)->text() == "Real") {
            QString varName = variabelTable->item(i,0)->text().split("_").at(0);
            if (allVar.length()==0) {
                allVar << varName;
            }else {
                for (int n = 0; n < allVar.length(); ++n) {
                    if (n == allVar.length()-1 && varName != allVar.at(allVar.length()-1)) {
                       allVar << varName;
                    }
                    if (allVar.at(n) == varName) {
                       break;
                    }
                }
            }

        }

    }
    return allVar;
}
QList<QString> VariableView::getAllTimesByVariableName(QString name){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        QString varName = variabelTable->item(i,0)->text().split("_").at(0);
        if (varName == name) {
            allVar << variabelTable->item(i,0)->text().split("_").at(1);
        }

    }
    return allVar;
}

void VariableView::sendDataFrameSeries(QString varName, QStringList timeList, RInside &m_r){
    QStringList varTimeJoin;
    for (int i = 0; i < timeList.length(); ++i) {
        varTimeJoin << varName +"_"+timeList.at(i);
    }
    sendDataFrameByVar(varTimeJoin,m_r);
}

void VariableView::sendDataFrameSeriesFormatted(QString varName,QString id, QStringList timeList, RInside &m_r){
    QStringList varTimeJoin;
    int len = table->rowCount()*timeList.length();
    Rcpp::CharacterVector times(len);
    Rcpp::NumericVector var(len);
    Rcpp::CharacterVector ids(len);
    int k = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        for (int j = 0; j < timeList.length(); ++j) {
        times[k] = timeList.at(j).toStdString();
        var[k] = table->item(i,getVariableIndex(varName+"_"+timeList.at(j)))->text().toDouble();
        ids[k] = table->item(i,getVariableIndex(id))->text().toStdString();
        k++;
        }
    }
    m_r["times"] = times;
    m_r[varName.toStdString()] = var;
    m_r["ID"] = ids;
    m_r.parseEvalQ(QString("dframe <- data.frame(times, %1 ,ID)").arg(varName).toStdString());
}
void VariableView::sendDataFrameSeriesFormatted2(QString varName,QString id, QStringList timeList, RInside &m_r){
    sendDataFrameSeries(varName,timeList,m_r);
    m_r.parseEvalQ("dframe <- as.data.frame(t(dframe))");
    int len = timeList.length();
    Rcpp::CharacterVector times(len);
    Rcpp::CharacterVector header = getCharacterVector(getVariableIndex(id));
    m_r["header"] = header;
    m_r.parseEvalQ("names(dframe) <- header");
    for (int i = 0; i < times.length(); ++i) {
        times[i] = timeList.at(i).toStdString();
    }
    m_r["times"] = times;
    m_r.parseEvalQ("dframe <- as.data.frame(cbind(times,dframe))");
    m_r.parseEvalQ("rownames(dframe) <- NULL");

}


//get All numeric variable in spreadsheet
QList<QString> VariableView::getRealVariableNames(){
    QList<QString> allVar;
    for (int i = 0; i < variabelTable->rowCount(); ++i) {
        if (variabelTable->item(i,1)->text() == "Real") {
            allVar << variabelTable->item(i,0)->text();
        }

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
        if (table->item(i,idx)->text().trimmed() =="") {

            vector(i) = NA_REAL;
        }else{

            vector(i) = table->item(i,idx)->text().trimmed().toDouble();
        }
    }

    return vector;
}
Rcpp::CharacterVector VariableView::getCharacterVector(int idx){
    Rcpp::CharacterVector vector(table->rowCount());

    for (int i = 0; i < table->rowCount(); ++i) {

        if (table->item(i,idx)->text().trimmed().length()<=0) {
            vector[i] = NA_STRING;
        }else {
            vector[i] =  table->item(i,idx)->text().toStdString();
        }
    }

    return vector;
}
Rcpp::NumericVector VariableView::getNumericVectorIgnoreNa(int idx){
    Rcpp::NumericVector vector(table->rowCount());
    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->item(i,idx)->text().trimmed() =="") {

            vector(i) = 0;
        }else{

            vector(i) = table->item(i,idx)->text().trimmed().toDouble();
        }
    }

    return vector;
}
Rcpp::CharacterVector VariableView::getCharacterVectorIgnoreNa(int idx){
    Rcpp::CharacterVector vector(table->rowCount());

    for (int i = 0; i < table->rowCount(); ++i) {

        if (table->item(i,idx)->text().trimmed().length()<=0) {
             vector[i] = "";
        }else {
             vector[i] =  table->item(i,idx)->text().toStdString();
        }
    }

    return vector;
}
//get R object
RInside& VariableView::getRObject(){
    return rconn;
}

//get variable index
int VariableView::getVariableIndex(QString variabel){
    for (int i = 0; i < variabelTable->rowCount() ; ++i) {
        if (variabelTable->item(i,0)->text() == variabel)
        return i;
    }
    return -1;
    }
//set spreadsheet column
void VariableView::setNumericVariable(QString name, Rcpp::NumericVector vector){
    int idx = getVariableIndex(name);
    for (int i = 0; i < vector.length(); ++i) {
        table->setItem(i,idx, new QTableWidgetItem(QString::number(vector[i])));
        table->item(i,idx)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
    }
}
//set constant varible
void VariableView::setConstantVariable(QString name, double cons){
    int idx = getVariableIndex(name);
    QString type = getVariableType(name);

    for (int i = 0; i < table->rowCount(); ++i) {
        table->setItem(i,idx, new QTableWidgetItem(QString::number(cons)));
        if (type != "String") {

            table->item(i,idx)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);

        }
    }
}
//set character variable
void VariableView::setCharacterVariable(QString name, Rcpp::NumericVector vector){
    int idx = getVariableIndex(name);
    for (int i = 0; i < vector.length(); ++i) {
        table->setItem(i,idx, new QTableWidgetItem(QString::number(vector[i])));
    }
}
//set character vector
void VariableView::setCharacterVector(QString name, Rcpp::CharacterVector vector){
    int idx = getVariableIndex(name);
    for (int i = 0; i < vector.length(); ++i) {

        if (getVariableType(name)!= "String") {
                table->setItem(i,idx, new QTableWidgetItem(QString::fromUtf8(vector[i])));
                table->item(i,idx)->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        }else {
             table->setItem(i,idx, new QTableWidgetItem(QString::fromUtf8(vector[i])));
        }
    }
}

//set integer variable
void VariableView::setIntegerVariable(QString name, Rcpp::NumericVector vector){
    int idx = getVariableIndex(name);
    for (int i = 0; i < vector.length(); ++i) {
        table->setItem(i,idx, new QTableWidgetItem(QString::number(vector[i])));
    }
}
//get variable type

QString VariableView::getVariableType(QString var){
    int idx = getVariableIndex(var);
        return variabelTable->item(idx,1)->text();
    }
//get variable Label

QString VariableView::getVariableLabel(QString var){
        int idx = getVariableIndex(var);
        return variabelTable->item(idx,2)->text();
    }
//get variable Label

QString VariableView::getVariableName(int idx){
        return variabelTable->item(idx,0)->text();
    }

//get Row Count
int VariableView::getRowCount(){
    return table->rowCount();
}
int VariableView::getColumnCount(){
    return table->columnCount();
}
void VariableView::sendDataFrame(RInside& m_r){
    sendDataFrameByVar(getAllVariableNames(),m_r);

}
void VariableView::sendDataFrameIgnoreNA(RInside& m_r){
    sendDataFrameByVarIgnoreNA(getAllVariableNames(),m_r);

}
void VariableView::sendDataFrameByVarIgnoreNA(QStringList var,RInside& m_r){
    QString allVarName;

    for (int i = 0; i < var.length(); ++i) {

            if (getVariableType(var.at(i)) == "String") {
                m_r[var.at(i).toStdString()] = getCharacterVectorIgnoreNa(getVariableIndex(var.at(i)));
            }else{
                m_r[var.at(i).toStdString()] = getNumericVectorIgnoreNa(getVariableIndex(var.at(i)));

            }
            if (i!= var.length()-1) {

                allVarName += var.at(i) +",";
            } else {
                allVarName += var.at(i);
            }

    }
    QString command = QString("dframe <- data.frame(%1)").arg(allVarName);

    m_r.parseEvalQ(command.toStdString());
    qDebug()<<command;

}
void VariableView::sendDataFrameByVar(QStringList var,RInside& m_r){
    QString allVarName;

    for (int i = 0; i < var.length(); ++i) {

            if (getVariableType(var.at(i)) == "String") {
                m_r[var.at(i).toStdString()] = getCharacterVector(getVariableIndex(var.at(i)));
            }else{
                m_r[var.at(i).toStdString()] = getNumericVector(getVariableIndex(var.at(i)));

            }
            if (i!= var.length()-1) {

                allVarName += var.at(i) +",";
            } else {
                allVarName += var.at(i);
            }

    }
    QString command = QString("dframe <- data.frame(%1)").arg(allVarName);

    m_r.parseEvalQ(command.toStdString());
    qDebug()<<command;

}
void VariableView::changeVarName(int idx, QString name){
    table->setHorizontalHeaderItem(idx,new QTableWidgetItem(name));
    variabelTable->setItem(idx,0,new QTableWidgetItem(name));
}

void VariableView::setShapePath(QString path){
    shapePath = path;
}

void VariableView::setDataPath(QString path){
    dataPath = path;
}

QString VariableView::getShapePath(){
    return shapePath;
}
QString VariableView::getDataPath(){
    return dataPath;
}
