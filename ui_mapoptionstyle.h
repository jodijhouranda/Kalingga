/********************************************************************************
** Form generated from reading UI file 'mapoptionstyle.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPTIONSTYLE_H
#define UI_MAPOPTIONSTYLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapOptionStyle
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QLabel *label_5;
    QComboBox *comboBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_6;

    void setupUi(QWidget *MapOptionStyle)
    {
        if (MapOptionStyle->objectName().isEmpty())
            MapOptionStyle->setObjectName(QString::fromUtf8("MapOptionStyle"));
        MapOptionStyle->resize(529, 446);
        gridLayout = new QGridLayout(MapOptionStyle);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(MapOptionStyle);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 20, 161, 91));
        widget->setAutoFillBackground(true);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(19, 27, 51, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 130, 66, 16));
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(110, 130, 361, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 160, 31, 16));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 160, 111, 20));
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(110, 200, 161, 101));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 159, 99));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 200, 71, 16));

        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);


        retranslateUi(MapOptionStyle);

        QMetaObject::connectSlotsByName(MapOptionStyle);
    } // setupUi

    void retranslateUi(QWidget *MapOptionStyle)
    {
        MapOptionStyle->setWindowTitle(QApplication::translate("MapOptionStyle", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MapOptionStyle", "Style", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MapOptionStyle", "Fill Sample", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MapOptionStyle", "Transparancy", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MapOptionStyle", "Colour", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MapOptionStyle", "Contour", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapOptionStyle: public Ui_MapOptionStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPTIONSTYLE_H
