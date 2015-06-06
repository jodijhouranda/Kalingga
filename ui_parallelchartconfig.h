/********************************************************************************
** Form generated from reading UI file 'parallelchartconfig.ui'
**
** Created: Sat Jun 6 20:51:22 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARALLELCHARTCONFIG_H
#define UI_PARALLELCHARTCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParallelChartConfig
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *comboBox_GroupCoolumn;
    QLabel *label_2;
    QComboBox *comboBox_Scale;
    QLabel *label_3;
    QComboBox *comboBox_Missing;
    QLabel *label_4;
    QComboBox *comboBox_Order;
    QSlider *horizontalSliderAlp;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_3;
    QLabel *label_9;
    QPushButton *pushButtonExport;

    void setupUi(QWidget *ParallelChartConfig)
    {
        if (ParallelChartConfig->objectName().isEmpty())
            ParallelChartConfig->setObjectName(QString::fromUtf8("ParallelChartConfig"));
        ParallelChartConfig->resize(213, 512);
        groupBox = new QGroupBox(ParallelChartConfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 191, 291));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 71, 16));
        comboBox_GroupCoolumn = new QComboBox(groupBox);
        comboBox_GroupCoolumn->setObjectName(QString::fromUtf8("comboBox_GroupCoolumn"));
        comboBox_GroupCoolumn->setGeometry(QRect(80, 50, 101, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 71, 16));
        comboBox_Scale = new QComboBox(groupBox);
        comboBox_Scale->setObjectName(QString::fromUtf8("comboBox_Scale"));
        comboBox_Scale->setGeometry(QRect(80, 80, 101, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 71, 16));
        comboBox_Missing = new QComboBox(groupBox);
        comboBox_Missing->setObjectName(QString::fromUtf8("comboBox_Missing"));
        comboBox_Missing->setGeometry(QRect(80, 110, 101, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 71, 16));
        comboBox_Order = new QComboBox(groupBox);
        comboBox_Order->setObjectName(QString::fromUtf8("comboBox_Order"));
        comboBox_Order->setGeometry(QRect(80, 140, 101, 22));
        horizontalSliderAlp = new QSlider(groupBox);
        horizontalSliderAlp->setObjectName(QString::fromUtf8("horizontalSliderAlp"));
        horizontalSliderAlp->setGeometry(QRect(80, 170, 101, 20));
        horizontalSliderAlp->setMaximum(10);
        horizontalSliderAlp->setSingleStep(1);
        horizontalSliderAlp->setPageStep(1);
        horizontalSliderAlp->setSliderPosition(10);
        horizontalSliderAlp->setOrientation(Qt::Horizontal);
        horizontalSliderAlp->setTickInterval(1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 170, 47, 13));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 200, 47, 13));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 230, 47, 13));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(80, 200, 70, 17));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(80, 230, 70, 17));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 71, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(82, 20, 101, 20));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(80, 260, 70, 17));
        checkBox_3->setChecked(true);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 260, 61, 16));
        pushButtonExport = new QPushButton(ParallelChartConfig);
        pushButtonExport->setObjectName(QString::fromUtf8("pushButtonExport"));
        pushButtonExport->setGeometry(QRect(120, 320, 81, 23));

        retranslateUi(ParallelChartConfig);

        QMetaObject::connectSlotsByName(ParallelChartConfig);
    } // setupUi

    void retranslateUi(QWidget *ParallelChartConfig)
    {
        ParallelChartConfig->setWindowTitle(QApplication::translate("ParallelChartConfig", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ParallelChartConfig", "Paralle Coordinates Plot", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ParallelChartConfig", "Group", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ParallelChartConfig", "Scale", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ParallelChartConfig", "Missing", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ParallelChartConfig", "Order", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ParallelChartConfig", "Alpha", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ParallelChartConfig", "Boxplot", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ParallelChartConfig", "Point", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        label_8->setText(QApplication::translate("ParallelChartConfig", "Tittle", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QString());
        label_9->setText(QApplication::translate("ParallelChartConfig", "Background", 0, QApplication::UnicodeUTF8));
        pushButtonExport->setText(QApplication::translate("ParallelChartConfig", "Export Plot...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParallelChartConfig: public Ui_ParallelChartConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARALLELCHARTCONFIG_H
