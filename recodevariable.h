#ifndef RECODEVARIABLE_H
#define RECODEVARIABLE_H

#include <QDialog>
#include <variableview.h>
#include <createnewvariable.h>
#include <Rcpp.h>
namespace Ui {
class RecodeVariable;
}

class RecodeVariable : public QDialog
{
    Q_OBJECT

public:
    explicit RecodeVariable(VariableView* vv, QString var,QWidget *parent = 0);
    ~RecodeVariable();

private slots:

    void on_pushButtonNewVar_clicked();

    void on_comboBoxVariables_currentIndexChanged(const QString &arg1);

    void on_pushButtonAdd_clicked();

    void on_radioButtonovalue_clicked();

    void on_radioButton_omissing_clicked();

    void on_radioButton_orange_clicked();

    void on_radioButton_olowestrange_clicked();

    void on_radioButton_ohighestrange_clicked();

    void on_radioButton_oother_clicked();

    void on_radioButton_nvalue_clicked();

    void on_radioButton_nmissing_clicked();

    void on_radioButton_ncopyold_clicked();

    void on_pushButtonRemove_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RecodeVariable *ui;
    VariableView* vv;
    QString var;
    void setupUI();
    void variableChecking(QString var);
    void variableCheckingNew(QString var);
    void disabledAll();
    void disabledAllOld();
    void insertRecodeVariable();
    Rcpp::CharacterVector createResultVector(int n);
    void oneVariableCode(QString value , QString code);
    void oneVariableCodeOther(QString code);
    void twoVariableCode(double from,double to, QString code);
    QString format;
    QString HIGHEST;
    QString LOWEST;
    QString MISSING;
    QString OTHER_VALUES;
    QString OLD_VALUE;
    Rcpp::CharacterVector source;
    Rcpp::CharacterVector result;
    double getMinimumVector(Rcpp::NumericVector vec);
    double getMaximumVector(Rcpp::NumericVector vec);
    Rcpp::NumericVector convert(Rcpp::CharacterVector vec);
    bool rangeValidation(double ffrom,double fto,double sfrom,double sto);
    bool testRangeValidation(double ffrom, double fto);
    bool rangeSmallerValidation(double from,double to);
    double nlowest;
    double nhighest;
    bool isNADetected();
};

#endif // RECODEVARIABLE_H
