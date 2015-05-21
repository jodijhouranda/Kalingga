/********************************************************************************
** Form generated from reading UI file 'recodevariable.ui'
**
** Created: Fri May 22 00:11:27 2015
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecodeVariable
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButtonovalue;
    QLineEdit *lineEditovalue;
    QRadioButton *radioButton_omissing;
    QRadioButton *radioButton_orange;
    QLineEdit *lineEdit_orangefrom;
    QLineEdit *lineEdit_orangeTo;
    QLabel *label_3;
    QRadioButton *radioButton_olowestrange;
    QLineEdit *lineEdit_olowestrange;
    QRadioButton *radioButton_ohighestrange;
    QLineEdit *lineEdit_5;
    QRadioButton *radioButton_oother;
    QLabel *label;
    QLabel *label_variable;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_nvalue;
    QLineEdit *lineEdit_nvalue;
    QRadioButton *radioButton_nmissing;
    QRadioButton *radioButton_ncopyold;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Result;
    QComboBox *comboBoxVariables;
    QPushButton *pushButtonNewVar;
    QListView *listView;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonChange;
    QPushButton *pushButtonRemove;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RecodeVariable)
    {
        if (RecodeVariable->objectName().isEmpty())
            RecodeVariable->setObjectName(QString::fromUtf8("RecodeVariable"));
        RecodeVariable->resize(507, 461);
        groupBox = new QGroupBox(RecodeVariable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 211, 361));
        radioButtonovalue = new QRadioButton(groupBox);
        radioButtonovalue->setObjectName(QString::fromUtf8("radioButtonovalue"));
        radioButtonovalue->setGeometry(QRect(10, 20, 82, 17));
        lineEditovalue = new QLineEdit(groupBox);
        lineEditovalue->setObjectName(QString::fromUtf8("lineEditovalue"));
        lineEditovalue->setGeometry(QRect(30, 40, 171, 20));
        radioButton_omissing = new QRadioButton(groupBox);
        radioButton_omissing->setObjectName(QString::fromUtf8("radioButton_omissing"));
        radioButton_omissing->setGeometry(QRect(10, 70, 82, 17));
        radioButton_orange = new QRadioButton(groupBox);
        radioButton_orange->setObjectName(QString::fromUtf8("radioButton_orange"));
        radioButton_orange->setGeometry(QRect(10, 100, 82, 17));
        lineEdit_orangefrom = new QLineEdit(groupBox);
        lineEdit_orangefrom->setObjectName(QString::fromUtf8("lineEdit_orangefrom"));
        lineEdit_orangefrom->setGeometry(QRect(30, 120, 171, 20));
        lineEdit_orangeTo = new QLineEdit(groupBox);
        lineEdit_orangeTo->setObjectName(QString::fromUtf8("lineEdit_orangeTo"));
        lineEdit_orangeTo->setGeometry(QRect(30, 160, 171, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 140, 47, 13));
        radioButton_olowestrange = new QRadioButton(groupBox);
        radioButton_olowestrange->setObjectName(QString::fromUtf8("radioButton_olowestrange"));
        radioButton_olowestrange->setGeometry(QRect(10, 190, 161, 17));
        lineEdit_olowestrange = new QLineEdit(groupBox);
        lineEdit_olowestrange->setObjectName(QString::fromUtf8("lineEdit_olowestrange"));
        lineEdit_olowestrange->setGeometry(QRect(30, 210, 171, 20));
        radioButton_ohighestrange = new QRadioButton(groupBox);
        radioButton_ohighestrange->setObjectName(QString::fromUtf8("radioButton_ohighestrange"));
        radioButton_ohighestrange->setGeometry(QRect(10, 240, 161, 17));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(30, 260, 171, 20));
        radioButton_oother = new QRadioButton(groupBox);
        radioButton_oother->setObjectName(QString::fromUtf8("radioButton_oother"));
        radioButton_oother->setGeometry(QRect(10, 290, 131, 17));
        label = new QLabel(RecodeVariable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 47, 13));
        label_variable = new QLabel(RecodeVariable);
        label_variable->setObjectName(QString::fromUtf8("label_variable"));
        label_variable->setGeometry(QRect(60, 20, 47, 13));
        label_variable->setStyleSheet(QString::fromUtf8("font: 75 9pt \"MS Shell Dlg 2\";"));
        label_variable->setTextFormat(Qt::AutoText);
        groupBox_2 = new QGroupBox(RecodeVariable);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 40, 251, 111));
        radioButton_nvalue = new QRadioButton(groupBox_2);
        radioButton_nvalue->setObjectName(QString::fromUtf8("radioButton_nvalue"));
        radioButton_nvalue->setGeometry(QRect(10, 20, 82, 17));
        lineEdit_nvalue = new QLineEdit(groupBox_2);
        lineEdit_nvalue->setObjectName(QString::fromUtf8("lineEdit_nvalue"));
        lineEdit_nvalue->setGeometry(QRect(10, 40, 171, 20));
        radioButton_nmissing = new QRadioButton(groupBox_2);
        radioButton_nmissing->setObjectName(QString::fromUtf8("radioButton_nmissing"));
        radioButton_nmissing->setGeometry(QRect(10, 60, 82, 17));
        radioButton_ncopyold = new QRadioButton(groupBox_2);
        radioButton_ncopyold->setObjectName(QString::fromUtf8("radioButton_ncopyold"));
        radioButton_ncopyold->setGeometry(QRect(10, 80, 91, 17));
        horizontalLayoutWidget = new QWidget(RecodeVariable);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(240, 10, 251, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Result = new QLabel(horizontalLayoutWidget);
        Result->setObjectName(QString::fromUtf8("Result"));

        horizontalLayout->addWidget(Result);

        comboBoxVariables = new QComboBox(horizontalLayoutWidget);
        comboBoxVariables->setObjectName(QString::fromUtf8("comboBoxVariables"));

        horizontalLayout->addWidget(comboBoxVariables);

        pushButtonNewVar = new QPushButton(horizontalLayoutWidget);
        pushButtonNewVar->setObjectName(QString::fromUtf8("pushButtonNewVar"));

        horizontalLayout->addWidget(pushButtonNewVar);

        horizontalLayout->setStretch(1, 1);
        listView = new QListView(RecodeVariable);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(300, 160, 191, 241));
        pushButtonAdd = new QPushButton(RecodeVariable);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(240, 210, 51, 23));
        pushButtonChange = new QPushButton(RecodeVariable);
        pushButtonChange->setObjectName(QString::fromUtf8("pushButtonChange"));
        pushButtonChange->setGeometry(QRect(240, 240, 51, 23));
        pushButtonRemove = new QPushButton(RecodeVariable);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));
        pushButtonRemove->setGeometry(QRect(240, 270, 51, 23));
        buttonBox = new QDialogButtonBox(RecodeVariable);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(340, 420, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox->raise();
        label->raise();
        label_variable->raise();
        groupBox_2->raise();
        horizontalLayoutWidget->raise();
        listView->raise();
        pushButtonAdd->raise();
        Result->raise();
        pushButtonChange->raise();
        pushButtonRemove->raise();
        buttonBox->raise();

        retranslateUi(RecodeVariable);

        QMetaObject::connectSlotsByName(RecodeVariable);
    } // setupUi

    void retranslateUi(QDialog *RecodeVariable)
    {
        RecodeVariable->setWindowTitle(QApplication::translate("RecodeVariable", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RecodeVariable", "Old Value", 0, QApplication::UnicodeUTF8));
        radioButtonovalue->setText(QApplication::translate("RecodeVariable", "Value", 0, QApplication::UnicodeUTF8));
        radioButton_omissing->setText(QApplication::translate("RecodeVariable", "Missing", 0, QApplication::UnicodeUTF8));
        radioButton_orange->setText(QApplication::translate("RecodeVariable", "Range", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RecodeVariable", "To", 0, QApplication::UnicodeUTF8));
        radioButton_olowestrange->setText(QApplication::translate("RecodeVariable", "Range, from lowest to value", 0, QApplication::UnicodeUTF8));
        radioButton_ohighestrange->setText(QApplication::translate("RecodeVariable", "Range, from value to highest", 0, QApplication::UnicodeUTF8));
        radioButton_oother->setText(QApplication::translate("RecodeVariable", "Other Values", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RecodeVariable", "Variable :", 0, QApplication::UnicodeUTF8));
        label_variable->setText(QApplication::translate("RecodeVariable", "name", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("RecodeVariable", "New Value", 0, QApplication::UnicodeUTF8));
        radioButton_nvalue->setText(QApplication::translate("RecodeVariable", "Value", 0, QApplication::UnicodeUTF8));
        radioButton_nmissing->setText(QApplication::translate("RecodeVariable", "Missing", 0, QApplication::UnicodeUTF8));
        radioButton_ncopyold->setText(QApplication::translate("RecodeVariable", "Copy old value", 0, QApplication::UnicodeUTF8));
        Result->setText(QApplication::translate("RecodeVariable", "Result", 0, QApplication::UnicodeUTF8));
        pushButtonNewVar->setText(QApplication::translate("RecodeVariable", "New Variable", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("RecodeVariable", "Add", 0, QApplication::UnicodeUTF8));
        pushButtonChange->setText(QApplication::translate("RecodeVariable", "Change", 0, QApplication::UnicodeUTF8));
        pushButtonRemove->setText(QApplication::translate("RecodeVariable", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecodeVariable: public Ui_RecodeVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECODEVARIABLE_H
