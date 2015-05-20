/********************************************************************************
** Form generated from reading UI file 'twovariablepicker.ui'
**
** Created: Wed May 20 08:19:35 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOVARIABLEPICKER_H
#define UI_TWOVARIABLEPICKER_H

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

class Ui_TwoVariablePicker
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidgetVariablesX;
    QLabel *label;
    QListWidget *listWidgetVariablesY;
    QLabel *label_2;

    void setupUi(QDialog *TwoVariablePicker)
    {
        if (TwoVariablePicker->objectName().isEmpty())
            TwoVariablePicker->setObjectName(QString::fromUtf8("TwoVariablePicker"));
        TwoVariablePicker->resize(436, 317);
        buttonBox = new QDialogButtonBox(TwoVariablePicker);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 270, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidgetVariablesX = new QListWidget(TwoVariablePicker);
        listWidgetVariablesX->setObjectName(QString::fromUtf8("listWidgetVariablesX"));
        listWidgetVariablesX->setGeometry(QRect(20, 60, 181, 192));
        label = new QLabel(TwoVariablePicker);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 81, 16));
        listWidgetVariablesY = new QListWidget(TwoVariablePicker);
        listWidgetVariablesY->setObjectName(QString::fromUtf8("listWidgetVariablesY"));
        listWidgetVariablesY->setGeometry(QRect(230, 60, 181, 192));
        label_2 = new QLabel(TwoVariablePicker);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 30, 81, 16));

        retranslateUi(TwoVariablePicker);
        QObject::connect(buttonBox, SIGNAL(accepted()), TwoVariablePicker, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TwoVariablePicker, SLOT(reject()));

        QMetaObject::connectSlotsByName(TwoVariablePicker);
    } // setupUi

    void retranslateUi(QDialog *TwoVariablePicker)
    {
        TwoVariablePicker->setWindowTitle(QApplication::translate("TwoVariablePicker", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TwoVariablePicker", "Select X Variable", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TwoVariablePicker", "Select Y Variable", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TwoVariablePicker: public Ui_TwoVariablePicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOVARIABLEPICKER_H
