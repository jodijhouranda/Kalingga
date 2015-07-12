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
#include <QMessageBox>
#include <QIcon>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
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
    ui->plug->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

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
    while (ui->listWidget->count() >0) {
        ui->listWidget->takeItem(0);
    }
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

     QStringList listFolderPlugin = pluginsDir.entryList(QDir::AllDirs);

    for (int i = 0 ;  i< listFolderPlugin.count(); i++) {

    QDir plugDir = pluginsDir;
    plugDir.cd(listFolderPlugin.at(i));

    foreach (QString fileName, plugDir.entryList(QDir::Files)) {

        QPluginLoader* loader = new QPluginLoader(plugDir.absoluteFilePath(fileName));
        QObject *plugin = loader->instance();
        if (PluginInterfaces *interface =
           qobject_cast<PluginInterfaces *>(plugin)){
            plugloaders.append(loader);
           interface->addResultDialog(MainWindow::centralView,MainWindow::resultViewAct);


           if (interface->getPluginType() == "Analysis") {

               ui->listWidget->addItem(new QListWidgetItem(QIcon("./images/analysis.png"),interface->getPluginTittle()));
               QList<QAction* > lact = analysis->actions();
               for (int i = 0; i < lact.length(); ++i) {
                  if (lact.at(i)->text() == interface->getPluginTittle()) {
                       ui->listWidget->item(ui->listWidget->count()-1)->setBackgroundColor(Qt::green);
                  }
              }

           }else {
               ui->listWidget->addItem(new QListWidgetItem(QIcon("./images/tools.png"),interface->getPluginTittle()));
               QList<QAction* > lact = tools->actions();
                 for (int i = 0; i < lact.length(); ++i) {
                     if (lact.at(i)->text() == interface->getPluginTittle()) {

                         ui->listWidget->item(ui->listWidget->count()-1)->setBackgroundColor(Qt::green);
                     }
                     }

        }
                }

    }


}
}

void PluginDialog::on_pushButton_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,"Open",QString(),tr("(*.zip)"));


    if (dir.length()>0) {
        ui->lineEdit->setText(dir);
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
        qDebug() << dir;
        try {
            QString cmd = QString("unzip( %1 , %2 )").arg("\""+dir+"\"" ,"exdir =\"" + pluginsDir.absolutePath() +"\"");
            qDebug() << cmd;
            rconn.parseEvalQ(cmd.toStdString());
            loadPlugins();
        } catch (...) {
            QMessageBox::information(this,"Cannot add pluggin" , "the pluggin has been added");
        }
    }



}
void PluginDialog::openPlugin(){
    QAction *action = qobject_cast<QAction *>(sender());
    PluginInterfaces *interface = qobject_cast<PluginInterfaces *>(action->parent());
    interface->runPluginDialog(vv,result,rconn,this->parentWidget());

}

void PluginDialog::on_pushButton_2_clicked()
{
    if (ui->listWidget->currentItem()->backgroundColor() != Qt::green) {

        QMessageBox::information(this,"Cannot unplug the plugin","The plugin is not plugged yet");
        return;
    }
// QMessageBox::StandardButton reply;
//reply = QMessageBox::question(this,"Unplug plugin", "Are sure to unplug plugin from KalinggaSoft environment",QMessageBox::Yes|QMessageBox::No);
//if (reply == QMessageBox::Yes) {

QString plugname = ui->listWidget->currentItem()->text();
    ui->listWidget->currentItem()->setBackgroundColor(Qt::white);
    QList<QAction* > lact = analysis->actions();
    for (int i = 0; i < lact.length(); i++) {
        if (lact.at(i)->text() == plugname) {

            analysis->removeAction(lact.at(i));

        }
    }

    QList<QAction* > lact2 = tools->actions();
    for (int i = 0; i < lact2.length(); i++) {
        if (lact2.at(i)->text() == plugname) {
            tools->removeAction(lact2.at(i));
        }
    }



//}else {
//    return;
//}
ui->plug->setEnabled(true);
ui->pushButton_2->setEnabled(false);
}

void PluginDialog::on_listWidget_currentTextChanged(const QString &currentText)
{
    ui->pushButton_2->setEnabled(true);
}


void PluginDialog::on_plug_clicked()
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
    pluginsDir.cd(ui->listWidget->currentItem()->text());

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {

        QPluginLoader* loader = new QPluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader->instance();
        if (PluginInterfaces *interface =
           qobject_cast<PluginInterfaces *>(plugin)){
            plugloaders.append(loader);
           interface->addResultDialog(MainWindow::centralView,MainWindow::resultViewAct);


           if (interface->getPluginType() == "Analysis") {

              QAction* action = new QAction(interface->getPluginTittle(),plugin);
              connect(action , SIGNAL(triggered()),this,SLOT(openPlugin()));
               QList<QAction* > lact = analysis->actions();
              for (int i = 0; i < lact.length(); ++i) {
                  if (lact.at(i)->text() == interface->getPluginTittle()) {
                      QMessageBox::information(this,"Cannot plug the plugin","The plugin has been added to Analysis menu");
                      goto stops;
                  }

              }
              interfaces.append(interface);
              analysis->addAction(action);

              ui->listWidget->currentItem()->setBackgroundColor(Qt::green);
          }else {
              QAction* action = new QAction(interface->getPluginTittle(),plugin);
              connect(action , SIGNAL(triggered()),this,SLOT(openPlugin()));
              QList<QAction* > lact = tools->actions();
              for (int i = 0; i < lact.length(); ++i) {
                  if (lact.at(i)->text() == interface->getPluginTittle()) {
                      QMessageBox::information(this,"Cannot plug the plugin","The plugin has been added to Tools menu");
                      goto stops;
                  }

              }
              interfaces.append(interface);
              tools->addAction(interface->getPluginTittle());

              ui->listWidget->currentItem()->setBackgroundColor(Qt::green);

          }
        }
       }

    stops :;
    ui->plug->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}



void PluginDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (ui->listWidget->currentItem()->background() == Qt::green) {
        ui->plug->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    }else {
        ui->plug->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
}


bool PluginDialog::copyDir(const QString source, const QString destination, const bool override)
{
    QDir directory(source);
        bool error = false;

        if (!directory.exists()) {
            return false;
        }

        QStringList dirs = directory.entryList(QDir::AllDirs | QDir::Hidden);
        QStringList files = directory.entryList(QDir::Files | QDir::Hidden);

        QList<QString>::iterator d,f;

        for (d = dirs.begin(); d != dirs.end(); ++d) {
            if ((*d) == "." || (*d) == "..") {
                continue;
            }

            if (!QFileInfo(directory.path() + "/" + (*d)).isDir()) {
                continue;
            }

            QDir temp(destination + "/" + (*d));
            temp.mkpath(temp.path());

            if (!copyDir(directory.path() + "/" + (*d), destination + "/" + (*d), override)) {
                error = true;
            }
        }

        for (f = files.begin(); f != files.end(); ++f) {
            QFile tempFile(directory.path() + "/" + (*f));


            if (QFileInfo(directory.path() + "/" + (*f)).isDir()) {
                continue;
            }

            QFile destFile(destination + "/" + directory.relativeFilePath(tempFile.fileName()));

            if (destFile.exists() && override) {
                destFile.remove();
            }

            if (!tempFile.copy(destination + "/" + directory.relativeFilePath(tempFile.fileName()))) {
                error = true;

            }
        }


        return !error;
}
