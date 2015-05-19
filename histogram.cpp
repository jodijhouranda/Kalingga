#include "histogram.h"
#include "ui_histogram.h"

Histogram::Histogram(QGraphicsScene* item ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Histogram),
    item(item)
{
    ui->setupUi(this);
    ui->histogramView->setScene(item);
}

Histogram::~Histogram()
{
    delete ui;
}
