/********************************************************************************
** Form generated from reading UI file 'mapoptiongeneral.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPTIONGENERAL_H
#define UI_MAPOPTIONGENERAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapOptionGeneral
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEditLayerName;
    QLabel *label_2;
    QLineEdit *lineEditLayerSource;
    QLabel *label_25;
    QLineEdit *lineEditLayerType;
    QLabel *label_26;
    QLineEdit *lineEditCRS;
    QCheckBox *checkBoxScaleDependentVisibility;
    QSplitter *splitter_7;
    QLabel *labelMaximumScale;
    QComboBox *comboBoxMaximumScale;
    QSplitter *splitter_8;
    QLabel *labelMinimumScale;
    QComboBox *comboBoxMinimumScale;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditCRS_2;
    QLineEdit *lineEditObservation;
    QLineEdit *lineEditField;

    void setupUi(QWidget *MapOptionGeneral)
    {
        if (MapOptionGeneral->objectName().isEmpty())
            MapOptionGeneral->setObjectName(QString::fromUtf8("MapOptionGeneral"));
        MapOptionGeneral->resize(531, 462);
        gridLayout = new QGridLayout(MapOptionGeneral);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(MapOptionGeneral);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMouseTracking(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 57, 16));
        lineEditLayerName = new QLineEdit(groupBox);
        lineEditLayerName->setObjectName(QString::fromUtf8("lineEditLayerName"));
        lineEditLayerName->setGeometry(QRect(170, 30, 311, 20));
        lineEditLayerName->setFrame(false);
        lineEditLayerName->setReadOnly(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 63, 16));
        lineEditLayerSource = new QLineEdit(groupBox);
        lineEditLayerSource->setObjectName(QString::fromUtf8("lineEditLayerSource"));
        lineEditLayerSource->setGeometry(QRect(170, 60, 311, 20));
        lineEditLayerSource->setFrame(false);
        lineEditLayerSource->setReadOnly(true);
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 90, 54, 16));
        lineEditLayerType = new QLineEdit(groupBox);
        lineEditLayerType->setObjectName(QString::fromUtf8("lineEditLayerType"));
        lineEditLayerType->setGeometry(QRect(170, 90, 311, 20));
        lineEditLayerType->setFrame(false);
        lineEditLayerType->setReadOnly(true);
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 120, 144, 16));
        lineEditCRS = new QLineEdit(groupBox);
        lineEditCRS->setObjectName(QString::fromUtf8("lineEditCRS"));
        lineEditCRS->setGeometry(QRect(174, 120, 311, 20));
        lineEditCRS->setFrame(false);
        lineEditCRS->setReadOnly(true);
        checkBoxScaleDependentVisibility = new QCheckBox(groupBox);
        checkBoxScaleDependentVisibility->setObjectName(QString::fromUtf8("checkBoxScaleDependentVisibility"));
        checkBoxScaleDependentVisibility->setGeometry(QRect(20, 260, 143, 17));
        splitter_7 = new QSplitter(groupBox);
        splitter_7->setObjectName(QString::fromUtf8("splitter_7"));
        splitter_7->setGeometry(QRect(40, 290, 171, 21));
        splitter_7->setOrientation(Qt::Horizontal);
        labelMaximumScale = new QLabel(splitter_7);
        labelMaximumScale->setObjectName(QString::fromUtf8("labelMaximumScale"));
        splitter_7->addWidget(labelMaximumScale);
        comboBoxMaximumScale = new QComboBox(splitter_7);
        comboBoxMaximumScale->setObjectName(QString::fromUtf8("comboBoxMaximumScale"));
        splitter_7->addWidget(comboBoxMaximumScale);
        splitter_8 = new QSplitter(groupBox);
        splitter_8->setObjectName(QString::fromUtf8("splitter_8"));
        splitter_8->setGeometry(QRect(40, 320, 171, 21));
        splitter_8->setOrientation(Qt::Horizontal);
        labelMinimumScale = new QLabel(splitter_8);
        labelMinimumScale->setObjectName(QString::fromUtf8("labelMinimumScale"));
        splitter_8->addWidget(labelMinimumScale);
        comboBoxMinimumScale = new QComboBox(splitter_8);
        comboBoxMinimumScale->setObjectName(QString::fromUtf8("comboBoxMinimumScale"));
        splitter_8->addWidget(comboBoxMinimumScale);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 150, 91, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 180, 121, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 210, 81, 16));
        lineEditCRS_2 = new QLineEdit(groupBox);
        lineEditCRS_2->setObjectName(QString::fromUtf8("lineEditCRS_2"));
        lineEditCRS_2->setGeometry(QRect(170, 150, 311, 20));
        lineEditCRS_2->setFrame(false);
        lineEditCRS_2->setReadOnly(true);
        lineEditObservation = new QLineEdit(groupBox);
        lineEditObservation->setObjectName(QString::fromUtf8("lineEditObservation"));
        lineEditObservation->setGeometry(QRect(170, 180, 311, 20));
        lineEditObservation->setFrame(false);
        lineEditObservation->setReadOnly(true);
        lineEditField = new QLineEdit(groupBox);
        lineEditField->setObjectName(QString::fromUtf8("lineEditField"));
        lineEditField->setGeometry(QRect(170, 210, 311, 20));
        lineEditField->setFrame(false);
        lineEditField->setReadOnly(true);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(MapOptionGeneral);

        QMetaObject::connectSlotsByName(MapOptionGeneral);
    } // setupUi

    void retranslateUi(QWidget *MapOptionGeneral)
    {
        MapOptionGeneral->setWindowTitle(QApplication::translate("MapOptionGeneral", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MapOptionGeneral", "General", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MapOptionGeneral", "Layer Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MapOptionGeneral", "Layer Source", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MapOptionGeneral", "Layer Type", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MapOptionGeneral", "Coordinate Reference System", 0, QApplication::UnicodeUTF8));
        lineEditCRS->setText(QApplication::translate("MapOptionGeneral", "EPSG:4326 - WGS 84", 0, QApplication::UnicodeUTF8));
        checkBoxScaleDependentVisibility->setText(QApplication::translate("MapOptionGeneral", "Scale dependent visibility", 0, QApplication::UnicodeUTF8));
        labelMaximumScale->setText(QApplication::translate("MapOptionGeneral", "Maximum (inclusive)", 0, QApplication::UnicodeUTF8));
        labelMinimumScale->setText(QApplication::translate("MapOptionGeneral", "Minimum (exclusive)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MapOptionGeneral", "Data Source Type", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MapOptionGeneral", "Number of Observation", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MapOptionGeneral", "Number of Field", 0, QApplication::UnicodeUTF8));
        lineEditCRS_2->setText(QApplication::translate("MapOptionGeneral", "ESRI Shapefile", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapOptionGeneral: public Ui_MapOptionGeneral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPTIONGENERAL_H
