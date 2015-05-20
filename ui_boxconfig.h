/********************************************************************************
** Form generated from reading UI file 'boxconfig.ui'
**
** Created: Wed May 20 09:10:51 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXCONFIG_H
#define UI_BOXCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxConfig
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QSlider *horizontalSliderAlp;
    QLabel *label_5;
    QComboBox *comboBox_weight;
    QLabel *label_7;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_color;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_fill;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_size;
    QLineEdit *lineEditSize;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_size;
    QCheckBox *checkBox;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *checkBox_flip;
    QLabel *label_10;
    QCheckBox *checkBox_notch;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayoutout;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEditSize_2;

    void setupUi(QWidget *BoxConfig)
    {
        if (BoxConfig->objectName().isEmpty())
            BoxConfig->setObjectName(QString::fromUtf8("BoxConfig"));
        BoxConfig->resize(223, 404);
        groupBox = new QGroupBox(BoxConfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 201, 271));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 47, 13));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 47, 13));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 100, 31, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 0, 0, 0);
        horizontalSliderAlp = new QSlider(groupBox);
        horizontalSliderAlp->setObjectName(QString::fromUtf8("horizontalSliderAlp"));
        horizontalSliderAlp->setGeometry(QRect(70, 140, 91, 20));
        horizontalSliderAlp->setMaximum(10);
        horizontalSliderAlp->setSingleStep(1);
        horizontalSliderAlp->setPageStep(1);
        horizontalSliderAlp->setSliderPosition(10);
        horizontalSliderAlp->setOrientation(Qt::Horizontal);
        horizontalSliderAlp->setTickInterval(1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 47, 13));
        comboBox_weight = new QComboBox(groupBox);
        comboBox_weight->setObjectName(QString::fromUtf8("comboBox_weight"));
        comboBox_weight->setGeometry(QRect(70, 30, 91, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 170, 47, 13));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 60, 91, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_color = new QComboBox(horizontalLayoutWidget);
        comboBox_color->setObjectName(QString::fromUtf8("comboBox_color"));

        horizontalLayout->addWidget(comboBox_color);

        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(160, 60, 31, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 100, 91, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_fill = new QComboBox(horizontalLayoutWidget_2);
        comboBox_fill->setObjectName(QString::fromUtf8("comboBox_fill"));

        horizontalLayout_2->addWidget(comboBox_fill);

        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(160, 160, 31, 31));
        verticalLayout_size = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_size->setObjectName(QString::fromUtf8("verticalLayout_size"));
        verticalLayout_size->setContentsMargins(1, 0, 0, 0);
        lineEditSize = new QLineEdit(verticalLayoutWidget_3);
        lineEditSize->setObjectName(QString::fromUtf8("lineEditSize"));

        verticalLayout_size->addWidget(lineEditSize);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(70, 160, 91, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox_size = new QComboBox(horizontalLayoutWidget_3);
        comboBox_size->setObjectName(QString::fromUtf8("comboBox_size"));

        horizontalLayout_4->addWidget(comboBox_size);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 200, 70, 17));
        checkBox->setChecked(false);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 200, 47, 13));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 220, 47, 13));
        checkBox_flip = new QCheckBox(groupBox);
        checkBox_flip->setObjectName(QString::fromUtf8("checkBox_flip"));
        checkBox_flip->setGeometry(QRect(70, 220, 70, 17));
        checkBox_flip->setChecked(false);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 240, 47, 13));
        checkBox_notch = new QCheckBox(groupBox);
        checkBox_notch->setObjectName(QString::fromUtf8("checkBox_notch"));
        checkBox_notch->setGeometry(QRect(70, 240, 70, 17));
        checkBox_notch->setChecked(false);
        groupBox_2 = new QGroupBox(BoxConfig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 290, 201, 81));
        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(70, 10, 31, 31));
        verticalLayoutout = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayoutout->setObjectName(QString::fromUtf8("verticalLayoutout"));
        verticalLayoutout->setContentsMargins(1, 0, 0, 0);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 20, 47, 13));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 50, 47, 13));
        lineEditSize_2 = new QLineEdit(groupBox_2);
        lineEditSize_2->setObjectName(QString::fromUtf8("lineEditSize_2"));
        lineEditSize_2->setGeometry(QRect(70, 50, 29, 20));

        retranslateUi(BoxConfig);

        QMetaObject::connectSlotsByName(BoxConfig);
    } // setupUi

    void retranslateUi(QWidget *BoxConfig)
    {
        BoxConfig->setWindowTitle(QApplication::translate("BoxConfig", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BoxConfig", "Boxplot", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BoxConfig", "Weight", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BoxConfig", "Color", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BoxConfig", "Fill", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BoxConfig", "Alpha", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BoxConfig", "Size", 0, QApplication::UnicodeUTF8));
        lineEditSize->setText(QApplication::translate("BoxConfig", "0.5", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        label_8->setText(QApplication::translate("BoxConfig", "Jitter", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BoxConfig", "Flip", 0, QApplication::UnicodeUTF8));
        checkBox_flip->setText(QString());
        label_10->setText(QApplication::translate("BoxConfig", "Notch", 0, QApplication::UnicodeUTF8));
        checkBox_notch->setText(QString());
        groupBox_2->setTitle(QApplication::translate("BoxConfig", "Outlier", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BoxConfig", "Color", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BoxConfig", "Size", 0, QApplication::UnicodeUTF8));
        lineEditSize_2->setText(QApplication::translate("BoxConfig", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BoxConfig: public Ui_BoxConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXCONFIG_H
