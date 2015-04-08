#include "mainwindow.h"
#include <QMenuBar>
#include <QTabWidget>

#include <QFileDialog>
MainWindow::MainWindow(RInside & R , QWidget *parent ) : QMainWindow(parent) ,Rcon(R)

{
    setupWindowsSetting();


}
//Mainwindow basic settings
void MainWindow::setupWindowsSetting(){
 //set fullscreen window
 this->showMaximized();
    createAction();
    setupMenuBar();
    createTabView();
}

void MainWindow::createAction(){
    openCSV = new QAction(tr("Comma Separated Value (*.csv)"),this);
    connect(openCSV, SIGNAL(triggered()),this,SLOT(openCSVSlot()));
}

//setup menubar for mainwindow
void MainWindow::setupMenuBar(){
QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
QMenu *dataMenu = menuBar()->addMenu(tr("&Data"));
QMenu *toolsMenu = menuBar()->addMenu(tr("&Tools"));
QMenu *analysisMenu = menuBar()->addMenu(tr("&Analysis"));

QMenu *openMenu = fileMenu->addMenu(tr("Create Project From"));
openMenu->addAction(openCSV);

}
void MainWindow::createTabView(){
    QWidget *centralView = new QWidget(this);
    tabView = new QTabWidget(centralView);
    tabView->setTabPosition(QTabWidget::South);
    tabView->setFixedSize(1370,650);
    tabView->addTab(new QWidget(),"Data View");
    tabView->addTab(new QWidget(),"Variabel View");
    tabView->addTab(new QWidget(),"Map View");

    this->setCentralWidget(centralView);

}

void MainWindow::openCSVSlot(){
    QString csvPath = QFileDialog::getOpenFileName(this,"Open",QString(),tr("Separate Comma Value (*.csv)"));
    std::string cmd0 ="data<- read.csv(\"" ;
    std::string cmd1 = "\")";
    std::string cmd = cmd0 + csvPath.toStdString() + cmd1 ;
    Rcpp::DataFrame data = Rcon.parseEval(cmd);
    Spreadsheet* ss = new Spreadsheet(data);
    updateDataView(ss);
    updateVariableView(ss->getVariabelAttribute());
  }

void MainWindow::updateDataView(Spreadsheet* ss){
    tabView->removeTab(0);
    tabView->insertTab(0,ss, tr("Data View"));
    tabView->setCurrentIndex(0);
}

void MainWindow::updateVariableView(QTableWidget* table){
    tabView->removeTab(1);
    tabView->insertTab(1,table, tr("Variable View"));
    tabView->setCurrentIndex(1);
}

