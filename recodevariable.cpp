#include "recodevariable.h"
#include "ui_recodevariable.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
RecodeVariable::RecodeVariable(VariableView* vv, QString var,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecodeVariable),
    vv(vv),
    var(var)
{
    ui->setupUi(this);
    ui->label_variable->setText(var);
    setupUI();
}
void RecodeVariable::setupUI(){
    ui->comboBoxVariables->addItem(var);
    variableChecking(var);
    variableCheckingNew(var);

    source = vv->getCharacterVector(vv->getVariableIndex(var));
    MISSING = "MISSING";
    HIGHEST = "HIGHEST";
    LOWEST = "LOWEST";
    OTHER_VALUES = "OTHERVALUES";
    OLD_VALUE = "OLDVALUE";
    format = QString("%1 -> %2");
    on_radioButtonovalue_clicked();
    on_radioButton_nvalue_clicked();
    }

RecodeVariable::~RecodeVariable()
{
    delete ui;
}

void RecodeVariable::on_pushButtonNewVar_clicked()
{
    if (ui->listWidget->count()>0) {
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            ui->listWidget->takeItem(i);
        }
    }
    CreateNewVariable* cnv = new CreateNewVariable(vv ,this );

    cnv->show();
    cnv->updateQCombox(new QListWidget(),ui->comboBoxVariables);
}

void RecodeVariable::variableChecking(QString var){
    if(vv->getVariableType(var)=="Integer"){
    ui->lineEditovalue->setValidator(new QIntValidator());
    ui->lineEdit_orangefrom->setValidator(new QIntValidator());
    ui->lineEdit_orangeTo->setValidator(new QIntValidator());
    ui->lineEdit_olowestrange->setValidator(new QIntValidator());
    ui->lineEdit_ohighestrange->setValidator(new QIntValidator());
    }else if (vv->getVariableType(var)=="Real") {
        ui->lineEditovalue->setValidator(new QDoubleValidator());
        ui->lineEdit_orangefrom->setValidator(new QDoubleValidator());
        ui->lineEdit_orangeTo->setValidator(new QDoubleValidator());
        ui->lineEdit_olowestrange->setValidator(new QDoubleValidator());
        ui->lineEdit_ohighestrange->setValidator(new QDoubleValidator());
    }else{
        ui->radioButton_orange->setEnabled(false);
        ui->radioButton_olowestrange->setEnabled(false);
        ui->radioButton_ohighestrange->setEnabled(false);
        ui->lineEdit_orangefrom->setEnabled(false);
        ui->lineEdit_orangeTo->setEnabled(false);
        ui->lineEdit_olowestrange->setEnabled(false);
        ui->lineEdit_ohighestrange->setEnabled(false);
        ui->label_3->setEnabled(false);
    }
}
void RecodeVariable::variableCheckingNew(QString var){
    if(vv->getVariableType(var)=="Integer"){
    ui->lineEdit_nvalue->setValidator(new QIntValidator());
    }else if (vv->getVariableType(var)=="Real") {
        ui->lineEdit_nvalue->setValidator(new QDoubleValidator());
    }
}

void RecodeVariable::on_comboBoxVariables_currentIndexChanged(const QString &arg1)
{
    variableCheckingNew(arg1);
}

void RecodeVariable::on_pushButtonAdd_clicked()
{


    QString first;
    QString second;
    if (ui->radioButtonovalue->isChecked()) {
        if (ui->lineEditovalue->text().trimmed()=="") {
            QMessageBox::information(this,"Input Error","Please fill the input");
            return;
        }
    first = ui->lineEditovalue->text();
    }else if (ui->radioButton_orange->isChecked()) {

        if (ui->lineEdit_orangeTo->text().trimmed()=="" || ui->lineEdit_orangefrom->text().trimmed()=="") {
            QMessageBox::information(this,"Input Error","Please fill the input");
            return;
        }
        if(rangeSmallerValidation(ui->lineEdit_orangefrom->text().toDouble(),ui->lineEdit_orangeTo->text().toDouble())){ return;}
        if(testRangeValidation(ui->lineEdit_orangefrom->text().toDouble(),ui->lineEdit_orangeTo->text().toDouble())) { return;}

    first = ui->lineEdit_orangefrom->text();
    first += " TO ";
    first += ui->lineEdit_orangeTo->text();
    }else if (ui->radioButton_olowestrange->isChecked()) {
        nlowest = getMinimumVector(vv->getNumericVector(vv->getVariableIndex(var)));
        nhighest = getMaximumVector(vv->getNumericVector(vv->getVariableIndex(var)));
        if (ui->lineEdit_olowestrange->text().trimmed()=="") {
            QMessageBox::information(this,"Input Error","Please fill the input");
            return;
        }
        if(rangeSmallerValidation(nlowest,ui->lineEdit_olowestrange->text().toDouble())){ return;}
        if(testRangeValidation(nlowest,ui->lineEdit_olowestrange->text().toDouble())){ return;}
        first = "LOWEST TO ";
        first += ui->lineEdit_olowestrange->text();
    }else if (ui->radioButton_ohighestrange->isChecked()) {
        nlowest = getMinimumVector(vv->getNumericVector(vv->getVariableIndex(var)));
        nhighest = getMaximumVector(vv->getNumericVector(vv->getVariableIndex(var)));
        if (ui->lineEdit_ohighestrange->text().trimmed()=="") {
            QMessageBox::information(this,"Input Error","Please fill the input");
            return;
        }
        if(rangeSmallerValidation(ui->lineEdit_ohighestrange->text().toDouble(),nhighest)){ return;}
        if(testRangeValidation(ui->lineEdit_ohighestrange->text().toDouble(),nhighest)) { return;}
        first = ui->lineEdit_ohighestrange->text();
        first += " TO HIGHEST";
    }else if (ui->radioButton_omissing->isChecked()) {
      first = "MISSING";
    }else if (ui->radioButton_oother->isChecked()) {
        first = "OTHER VALUES";
    }

    if (ui->radioButton_nvalue->isChecked()) {
        if (ui->lineEdit_nvalue->text().trimmed()=="") {
            QMessageBox::information(this,"Input Error","Please fill the input field");
            return;
        }
        second = ui->lineEdit_nvalue->text();
    }else if (ui->radioButton_nmissing->isChecked()) {
        second = "MISSING";
    }
    else if (ui->radioButton_ncopyold->isChecked()) {
        second = "OLD VALUE";
    }

    if (ui->listWidget->count()>0) {

        for (int i = 0; i < ui->listWidget->count(); ++i) {
            if (ui->listWidget->item(i)->text().split(QRegExp("(\\->)")).at(0).trimmed() == first.trimmed()) {
                QMessageBox::information(this,"Input Error","Please insert different code!");
                return;
            }
        }
    }
    ui->listWidget->addItem(format.arg(first,second));
    ui->radioButtonovalue->setChecked(true);
    ui->radioButton_nvalue->setChecked(true);
    on_radioButtonovalue_clicked();
    on_radioButton_nvalue_clicked();
}
void RecodeVariable::disabledAll(){
    ui->lineEditovalue->setEnabled(false);
    ui->lineEdit_orangefrom->setEnabled(false);
    ui->lineEdit_orangeTo->setEnabled(false);
    ui->lineEdit_olowestrange->setEnabled(false);
    ui->lineEdit_ohighestrange->setEnabled(false);

    ui->lineEditovalue->setText("");
    ui->lineEdit_orangefrom->setText("");
    ui->lineEdit_orangeTo->setText("");
    ui->lineEdit_olowestrange->setText("");
    ui->lineEdit_ohighestrange->setText("");
}
void RecodeVariable::disabledAllOld(){
    ui->lineEdit_nvalue->setEnabled(false);
    ui->lineEdit_nvalue->setText("");
}

void RecodeVariable::on_radioButtonovalue_clicked()
{
    disabledAll();
    ui->lineEditovalue->setEnabled(true);
}

void RecodeVariable::on_radioButton_omissing_clicked()
{
    disabledAll();
}

void RecodeVariable::on_radioButton_orange_clicked()
{
    disabledAll();

    ui->lineEdit_orangefrom->setEnabled(true);
    ui->lineEdit_orangeTo->setEnabled(true);
}

void RecodeVariable::on_radioButton_olowestrange_clicked()
{
    disabledAll();
    ui->lineEdit_olowestrange->setEnabled(true);
}

void RecodeVariable::on_radioButton_ohighestrange_clicked()
{
    disabledAll();
    ui->lineEdit_ohighestrange->setEnabled(true);
}

void RecodeVariable::on_radioButton_oother_clicked()
{
    disabledAll();
}

void RecodeVariable::on_radioButton_nvalue_clicked()
{
 disabledAllOld();

 ui->lineEdit_nvalue->setEnabled(true);
}

void RecodeVariable::on_radioButton_nmissing_clicked()
{
     disabledAllOld();
}

void RecodeVariable::on_radioButton_ncopyold_clicked()
{
     disabledAllOld();
}


void RecodeVariable::on_pushButtonRemove_clicked()
{
    if (ui->listWidget->count()>0) {

        ui->listWidget->takeItem(ui->listWidget->currentRow());
    }
}

void RecodeVariable::on_buttonBox_accepted()
{
    if (ui->listWidget->count()==0) {
        QMessageBox::information(this,"Input Error","Please Insert OLD VALUE -> NEW VALUE");
        return;
    }
    insertRecodeVariable();
    close();
}
void RecodeVariable::insertRecodeVariable(){
     result = createResultVector(source.length());
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QRegExp rx("(\\->)");
        QString code = ui->listWidget->item(i)->text().replace(" ","");
        QStringList codeSplitted = code.split(rx);
        QString oldvalue = codeSplitted.at(0);
        QString newvalue = codeSplitted.at(1);


        QStringList oldValueSplitted = oldvalue.split( QRegExp("(\\TO)"));
        if (oldValueSplitted.length() == 1) {
            if (oldvalue.trimmed() == MISSING) {
                if (newvalue.trimmed() == MISSING) {
                    for (int i = 0; i < result.length(); ++i) {
                        if (source[i]==NA_STRING) {
                            result[i]="";
                        }
                    }
                }else if (newvalue == OLD_VALUE) {

                    for (int i = 0; i < result.length(); ++i) {
                        if (source[i]==NA_STRING) {
                            result[i]=source[i];
                        }
                    }
                }
                else {
                        for (int i = 0; i < result.length(); ++i) {
                            if (source[i]==NA_STRING) {
                                result[i]=newvalue.toStdString();
                            }
                        }
                    }
            }else if (oldvalue.trimmed() == OTHER_VALUES) {
                if (i!=ui->listWidget->count()-1) {
                    ui->listWidget->insertItem(ui->listWidget->count()-1,ui->listWidget->takeItem(i));
                }
                oneVariableCodeOther(newvalue);
            }else {
                oneVariableCode(oldvalue,newvalue);
            }

        }else {
            if (oldValueSplitted.at(0).trimmed() == LOWEST) {

                twoVariableCode(getMinimumVector(convert(source)),oldValueSplitted.at(1).toDouble(),newvalue);

            }else if (oldValueSplitted.at(1).trimmed() == HIGHEST) {
                twoVariableCode(oldValueSplitted.at(0).toDouble(),getMaximumVector(convert(source)),newvalue);
            }else {
               twoVariableCode(oldValueSplitted.at(0).toDouble(),oldValueSplitted.at(1).toDouble(),newvalue);
            }
        }

}
    if (isNADetected()) {
       oneVariableCodeOther(OLD_VALUE);
    }
    vv->setCharacterVector(ui->comboBoxVariables->currentText(),result);
}
void RecodeVariable::oneVariableCode(QString value, QString code){
    if (code.trimmed() == MISSING) {
        for (int i = 0; i < result.length(); ++i) {
            if (QString::fromUtf8(source[i])==value) {
                result[i]="";
            }
        }
    }else if (code == OLD_VALUE) {

        for (int i = 0; i < result.length(); ++i) {
            if (QString::fromUtf8(source[i])==value) {
                result[i]=source[i];
            }
        }
    }
    else {
            for (int i = 0; i < result.length(); ++i) {
                if (QString::fromUtf8(source[i])==value) {
                    result[i]=code.toStdString();
                }
            }
        }
}

void RecodeVariable::oneVariableCodeOther(QString code){
    if (code.trimmed() == MISSING) {
        for (int i = 0; i < result.length(); ++i) {
            if (result[i]==NA_STRING) {
                result[i]="";
            }
        }
    }else if (code == OLD_VALUE) {

        for (int i = 0; i < result.length(); ++i) {
            if (result[i]==NA_STRING) {
                result[i]=source[i];
            }
        }
    }
    else {
            for (int i = 0; i < result.length(); ++i) {
                if (result[i]==NA_STRING) {
                    result[i]=code.toStdString();
                }
            }
        }
}
void RecodeVariable::twoVariableCode(double from,double to, QString code){
    if (code.trimmed() == MISSING) {
        for (int i = 0; i < result.length(); ++i) {
            double tes = QString::fromUtf8(source[i]).toDouble();
            if (tes>from && tes<=to) {
                result[i]="";
            }
        }
    }else if (code.trimmed() == OLD_VALUE) {

        for (int i = 0; i < result.length(); ++i) {
            double tes = QString::fromUtf8(source[i]).toDouble();
            if (tes>from && tes<=to) {
                result[i]=source[i];
            }
        }
    }
    else {
            for (int i = 0; i < result.length(); ++i) {
                double tes = QString::fromUtf8(source[i]).toDouble();
                if (tes>from && tes<=to) {
                    result[i]=code.toStdString();
                }
            }
        }
}

Rcpp::CharacterVector RecodeVariable::createResultVector(int n){
    Rcpp::CharacterVector x(n);
    for (int i = 0; i < x.length(); ++i) {
        x[i] = NA_STRING;
    }
    return x;
}

double RecodeVariable::getMinimumVector(Rcpp::NumericVector vec){
    Rcpp::NumericVector::iterator it = std::min_element(vec.begin(),vec.end());
    return vec[it-vec.begin()];
}
double RecodeVariable::getMaximumVector(Rcpp::NumericVector vec){
    Rcpp::NumericVector::iterator it = std::max_element(vec.begin(),vec.end());
    return vec[it-vec.begin()];
}
 Rcpp::NumericVector RecodeVariable::convert(Rcpp::CharacterVector vec){
    Rcpp::NumericVector res(vec.length());
     for (int i = 0; i < vec.length(); ++i) {
         res[i] = QString::fromUtf8(vec[i]).toDouble();
     }
     return res;
 }
bool RecodeVariable::rangeValidation(double ffrom, double fto, double sfrom, double sto){
    if ((sfrom >ffrom && sfrom<=fto) || (sto >ffrom && sto<=fto)) {
        return true;
    }
    if ((ffrom >sfrom && ffrom<=sto) || (fto >sfrom && fto<=sto)) {
        return true;
    }
    return false;
}

bool RecodeVariable::testRangeValidation(double ffrom,double fto){
    if (ui->listWidget->count()<=0) {
        return false;
    }
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QString arg = ui->listWidget->item(i)->text().split("->").at(0);
        QStringList argSplitted = arg.split("TO");
        if (argSplitted.length()==1) {
            continue;
        }
        if (rangeValidation(ffrom,fto,argSplitted.at(0).toDouble(),argSplitted.at(1).toDouble())) {

            QMessageBox::information(this,"Input Error","Insert different range!");
            return true;
        }
    }
    return false;
}
bool RecodeVariable::rangeSmallerValidation(double from, double to){
    if (from>to) {
        QMessageBox::information(this,"Input Error","First argument must smaller than second argument");
        return true;
    }
    return false;
}

void RecodeVariable::on_buttonBox_rejected()
{
    close();
}
bool RecodeVariable::isNADetected(){
    for (int i = 0; i < result.length(); ++i) {
        if (result[i]==NA_STRING) {
            return true;
        }
    }
    return false;
}
