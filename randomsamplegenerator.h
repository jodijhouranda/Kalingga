#ifndef RANDOMSAMPLEGENERATOR_H
#define RANDOMSAMPLEGENERATOR_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>

namespace Ui {
class randomSampleGenerator;
}

class randomSampleGenerator : public QDialog
{
    Q_OBJECT

public:
    explicit randomSampleGenerator(VariableView* vv ,RInside &rconn, QWidget *parent = 0);
    ~randomSampleGenerator();

private:
    Ui::randomSampleGenerator *ui;
    void init();

    VariableView* vv;
    RInside& rconn;
};

#endif // RANDOMSAMPLEGENERATOR_H
