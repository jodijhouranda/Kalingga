#ifndef CREATENEWVARIABLE_H
#define CREATENEWVARIABLE_H

#include <QDialog>
#include <QComboBox>
#include <variableview.h>
#include <QListWidget>
namespace Ui {
class CreateNewVariable;
}

class CreateNewVariable : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewVariable(VariableView* vv , QWidget *parent = 0);
    ~CreateNewVariable();
    void updateQCombox(QListWidget* listwidget , QComboBox* combo);
    void inactivatedRealType();
    void inactivatedIntegerType();
    void inactivatedStringType();

private slots:

    void on_buttonBox_accepted();


private:
    QListWidget* m_listwidget;
    QComboBox* m_combo;
    Ui::CreateNewVariable *ui;
    VariableView* vv;
    bool TEST;
};

#endif // CREATENEWVARIABLE_H
