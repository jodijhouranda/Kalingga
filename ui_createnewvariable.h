/********************************************************************************
** Form generated from reading UI file 'createnewvariable.ui'
**
** Created: Thu May 7 13:26:08 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWVARIABLE_H
#define UI_CREATENEWVARIABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateNewVariable
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditName;
    QComboBox *comboBoxType;
    QLineEdit *lineEditLabel;

    void setupUi(QDialog *CreateNewVariable)
    {
        if (CreateNewVariable->objectName().isEmpty())
            CreateNewVariable->setObjectName(QString::fromUtf8("CreateNewVariable"));
        CreateNewVariable->resize(325, 224);
        buttonBox = new QDialogButtonBox(CreateNewVariable);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 160, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CreateNewVariable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 47, 13));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(CreateNewVariable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 47, 13));
        label_2->setFont(font);
        label_3 = new QLabel(CreateNewVariable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 110, 47, 13));
        label_3->setFont(font);
        lineEditName = new QLineEdit(CreateNewVariable);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(90, 50, 211, 20));
        comboBoxType = new QComboBox(CreateNewVariable);
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));
        comboBoxType->setGeometry(QRect(90, 80, 121, 22));
        lineEditLabel = new QLineEdit(CreateNewVariable);
        lineEditLabel->setObjectName(QString::fromUtf8("lineEditLabel"));
        lineEditLabel->setGeometry(QRect(90, 110, 211, 20));

        retranslateUi(CreateNewVariable);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateNewVariable, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateNewVariable, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateNewVariable);
    } // setupUi

    void retranslateUi(QDialog *CreateNewVariable)
    {
        CreateNewVariable->setWindowTitle(QApplication::translate("CreateNewVariable", "Create New Variable", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateNewVariable", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateNewVariable", "Type", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateNewVariable", "Label", 0, QApplication::UnicodeUTF8));
        comboBoxType->clear();
        comboBoxType->insertItems(0, QStringList()
         << QApplication::translate("CreateNewVariable", "Real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreateNewVariable", "Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreateNewVariable", "String", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CreateNewVariable: public Ui_CreateNewVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWVARIABLE_H
