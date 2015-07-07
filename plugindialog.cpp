#include "plugindialog.h"
#include "ui_plugindialog.h"
#include <QListWidgetItem>
#include <QDebug>
#include <QFileDialog>
#include <QTreeView>
#include <variableview.h>
#include <resultview.h>
#include <QMenu>
#include <QAction>
#include <mainwindow.h>
#include <QIcon>
PluginDialog::PluginDialog(VariableView* vv, ResultView* result, RInside& rconn,QMenu* analysis,QMenu* tools,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginDialog),
    vv(vv),
    result(result),
    rconn(rconn),
    analysis(analysis),
    tools(tools)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(45,54));

    loadPlugins();
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

    QDir pluginsDir = QDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");

//! [5]
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        qDebug() << fileName;
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            qDebug() << "runplug";
        }
        if (PluginInterfaces *interface =
           qobject_cast<PluginInterfaces *>(plugin)){

           interface->addResultDialog(MainWindow::centralView,MainWindow::resultViewAct);
           QList<QAction* > lact = analysis->actions();

           if (interface->getPluginType() == "Analysis") {

               ui->listWidget->addItem(new QListWidgetItem(QIcon("./images/analysis.png"),interface->getPluginTittle()));
               QAction* action = new QAction(interface->getPluginTittle(),plugin);
               connect(action , SIGNAL(triggered()),this,SLOT(openPlugin()));

               for (int i = 0; i < lact.length(); ++i) {
                   if (lact.at(i)->text() == interface->getPluginTittle()) {
                       return;
                   }

               }
               interfaces.append(interface);
               analysis->addAction(action);
           }else {
               ui->listWidget->addItem(new QListWidgetItem(QIcon("./images/tools.png"),interface->getPluginTittle()));
               QAction* action = new QAction(interface->getPluginTittle(),plugin);
               connect(action , SIGNAL(triggered()),this,SLOT(openPlugin()));
               for (int i = 0; i < lact.length(); ++i) {
                   if (lact.at(i)->text() == interface->getPluginTittle()) {
                       return;
                   }

               }
               interfaces.append(interface);
               tools->addAction(interface->getPluginTittle());

           }

            qDebug() << interface->getPluginTittle();
            qDebug() << "run";
        }
                }

}

void PluginDialog::on_pushButton_clicked()
{
    QDir dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    qDebug() << dir;



}

void PluginDialog::openPlugin(){
    QAction *action = qobject_cast<QAction *>(sender());
    PluginInterfaces *interface = qobject_cast<PluginInterfaces *>(action->parent());
    interface->runPluginDialog(vv,result,rconn,this->parentWidget());
}
