#include "dialog.h"
#include "ui_dialog.h"
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QTextTable>
#include <QDebug>
#include <QTextBrowser>
Dialog::Dialog(VariableView *vv, ResultView *result, RInside &rcon,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    vv(vv),
    rcon(rcon),
    result(result)
{
    rcon.parseEvalQ("library(ape)");
    ui->setupUi(this);
    ui->comboBoxLat->addItems(vv->getNumericVariableNames());
    ui->comboBoxLong->addItems(vv->getNumericVariableNames());
    ui->comboBoxVar->addItems(vv->getNumericVariableNames());
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    QStringList var;
    var << ui->comboBoxLat->currentText();
    var << ui->comboBoxLong->currentText();
    var << ui->comboBoxVar->currentText();
    vv->sendDataFrameByVar(var,rcon);

    QString cmd1 = QString("dists <- as.matrix(dist(cbind( %1 , %2)))").arg("dframe$" + ui->comboBoxLong->currentText(),"dframe$" + ui->comboBoxLat->currentText());

    qDebug() << cmd1;
    rcon.parseEvalQ(cmd1.toStdString());
    rcon.parseEvalQ("dists.inv <- 1/dists");
    rcon.parseEvalQ("diag(dists.inv) <- 0");
    QString cmd2 = QString("Moran.I(dframe$Av8top, dists.inv)");
    cmd2.arg(ui->comboBoxVar->currentText());
    double observed = rcon.parseEval(cmd2.toStdString() + "$observed");

    double expected = rcon.parseEval(cmd2.toStdString() + "$expected");

    double sd = rcon.parseEval(cmd2.toStdString() + "$sd");

    double pvalue = rcon.parseEval(cmd2.toStdString() + "$p.value");


    QStringList attr;
    attr << "Observed" << "Expected" << "sd" << "pvalue";
    QTextTableFormat orderTableFormat;
    orderTableFormat.setMargin(40);
    orderTableFormat.setCellPadding(8);
    orderTableFormat.setCellSpacing(0);
    orderTableFormat.setBorderBrush(QBrush(Qt::SolidPattern));
    QWidget* descriptive= new QWidget();
    QTextBrowser* descText= new QTextBrowser(descriptive);
    QTextCursor cursor(descText->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QTextTable * statTable = cursor.insertTable(2,4, orderTableFormat);
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    format.setFontPointSize(10);
    for (int col = 0; col < (attr.length()); ++col) {
            cursor = statTable->cellAt(0, col).firstCursorPosition();
            cursor.insertText(attr.at(col),format);
    }
    cursor = statTable->cellAt(1, 0).firstCursorPosition();
    cursor.insertText(QString::number(observed),format);

    cursor = statTable->cellAt(1, 1).firstCursorPosition();
    cursor.insertText(QString::number(expected),format);

    cursor = statTable->cellAt(1, 2).firstCursorPosition();
    cursor.insertText(QString::number(sd),format);

    cursor = statTable->cellAt(1, 3).firstCursorPosition();
    cursor.insertText(QString::number(pvalue),format);


    QStringList listItem ;
    listItem << "Descriptive";
    QList<QWidget*> resultWidget;
    resultWidget << descriptive;
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(descText);
    layout->setMargin(0);
    descriptive->setLayout(layout);
    descText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    ResultViewItem* resultitem  = new ResultViewItem(listItem,resultWidget,"Moran I Test");
    result->setResultViewItem(resultitem);
    MoranPLugins::showResultDialog();
    close();
}

void Dialog::on_buttonBox_rejected()
{
    close();
}
