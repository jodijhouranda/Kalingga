#include "descriptivestat.h"
#include "ui_descriptivestat.h"
#include <QMessageBox>
#include <mainwindow.h>
#include <resultviewitem.h>
#include <resultview.h>
#include <QHBoxLayout>
#include <QDebug>
DescriptiveStat::DescriptiveStat(VariableView* vv ,RInside &rconn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DescriptiveStat),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    ui->listWidget->addItems(vv->getNumericVariableNames());
    functionMean = QString("mean(%1)");
    functionMedian = QString("median(%1)");
    functionSum = QString("sum(%1)");

    functionStdev = QString("sqrt(var(%1))");
    functionVariance = QString("var(%1)");
    functionRange = QString("max(%1)-min(%1)");
    functionMaximum = QString("max(%1)");
    functionMinimum = QString("min(%1)");
    functionSEMean = QString("std.error(%1)");

    functionSkewness = QString("skewness(%1)");
    functionKurtosis = QString("kurtosis(%1)");

    tittle = "Desciptive Statistics";
    rconn.parseEvalQ("library(e1071)");
    rconn.parseEvalQ("library(plotrix)");
}

DescriptiveStat::~DescriptiveStat()
{
    delete ui;
}
QString DescriptiveStat::getChooseVar(QList<QListWidgetItem*> list){
    QString var = QString("c(%1)");
    QString arg="";

    if (list.count()>0) {

        for (int i = 0; i < list.count(); ++i) {
            if (i==0) {
                arg += QString::number(vv->getVariableIndex(list.at(i)->text())+1);
            }else {
                arg += ","+ QString::number(vv->getVariableIndex(list.at(i)->text())+1);
            }
        }
    }
    return var.arg(arg);
}

void DescriptiveStat::on_buttonBox_rejected()
{
close();
}

void DescriptiveStat::on_buttonBox_accepted()
{
    if (ui->listWidget->selectedItems().length()<=0) {
        QMessageBox::information(this,"Choose Variable!","Please choose at least one variabel !");
    }
    QStringList stringList;
    foreach( QListWidgetItem *item, ui->listWidget->selectedItems() )
        stringList << item->text();
    vv->sendDataFrameByVar(stringList,rconn);
    variables = stringList;
    showResult();
}
void DescriptiveStat::showResult(){

    statistics <<"Variable";
    if (ui->checkBoxMean->isChecked()) {
    statistics<<"Mean";
    }
    if (ui->checkBoxMedian->isChecked()) {
    statistics<<"Median";

    }
    if (ui->checkBoxSum->isChecked()) {
    statistics<<"Sum";

    }
    if (ui->checkBoxSdev->isChecked()) {
    statistics<<"Standar Deviation";

    }
    if (ui->checkBoxVariance->isChecked()) {
    statistics<<"Variance";

    }
    if (ui->checkBoxRange->isChecked()) {
    statistics<<"Range";

    }
    if (ui->checkBoxMaximum->isChecked()) {
    statistics<<"Maximum";

    }
    if (ui->checkBoxMinimum->isChecked()) {
    statistics<<"Minimum";

    }
    if (ui->checkBoxSEMean->isChecked()) {
    statistics<<"S.E. Mean";

    }
    if (ui->checkBoxKurtosis->isChecked()) {
    statistics<<"Kurtosis";

    }
    if (ui->checkBoxSkewness->isChecked()) {
    statistics<<"Skewness";

    }
    if (statistics.length()>1) {


        QTextTableFormat orderTableFormat;
        orderTableFormat.setMargin(40);
        orderTableFormat.setCellPadding(8);
        orderTableFormat.setCellSpacing(0);
        orderTableFormat.setBorderBrush(QBrush(Qt::SolidPattern));
        QWidget* descriptive= new QWidget();
        descText= new QTextBrowser(descriptive);
        QTextCursor cursor(descText->textCursor());
        cursor.movePosition(QTextCursor::Start);
        statTable = cursor.insertTable(variables.length()+1,statistics.length(), orderTableFormat);
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        format.setFontPointSize(10);
        for (int col = 0; col < (statistics.length()); ++col) {
                cursor = statTable->cellAt(0, col).firstCursorPosition();
                cursor.insertText(statistics.at(col),format);

        }

        for (int row = 0; row < variables.length(); ++row) {
            cursor = statTable->cellAt(row+1, 0).firstCursorPosition();
            cursor.insertText(variables.at(row));
        }
        if (ui->checkBoxMean->isChecked()) {
        countVariable(functionMean,meanValue,statistics.indexOf("Mean"));
        }
        if (ui->checkBoxMedian->isChecked()) {
        countVariable(functionMedian,medianValue,statistics.indexOf("Median"));
        }
        if (ui->checkBoxSum->isChecked()) {
        countVariable(functionSum,sumValue,statistics.indexOf("Sum"));
        }
        if (ui->checkBoxSdev->isChecked()) {
        countVariable(functionStdev,stdevValue,statistics.indexOf("Standar Deviation"));
        }
        if (ui->checkBoxVariance->isChecked()) {
        countVariable(functionVariance,varianceValue,statistics.indexOf("Variance"));
        }
        if (ui->checkBoxRange->isChecked()) {
        countVariable(functionRange,rangeValue,statistics.indexOf("Range"));
        }
        if (ui->checkBoxMaximum->isChecked()) {
        countVariable(functionMaximum,maximumValue,statistics.indexOf("Maximum"));
        }
        if (ui->checkBoxMinimum->isChecked()) {
        countVariable(functionMinimum,minimumValue,statistics.indexOf("Minimum"));
        }
        if (ui->checkBoxSEMean->isChecked()) {
        countVariable(functionSEMean,SEmeanValue,statistics.indexOf("S.E. Mean"));
        }
        if (ui->checkBoxKurtosis->isChecked()) {
        countVariable(functionKurtosis,kurtosisValue,statistics.indexOf("Kurtosis"));
        }
        if (ui->checkBoxSkewness->isChecked()) {
        countVariable(functionSkewness,skewnessValue,statistics.indexOf("Skewness"));
        }


        listItem<< "Descriptive";
        resultWidget << descriptive;
        QHBoxLayout* layout = new QHBoxLayout();
        layout->addWidget(descText);
        layout->setMargin(0);
        descriptive->setLayout(layout);
        descText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    }
    if (ui->checkBoxSummary->isChecked()) {
        summaryVariable();
    }
    if (ui->checkBoxFivenum->isChecked()) {
        fivenumVariable();
    }
    ResultViewItem* result  = new ResultViewItem(listItem,resultWidget,tittle);
    MainWindow::result->setResultViewItem(result);
    MainWindow::enableResultView();
}
void DescriptiveStat::countVariable(QString function,QStringList result,int col){
    for (int i = 0; i < variables.count(); ++i) {
    Rcpp::NumericVector vec = vv->getNumericVector(vv->getVariableIndex(variables.at(i)));
    rconn["vector"] = vec;
    double res  = rconn.parseEval(function.arg("vector").toStdString());
    result << QString::number(res);
    }
    for (int row = 0; row < variables.length(); ++row) {
        QTextCursor cursor(descText->textCursor());
        cursor = statTable->cellAt(row+1,col ).firstCursorPosition();
        cursor.insertText(result.at(row));
    }
}

void DescriptiveStat::summaryVariable(){

    QTextTableFormat orderTableFormat;
    orderTableFormat.setCellPadding(10);
    orderTableFormat.setMargin(20);
    orderTableFormat.setCellSpacing(0);
    orderTableFormat.setBorderBrush(QBrush(Qt::SolidPattern));
    QWidget* summary= new QWidget();
    QTextEdit* summaryText= new QTextEdit(summary);
    summaryText->setAlignment(Qt::AlignHorizontal_Mask);
    QTextCursor cursor(summaryText->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QStringList attr;
    attr << "Min." << "1St.Quantile" << "Median" << "Mean" << "3Rd.Quantile" << "Max";
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(summaryText);
    layout->setMargin(0);
    summary->setLayout(layout);
    summaryText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QTextTableFormat alignFormat;
    alignFormat.setMargin(20);
    alignFormat.setBorderStyle(QTextFrameFormat::BorderStyle_None);

    QTextTable* align;
    if (variables.length()>=5) {
        if (variables.length()/5 == (double)variables.length()/5) {
            align = cursor.insertTable(variables.length()/5,5,alignFormat);
        }else {
            align = cursor.insertTable((variables.length()/5)+1,5,alignFormat);

        }
    }else {
        align = cursor.insertTable(1,5,alignFormat);
    }
    int j = 0;
    int k = 0;
    for (int i = 0; i < variables.length(); ++i) {
        if (i/5 == (double)i/5 && i!=0) {
            j++;
            k=0;
        }
        qDebug()<<QString::number(j) +" "+QString::number(k);

        cursor = align->cellAt(j, k).firstCursorPosition();
        QTextTable* baru = cursor.insertTable(7,2, orderTableFormat);

        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        format.setFontPointSize(10);
        format.setVerticalAlignment(QTextCharFormat::AlignBottom );
        baru->mergeCells(0,0,1,2);

        Rcpp::NumericVector vec = vv->getNumericVector(vv->getVariableIndex(variables.at(i)));
        rconn["vector"] = vec;
        qDebug()<<"samoai";
        cursor = baru->cellAt(0, 0).firstCursorPosition();
        cursor.insertText(variables.at(i),format);
        for (int col = 0; col < attr.length(); ++col) {
                cursor = baru->cellAt(col+1, 0).firstCursorPosition();
                cursor.insertText(attr.at(col));
        }
        cursor = baru->cellAt(1, 1).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("min(vector)")));

        cursor = baru->cellAt(2, 1).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("quantile(vector , probs=0.25)")));

        cursor = baru->cellAt(3, 1).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("median(vector)")));

        cursor = baru->cellAt(4, 1).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("mean(vector)")));

        cursor = baru->cellAt(5, 1).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("quantile(vector , probs=0.75)")));

        cursor = baru->cellAt(6, 1).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("max(vector)")));

        k++;
    }

    listItem<< "Summary";
    resultWidget << summary;

}

void DescriptiveStat::fivenumVariable(){

    QTextTableFormat orderTableFormat;
    orderTableFormat.setCellPadding(10);
    orderTableFormat.setMargin(20);
    orderTableFormat.setCellSpacing(0);
    orderTableFormat.setBorderBrush(QBrush(Qt::SolidPattern));
    QWidget* summary= new QWidget();
    QTextEdit* summaryText= new QTextEdit(summary);
    summaryText->setAlignment(Qt::AlignHorizontal_Mask);
    QTextCursor cursor(summaryText->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(summaryText);
    layout->setMargin(0);
    summary->setLayout(layout);
    summaryText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QTextTableFormat alignFormat;
    alignFormat.setMargin(20);
    alignFormat.setBorderStyle(QTextFrameFormat::BorderStyle_None);

    QTextTable* align;
    if (variables.length()>=8) {
        if (variables.length()/8 == (double)variables.length()/8) {
            align = cursor.insertTable(variables.length()/8,5,alignFormat);
        }else {
            align = cursor.insertTable((variables.length()/8)+1,8,alignFormat);

        }
    }else {
        align = cursor.insertTable(1,8,alignFormat);
    }
    int j = 0;
    int k = 0;
    for (int i = 0; i < variables.length(); ++i) {
        if (i/8 == (double)i/8 && i!=0) {
            j++;
            k=0;
        }
        qDebug()<<QString::number(j) +" "+QString::number(k);

        cursor = align->cellAt(j, k).firstCursorPosition();
        QTextTable* baru = cursor.insertTable(6,1, orderTableFormat);

        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        format.setFontPointSize(10);
        format.setVerticalAlignment(QTextCharFormat::AlignBottom );


        Rcpp::NumericVector vec = vv->getNumericVector(vv->getVariableIndex(variables.at(i)));
        rconn["vector"] = vec;
        qDebug()<<"samoai";
        cursor = baru->cellAt(0, 0).firstCursorPosition();
        cursor.insertText(variables.at(i),format);

        cursor = baru->cellAt(1, 0).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("min(vector)")));

        cursor = baru->cellAt(2, 0).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("quantile(vector , probs=0.25)")));

        cursor = baru->cellAt(3, 0).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("median(vector)")));

        cursor = baru->cellAt(4, 0).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("quantile(vector , probs=0.75)")));

        cursor = baru->cellAt(5, 0).firstCursorPosition();
        cursor.insertText(QString::number((double)rconn.parseEval("max(vector)")));

        k++;
    }

    listItem<< "Fivenum";
    resultWidget << summary;

}
