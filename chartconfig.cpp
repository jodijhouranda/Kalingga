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
