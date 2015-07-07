#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <Kalingga-master/includes.h>
#include <RInside.h>
#include <moranplugins.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(VariableView *vv, ResultView *result, RInside &rcon,QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    VariableView *vv;
    ResultView *result;
    RInside &rcon;
};

#endif // DIALOG_H
