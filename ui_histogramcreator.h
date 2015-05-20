/********************************************************************************
** Form generated from reading UI file 'histogramcreator.ui'
**
** Created: Wed May 20 08:19:35 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMCREATOR_H
#define UI_HISTOGRAMCREATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramCreator
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QListWidget *listWidgetVariables;

    void setupUi(QDialog *HistogramCreator)
    {
        if (HistogramCreator->objectName().isEmpty())
            HistogramCreator->setObjectName(QString::fromUtf8("HistogramCreator"));
        HistogramCreator->resize(224, 320);
        buttonBox = new QDialogButtonBox(HistogramCreator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-30, 270, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(HistogramCreator);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 81, 16));
        listWidgetVariables = new QListWidget(HistogramCreator);
        listWidgetVariables->setObjectName(QString::fromUtf8("listWidgetVariables"));
        listWidgetVariables->setGeometry(QRect(20, 60, 181, 192));

        retranslateUi(HistogramCreator);
        QObject::connect(buttonBox, SIGNAL(accepted()), HistogramCreator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HistogramCreator, SLOT(reject()));

        QMetaObject::connectSlotsByName(HistogramCreator);
    } // setupUi

    void retranslateUi(QDialog *HistogramCreator)
    {
        HistogramCreator->setWindowTitle(QApplication::translate("HistogramCreator", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HistogramCreator", "Select Variable", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistogramCreator: public Ui_HistogramCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMCREATOR_H
