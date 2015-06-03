#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDesktopWidget>
#include <QMainWindow>
#include <RInside.h>
#include <spreadsheet.h>
#include <variableview.h>
#include <createnewvariable.h>
#include <deletevariable.h>
#include <histogramcreator.h>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <resultview.h>
#include <resultviewitem.h>
#include <twovariablepicker.h>
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(RInside & R,QWidget *parent = 0);
    RInside& Rcon;
static ResultView* result;


static void enableResultView();
private slots:
    //slot data menu
    void openCSVSlot();
    void openSHPSlot();
    void openDBFSlot();
    void openCreateNewVariable();
    void openDeleteVariable();
    void openModifyVariable();
    void openCalculateVariable();
    void openRecodeVariable();
    void openRandomSampleGenerator();
    //slot explore menu
    void openDescriptiveCreator();
    void openHistogramCreator();
    void openScatterCreator();
    void openBoxplotCreator();
    void openParallelCreator();
    //slot window menu

    void openDataView();
    void openVariableView();
    void openMapView();
    void openResultView();
private:
    void setupWindowsSetting();
    void setupMenuBar();
    void createAction();
    void updateViewMenu();
    void updateViewMenuDataOnly();

    void setMenubarVisible(bool x);
    VariableView* vv;
    QTabWidget *tabView;


    QAction* openCSV;
    QAction* openSHP;
    QAction* openDBF;
    //data menu action

    QAction* createNewVariable;
    QAction* deleteVariable;
    QAction* modifyVariable;
    QAction* calculateVariable;
    QAction* recodeVariable;
    QAction* openRSGenerator;

    //explore menu action
    QAction* createDescriptive;
    QAction* createHistogram;
    QAction* createScatter;
    QAction* createBoxplot;
    QAction* createParallel;
    QMenu* fileMenu;
    QMenu *viewMenu;
    QMenu *attributeMenu;
    QMenu *mapMenu;
    QMenu *toolsMenu;
    QMenu *analysisMenu;
    QMenu *pluginMenu;
    QMenu *aboutMenu;
//view menu action
    QAction* mapViewAct;
    QAction* dataViewAct;
    QAction* variableViewAct;
    static QStackedWidget* centralView;
    static QAction* resultViewAct;
};

#endif // MAINWINDOW_H
