/********************************************************************************
** Form generated from reading UI file 'plugindialog.ui'
**
** Created: Wed Jun 10 21:55:39 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINDIALOG_H
#define UI_PLUGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_PluginDialog
{
public:
    QListWidget *listWidget;
    QLabel *label;

    void setupUi(QDialog *PluginDialog)
    {
        if (PluginDialog->objectName().isEmpty())
            PluginDialog->setObjectName(QString::fromUtf8("PluginDialog"));
        PluginDialog->resize(341, 396);
        listWidget = new QListWidget(PluginDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 321, 351));
        label = new QLabel(PluginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 47, 13));

        retranslateUi(PluginDialog);

        QMetaObject::connectSlotsByName(PluginDialog);
    } // setupUi

    void retranslateUi(QDialog *PluginDialog)
    {
        PluginDialog->setWindowTitle(QApplication::translate("PluginDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PluginDialog", "Plugin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PluginDialog: public Ui_PluginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINDIALOG_H
