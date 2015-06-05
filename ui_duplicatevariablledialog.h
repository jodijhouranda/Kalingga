/********************************************************************************
** Form generated from reading UI file 'duplicatevariablledialog.ui'
**
** Created: Thu Jun 4 20:10:06 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUPLICATEVARIABLLEDIALOG_H
#define UI_DUPLICATEVARIABLLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DuplicateVariablleDialog
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DuplicateVariablleDialog)
    {
        if (DuplicateVariablleDialog->objectName().isEmpty())
            DuplicateVariablleDialog->setObjectName(QString::fromUtf8("DuplicateVariablleDialog"));
        DuplicateVariablleDialog->resize(224, 320);
        tableWidget = new QTableWidget(DuplicateVariablleDialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 201, 251));
        label = new QLabel(DuplicateVariablleDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 101, 16));
        pushButton = new QPushButton(DuplicateVariablleDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 290, 75, 23));
        pushButton_2 = new QPushButton(DuplicateVariablleDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 290, 75, 23));

        retranslateUi(DuplicateVariablleDialog);

        QMetaObject::connectSlotsByName(DuplicateVariablleDialog);
    } // setupUi

    void retranslateUi(QDialog *DuplicateVariablleDialog)
    {
        DuplicateVariablleDialog->setWindowTitle(QApplication::translate("DuplicateVariablleDialog", "Duplicate variables Editor", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DuplicateVariablleDialog", "Old Names", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DuplicateVariablleDialog", "New Name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DuplicateVariablleDialog", "Duplicate variables", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DuplicateVariablleDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DuplicateVariablleDialog", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DuplicateVariablleDialog: public Ui_DuplicateVariablleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUPLICATEVARIABLLEDIALOG_H
