#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <QDialog>
#include <QDir>
#include <QPluginLoader>
#include <plugininterfaces.h>
#include <QListWidgetItem>

namespace Ui {
class PluginDialog;
}

class PluginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginDialog(QWidget *parent = 0);
    ~PluginDialog();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::PluginDialog *ui;
    QList<PluginInterfaces*> interfaces;
    void loadPlugins();
};

#endif // PLUGINDIALOG_H
