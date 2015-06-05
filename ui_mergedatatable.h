/********************************************************************************
** Form generated from reading UI file 'mergedatatable.ui'
**
** Created: Thu Jun 4 16:46:47 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEDATATABLE_H
#define UI_MERGEDATATABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_MergeDataTable
{
public:
    QLabel *label;
    QLineEdit *lineEditSource;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QRadioButton *radioButtonByValue;
    QRadioButton *radioButtonRecordOrder;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBoxKeyCurrent;
    QComboBox *comboBoxKeyImport;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QPushButton *pushButtonRightTwo;
    QPushButton *pushButtonRight;
    QPushButton *pushButtonLeft;
    QPushButton *pushButtonLeftTwo;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *MergeDataTable)
    {
        if (MergeDataTable->objectName().isEmpty())
            MergeDataTable->setObjectName(QString::fromUtf8("MergeDataTable"));
        MergeDataTable->resize(450, 453);
        label = new QLabel(MergeDataTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 71, 16));
        lineEditSource = new QLineEdit(MergeDataTable);
        lineEditSource->setObjectName(QString::fromUtf8("lineEditSource"));
        lineEditSource->setGeometry(QRect(90, 10, 271, 20));
        pushButton = new QPushButton(MergeDataTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 10, 61, 23));
        groupBox = new QGroupBox(MergeDataTable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 411, 141));
        radioButtonByValue = new QRadioButton(groupBox);
        radioButtonByValue->setObjectName(QString::fromUtf8("radioButtonByValue"));
        radioButtonByValue->setGeometry(QRect(20, 20, 121, 17));
        radioButtonByValue->setChecked(true);
        radioButtonRecordOrder = new QRadioButton(groupBox);
        radioButtonRecordOrder->setObjectName(QString::fromUtf8("radioButtonRecordOrder"));
        radioButtonRecordOrder->setGeometry(QRect(20, 110, 141, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 50, 101, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 80, 101, 16));
        comboBoxKeyCurrent = new QComboBox(groupBox);
        comboBoxKeyCurrent->setObjectName(QString::fromUtf8("comboBoxKeyCurrent"));
        comboBoxKeyCurrent->setGeometry(QRect(180, 50, 161, 22));
        comboBoxKeyImport = new QComboBox(groupBox);
        comboBoxKeyImport->setObjectName(QString::fromUtf8("comboBoxKeyImport"));
        comboBoxKeyImport->setGeometry(QRect(180, 80, 161, 22));
        listWidget = new QListWidget(MergeDataTable);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 200, 181, 211));
        listWidget_2 = new QListWidget(MergeDataTable);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(250, 200, 181, 211));
        pushButtonRightTwo = new QPushButton(MergeDataTable);
        pushButtonRightTwo->setObjectName(QString::fromUtf8("pushButtonRightTwo"));
        pushButtonRightTwo->setGeometry(QRect(210, 230, 31, 31));
        pushButtonRight = new QPushButton(MergeDataTable);
        pushButtonRight->setObjectName(QString::fromUtf8("pushButtonRight"));
        pushButtonRight->setGeometry(QRect(210, 270, 31, 31));
        pushButtonLeft = new QPushButton(MergeDataTable);
        pushButtonLeft->setObjectName(QString::fromUtf8("pushButtonLeft"));
        pushButtonLeft->setGeometry(QRect(210, 310, 31, 31));
        pushButtonLeftTwo = new QPushButton(MergeDataTable);
        pushButtonLeftTwo->setObjectName(QString::fromUtf8("pushButtonLeftTwo"));
        pushButtonLeftTwo->setGeometry(QRect(210, 350, 31, 31));
        pushButton_2 = new QPushButton(MergeDataTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 420, 75, 23));
        pushButton_3 = new QPushButton(MergeDataTable);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 420, 75, 23));

        retranslateUi(MergeDataTable);

        QMetaObject::connectSlotsByName(MergeDataTable);
    } // setupUi

    void retranslateUi(QDialog *MergeDataTable)
    {
        MergeDataTable->setWindowTitle(QApplication::translate("MergeDataTable", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MergeDataTable", "Input source", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MergeDataTable", "Open", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MergeDataTable", "Marge Setting", 0, QApplication::UnicodeUTF8));
        radioButtonByValue->setText(QApplication::translate("MergeDataTable", "Merge By Key Values", 0, QApplication::UnicodeUTF8));
        radioButtonRecordOrder->setText(QApplication::translate("MergeDataTable", "Merge By Record Order", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MergeDataTable", "Current Table Key", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MergeDataTable", "Import Table Key", 0, QApplication::UnicodeUTF8));
        pushButtonRightTwo->setText(QApplication::translate("MergeDataTable", ">>", 0, QApplication::UnicodeUTF8));
        pushButtonRight->setText(QApplication::translate("MergeDataTable", ">", 0, QApplication::UnicodeUTF8));
        pushButtonLeft->setText(QApplication::translate("MergeDataTable", "<", 0, QApplication::UnicodeUTF8));
        pushButtonLeftTwo->setText(QApplication::translate("MergeDataTable", "<<", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MergeDataTable", "Merge", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MergeDataTable", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MergeDataTable: public Ui_MergeDataTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEDATATABLE_H
