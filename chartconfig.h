#ifndef CHARTCONFIG_H
#define CHARTCONFIG_H
#include <QString>

class ChartConfig
{
public:
    ChartConfig();
    ~ChartConfig();
    void setBaseCommand(QString cmd);
    QString getBaseCommand();
    void setCommand(QString cmd);
    QString getCommand();
    void removeCommand();


private:
  QString baseCommand;
  QString command;
};

#endif // CHARTCONFIG_H
