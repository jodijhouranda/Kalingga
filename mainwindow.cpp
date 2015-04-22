#include "mainwindow.h"
#include <QMenuBar>
#include <QTabWidget>
#include <QFileDialog>
#include <mapview.h>
#include <QDebug>
#include <QMessageBox>
#include <qdbftablemodel.h>
#include <QPointer>
mapview* mview;

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
    //data menu create Action

    openCSV = new QAction(tr("Comma Separated Value (*.csv)"),this);
    connect(openCSV, SIGNAL(triggered()),this,SLOT(openCSVSlot()));

    openSHP = new QAction(tr("Esri Shapefile (*.shp)"),this);
    connect(openSHP, SIGNAL(triggered()),this,SLOT(openSHPSlot()));

    openDBF = new QAction(tr("dBase Database File (*.dbf)"),this);
    connect(openDBF, SIGNAL(triggered()),this,SLOT(openDBFSlot()));

    createNewVariable = new QAction (tr("Add Variable"),this);
    connect(createNewVariable , SIGNAL(triggered()),this,SLOT(openCreateNewVariable()));

    deleteVariable = new QAction (tr("Delete Variable"),this);
    connect(deleteVariable , SIGNAL(triggered()),this,SLOT(openDeleteVariable()));

    //explore menu create Action
    createHistogram = new QAction(tr("Histogram"),this);
    connect(createHistogram , SIGNAL(triggered()),this,SLOT(openHistogramCreator()));
}

//setup menubar for mainwindow
void MainWindow::setupMenuBar(){
QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
QMenu *dataMenu = menuBar()->addMenu(tr("&Data"));
QMenu *exploreMenu = menuBar()->addMenu(tr("&Explore"));
QMenu *toolsMenu = menuBar()->addMenu(tr("&Tools"));
QMenu *analysisMenu = menuBar()->addMenu(tr("&Analysis"));
//file menu child
QMenu *openMenu = fileMenu->addMenu(tr("Create Project From"));
openMenu->addAction(openSHP);
openMenu->addAction(openDBF);
openMenu->addAction(openCSV);

//data menu child
dataMenu->addAction(createNewVariable);
dataMenu->addAction(deleteVariable);
//explore menu child
exploreMenu->addAction(createHistogram);
}
void MainWindow::createTabView(){
    QWidget *centralView = new QWidget(this);
    tabView = new QTabWidget(centralView);
    tabView->setTabPosition(QTabWidget::South);
    tabView->setFixedSize(1370,625);
    tabView->addTab(new QWidget(),"Data View");
    tabView->addTab(new QWidget(),"Variabel View");
    mview = new mapview(this,tabView);
    tabView->addTab(mview,"Map View");

    setCentralWidget(centralView);
}


//update ui
void MainWindow::updateDataView(QTableWidget* ss){
    tabView->removeTab(0);
    tabView->insertTab(0,ss, tr("Data View"));
    tabView->setCurrentIndex(0);
}

void MainWindow::updateVariableView(QTableWidget* vv){
    tabView->removeTab(1);
    tabView->insertTab(1,vv, tr("Variable View"));

}
//All File dan data Slots

//1 open file slot
void MainWindow::openCSVSlot(){
    QString csvPath = QFileDialog::getOpenFileName(this,"Open",QString(),tr("Separate Comma Value (*.csv)"));
    std::string cmd0 ="data<- read.csv(\"" ;
    std::string cmd1 = "\")";
    std::string cmd = cmd0 + csvPath.toStdString() + cmd1 ;
    Rcpp::DataFrame data = Rcon.parseEval(cmd);
    vv = new VariableView(data,Rcon);
    updateDataView(vv->getSpreadsheetTable());
    updateVariableView(vv->getVariabelViewTable());
  }

void MainWindow::openSHPSlot(){
    QString shpPath = QFileDialog::getOpenFileName(this,"Open",QString(),tr("Esri Shapefile (*.shp)"));
    QString dbfPath = shpPath.left(shpPath.length()-4) + ".dbf";
    QFile* dbfFile = new QFile(dbfPath);
    if (!dbfFile->exists() || shpPath.isEmpty()) {
        QMessageBox::information(this,"Error opening shapefile" ,"dbf file not found");
        return;
    }

   QDbf::QDbfTableModel *const tableModel = new QDbf::QDbfTableModel();
   tableModel->open(dbfPath);
    vv = new VariableView(tableModel,Rcon);
    updateDataView(vv->getSpreadsheetTable());
    updateVariableView(vv->getVariabelViewTable());
    mview->openShapeFile(shpPath);
}

void MainWindow::openDBFSlot(){
    QString dbfPath = QFileDialog::getOpenFileName(this,"Open",QString(),tr("dBase Database File (*.dbf)"));


    if (dbfPath.isEmpty()) {
        QMessageBox::information(this,"Error opening shapefile" ,"dbf file not found");
        return;
    }

   QDbf::QDbfTableModel *const tableModel = new QDbf::QDbfTableModel();
   tableModel->open(dbfPath);
    vv = new VariableView(tableModel,Rcon);
    updateDataView(vv->getSpreadsheetTable());
    updateVariableView(vv->getVariabelViewTable());

}

//inisialisasi slot data menu
//slot buka windows create new Variable
void MainWindow::openCreateNewVariable(){
   CreateNewVariable* dialog =  new CreateNewVariable(vv,this );
    dialog->show();
}

// slot buka dialog delete variable
void MainWindow::openDeleteVariable(){
    DeleteVariable* dialog =  new DeleteVariable(vv,this );
     dialog->show();
}


//inisialisasi slot explore menu
void MainWindow::openHistogramCreator(){
    HistogramCreator* dialog =  new HistogramCreator(vv,Rcon,this );
     dialog->show();
}
