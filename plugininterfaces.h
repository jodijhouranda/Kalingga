#ifndef PLUGININTERFACES_H
#define PLUGININTERFACES_H
#include <QtPlugin>
QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

class PluginInterfaces
{
public:
    virtual ~PluginInterfaces(){}

    virtual QString getPluginTittle() const = 0;

};
Q_DECLARE_INTERFACE(PluginInterfaces,
                    "com.kalinggasoft-Inc.KalinggaSoft.PluginInterfaces/2.0")

#endif // PLUGININTERFACES_H
