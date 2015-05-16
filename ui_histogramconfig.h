/********************************************************************************
** Form generated from reading UI file 'histogramconfig.ui'
**
** Created: Wed May 13 20:47:19 2015
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramConfig
{
public:
    QGroupBox *groupBox;
    QSpinBox *spinBoxBinwidth;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QWidget *HistogramConfig)
    {
        if (HistogramConfig->objectName().isEmpty())
            HistogramConfig->setObjectName(QString::fromUtf8("HistogramConfig"));
        HistogramConfig->resize(663, 293);
        groupBox = new QGroupBox(HistogramConfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 201, 221));
        spinBoxBinwidth = new QSpinBox(groupBox);
        spinBoxBinwidth->setObjectName(QString::fromUtf8("spinBoxBinwidth"));
        spinBoxBinwidth->setGeometry(QRect(100, 20, 91, 22));
        spinBoxBinwidth->setMinimumSize(QSize(91, 0));
        spinBoxBinwidth->setMaximum(100);
        spinBoxBinwidth->setValue(50);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 47, 13));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 50, 91, 23));
        comboBox = new QComboBox(HistogramConfig);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 20, 151, 21));
        label = new QLabel(HistogramConfig);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 47, 13));

        retranslateUi(HistogramConfig);

        QMetaObject::connectSlotsByName(HistogramConfig);
    } // setupUi

    void retranslateUi(QWidget *HistogramConfig)
    {
        HistogramConfig->setWindowTitle(QApplication::translate("HistogramConfig", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("HistogramConfig", "Histogram", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HistogramConfig", "Binwidth", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HistogramConfig", "Color", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("HistogramConfig", "Histogram", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramConfig", "Density", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramConfig", "Histogram & Density", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("HistogramConfig", "Type", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistogramConfig: public Ui_HistogramConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMCONFIG_H
