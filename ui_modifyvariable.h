/********************************************************************************
** Form generated from reading UI file 'modifyvariable.ui'
**
** Created: Fri May 29 10:59:42 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYVARIABLE_H
#define UI_MODIFYVARIABLE_H

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
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyVariable
{
public:
    QTableWidget *tableWidgetVariable;
    QTableWidget *tableWidgetValue;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QLabel *label_4;
    QComboBox *comboBoxVariablesInsertBefore;
    QLabel *label_5;
    QLineEdit *lineEditName;
    QLabel *label_6;
    QLineEdit *lineEditLabel;
    QLabel *label_7;
    QComboBox *comboBoxVariablesType;
    QPushButton *pushButtonApply;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *ModifyVariable)
    {
        if (ModifyVariable->objectName().isEmpty())
            ModifyVariable->setObjectName(QString::fromUtf8("ModifyVariable"));
        ModifyVariable->resize(786, 287);
        tableWidgetVariable = new QTableWidget(ModifyVariable);
        if (tableWidgetVariable->columnCount() < 3)
            tableWidgetVariable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetVariable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetVariable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetVariable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidgetVariable->setObjectName(QString::fromUtf8("tableWidgetVariable"));
        tableWidgetVariable->setGeometry(QRect(10, 30, 251, 241));
        tableWidgetVariable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetVariable->setProperty("showDropIndicator", QVariant(false));
        tableWidgetVariable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidgetVariable->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetVariable->setShowGrid(false);
        tableWidgetVariable->setWordWrap(false);
        tableWidgetVariable->setCornerButtonEnabled(false);
        tableWidgetVariable->setColumnCount(3);
        tableWidgetValue = new QTableWidget(ModifyVariable);
        if (tableWidgetValue->columnCount() < 2)
            tableWidgetValue->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetValue->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetValue->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidgetValue->setObjectName(QString::fromUtf8("tableWidgetValue"));
        tableWidgetValue->setGeometry(QRect(270, 30, 221, 241));
        tableWidgetValue->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetValue->setTabKeyNavigation(false);
        tableWidgetValue->setProperty("showDropIndicator", QVariant(false));
        tableWidgetValue->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetValue->setSelectionBehavior(QAbstractItemView::SelectColumns);
        tableWidgetValue->setTextElideMode(Qt::ElideRight);
        tableWidgetValue->setShowGrid(false);
        tableWidgetValue->setWordWrap(false);
        tableWidgetValue->setCornerButtonEnabled(false);
        tableWidgetValue->setColumnCount(2);
        tableWidgetValue->verticalHeader()->setVisible(false);
        label = new QLabel(ModifyVariable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 47, 13));
        label_2 = new QLabel(ModifyVariable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 10, 81, 16));
        groupBox = new QGroupBox(ModifyVariable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(500, 20, 271, 161));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 81, 16));
        comboBoxVariablesInsertBefore = new QComboBox(groupBox);
        comboBoxVariablesInsertBefore->setObjectName(QString::fromUtf8("comboBoxVariablesInsertBefore"));
        comboBoxVariablesInsertBefore->setGeometry(QRect(90, 120, 171, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 81, 16));
        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(90, 30, 171, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 81, 16));
        lineEditLabel = new QLineEdit(groupBox);
        lineEditLabel->setObjectName(QString::fromUtf8("lineEditLabel"));
        lineEditLabel->setGeometry(QRect(90, 90, 171, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 81, 16));
        comboBoxVariablesType = new QComboBox(groupBox);
        comboBoxVariablesType->setObjectName(QString::fromUtf8("comboBoxVariablesType"));
        comboBoxVariablesType->setGeometry(QRect(90, 60, 171, 22));
        pushButtonApply = new QPushButton(ModifyVariable);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setGeometry(QRect(610, 250, 75, 23));
        pushButtonCancel = new QPushButton(ModifyVariable);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(690, 250, 75, 23));

        retranslateUi(ModifyVariable);

        QMetaObject::connectSlotsByName(ModifyVariable);
    } // setupUi

    void retranslateUi(QDialog *ModifyVariable)
    {
        ModifyVariable->setWindowTitle(QApplication::translate("ModifyVariable", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetVariable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ModifyVariable", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetVariable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ModifyVariable", "Type ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetVariable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ModifyVariable", "Label", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetValue->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("ModifyVariable", "Row", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetValue->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("ModifyVariable", "Value", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifyVariable", "Variable", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModifyVariable", "Variable's values", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ModifyVariable", "Modify Settings", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ModifyVariable", "Insert before :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ModifyVariable", "Name:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ModifyVariable", "Label:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ModifyVariable", "Type:", 0, QApplication::UnicodeUTF8));
        comboBoxVariablesType->clear();
        comboBoxVariablesType->insertItems(0, QStringList()
         << QApplication::translate("ModifyVariable", "Real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModifyVariable", "Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModifyVariable", "String", 0, QApplication::UnicodeUTF8)
        );
        pushButtonApply->setText(QApplication::translate("ModifyVariable", "Apply", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("ModifyVariable", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModifyVariable: public Ui_ModifyVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYVARIABLE_H
