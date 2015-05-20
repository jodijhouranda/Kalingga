/********************************************************************************
** Form generated from reading UI file 'histogramconfig.ui'
**
** Created: Wed May 20 08:19:35 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMCONFIG_H
#define UI_HISTOGRAMCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_HistogramConfig
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QSlider *horizontalSlider;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QComboBox *comboBox_linetype;
    QLabel *label_7;
    QLineEdit *lineEdit_Size;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_coloraes;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_fillaes;
    QGroupBox *groupBox_2;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_cpdfill;
    QLineEdit *lineEdit_adjust;
    QSlider *horizontalSlider_Dens;
    QLabel *label_19;
    QLabel *label_20;
    QComboBox *comboBox_WeightDens;
    QComboBox *comboBox_linetype_Dens;
    QLabel *label_21;
    QLineEdit *lineEdit_Size_Dens;
    QLabel *label_22;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_colorDens;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_cpd;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_fillDens;
    QComboBox *comboBox_kernel;
    QLabel *label_23;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *HistogramConfig)
    {
        if (HistogramConfig->objectName().isEmpty())
            HistogramConfig->setObjectName(QString::fromUtf8("HistogramConfig"));
        HistogramConfig->resize(211, 647);
        groupBox = new QGroupBox(HistogramConfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 40, 201, 271));
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
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 30, 91, 20));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 140, 91, 20));
        horizontalSlider->setMaximum(10);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setSliderPosition(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickInterval(1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 47, 13));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 180, 47, 13));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(70, 170, 91, 22));
        comboBox_linetype = new QComboBox(groupBox);
        comboBox_linetype->setObjectName(QString::fromUtf8("comboBox_linetype"));
        comboBox_linetype->setGeometry(QRect(70, 200, 91, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 210, 47, 13));
        lineEdit_Size = new QLineEdit(groupBox);
        lineEdit_Size->setObjectName(QString::fromUtf8("lineEdit_Size"));
        lineEdit_Size->setGeometry(QRect(70, 230, 91, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 230, 47, 13));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 60, 91, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_coloraes = new QComboBox(horizontalLayoutWidget);
        comboBox_coloraes->setObjectName(QString::fromUtf8("comboBox_coloraes"));

        horizontalLayout->addWidget(comboBox_coloraes);

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
        comboBox_fillaes = new QComboBox(horizontalLayoutWidget_2);
        comboBox_fillaes->setObjectName(QString::fromUtf8("comboBox_fillaes"));

        horizontalLayout_2->addWidget(comboBox_fillaes);

        groupBox_2 = new QGroupBox(HistogramConfig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 320, 201, 291));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 60, 47, 13));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 100, 47, 13));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 140, 47, 13));
        verticalLayoutWidget_5 = new QWidget(groupBox_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(160, 130, 31, 31));
        verticalLayout_cpdfill = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_cpdfill->setObjectName(QString::fromUtf8("verticalLayout_cpdfill"));
        verticalLayout_cpdfill->setContentsMargins(1, 0, 0, 0);
        lineEdit_adjust = new QLineEdit(groupBox_2);
        lineEdit_adjust->setObjectName(QString::fromUtf8("lineEdit_adjust"));
        lineEdit_adjust->setGeometry(QRect(70, 60, 91, 20));
        horizontalSlider_Dens = new QSlider(groupBox_2);
        horizontalSlider_Dens->setObjectName(QString::fromUtf8("horizontalSlider_Dens"));
        horizontalSlider_Dens->setGeometry(QRect(70, 170, 91, 20));
        horizontalSlider_Dens->setMaximum(10);
        horizontalSlider_Dens->setSingleStep(1);
        horizontalSlider_Dens->setPageStep(1);
        horizontalSlider_Dens->setSliderPosition(10);
        horizontalSlider_Dens->setOrientation(Qt::Horizontal);
        horizontalSlider_Dens->setTickInterval(1);
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 170, 47, 13));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 210, 47, 13));
        comboBox_WeightDens = new QComboBox(groupBox_2);
        comboBox_WeightDens->setObjectName(QString::fromUtf8("comboBox_WeightDens"));
        comboBox_WeightDens->setGeometry(QRect(70, 200, 91, 22));
        comboBox_linetype_Dens = new QComboBox(groupBox_2);
        comboBox_linetype_Dens->setObjectName(QString::fromUtf8("comboBox_linetype_Dens"));
        comboBox_linetype_Dens->setGeometry(QRect(70, 230, 91, 22));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 240, 47, 13));
        lineEdit_Size_Dens = new QLineEdit(groupBox_2);
        lineEdit_Size_Dens->setObjectName(QString::fromUtf8("lineEdit_Size_Dens"));
        lineEdit_Size_Dens->setGeometry(QRect(70, 260, 91, 20));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 260, 47, 13));
        horizontalLayoutWidget_5 = new QWidget(groupBox_2);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(70, 90, 91, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_colorDens = new QComboBox(horizontalLayoutWidget_5);
        comboBox_colorDens->setObjectName(QString::fromUtf8("comboBox_colorDens"));

        horizontalLayout_5->addWidget(comboBox_colorDens);

        verticalLayoutWidget_6 = new QWidget(groupBox_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(160, 90, 31, 31));
        verticalLayout_cpd = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_cpd->setObjectName(QString::fromUtf8("verticalLayout_cpd"));
        verticalLayout_cpd->setContentsMargins(1, 0, 0, 0);
        horizontalLayoutWidget_6 = new QWidget(groupBox_2);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(70, 130, 91, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox_fillDens = new QComboBox(horizontalLayoutWidget_6);
        comboBox_fillDens->setObjectName(QString::fromUtf8("comboBox_fillDens"));

        horizontalLayout_6->addWidget(comboBox_fillDens);

        comboBox_kernel = new QComboBox(groupBox_2);
        comboBox_kernel->setObjectName(QString::fromUtf8("comboBox_kernel"));
        comboBox_kernel->setGeometry(QRect(70, 30, 91, 22));
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 30, 47, 13));
        horizontalLayoutWidget_3 = new QWidget(HistogramConfig);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 10, 181, 22));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        retranslateUi(HistogramConfig);

        QMetaObject::connectSlotsByName(HistogramConfig);
    } // setupUi

    void retranslateUi(QWidget *HistogramConfig)
    {
        HistogramConfig->setWindowTitle(QApplication::translate("HistogramConfig", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("HistogramConfig", "Histogram", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HistogramConfig", "Binwidth", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HistogramConfig", "Color", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HistogramConfig", "Fill", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HistogramConfig", "Alpha", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HistogramConfig", "Weight", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HistogramConfig", "Line Type", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HistogramConfig", "Size", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("HistogramConfig", "Density", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("HistogramConfig", "Adjust", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("HistogramConfig", "Color", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("HistogramConfig", "Fill", 0, QApplication::UnicodeUTF8));
        lineEdit_adjust->setText(QApplication::translate("HistogramConfig", "1", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("HistogramConfig", "Alpha", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("HistogramConfig", "Weight", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("HistogramConfig", "Line Type", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("HistogramConfig", "Size", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("HistogramConfig", "Kernel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HistogramConfig", "Type", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("HistogramConfig", "Histogram", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramConfig", "Density", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramConfig", "Histogram & Density", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class HistogramConfig: public Ui_HistogramConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMCONFIG_H
