#ifndef MAPTEMATIKCONFIG_H
#define MAPTEMATIKCONFIG_H

#include <QDialog>
#include <variableview.h>
#include <RInside.h>

class MapView;
class MapGraphicsPolygonItem;
class QtColorPicker;
class QLabel;
class QComboBox;
class QGraphicsItem;
class QGraphicsScene;
class MapColorReader;

namespace Ui {
class MapTematikConfig;
}

class MapTematikConfig : public QDialog
{
    Q_OBJECT

public:
    explicit MapTematikConfig(MapView* mviewResult,VariableView* vv,RInside& rconn,QList<QList<int> > temp,
                              QString var,int typeMap = 0,QWidget *parent = 0);
    ~MapTematikConfig();

private slots:
    void on_pushButtonBorderColor_clicked();
    void on_pushButtonBackgroundColor_clicked();
    void on_pushButtonLabelColor_clicked();
    void on_pushButtonAdvance_clicked();

    void setColorMover(QColor color);
    void setColorSelect(QColor color);
    void labelVisibilityChange(bool value);
    void selectBrushChange(int);
    void moverBrushChange(int);
    void borderStyleChanged();
    void borderWidthChanged(int);
    void transparencyChanged(int );
    void labelChanged(int);
    void centroidChange(bool);

private:
    void setupUiInitialized();
    void updateColorLabel(QLabel *label,const QColor &color);
    void chooseColor(QLabel *label, QColor *color);
    void setLabelVisibility(bool b);
    QVariant currentItemData(QComboBox *comboBox);

    Ui::MapTematikConfig *ui;
    MapView* mviewResult;
    VariableView* vv;
    RInside& rconn;
    QList<QList<int> > temp;
    QString var;
    int typeMap;

    QList<MapGraphicsPolygonItem *> *itemRegion;
    QList<QGraphicsItem *> *listLabel;
    QList<QGraphicsItem *> *listCentroid;
    QColor borderColor;
    QColor backgroundColor;
    QColor labelColor;
    QtColorPicker *cpMover;
    QtColorPicker *cpSelect;
};

#endif // MAPTEMATIKCONFIG_H
