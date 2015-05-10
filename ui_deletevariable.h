/********************************************************************************
** Form generated from reading UI file 'deletevariable.ui'
**
** Created: Thu May 7 13:26:08 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEVARIABLE_H
#define UI_DELETEVARIABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeleteVariable
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBoxVariables;

    void setupUi(QDialog *DeleteVariable)
    {
        if (DeleteVariable->objectName().isEmpty())
            DeleteVariable->setObjectName(QString::fromUtf8("DeleteVariable"));
        DeleteVariable->resize(311, 79);
        buttonBox = new QDialogButtonBox(DeleteVariable);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 10, 81, 301));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DeleteVariable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 151, 16));
        comboBoxVariables = new QComboBox(DeleteVariable);
        comboBoxVariables->setObjectName(QString::fromUtf8("comboBoxVariables"));
        comboBoxVariables->setGeometry(QRect(20, 30, 171, 22));

        retranslateUi(DeleteVariable);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeleteVariable, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeleteVariable, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeleteVariable);
    } // setupUi

    void retranslateUi(QDialog *DeleteVariable)
    {
        DeleteVariable->setWindowTitle(QApplication::translate("DeleteVariable", "Delete Variable", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeleteVariable", "Variable to delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeleteVariable: public Ui_DeleteVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEVARIABLE_H
