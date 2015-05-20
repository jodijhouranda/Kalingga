/********************************************************************************
** Form generated from reading UI file 'parallechart.ui'
**
** Created: Wed May 20 21:03:07 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARALLECHART_H
#define UI_PARALLECHART_H

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

class Ui_ParalleChart
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLabel *label;

    void setupUi(QDialog *ParalleChart)
    {
        if (ParalleChart->objectName().isEmpty())
            ParalleChart->setObjectName(QString::fromUtf8("ParalleChart"));
        ParalleChart->resize(219, 361);
        buttonBox = new QDialogButtonBox(ParalleChart);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-140, 310, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(ParalleChart);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 50, 191, 241));
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        label = new QLabel(ParalleChart);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 101, 16));

        retranslateUi(ParalleChart);
        QObject::connect(buttonBox, SIGNAL(accepted()), ParalleChart, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ParalleChart, SLOT(reject()));

        QMetaObject::connectSlotsByName(ParalleChart);
    } // setupUi

    void retranslateUi(QDialog *ParalleChart)
    {
        ParalleChart->setWindowTitle(QApplication::translate("ParalleChart", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ParalleChart", "Choose Variables...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParalleChart: public Ui_ParalleChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARALLECHART_H
