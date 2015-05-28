#ifndef INTEGERDELEGATE_H
#define INTEGERDELEGATE_H
#include <QItemDelegate>

class IntegerDelegate : public QItemDelegate
{
public:
    IntegerDelegate();    
    ~IntegerDelegate();
    QWidget* createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;

};

#endif // INTEGERDELEGATE_H
