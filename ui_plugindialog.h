/********************************************************************************
** Form generated from reading UI file 'plugindialog.ui'
**
** Created: Sun Jul 12 15:12:17 2015
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
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PluginDialog
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *plug;

    void setupUi(QDialog *PluginDialog)
    {
        if (PluginDialog->objectName().isEmpty())
            PluginDialog->setObjectName(QString::fromUtf8("PluginDialog"));
        PluginDialog->resize(341, 424);
        listWidget = new QListWidget(PluginDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 60, 321, 321));
        label = new QLabel(PluginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 47, 13));
        lineEdit = new QLineEdit(PluginDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 251, 20));
        pushButton = new QPushButton(PluginDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 10, 61, 23));
        pushButton_2 = new QPushButton(PluginDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 390, 75, 23));
        plug = new QPushButton(PluginDialog);
        plug->setObjectName(QString::fromUtf8("plug"));
        plug->setGeometry(QRect(170, 390, 75, 23));

        retranslateUi(PluginDialog);

        QMetaObject::connectSlotsByName(PluginDialog);
    } // setupUi

    void retranslateUi(QDialog *PluginDialog)
    {
        PluginDialog->setWindowTitle(QApplication::translate("PluginDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PluginDialog", "Plugin", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PluginDialog", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("PluginDialog", "Unplug", 0, QApplication::UnicodeUTF8));
        plug->setText(QApplication::translate("PluginDialog", "Plug", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PluginDialog: public Ui_PluginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINDIALOG_H
