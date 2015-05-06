#ifndef RECODEVARIABLE_H
#define RECODEVARIABLE_H

#include <QDialog>

namespace Ui {
class RecodeVariable;
}

class RecodeVariable : public QDialog
{
    Q_OBJECT

public:
    explicit RecodeVariable(QWidget *parent = 0);
    ~RecodeVariable();

private:
    Ui::RecodeVariable *ui;
};

#endif // RECODEVARIABLE_H
