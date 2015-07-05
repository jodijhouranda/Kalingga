#ifndef MAPOPTIONDEFAULT_H
#define MAPOPTIONDEFAULT_H

#include <QWidget>

namespace Ui {
class MapOptionDefault;
}

class MapOptionDefault : public QWidget
{
    Q_OBJECT

public:
    explicit MapOptionDefault(QWidget *parent = 0);
    ~MapOptionDefault();

private:
    Ui::MapOptionDefault *ui;
};

#endif // MAPOPTIONDEFAULT_H
