#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDesktopWidget>
#include <QMainWindow>
#include <RInside.h>
#include <spreadsheet.h>
#include <variableview.h>
#include <mapview.h>
#include <createnewvariable.h>
#include <deletevariable.h>
#include <histogramcreator.h>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <resultview.h>
#include <resultviewitem.h>
#include <twovariablepicker.h>
#include <QCloseEvent>
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(RInside & R,QWidget *parent = 0);
    RInside& Rcon;
static ResultView* result;


static void enableResultView();
static void addAnalysisMenu(QString tittle);
private slots:
    //slot file menu
    void openCSVSlot();
    void openSHPSlot();
    void openDBFSlot();
    void saveDataAsSlot();
    void saveDataSlot();
    void exitSlot();
    //slot file menu
    void openMergeTable();
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
    void openTimeSeriesCreator();
    //slot plugin menu
    void openPluginDialog();
    //slot window menu
    void openDataView();
    void openVariableView();
    void openMapView();
    void openResultView();
    //slot map menu
    void openQuantileMapCreator();
    void openPercentilMapCreator();
    void openBoxMapCreator();
    void openStandarDeviationMapCreator();
    void openUniqueValueMapCreator();
    void openNaturalBreaksMapCreator();
    void openEqualIntervalsCreator();
    void openOptionChooser();

private:
    bool closer;
    void closeEvent(QCloseEvent *event);
    void setupWindowsSetting();
    void setupMenuBar();
    void createAction();
    void updateViewMenu();
    void updateViewMenuDataOnly();

    void setMenubarVisible(bool x);
    VariableView* vv;
    QTabWidget *tabView;
    MapView* mview;

    QAction* openCSV;
    QAction* openSHP;
    QAction* openDBF;
    QAction* saveDataAs;
    QAction* saveData;
    QAction* exit;
    //data menu action
    QAction* mergeTable;
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
    QAction* createTimeSeries;
    QAction* createPluginDialog;

    //map menu action
    QAction* chooseOption;
    //tematik menu action
    QAction* createStandardMap;
    QAction* createQuantileMap;
    QAction* createPercentilMap;
    QAction* createBoxMap;
    QAction* createStandarDeviationMap;
    QAction* createUniqueValueMap;
    QAction* createNaturalBreaksMap;
    QAction* createEqualIntervalsMap;

    //plugin dialog
    QMenu* fileMenu;
    QMenu *viewMenu;
    QMenu *attributeMenu;
    QMenu *mapMenu;
    QMenu *toolsMenu;
    static QMenu *analysisMenu;
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
