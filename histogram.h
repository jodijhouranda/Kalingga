#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QDialog>
#include <QGraphicsScene>
namespace Ui {
class Histogram;
}

class Histogram : public QDialog
{
    Q_OBJECT

public:
    explicit Histogram(QGraphicsScene* item , QWidget *parent = 0);
    ~Histogram();

private:
    Ui::Histogram *ui;
    QGraphicsScene* item;
};

#endif // HISTOGRAM_H
