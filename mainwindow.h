#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDesktopWidget>
#include <QMainWindow>
#include <RInside.h>
#include <spreadsheet.h>
#include <variableview.h>
#include <createnewvariable.h>
#include <deletevariable.h>
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(RInside & R,QWidget *parent = 0);

public slots:
    void openCSVSlot();
    void openCreateNewVariable();
    void openDeleteVariable();
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
    QAction* createNewVariable;
    QAction* deleteVariable;
    QMenu* filemenu;
    RInside& Rcon;


};

#endif // MAINWINDOW_H
