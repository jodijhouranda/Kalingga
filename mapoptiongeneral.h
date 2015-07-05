#ifndef MAPOPTIONGENERAL_H
#define MAPOPTIONGENERAL_H

#include <QWidget>

class MapView;
class VariableView;
class QCheckBox;

namespace Ui {
class MapOptionGeneral;
}

class MapOptionGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit MapOptionGeneral(MapView *view, VariableView* vv, QWidget *parent = 0);
    ~MapOptionGeneral();

    QString getLineEditLayerName() const;
    void setLineEditLayerName();

    QString getLineEditLayerSource() const;
    void setLineEditLayerSource();

    QString getLineEditLayerType() const;
    void setLineEditLayerType();

    QString getLineEditObservation() const;
    void setLineEditObservation(QString value);

    QString getLineEditField() const;
    void setLineEditField(QString value);

    void setScaleDependentVisibility(bool value);

private slots:
    void ScaleDependentVisibilityChange(bool value);

private:
    Ui::MapOptionGeneral *ui;
    MapView *mview;
    VariableView *vv;
};

#endif // MAPOPTIONGENERAL_H
