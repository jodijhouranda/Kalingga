#ifndef INTERFACES
#define INTERFACES
#include <QtPlugin>
QT_BEGIN_NAMESPACE
class QString;
class VariableView;
class RInside;
class ResultView;
class QStackedWidget;
class QAction;
class QWidget;
QT_END_NAMESPACE

class PluginInterfaces
{
public:
    virtual ~PluginInterfaces(){}

    virtual QString getPluginTittle() const = 0;

    virtual QString getPluginType() const = 0;

    virtual void runPluginDialog(VariableView* vv,ResultView* result, RInside& rconn,QWidget* parent) const = 0;

    virtual void addResultDialog(QStackedWidget* widget, QAction* action) const =0;

};
Q_DECLARE_INTERFACE(PluginInterfaces,
                    "com.kalinggasoft-Inc.KalinggaSoft.PluginInterfaces/4.2")
#endif // INTERFACES

