#include "chartconfig.h"


ChartConfig::ChartConfig()
{

}

ChartConfig::~ChartConfig()
{

}

void ChartConfig::setBaseCommand(QString cmd){
    baseCommand = cmd;
}

QString ChartConfig::getBaseCommand(){
    return baseCommand;
}

void ChartConfig::setCommand(QString cmd){
    command += cmd;
}

QString ChartConfig::getCommand(){
    return command;
}

void ChartConfig::removeCommand(){
    command = "";
}

QString ChartConfig::getGraphParameter(QStringList par, QStringList parAes){
    QString args= "";
    QString aesIterator ="";
    if (parAes.size()>0) {
        for (int i = 0; i < parAes.size(); ++i) {
            if (i==0) {
                aesIterator += parAes.at(i);
            }else {

                aesIterator += ("," + parAes.at(i));
            }

        }
    }
    QString aess= QString("aes(%1)").arg(aesIterator);

        if (par.size()>0) {
            for (int i = 0; i < par.size(); ++i) {
                if (i==0) {
                    args += par.at(i);
                }else {

                    args += ("," + par.at(i));
                }

            }
            if (parAes.size()>0) {
                args += ("," +aess);
            }

        }else if(par.size()<=0 && parAes.size()>0){
            args = aess;
        }
    return args;
}

bool ChartConfig::parameterCheck(QString x){
    for (int i = 0; i < allVar.size(); ++i) {
        if (allVar.at(i)==x) {
            return true;
        }
    }
    return false;
}



void ChartConfig::setAllVar(QStringList av){
    allVar = av;
}
void ChartConfig::addParameter(QString var){
    if (var.size()>0) {
       par << var;
    }
}

void ChartConfig::addParameterAes(QString var, QString sufx){
    if (parameterCheck(var)) {
      QString edit = sufx +var;
       parAes << edit;
    }else if (var.size()>0) {
        par << var;
    }
}
void ChartConfig::addParameter2(QString var){
    if (var.size()>0) {
       par2 << var;
    }
}

void ChartConfig::addParameterAes2(QString var, QString sufx){
    if (parameterCheck(var)) {
      QString edit = sufx +var;
       parAes2 << edit;
    }else if (var.size()>0) {
        par2 << var;
    }
}
void ChartConfig::setComboMap(QComboBox *combo,VariableView* vv){
    QStringList content;
    content <<"Default" << "Colour";
    content << vv->getAllVariableNames();
    combo->addItems(content);
}
void ChartConfig::setComboSize(QComboBox *combo,VariableView* vv){
    QStringList content;
    content <<"Default" << "Value...";
    content << vv->getAllVariableNames();
    combo->addItems(content);
}
void ChartConfig::setComboVariable(QComboBox *combo,VariableView* vv){
    QStringList content;
    content <<"Default";
    content << vv->getAllVariableNames();
    combo->addItems(content);
}
void ChartConfig::setComboPosition(QComboBox *combo,VariableView* vv){
    QStringList content;
    content <<"Default"<<"Dodge"<<"fill"<<"Identity"<<"Jitter"<<"Stack" ;
    combo->addItems(content);
}
void ChartConfig::setComboContent(QComboBox *combo,VariableView* vv){
    QStringList content;
    content <<"Default";
    content << vv->getAllVariableNames();
    combo->addItems(content);
}
QString ChartConfig::getComboValue(QString value){
    if(value == "Default"){
        return "";
    }
    return value;
}
void ChartConfig::setComboLineContent(QComboBox *combo,VariableView* vv){
    QStringList content;
    content <<"Default" << "solid" << "dashed" <<"dotted"<<"dotdash"
           << "longdash"<<"twodash";
    combo->addItems(content);
}
