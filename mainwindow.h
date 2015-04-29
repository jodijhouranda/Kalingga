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

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(RInside & R,QWidget *parent = 0);
    RInside& Rcon;
private slots:
    //slot data menu
    void openCSVSlot();
    void openSHPSlot();
    void openDBFSlot();
    void openCreateNewVariable();
    void openDeleteVariable();
    void openCalculateVariable();
    void openRandomSampleGenerator();
    //slot explore menu
    void openHistogramCreator();
private:
    void setupWindowsSetting();
    void setupMenuBar();
    void createTabView();
    void createAction();
    void updateDataView(QTableWidget* ss);
    void updateVariableView(QTableWidget* table);

    VariableView* vv;
    QTabWidget *tabView;


    QAction* openCSV;
    QAction* openSHP;
    QAction* openDBF;
    //data menu action

    QAction* createNewVariable;
    QAction* deleteVariable;
    QAction* calculateVariable;
    QAction* openRSGenerator;

    //explore menu action
    QAction* createHistogram;
    QMenu* filemenu;



};

#endif // MAINWINDOW_H
