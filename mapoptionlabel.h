#ifndef MAPOPTIONLABEL_H
#define MAPOPTIONLABEL_H

#include <QWidget>

namespace Ui {
class MapOptionLabel;
}

class MapOptionLabel : public QWidget
{
    Q_OBJECT

public:
    explicit MapOptionLabel(QWidget *parent = 0);
    ~MapOptionLabel();

private:
    Ui::MapOptionLabel *ui;
};

#endif // MAPOPTIONLABEL_H
