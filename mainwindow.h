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

    //data menu action
    QAction* openCSV;
    QAction* openSHP;
    QAction* openDBF;

    QAction* createNewVariable;
    QAction* deleteVariable;
    //explore menu action
    QAction* createHistogram;
    QMenu* filemenu;



};

#endif // MAINWINDOW_H
