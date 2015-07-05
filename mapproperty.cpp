#include "mapproperty.h"

#include "mapgraphicspolygonitem.h"
#include <QtGui>
#include <QDebug>

MapProperty::MapProperty(QList<MapGraphicsPolygonItem*> *itemRegion, QWidget *parent) :
    QWidget(parent),
    itemRegion(itemRegion)
{

    fillRuleComboBox = new QComboBox;
    fillRuleComboBox->addItem(tr("Odd Even"), Qt::OddEvenFill);
    fillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);

    fillRuleLabel = new QLabel(tr("Fill &Rule:"));
    fillRuleLabel->setBuddy(fillRuleComboBox);
//! [11]

//! [12]
    fillColor1ComboBox = new QComboBox;
    populateWithColors(fillColor1ComboBox);
    fillColor1ComboBox->setCurrentIndex(
            fillColor1ComboBox->findText("mediumslateblue"));

    fillColor2ComboBox = new QComboBox;
    populateWithColors(fillColor2ComboBox);
    fillColor2ComboBox->setCurrentIndex(
            fillColor2ComboBox->findText("cornsilk"));

    fillGradientLabel = new QLabel(tr("&Fill Gradient:"));
    fillGradientLabel->setBuddy(fillColor1ComboBox);

    fillColorComboBox = new QComboBox;
    populateWithColors(fillColorComboBox);
    fillColorComboBox->setCurrentIndex(
                fillColorComboBox->findText("cornsilk"));

    fillColorLabel = new QLabel(tr("&Fill Color:"));
    fillColorLabel->setBuddy(fillColorComboBox);

    fillToLabel = new QLabel(tr("to"));
    fillToLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);

    penWidthLabel = new QLabel(tr("&Pen Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penColorComboBox = new QComboBox;
    populateWithColors(penColorComboBox);
    penColorComboBox->setCurrentIndex(
            penColorComboBox->findText("darkslateblue"));

    penColorLabel = new QLabel(tr("Pen &Color:"));
    penColorLabel->setBuddy(penColorComboBox);

    connect(fillRuleComboBox, SIGNAL(activated(int)),
            this, SLOT(fillRuleChanged()));
    connect(fillColor1ComboBox, SIGNAL(activated(int)),
            this, SLOT(fillGradientChanged()));
    connect(fillColor2ComboBox, SIGNAL(activated(int)),
            this, SLOT(fillGradientChanged()));
    connect(fillColorComboBox, SIGNAL(activated(int)),
            this, SLOT(fillColorChanged()));
    connect(penColorComboBox, SIGNAL(activated(int)),
            this, SLOT(penColorChanged()));

    connect(penWidthSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(penWidthChanged(int)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fillRuleLabel, 0, 0);
    mainLayout->addWidget(fillRuleComboBox, 0, 1, 1, 3);
    mainLayout->addWidget(fillGradientLabel, 1, 0);
    mainLayout->addWidget(fillColor1ComboBox, 1, 1);
    mainLayout->addWidget(fillToLabel, 1, 2);
    mainLayout->addWidget(fillColor2ComboBox, 1, 3);
    mainLayout->addWidget(fillColorLabel, 2, 0);
    mainLayout->addWidget(fillColorComboBox, 2, 1 ,1, 3);
    mainLayout->addWidget(penWidthLabel, 3, 0);
    mainLayout->addWidget(penWidthSpinBox, 3, 1, 1, 3);
    mainLayout->addWidget(penColorLabel, 4, 0);
    mainLayout->addWidget(penColorComboBox, 4, 1, 1, 3);
    setLayout(mainLayout);

    //fillRuleChanged();
    //fillGradientChanged();
    //fillColorChanged();
    //penColorChanged();
    //penWidthSpinBox->setValue(0);

    setWindowTitle(tr("Property Windows"));
}

MapProperty::MapProperty(QList<MapGraphicsLineItem *> *itemLine, QWidget *parent) :
    QWidget(parent),
    itemLine(itemLine)
{
    qDebug() << "map property start";
    fillRuleComboBox = new QComboBox;
    fillRuleComboBox->addItem(tr("Odd Even"), Qt::OddEvenFill);
    fillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);

    fillRuleLabel = new QLabel(tr("Fill &Rule:"));
    fillRuleLabel->setBuddy(fillRuleComboBox);
//! [11]

//! [12]
    fillColor1ComboBox = new QComboBox;
    populateWithColors(fillColor1ComboBox);
    fillColor1ComboBox->setCurrentIndex(
            fillColor1ComboBox->findText("mediumslateblue"));

    fillColor2ComboBox = new QComboBox;
    populateWithColors(fillColor2ComboBox);
    fillColor2ComboBox->setCurrentIndex(
            fillColor2ComboBox->findText("cornsilk"));

    fillGradientLabel = new QLabel(tr("&Fill Gradient:"));
    fillGradientLabel->setBuddy(fillColor1ComboBox);

    fillColorComboBox = new QComboBox;
    populateWithColors(fillColorComboBox);
    fillColorComboBox->setCurrentIndex(
                fillColorComboBox->findText("cornsilk"));

    fillColorLabel = new QLabel(tr("&Fill Color:"));
    fillColorLabel->setBuddy(fillColorComboBox);

    fillToLabel = new QLabel(tr("to"));
    fillToLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);

    penWidthLabel = new QLabel(tr("&Pen Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penColorComboBox = new QComboBox;
    populateWithColors(penColorComboBox);
    penColorComboBox->setCurrentIndex(
            penColorComboBox->findText("darkslateblue"));

    penColorLabel = new QLabel(tr("Pen &Color:"));
    penColorLabel->setBuddy(penColorComboBox);

    connect(fillRuleComboBox, SIGNAL(activated(int)),
            this, SLOT(fillRuleChanged()));
    connect(fillColor1ComboBox, SIGNAL(activated(int)),
            this, SLOT(fillGradientChanged()));
    connect(fillColor2ComboBox, SIGNAL(activated(int)),
            this, SLOT(fillGradientChanged()));
    connect(fillColorComboBox, SIGNAL(activated(int)),
            this, SLOT(fillColorChanged()));
    connect(penColorComboBox, SIGNAL(activated(int)),
            this, SLOT(penColorChanged()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(penWidthChanged(int)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fillRuleLabel, 0, 0);
    mainLayout->addWidget(fillRuleComboBox, 0, 1, 1, 3);
    mainLayout->addWidget(fillGradientLabel, 1, 0);
    mainLayout->addWidget(fillColor1ComboBox, 1, 1);
    mainLayout->addWidget(fillToLabel, 1, 2);
    mainLayout->addWidget(fillColor2ComboBox, 1, 3);
    mainLayout->addWidget(fillColorLabel, 2, 0);
    mainLayout->addWidget(fillColorComboBox, 2, 1 ,1, 3);
    mainLayout->addWidget(penWidthLabel, 3, 0);
    mainLayout->addWidget(penWidthSpinBox, 3, 1, 1, 3);
    mainLayout->addWidget(penColorLabel, 4, 0);
    mainLayout->addWidget(penColorComboBox, 4, 1, 1, 3);
    setLayout(mainLayout);

    qDebug() << "map property midle";
    fillRuleChanged();
    fillGradientChanged();
    fillColorChanged();
    penColorChanged();
    penWidthSpinBox->setValue(2);

    setWindowTitle(tr("Property Windows"));

    qDebug() << "map property finish";
}

void MapProperty::fillRuleChanged()
{
    Qt::FillRule rule = (Qt::FillRule)currentItemData(fillRuleComboBox).toInt();

//    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
//        (*it)->setFillRule(rule);
}

void MapProperty::fillGradientChanged()
{
    QColor color1 = qvariant_cast<QColor>(currentItemData(fillColor1ComboBox));
    QColor color2 = qvariant_cast<QColor>(currentItemData(fillColor2ComboBox));

//    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
//        (*it)->setFillGradient(color1, color2);
}

void MapProperty::fillColorChanged()
{
    QColor color = qvariant_cast<QColor>(currentItemData(fillColorComboBox));

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setFillColor(color);
}

void MapProperty::penColorChanged()
{
    QColor color = qvariant_cast<QColor>(currentItemData(penColorComboBox));

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setPenColor(color);
}

void MapProperty::penWidthChanged(int x)
{

    for(QList<MapGraphicsPolygonItem*>::iterator it = itemRegion->begin(); it != itemRegion->end(); it++)
        (*it)->setPenWidth(x);
}

void MapProperty::populateWithColors(QComboBox *comboBox)
{
    QStringList colorNames = QColor::colorNames();
    foreach (QString name, colorNames)
        comboBox->addItem(name, QColor(name));
}

QVariant MapProperty::currentItemData(QComboBox *comboBox)
{
    return comboBox->itemData(comboBox->currentIndex());
}

MapProperty::~MapProperty()
{

}

