#ifndef MERGEDATATABLE_H
#define MERGEDATATABLE_H

#include <QDialog>
#include<variableview.h>
#include <RInside.h>
#include <Rcpp.h>
#include <QMenu>
#include <QListWidgetItem>
namespace Ui {
class MergeDataTable;
}

class MergeDataTable : public QDialog
{
    Q_OBJECT

public:
    explicit MergeDataTable(VariableView* vv ,RInside &rconn, QWidget *parent = 0);
    ~MergeDataTable();


private slots:
    void openCSVSlot();
    void openDBFSlot();
    void on_radioButtonByValue_clicked();

    void on_radioButtonRecordOrder_clicked();

    void on_pushButtonRightTwo_clicked();

    void on_pushButtonLeftTwo_clicked();

    void on_pushButtonRight_clicked();

    void on_pushButtonLeft_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MergeDataTable *ui;
    VariableView* vv;
    VariableView* vvImport;
    RInside& rconn;
    void init();
    QAction* openCSV;
    QAction* openSHP;
    QAction* openDBF;
    QList<int> indexToImport;

    void setButtonMenu();
    void setImportContent();
    bool nameCheckEdit(QStringList var);
};

#endif // MERGEDATATABLE_H
