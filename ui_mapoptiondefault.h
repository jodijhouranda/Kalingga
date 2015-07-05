/********************************************************************************
** Form generated from reading UI file 'mapoptiondefault.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPTIONDEFAULT_H
#define UI_MAPOPTIONDEFAULT_H

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
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapOptionDefault
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QLabel *label_58;
    QLabel *label_63;
    QLabel *label_64;
    QSlider *horizontalSlider_7;
    QCheckBox *checkBox_9;
    QLabel *label_59;
    QComboBox *comboBox_25;
    QLabel *label_62;
    QComboBox *comboBox_28;
    QLabel *label_60;
    QComboBox *comboBox_26;
    QLabel *label_61;
    QComboBox *comboBox_27;

    void setupUi(QWidget *MapOptionDefault)
    {
        if (MapOptionDefault->objectName().isEmpty())
            MapOptionDefault->setObjectName(QString::fromUtf8("MapOptionDefault"));
        MapOptionDefault->resize(530, 451);
        gridLayout = new QGridLayout(MapOptionDefault);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_5 = new QGroupBox(MapOptionDefault);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        label_58 = new QLabel(groupBox_5);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(20, 30, 111, 17));
        label_63 = new QLabel(groupBox_5);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(20, 190, 67, 17));
        label_64 = new QLabel(groupBox_5);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(30, 210, 101, 17));
        horizontalSlider_7 = new QSlider(groupBox_5);
        horizontalSlider_7->setObjectName(QString::fromUtf8("horizontalSlider_7"));
        horizontalSlider_7->setGeometry(QRect(100, 210, 331, 21));
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        checkBox_9 = new QCheckBox(groupBox_5);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(30, 240, 181, 22));
        label_59 = new QLabel(groupBox_5);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(30, 60, 33, 16));
        comboBox_25 = new QComboBox(groupBox_5);
        comboBox_25->setObjectName(QString::fromUtf8("comboBox_25"));
        comboBox_25->setGeometry(QRect(100, 60, 91, 20));
        label_62 = new QLabel(groupBox_5);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(30, 150, 55, 16));
        comboBox_28 = new QComboBox(groupBox_5);
        comboBox_28->setObjectName(QString::fromUtf8("comboBox_28"));
        comboBox_28->setGeometry(QRect(100, 150, 91, 20));
        label_60 = new QLabel(groupBox_5);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(30, 90, 19, 16));
        comboBox_26 = new QComboBox(groupBox_5);
        comboBox_26->setObjectName(QString::fromUtf8("comboBox_26"));
        comboBox_26->setGeometry(QRect(100, 90, 91, 20));
        label_61 = new QLabel(groupBox_5);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(30, 120, 16, 16));
        comboBox_27 = new QComboBox(groupBox_5);
        comboBox_27->setObjectName(QString::fromUtf8("comboBox_27"));
        comboBox_27->setGeometry(QRect(100, 120, 91, 20));

        gridLayout->addWidget(groupBox_5, 0, 0, 1, 1);


        retranslateUi(MapOptionDefault);

        QMetaObject::connectSlotsByName(MapOptionDefault);
    } // setupUi

    void retranslateUi(QWidget *MapOptionDefault)
    {
        MapOptionDefault->setWindowTitle(QApplication::translate("MapOptionDefault", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MapOptionDefault", "Default Style", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("MapOptionDefault", "Default Symbol", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("MapOptionDefault", "Option", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("MapOptionDefault", "Transparency", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("MapOptionDefault", "Assigned random color to symbol", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("MapOptionDefault", "Marker", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("MapOptionDefault", "Color Ramp", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("MapOptionDefault", "Line", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("MapOptionDefault", "Fill", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapOptionDefault: public Ui_MapOptionDefault {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPTIONDEFAULT_H
