/********************************************************************************
** Form generated from reading UI file 'descriptivestat.ui'
**
** Created: Wed Jun 3 13:22:03 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCRIPTIVESTAT_H
#define UI_DESCRIPTIVESTAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_DescriptiveStat
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QCheckBox *checkBoxSdev;
    QCheckBox *checkBoxVariance;
    QCheckBox *checkBoxRange;
    QCheckBox *checkBoxSEMean;
    QCheckBox *checkBoxMaximum;
    QCheckBox *checkBoxMinimum;
    QGroupBox *groupBox_2;
    QCheckBox *checkBoxKurtosis;
    QCheckBox *checkBoxSkewness;
    QGroupBox *groupBox_3;
    QCheckBox *checkBoxMean;
    QCheckBox *checkBoxMedian;
    QCheckBox *checkBoxSum;
    QGroupBox *groupBox_4;
    QCheckBox *checkBoxSummary;
    QCheckBox *checkBoxFivenum;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DescriptiveStat)
    {
        if (DescriptiveStat->objectName().isEmpty())
            DescriptiveStat->setObjectName(QString::fromUtf8("DescriptiveStat"));
        DescriptiveStat->resize(437, 320);
        listWidget = new QListWidget(DescriptiveStat);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 20, 191, 261));
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        label = new QLabel(DescriptiveStat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 101, 16));
        groupBox = new QGroupBox(DescriptiveStat);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(210, 80, 211, 91));
        checkBoxSdev = new QCheckBox(groupBox);
        checkBoxSdev->setObjectName(QString::fromUtf8("checkBoxSdev"));
        checkBoxSdev->setGeometry(QRect(10, 20, 91, 17));
        checkBoxVariance = new QCheckBox(groupBox);
        checkBoxVariance->setObjectName(QString::fromUtf8("checkBoxVariance"));
        checkBoxVariance->setGeometry(QRect(10, 40, 70, 17));
        checkBoxRange = new QCheckBox(groupBox);
        checkBoxRange->setObjectName(QString::fromUtf8("checkBoxRange"));
        checkBoxRange->setGeometry(QRect(10, 60, 70, 17));
        checkBoxSEMean = new QCheckBox(groupBox);
        checkBoxSEMean->setObjectName(QString::fromUtf8("checkBoxSEMean"));
        checkBoxSEMean->setGeometry(QRect(130, 60, 70, 17));
        checkBoxMaximum = new QCheckBox(groupBox);
        checkBoxMaximum->setObjectName(QString::fromUtf8("checkBoxMaximum"));
        checkBoxMaximum->setGeometry(QRect(130, 40, 70, 17));
        checkBoxMinimum = new QCheckBox(groupBox);
        checkBoxMinimum->setObjectName(QString::fromUtf8("checkBoxMinimum"));
        checkBoxMinimum->setGeometry(QRect(130, 20, 70, 17));
        groupBox_2 = new QGroupBox(DescriptiveStat);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 170, 211, 51));
        checkBoxKurtosis = new QCheckBox(groupBox_2);
        checkBoxKurtosis->setObjectName(QString::fromUtf8("checkBoxKurtosis"));
        checkBoxKurtosis->setGeometry(QRect(10, 20, 91, 17));
        checkBoxSkewness = new QCheckBox(groupBox_2);
        checkBoxSkewness->setObjectName(QString::fromUtf8("checkBoxSkewness"));
        checkBoxSkewness->setGeometry(QRect(130, 20, 70, 17));
        groupBox_3 = new QGroupBox(DescriptiveStat);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(210, 10, 211, 71));
        checkBoxMean = new QCheckBox(groupBox_3);
        checkBoxMean->setObjectName(QString::fromUtf8("checkBoxMean"));
        checkBoxMean->setGeometry(QRect(10, 20, 70, 17));
        checkBoxMedian = new QCheckBox(groupBox_3);
        checkBoxMedian->setObjectName(QString::fromUtf8("checkBoxMedian"));
        checkBoxMedian->setGeometry(QRect(130, 20, 70, 17));
        checkBoxSum = new QCheckBox(groupBox_3);
        checkBoxSum->setObjectName(QString::fromUtf8("checkBoxSum"));
        checkBoxSum->setGeometry(QRect(10, 40, 70, 17));
        groupBox_4 = new QGroupBox(DescriptiveStat);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(210, 230, 211, 51));
        checkBoxSummary = new QCheckBox(groupBox_4);
        checkBoxSummary->setObjectName(QString::fromUtf8("checkBoxSummary"));
        checkBoxSummary->setGeometry(QRect(10, 20, 91, 17));
        checkBoxFivenum = new QCheckBox(groupBox_4);
        checkBoxFivenum->setObjectName(QString::fromUtf8("checkBoxFivenum"));
        checkBoxFivenum->setGeometry(QRect(130, 20, 70, 17));
        buttonBox = new QDialogButtonBox(DescriptiveStat);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 290, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DescriptiveStat);

        QMetaObject::connectSlotsByName(DescriptiveStat);
    } // setupUi

    void retranslateUi(QDialog *DescriptiveStat)
    {
        DescriptiveStat->setWindowTitle(QApplication::translate("DescriptiveStat", "Descriptive Statistics", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DescriptiveStat", "Choose Variables...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DescriptiveStat", "Dispersion", 0, QApplication::UnicodeUTF8));
        checkBoxSdev->setText(QApplication::translate("DescriptiveStat", "Std. deviation", 0, QApplication::UnicodeUTF8));
        checkBoxVariance->setText(QApplication::translate("DescriptiveStat", "Variance", 0, QApplication::UnicodeUTF8));
        checkBoxRange->setText(QApplication::translate("DescriptiveStat", "Range", 0, QApplication::UnicodeUTF8));
        checkBoxSEMean->setText(QApplication::translate("DescriptiveStat", "S.E. mean", 0, QApplication::UnicodeUTF8));
        checkBoxMaximum->setText(QApplication::translate("DescriptiveStat", "Maximum", 0, QApplication::UnicodeUTF8));
        checkBoxMinimum->setText(QApplication::translate("DescriptiveStat", "Minimum", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DescriptiveStat", "Distribution", 0, QApplication::UnicodeUTF8));
        checkBoxKurtosis->setText(QApplication::translate("DescriptiveStat", "Kurtosis ", 0, QApplication::UnicodeUTF8));
        checkBoxSkewness->setText(QApplication::translate("DescriptiveStat", "Skewness", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DescriptiveStat", "General", 0, QApplication::UnicodeUTF8));
        checkBoxMean->setText(QApplication::translate("DescriptiveStat", "Mean", 0, QApplication::UnicodeUTF8));
        checkBoxMedian->setText(QApplication::translate("DescriptiveStat", "Median", 0, QApplication::UnicodeUTF8));
        checkBoxSum->setText(QApplication::translate("DescriptiveStat", "Sum", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("DescriptiveStat", "R Descriptive", 0, QApplication::UnicodeUTF8));
        checkBoxSummary->setText(QApplication::translate("DescriptiveStat", "Summary", 0, QApplication::UnicodeUTF8));
        checkBoxFivenum->setText(QApplication::translate("DescriptiveStat", "Fivenum", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DescriptiveStat: public Ui_DescriptiveStat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCRIPTIVESTAT_H
