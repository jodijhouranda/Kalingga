#ifndef CHARTCONFIG_H
#define CHARTCONFIG_H
#include <QString>

#include <QStringList>
#include <qtColorpicker.h>
#include <variableview.h>
#include <QComboBox>
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
    QString getGraphParameter(QStringList par ,QStringList parAes);
    bool parameterCheck(QString x);
    void setAllVar(QStringList av);
    void addParameter(QString var);
    void addParameterAes(QString var , QString sufx);
    void addParameter2(QString var);
    void addParameterAes2(QString var , QString sufx);
    void setComboMap(QComboBox *combo,VariableView* vv);
    void setComboVariable(QComboBox *combo,VariableView* vv);
    void setComboSize(QComboBox *combo,VariableView* vv);
    void setComboPosition(QComboBox *combo,VariableView* vv);
    void setComboContent(QComboBox *combo,VariableView* vv);
    void setComboLineContent(QComboBox* combo,VariableView* vv);
    QString getComboValue(QString value);
    QStringList par;
    QStringList parAes;
    QStringList par2;
    QStringList parAes2;
    void exportPlot(QWidget* parent,RInside &rconn);
private:
  QString baseCommand;
  QString command;
  QStringList allVar;
};

#endif // CHARTCONFIG_H
