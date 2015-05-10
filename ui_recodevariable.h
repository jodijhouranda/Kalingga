/********************************************************************************
** Form generated from reading UI file 'recodevariable.ui'
**
** Created: Sun May 10 17:06:41 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECODEVARIABLE_H
#define UI_RECODEVARIABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_RecodeVariable
{
public:

    void setupUi(QDialog *RecodeVariable)
    {
        if (RecodeVariable->objectName().isEmpty())
            RecodeVariable->setObjectName(QString::fromUtf8("RecodeVariable"));
        RecodeVariable->resize(400, 300);

        retranslateUi(RecodeVariable);

        QMetaObject::connectSlotsByName(RecodeVariable);
    } // setupUi

    void retranslateUi(QDialog *RecodeVariable)
    {
        RecodeVariable->setWindowTitle(QApplication::translate("RecodeVariable", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecodeVariable: public Ui_RecodeVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECODEVARIABLE_H
