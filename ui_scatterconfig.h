/********************************************************************************
** Form generated from reading UI file 'scatterconfig.ui'
**
** Created: Sat Jun 6 20:51:22 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCATTERCONFIG_H
#define UI_SCATTERCONFIG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScatterConfig
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
    QComboBox *comboBox_shape;
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
    QGroupBox *groupBox_2;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_cpdfill;
    QSlider *horizontalSlider_smot;
    QLabel *label_19;
    QComboBox *comboBox_linetype_s;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_cpd;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_fills;
    QComboBox *comboBox_method;
    QLabel *label_23;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBox_sizes;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_size_2;
    QLineEdit *lineEditSize_2;
    QCheckBox *checkBox;
    QComboBox *comboBox_colors;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButtonExport;

    void setupUi(QWidget *ScatterConfig)
    {
        if (ScatterConfig->objectName().isEmpty())
            ScatterConfig->setObjectName(QString::fromUtf8("ScatterConfig"));
        ScatterConfig->resize(221, 537);
        groupBox = new QGroupBox(ScatterConfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 40, 201, 201));
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
        comboBox_shape = new QComboBox(groupBox);
        comboBox_shape->setObjectName(QString::fromUtf8("comboBox_shape"));
        comboBox_shape->setGeometry(QRect(70, 30, 91, 22));
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
        verticalLayoutWidget_3->setGeometry(QRect(160, 160, 52, 31));
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

        groupBox_2 = new QGroupBox(ScatterConfig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 250, 201, 251));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 20, 47, 13));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 80, 47, 13));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 120, 47, 13));
        verticalLayoutWidget_5 = new QWidget(groupBox_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(160, 110, 31, 31));
        verticalLayout_cpdfill = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_cpdfill->setObjectName(QString::fromUtf8("verticalLayout_cpdfill"));
        verticalLayout_cpdfill->setContentsMargins(1, 0, 0, 0);
        horizontalSlider_smot = new QSlider(groupBox_2);
        horizontalSlider_smot->setObjectName(QString::fromUtf8("horizontalSlider_smot"));
        horizontalSlider_smot->setGeometry(QRect(70, 150, 91, 20));
        horizontalSlider_smot->setMaximum(10);
        horizontalSlider_smot->setSingleStep(1);
        horizontalSlider_smot->setPageStep(1);
        horizontalSlider_smot->setValue(5);
        horizontalSlider_smot->setSliderPosition(5);
        horizontalSlider_smot->setOrientation(Qt::Horizontal);
        horizontalSlider_smot->setTickInterval(1);
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 150, 47, 13));
        comboBox_linetype_s = new QComboBox(groupBox_2);
        comboBox_linetype_s->setObjectName(QString::fromUtf8("comboBox_linetype_s"));
        comboBox_linetype_s->setGeometry(QRect(70, 180, 91, 22));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 180, 47, 13));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 220, 47, 13));
        horizontalLayoutWidget_5 = new QWidget(groupBox_2);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(70, 90, 91, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_6 = new QWidget(groupBox_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(160, 70, 31, 31));
        verticalLayout_cpd = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_cpd->setObjectName(QString::fromUtf8("verticalLayout_cpd"));
        verticalLayout_cpd->setContentsMargins(1, 0, 0, 0);
        horizontalLayoutWidget_6 = new QWidget(groupBox_2);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(70, 110, 91, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox_fills = new QComboBox(horizontalLayoutWidget_6);
        comboBox_fills->setObjectName(QString::fromUtf8("comboBox_fills"));

        horizontalLayout_6->addWidget(comboBox_fills);

        comboBox_method = new QComboBox(groupBox_2);
        comboBox_method->setObjectName(QString::fromUtf8("comboBox_method"));
        comboBox_method->setGeometry(QRect(70, 40, 91, 22));
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 40, 47, 13));
        horizontalLayoutWidget_4 = new QWidget(groupBox_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(70, 210, 91, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        comboBox_sizes = new QComboBox(horizontalLayoutWidget_4);
        comboBox_sizes->setObjectName(QString::fromUtf8("comboBox_sizes"));

        horizontalLayout_7->addWidget(comboBox_sizes);

        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(160, 210, 52, 31));
        verticalLayout_size_2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_size_2->setObjectName(QString::fromUtf8("verticalLayout_size_2"));
        verticalLayout_size_2->setContentsMargins(1, 0, 0, 0);
        lineEditSize_2 = new QLineEdit(verticalLayoutWidget_4);
        lineEditSize_2->setObjectName(QString::fromUtf8("lineEditSize_2"));

        verticalLayout_size_2->addWidget(lineEditSize_2);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 20, 70, 17));
        checkBox->setChecked(true);
        comboBox_colors = new QComboBox(groupBox_2);
        comboBox_colors->setObjectName(QString::fromUtf8("comboBox_colors"));
        comboBox_colors->setGeometry(QRect(71, 75, 89, 20));
        horizontalLayoutWidget_7 = new QWidget(ScatterConfig);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 10, 181, 22));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_7);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget_7);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_8->addWidget(comboBox);

        pushButtonExport = new QPushButton(ScatterConfig);
        pushButtonExport->setObjectName(QString::fromUtf8("pushButtonExport"));
        pushButtonExport->setGeometry(QRect(120, 510, 81, 23));

        retranslateUi(ScatterConfig);

        QMetaObject::connectSlotsByName(ScatterConfig);
    } // setupUi

    void retranslateUi(QWidget *ScatterConfig)
    {
        ScatterConfig->setWindowTitle(QApplication::translate("ScatterConfig", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ScatterConfig", "Scatter", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ScatterConfig", "Shape", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ScatterConfig", "Color", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ScatterConfig", "Fill", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ScatterConfig", "Alpha", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ScatterConfig", "Size", 0, QApplication::UnicodeUTF8));
        lineEditSize->setText(QApplication::translate("ScatterConfig", "2", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ScatterConfig", "Smooth", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ScatterConfig", "Se", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("ScatterConfig", "Color", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("ScatterConfig", "Fill", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("ScatterConfig", "Alpha", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("ScatterConfig", "Line Type", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("ScatterConfig", "Size", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("ScatterConfig", "Method", 0, QApplication::UnicodeUTF8));
        lineEditSize_2->setText(QApplication::translate("ScatterConfig", "0.5", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        label->setText(QApplication::translate("ScatterConfig", "Type", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ScatterConfig", "Scatter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ScatterConfig", "Smooth", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ScatterConfig", "Scatter and Smooth", 0, QApplication::UnicodeUTF8)
        );
        pushButtonExport->setText(QApplication::translate("ScatterConfig", "Export Plot...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScatterConfig: public Ui_ScatterConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCATTERCONFIG_H
