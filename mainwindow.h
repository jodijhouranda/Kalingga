#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDesktopWidget>
#include <QMainWindow>
#include <RInside.h>
#include <spreadsheet.h>
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(RInside & R,QWidget *parent = 0);

public slots:
    void openCSVSlot();

private:
    void setupWindowsSetting();
    void setupMenuBar();
    void createTabView();
    void createAction();
    void updateDataView(Spreadsheet* ss);
    void updateVariableView(QTableWidget* table);
    QTabWidget *tabView;
    QAction* openCSV;
    QMenu* filemenu;
    RInside& Rcon;


};

#endif // MAINWINDOW_H
