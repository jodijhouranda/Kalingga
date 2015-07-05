#include "mapcolorreader.h"

MapColorReader::MapColorReader()
{
    model = new QStandardItemModel();
    QString fileName = ":/MyFiles/color-breawer.csv";
    readCsv(fileName);
}

MapColorReader::~MapColorReader()
{
}

QList<QColor> MapColorReader::getListColor(QString colorName, QString numOfColor)
{
    int row = model->rowCount();
    QString textColorName;
    QString textNumOfColor;

    QList<int> idColorName;
    QList<int> idNumOfColor;

    QList<int> idRGB;

    for(int i=0; i < row; i++){
        textColorName = model->item(i,0)->text();
        textNumOfColor = model->item(i,1)->text();

        if(textColorName == colorName){
            idColorName.append(i);
        }

        if(textNumOfColor == numOfColor){
            idNumOfColor.append(i);
        }
    }

    for(int i=0; i<idColorName.size(); i++){
        for(int j=0; j<idNumOfColor.size(); j++){
            if(idColorName.value(i) == idNumOfColor.value(j)){
                idRGB.append(idColorName.value(i));
            }
        }
    }

    int r,g,b;
    QList<QColor> listColor;
    for(int i=0; i<idRGB.size(); i++){
        r = model->item(idRGB.value(i),5)->text().toInt();
        g = model->item(idRGB.value(i),6)->text().toInt();
        b = model->item(idRGB.value(i),7)->text().toInt();
        listColor.append(QColor(r,g,b));
    }

    return listColor;
}

void MapColorReader::readCsv(QString fileName)
{
    QFile file (fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QString data = file.readAll();
        data.remove( QRegExp("\r") ); //remove all ocurrences of CR (Carriage Return)
        QString temp;
        QChar character;
        QTextStream textStream(&data);
        while (!textStream.atEnd()) {
            textStream >> character;
            if (character == ',') {
                checkString(temp, character);
            } else if (character == '\n') {
                checkString(temp, character);
            } else if (textStream.atEnd()) {
                temp.append(character);
                checkString(temp);
            } else {
                temp.append(character);
            }
        }
    }
}

void MapColorReader::checkString(QString &temp, QChar character)
{
    if(temp.count("\"")%2 == 0) {
        //if (temp.size() == 0 && character != ',') //problem with line endings
        //    return;
        if (temp.startsWith( QChar('\"')) && temp.endsWith( QChar('\"') ) ) {
             temp.remove( QRegExp("^\"") );
             temp.remove( QRegExp("\"$") );
        }
        temp.replace("\"\"", "\"");
        QStandardItem *item = new QStandardItem(temp);
        standardItemList.append(item);
        if (character != QChar(',')) {
            model->appendRow(standardItemList);
            standardItemList.clear();
        }
        temp.clear();
    } else {
        temp.append(character);
    }
}

