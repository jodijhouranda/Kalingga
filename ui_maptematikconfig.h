/********************************************************************************
** Form generated from reading UI file 'maptematikconfig.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPTEMATIKCONFIG_H
#define UI_MAPTEMATIKCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapTematikConfig
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *checkBoxLabel;
    QLabel *label_5;
    QPushButton *pushButtonAdvance;
    QComboBox *comboBoxLabel;
    QComboBox *comboBoxBorderStyle;
    QSlider *sliderTransparency;
    QGroupBox *groupBoxPickColor;
    QGridLayout *gridLayout;
    QLabel *labelNumberClass;
    QLabel *label_7;
    QLabel *textColorBorder;
    QLabel *textColorBackground;
    QLabel *textColorLabel;
    QPushButton *pushButtonBorderColor;
    QPushButton *pushButtonBackgroundColor;
    QPushButton *pushButtonLabelColor;
    QCheckBox *checkBoxCentroid;
    QLabel *label_6;
    QComboBox *comboBoxMoverBrush;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayoutcp;
    QLabel *label_8;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayoutcp_2;
    QComboBox *comboBoxSelectBrush;
    QSpinBox *spinBoxBorderWith;

    void setupUi(QDialog *MapTematikConfig)
    {
        if (MapTematikConfig->objectName().isEmpty())
            MapTematikConfig->setObjectName(QString::fromUtf8("MapTematikConfig"));
        MapTematikConfig->resize(210, 610);
        label = new QLabel(MapTematikConfig);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 280, 71, 16));
        label_2 = new QLabel(MapTematikConfig);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 400, 71, 20));
        label_3 = new QLabel(MapTematikConfig);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 320, 71, 16));
        label_4 = new QLabel(MapTematikConfig);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 360, 71, 16));
        checkBoxLabel = new QCheckBox(MapTematikConfig);
        checkBoxLabel->setObjectName(QString::fromUtf8("checkBoxLabel"));
        checkBoxLabel->setGeometry(QRect(10, 480, 70, 17));
        label_5 = new QLabel(MapTematikConfig);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 440, 61, 16));
        pushButtonAdvance = new QPushButton(MapTematikConfig);
        pushButtonAdvance->setObjectName(QString::fromUtf8("pushButtonAdvance"));
        pushButtonAdvance->setGeometry(QRect(120, 580, 75, 23));
        comboBoxLabel = new QComboBox(MapTematikConfig);
        comboBoxLabel->setObjectName(QString::fromUtf8("comboBoxLabel"));
        comboBoxLabel->setGeometry(QRect(90, 480, 101, 22));
        comboBoxBorderStyle = new QComboBox(MapTematikConfig);
        comboBoxBorderStyle->setObjectName(QString::fromUtf8("comboBoxBorderStyle"));
        comboBoxBorderStyle->setGeometry(QRect(90, 360, 101, 22));
        sliderTransparency = new QSlider(MapTematikConfig);
        sliderTransparency->setObjectName(QString::fromUtf8("sliderTransparency"));
        sliderTransparency->setGeometry(QRect(90, 400, 101, 20));
        sliderTransparency->setOrientation(Qt::Horizontal);
        groupBoxPickColor = new QGroupBox(MapTematikConfig);
        groupBoxPickColor->setObjectName(QString::fromUtf8("groupBoxPickColor"));
        groupBoxPickColor->setGeometry(QRect(10, 30, 191, 161));
        gridLayout = new QGridLayout(groupBoxPickColor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelNumberClass = new QLabel(MapTematikConfig);
        labelNumberClass->setObjectName(QString::fromUtf8("labelNumberClass"));
        labelNumberClass->setGeometry(QRect(80, 0, 121, 20));
        label_7 = new QLabel(MapTematikConfig);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 520, 61, 16));
        textColorBorder = new QLabel(MapTematikConfig);
        textColorBorder->setObjectName(QString::fromUtf8("textColorBorder"));
        textColorBorder->setGeometry(QRect(170, 280, 21, 21));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textColorBorder->sizePolicy().hasHeightForWidth());
        textColorBorder->setSizePolicy(sizePolicy);
        textColorBorder->setFrameShape(QFrame::StyledPanel);
        textColorBorder->setFrameShadow(QFrame::Raised);
        textColorBorder->setScaledContents(true);
        textColorBackground = new QLabel(MapTematikConfig);
        textColorBackground->setObjectName(QString::fromUtf8("textColorBackground"));
        textColorBackground->setGeometry(QRect(170, 440, 21, 21));
        sizePolicy.setHeightForWidth(textColorBackground->sizePolicy().hasHeightForWidth());
        textColorBackground->setSizePolicy(sizePolicy);
        textColorBackground->setFrameShape(QFrame::StyledPanel);
        textColorBackground->setFrameShadow(QFrame::Raised);
        textColorBackground->setScaledContents(true);
        textColorLabel = new QLabel(MapTematikConfig);
        textColorLabel->setObjectName(QString::fromUtf8("textColorLabel"));
        textColorLabel->setGeometry(QRect(170, 520, 21, 21));
        sizePolicy.setHeightForWidth(textColorLabel->sizePolicy().hasHeightForWidth());
        textColorLabel->setSizePolicy(sizePolicy);
        textColorLabel->setFrameShape(QFrame::StyledPanel);
        textColorLabel->setFrameShadow(QFrame::Raised);
        textColorLabel->setScaledContents(true);
        pushButtonBorderColor = new QPushButton(MapTematikConfig);
        pushButtonBorderColor->setObjectName(QString::fromUtf8("pushButtonBorderColor"));
        pushButtonBorderColor->setGeometry(QRect(90, 280, 81, 23));
        pushButtonBackgroundColor = new QPushButton(MapTematikConfig);
        pushButtonBackgroundColor->setObjectName(QString::fromUtf8("pushButtonBackgroundColor"));
        pushButtonBackgroundColor->setGeometry(QRect(90, 440, 81, 23));
        pushButtonLabelColor = new QPushButton(MapTematikConfig);
        pushButtonLabelColor->setObjectName(QString::fromUtf8("pushButtonLabelColor"));
        pushButtonLabelColor->setGeometry(QRect(90, 520, 81, 23));
        checkBoxCentroid = new QCheckBox(MapTematikConfig);
        checkBoxCentroid->setObjectName(QString::fromUtf8("checkBoxCentroid"));
        checkBoxCentroid->setGeometry(QRect(10, 560, 70, 17));
        label_6 = new QLabel(MapTematikConfig);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 240, 61, 21));
        comboBoxMoverBrush = new QComboBox(MapTematikConfig);
        comboBoxMoverBrush->setObjectName(QString::fromUtf8("comboBoxMoverBrush"));
        comboBoxMoverBrush->setGeometry(QRect(90, 240, 81, 22));
        verticalLayoutWidget_7 = new QWidget(MapTematikConfig);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(170, 240, 21, 21));
        verticalLayoutcp = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayoutcp->setObjectName(QString::fromUtf8("verticalLayoutcp"));
        verticalLayoutcp->setContentsMargins(1, 0, 0, 0);
        label_8 = new QLabel(MapTematikConfig);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 200, 71, 21));
        verticalLayoutWidget_8 = new QWidget(MapTematikConfig);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(170, 200, 21, 21));
        verticalLayoutcp_2 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayoutcp_2->setObjectName(QString::fromUtf8("verticalLayoutcp_2"));
        verticalLayoutcp_2->setContentsMargins(1, 0, 0, 0);
        comboBoxSelectBrush = new QComboBox(MapTematikConfig);
        comboBoxSelectBrush->setObjectName(QString::fromUtf8("comboBoxSelectBrush"));
        comboBoxSelectBrush->setGeometry(QRect(90, 200, 81, 22));
        spinBoxBorderWith = new QSpinBox(MapTematikConfig);
        spinBoxBorderWith->setObjectName(QString::fromUtf8("spinBoxBorderWith"));
        spinBoxBorderWith->setGeometry(QRect(90, 320, 101, 22));

        retranslateUi(MapTematikConfig);

        QMetaObject::connectSlotsByName(MapTematikConfig);
    } // setupUi

    void retranslateUi(QDialog *MapTematikConfig)
    {
        MapTematikConfig->setWindowTitle(QApplication::translate("MapTematikConfig", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MapTematikConfig", "Borders Color", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MapTematikConfig", "Transparency", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MapTematikConfig", "Borders Width", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MapTematikConfig", "Borders Style", 0, QApplication::UnicodeUTF8));
        checkBoxLabel->setText(QApplication::translate("MapTematikConfig", "Label with", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MapTematikConfig", "Background", 0, QApplication::UnicodeUTF8));
        pushButtonAdvance->setText(QApplication::translate("MapTematikConfig", "Advance...", 0, QApplication::UnicodeUTF8));
        groupBoxPickColor->setTitle(QApplication::translate("MapTematikConfig", "Pick a Color Scheme", 0, QApplication::UnicodeUTF8));
        labelNumberClass->setText(QApplication::translate("MapTematikConfig", "Number of Data Class", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MapTematikConfig", "Label Color", 0, QApplication::UnicodeUTF8));
        pushButtonBorderColor->setText(QApplication::translate("MapTematikConfig", "Choose...", 0, QApplication::UnicodeUTF8));
        pushButtonBackgroundColor->setText(QApplication::translate("MapTematikConfig", "Choose...", 0, QApplication::UnicodeUTF8));
        pushButtonLabelColor->setText(QApplication::translate("MapTematikConfig", "Choose...", 0, QApplication::UnicodeUTF8));
        checkBoxCentroid->setText(QApplication::translate("MapTematikConfig", "Centroid", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MapTematikConfig", "Mouse Over", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MapTematikConfig", "Mouse Select", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapTematikConfig: public Ui_MapTematikConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPTEMATIKCONFIG_H
