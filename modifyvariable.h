#ifndef MODIFYVARIABLE_H
#define MODIFYVARIABLE_H

#include <QDialog>
#include <variableview.h>
#include <Rcpp.h>
namespace Ui {
class ModifyVariable;
}

class ModifyVariable : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyVariable(VariableView* vv,QWidget *parent = 0);
    ~ModifyVariable();

private slots:
    void on_tableWidgetVariable_cellClicked(int row, int column);

    void on_pushButtonApply_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::ModifyVariable *ui;
    VariableView* vv;
    QStringList allVar;
    QStringList vars ;
    void setupUiContent(int row);
    void removeComboContents();
    void removeTableVariableContents();
    void removeTableValueContents();
    bool validate();
    Rcpp::NumericVector convertReal(Rcpp::CharacterVector vec);
    Rcpp::NumericVector convertInt(Rcpp::CharacterVector vec);
    Rcpp::CharacterVector vec;

};

#endif // MODIFYVARIABLE_H
