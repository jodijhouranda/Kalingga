#ifndef MAPOPTIONSTYLE_H
#define MAPOPTIONSTYLE_H

#include <QWidget>

namespace Ui {
class MapOptionStyle;
}

class MapOptionStyle : public QWidget
{
    Q_OBJECT

public:
    explicit MapOptionStyle(QWidget *parent = 0);
    ~MapOptionStyle();

private:
    Ui::MapOptionStyle *ui;
};

#endif // MAPOPTIONSTYLE_H
