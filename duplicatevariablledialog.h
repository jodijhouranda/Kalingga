#ifndef DUPLICATEVARIABLLEDIALOG_H
#define DUPLICATEVARIABLLEDIALOG_H

#include <QDialog>
#include <variableview.h>
namespace Ui {
class DuplicateVariablleDialog;
}

class DuplicateVariablleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DuplicateVariablleDialog(QList<int> indexToImport,QStringList duplicateVar,VariableView* vv,VariableView* vvImport,int mode,QWidget *parent = 0);
    ~DuplicateVariablleDialog();

    void setCurrentKey(QString key);
    void setImportKey(QString key);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DuplicateVariablleDialog *ui;
    QStringList duplicateVar;
    VariableView* vv;
    VariableView* vvImport;
    QList<int> indexToImport;
    int mode;
    void init();

    QString currentKey;
    QString importKey;

};

#endif // DUPLICATEVARIABLLEDIALOG_H
