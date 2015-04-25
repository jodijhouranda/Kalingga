#include "histogramcreator.h"
#include "ui_histogramcreator.h"
#include <QFile>
#include <QGraphicsSvgItem>
#include <QTextStream>
#include <histogram.h>
#include <QGraphicsScene>
#include <QDebug>
HistogramCreator::HistogramCreator(VariableView* vv ,RInside &rconn, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::HistogramCreator),
    vv(vv),
    rconn(rconn)
{
    ui->setupUi(this);
    QList<QString> allVar = vv->getNumericVariableNames();
    ui->listWidgetVariables->addItems(allVar);
    m_tempfile = QString::fromStdString(Rcpp::as<std::string>(rconn.parseEval("tfile <- tempfile()")));
    m_svgfile = QString::fromStdString(Rcpp::as<std::string>(rconn.parseEval("sfile <- tempfile()")));

}

HistogramCreator::~HistogramCreator()
{
    delete ui;

}

void HistogramCreator::on_buttonBox_accepted()
{

    QString selectedVar = ui->listWidgetVariables->item(ui->listWidgetVariables->currentRow())->text();
    Rcpp::NumericVector vektor = vv->getNumericVector(vv->getVariableIndex(selectedVar));
    std::string x = ui->listWidgetVariables->currentItem()->text().toStdString();

    rconn[x] = vektor;
    try {

        std::string cmd0 ="svg(width=6,height=6,pointsize=10,filename=tfile); x <- as.vector(" ;
        std::string cmd1 = ");";
        std::string cmd2 = "y <- mean(x)";
        std::string cmd = cmd0 + x + cmd1  + cmd2  ; // stick the selected kernel in the middle
        rconn.parseEvalQ(cmd);
        rconn.parseEvalQ("hist(x) ; dev.off()");
    } catch (...) {

        qDebug() << "error 2";
    }
    double y = rconn["y"];
     qDebug() << y;
    filterSVGFile();
    m_svgItem = new QGraphicsSvgItem(m_svgfile);
    QGraphicsScene *s = new QGraphicsScene;
    s->addItem(m_svgItem);
    Histogram* dialog =  new Histogram(s);
    dialog->show();
}

void HistogramCreator::filterSVGFile() {
    // cairoDevice creates richer SVG than Qt can display
    // but per Michaele Lawrence, a simple trick is to s/symbol/g/ which we do here
    QFile infile(m_tempfile);
    infile.open(QFile::ReadOnly);
    QFile outfile(m_svgfile);
    outfile.open(QFile::WriteOnly | QFile::Truncate);

    QTextStream in(&infile);
    QTextStream out(&outfile);
    QRegExp rx1("<symbol");
    QRegExp rx2("</symbol");
    while (!in.atEnd()) {
        QString line = in.readLine();
        line.replace(rx1, "<g"); // so '<symbol' becomes '<g ...'
        line.replace(rx2, "</g");// and '</symbol becomes '</g'
        out << line << "\n";
    }
    infile.close();
    outfile.close();
}
