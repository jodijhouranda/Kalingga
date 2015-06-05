#include "mainwindow.h"
#include <computevariable.h>
#include <randomsamplegenarator.h>
#include <QMenuBar>
#include <QTabWidget>
#include <QFileDialog>
#include <mapview.h>
#include <QDebug>
#include <QMessageBox>
#include <qdbftablemodel.h>
#include <QPointer>
#include <parallechart.h>
#include <QPushButton>
#include <modifyvariable.h>
#include <descriptivestat.h>
#include <mergedatatable.h>
mapview* mview;
ResultView* MainWindow::result;
QStackedWidget* MainWindow::centralView;
QAction* MainWindow::resultViewAct;
void MainWindow::enableResultView(){
    centralView->setCurrentIndex(3);
    resultViewAct->setVisible(true);
}

MainWindow::MainWindow(RInside & R , QWidget *parent ) : QMainWindow(parent) ,Rcon(R)

{
    setupWindowsSetting();
    result = new ResultView(this);
    setMenubarVisible(false);


}
//Mainwindow basic settings
void MainWindow::setupWindowsSetting(){
 //set fullscreen window
 this->showMaximized();
    createAction();
    setupMenuBar();

    centralView = new QStackedWidget(this);

    mview = new mapview(this,0,centralView);
    mview->disableToolBar();
    centralView->addWidget(mview);
    setCentralWidget(centralView);

}

void MainWindow::createAction(){
    //data menu create Action

    openCSV = new QAction(tr("Comma Separated Value (*.csv)"),this);
    connect(openCSV, SIGNAL(triggered()),this,SLOT(openCSVSlot()));

    openSHP = new QAction(tr("Esri Shapefile (*.shp)"),this);
    connect(openSHP, SIGNAL(triggered()),this,SLOT(openSHPSlot()));

    openDBF = new QAction(tr("dBase Database File (*.dbf)"),this);
    connect(openDBF, SIGNAL(triggered()),this,SLOT(openDBFSlot()));

    mergeTable = new QAction (tr("Merge"),this);
    connect(mergeTable, SIGNAL(triggered()),this,SLOT(openMergeTable()));

    createNewVariable = new QAction (tr("Add Variable"),this);
    connect(createNewVariable , SIGNAL(triggered()),this,SLOT(openCreateNewVariable()));

    deleteVariable = new QAction (tr("Delete Variable ... "),this);
    connect(deleteVariable , SIGNAL(triggered()),this,SLOT(openDeleteVariable()));

    modifyVariable = new QAction (tr("Modify Variable ... "),this);
    connect(modifyVariable , SIGNAL(triggered()),this,SLOT(openModifyVariable()));

    calculateVariable = new QAction (tr("Calculate Variable ..."),this);
    connect(calculateVariable , SIGNAL(triggered()),this,SLOT(openCalculateVariable()));

    recodeVariable = new QAction (tr("Recode Variable ..."),this);
    connect(recodeVariable , SIGNAL(triggered()),this,SLOT(openRecodeVariable()));

    openRSGenerator = new QAction (tr("Generate Random Sample"),this);
    connect(openRSGenerator , SIGNAL(triggered()),this,SLOT(openRandomSampleGenerator()));

    //explore menu create Action
    createDescriptive = new QAction(tr("Descriptive"),this);
    connect(createDescriptive , SIGNAL(triggered()),this,SLOT(openDescriptiveCreator()));

    createHistogram = new QAction(tr("Histogram"),this);
    connect(createHistogram , SIGNAL(triggered()),this,SLOT(openHistogramCreator()));

    createScatter = new QAction(tr("Scatter"),this);
    connect(createScatter , SIGNAL(triggered()),this,SLOT(openScatterCreator()));

    createBoxplot = new QAction(tr("Boxplot"),this);
    connect(createBoxplot , SIGNAL(triggered()),this,SLOT(openBoxplotCreator()));

    createParallel = new QAction(tr("Parallel Coordinates Plot"),this);
    connect(createParallel , SIGNAL(triggered()),this,SLOT(openParallelCreator()));

}

//setup menubar for mainwindow
void MainWindow::setupMenuBar(){
fileMenu = menuBar()->addMenu(tr("&File"));
viewMenu = menuBar()->addMenu(tr("&View"));
attributeMenu = menuBar()->addMenu(tr("&Attribute"));
QMenu* explore = new QMenu(tr("Explore"));

mapMenu = menuBar()->addMenu(tr("&Map"));
toolsMenu = menuBar()->addMenu(tr("&Tools"));
analysisMenu = menuBar()->addMenu(tr("&Analysis"));
pluginMenu = menuBar()->addMenu(tr("&Plugin"));
aboutMenu = menuBar()->addMenu(tr("&Help"));

//file menu child
QMenu *openMenu = fileMenu->addMenu(tr("Open File"));
openMenu->addAction(openSHP);
openMenu->addAction(openDBF);
openMenu->addAction(openCSV);
//view menu child



mapViewAct = new QAction(tr("Map View"),this);
connect(mapViewAct, SIGNAL(triggered()),this,SLOT(openMapView()));
viewMenu->addAction(mapViewAct);

dataViewAct = new QAction(tr("Data View"),this);
connect(dataViewAct, SIGNAL(triggered()),this,SLOT(openDataView()));
viewMenu->addAction(dataViewAct);

variableViewAct = new QAction(tr("Variable View"),this);
connect(variableViewAct, SIGNAL(triggered()),this,SLOT(openVariableView()));
viewMenu->addAction(variableViewAct);

resultViewAct = new QAction(tr("Result View"),this);
connect(resultViewAct, SIGNAL(triggered()),this,SLOT(openResultView()));
viewMenu->addAction(resultViewAct);
//data menu child
attributeMenu->addAction(mergeTable);
attributeMenu->addAction(createNewVariable);
attributeMenu->addAction(deleteVariable);
attributeMenu->addAction(modifyVariable);
attributeMenu->addAction(calculateVariable);
attributeMenu->addAction(openRSGenerator);
attributeMenu->addAction(recodeVariable);
attributeMenu->addMenu(explore);
explore->addAction(createDescriptive);
explore->addAction(createHistogram);
explore->addAction(createScatter);
explore->addAction(createBoxplot);
explore->addAction(createParallel);
}


//update ui
void MainWindow::openDataView(){
    centralView->setCurrentIndex(1);
    setWindowTitle("KalinggaSoft : Data View");
    mview->disableToolBar();

}

void MainWindow::openVariableView(){
    centralView->setCurrentIndex(2);
    setWindowTitle("KalinggaSoft : Variable View");
    mview->disableToolBar();
}

void MainWindow::openMapView(){
    centralView->setCurrentIndex(0);
    setWindowTitle("KalinggaSoft : Map View");
    mview->enableToolBar();
}

void MainWindow::openResultView(){
    centralView->setCurrentIndex(3);
    setWindowTitle("KalinggaSoft : Result View");
    mview->disableToolBar();
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
    centralView->addWidget(vv->getSpreadsheetTable());
    centralView->addWidget(vv->getVariabelViewTable());
    centralView->addWidget(result);
    updateViewMenuDataOnly();
    openDataView();
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
    centralView->addWidget(vv->getSpreadsheetTable());
    centralView->addWidget(vv->getVariabelViewTable());
    mview->openShapeFile(shpPath);
    openMapView();
    mview->enableToolBar();

    centralView->addWidget(result);
    updateViewMenu();
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
    centralView->addWidget(vv->getSpreadsheetTable());
    centralView->addWidget(vv->getVariabelViewTable());
    centralView->addWidget(result);
    updateViewMenuDataOnly();
    openDataView();
}

//inisialisasi slot data menu
//slot buka windows create new Variable
void MainWindow::openMergeTable(){
   MergeDataTable* dialog =  new MergeDataTable(vv,Rcon,this );
    dialog->show();
}

void MainWindow::openCreateNewVariable(){
   CreateNewVariable* dialog =  new CreateNewVariable(vv,this );
    dialog->show();
}

// slot buka dialog delete variable
void MainWindow::openDeleteVariable(){
    DeleteVariable* dialog =  new DeleteVariable(vv,this );
     dialog->show();
}
void MainWindow::openModifyVariable(){
     ModifyVariable* dialog =  new ModifyVariable(vv,this );
     dialog->show();
}
void MainWindow::openCalculateVariable(){
    ComputeVariable* dialog =  new ComputeVariable(vv,Rcon ,this );
     dialog->show();
}
void MainWindow::openRecodeVariable(){
    HistogramCreator* dialog =  new HistogramCreator(vv,Rcon,HistogramCreator::RECODEVARIABLE,this );
     dialog->show();;
}

//inisialisasi slot explore menu
void MainWindow::openDescriptiveCreator(){
    DescriptiveStat* dialog =  new DescriptiveStat(vv,Rcon,this );
     dialog->show();
}
void MainWindow::openHistogramCreator(){
    HistogramCreator* dialog =  new HistogramCreator(vv,Rcon,HistogramCreator::HISTOGRAM,this );
     dialog->show();
}
void MainWindow::openScatterCreator(){
    TwoVariablePicker* dialog = new TwoVariablePicker(vv,Rcon,TwoVariablePicker::SCATTER,this);
    dialog->show();
}
void MainWindow::openBoxplotCreator(){
    TwoVariablePicker* dialog = new TwoVariablePicker(vv,Rcon,TwoVariablePicker::BOXPLOT,this);
    dialog->show();
}
void MainWindow::openParallelCreator(){
    ParalleChart* dialog = new ParalleChart(vv,Rcon,this);
    dialog->show();
}
//open random sample generator dialog
void MainWindow::openRandomSampleGenerator(){
RandomSampleGenarator* dialog = new RandomSampleGenarator(vv,Rcon,this);
dialog->show();
}

void MainWindow::updateViewMenu(){
   setMenubarVisible(true);
    resultViewAct->setVisible(false);
}

void MainWindow::updateViewMenuDataOnly(){
    setMenubarVisible(true);
    mapViewAct->setVisible(false);
    resultViewAct->setVisible(false);

}

void MainWindow::setMenubarVisible(bool x){

    if (x) {
        viewMenu->menuAction()->setVisible(true);
        attributeMenu->menuAction()->setVisible(true);
        mapMenu->menuAction()->setVisible(true);
        toolsMenu->menuAction()->setVisible(true);
        analysisMenu->menuAction()->setVisible(true);
        pluginMenu->menuAction()->setVisible(true);
    } else {
        viewMenu->menuAction()->setVisible(false);
        attributeMenu->menuAction()->setVisible(false);
        mapMenu->menuAction()->setVisible(false);
        toolsMenu->menuAction()->setVisible(false);
        analysisMenu->menuAction()->setVisible(false);
        pluginMenu->menuAction()->setVisible(false);
    }
}
