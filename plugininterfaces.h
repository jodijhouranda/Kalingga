#ifndef PLUGININTERFACES_H
#define PLUGININTERFACES_H
#include <QtPlugin>
QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

class PluginInterfaces
{
public:
    virtual ~PluginInterfaces(){};

    virtual QString setPluginTittle() const = 0;

};
Q_DECLARE_INTERFACE(PluginInterfaces,
                    "com.kalinggasoft-Inc.kalinggasoft.PluginInterface/1.0")

#endif // PLUGININTERFACES_H
