#include "plugindialog.h"
#include "ui_plugindialog.h"

PluginDialog::PluginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginDialog)
{
    ui->setupUi(this);
}

PluginDialog::~PluginDialog()
{
    delete ui;
}

void PluginDialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

void PluginDialog::loadPlugins()
{
    QDir pluginsDir = qApp->applicationDirPath()+"/plugins";
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        if (PluginInterfaces *interface =
                qobject_cast<PluginInterfaces *>(loader.instance()))
            interfaces.append(interface);
    }
}
