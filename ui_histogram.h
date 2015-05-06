/********************************************************************************
** Form generated from reading UI file 'histogram.ui'
**
** Created: Tue May 5 16:36:04 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:
    QGraphicsView *histogramView;

    void setupUi(QDialog *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QString::fromUtf8("Histogram"));
        Histogram->resize(491, 436);
        histogramView = new QGraphicsView(Histogram);
        histogramView->setObjectName(QString::fromUtf8("histogramView"));
        histogramView->setGeometry(QRect(0, -30, 491, 471));

        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QDialog *Histogram)
    {
        Histogram->setWindowTitle(QApplication::translate("Histogram", "Histogram", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
