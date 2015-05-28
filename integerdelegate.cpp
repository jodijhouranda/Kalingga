#include "integerdelegate.h"
#include <QLineEdit>
IntegerDelegate::IntegerDelegate()
{

}

IntegerDelegate::~IntegerDelegate()
{

}

QWidget* IntegerDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);
        // Set validator
        QIntValidator *validator = new QIntValidator(lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
