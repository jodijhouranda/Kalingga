#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <QDialog>
#include <QDir>
#include <QPluginLoader>
#include <interfaces.h>
#include <QListWidgetItem>

namespace Ui {
class PluginDialog;
}

class PluginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginDialog(VariableView* vv, ResultView* result, RInside& rconn,QMenu* analysis,QMenu* tools,QWidget *parent = 0);
    ~PluginDialog();
void loadPlugins();
private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void openPlugin();
    void on_pushButton_2_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_plug_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);


private:
    Ui::PluginDialog *ui;
    QList<PluginInterfaces*> interfaces;
    PluginInterfaces* myint;

    VariableView* vv;
    ResultView* result;
    RInside& rconn;
    QMenu* analysis;
    QMenu* tools;
    QList<QPluginLoader*> plugloaders;

};

#endif // PLUGINDIALOG_H
