#ifndef MORANPLUGINS_H
#define MORANPLUGINS_H
#include <QObject>
#include <Kalingga-master/interfaces.h>
#include <Kalingga-master/includes.h>
#include <RInside.h>
#include <QAction>
class MoranPLugins : public QObject, public PluginInterfaces
{
    Q_OBJECT
    Q_INTERFACES(PluginInterfaces)

public:

    QString getPluginTittle() const;

    QString getPluginType() const;

    void runPluginDialog(VariableView* vv, ResultView* result , RInside& rconn,QWidget* parent) const;

    void addResultDialog(QStackedWidget* widget, QAction* action) const;

    static void showResultDialog();
private :
    static QStackedWidget* widget;
    static QAction* action;
};

#endif // MORANPLUGINS_H
