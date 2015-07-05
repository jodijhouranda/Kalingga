/********************************************************************************
** Form generated from reading UI file 'mapvariablechooser.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPVARIABLECHOOSER_H
#define UI_MAPVARIABLECHOOSER_H

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

class Ui_MapVariableChooser
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelVariable;
    QListWidget *listWidgetVariables;

    void setupUi(QDialog *MapVariableChooser)
    {
        if (MapVariableChooser->objectName().isEmpty())
            MapVariableChooser->setObjectName(QString::fromUtf8("MapVariableChooser"));
        MapVariableChooser->resize(211, 300);
        buttonBox = new QDialogButtonBox(MapVariableChooser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 151, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        labelVariable = new QLabel(MapVariableChooser);
        labelVariable->setObjectName(QString::fromUtf8("labelVariable"));
        labelVariable->setGeometry(QRect(20, 20, 81, 16));
        listWidgetVariables = new QListWidget(MapVariableChooser);
        listWidgetVariables->setObjectName(QString::fromUtf8("listWidgetVariables"));
        listWidgetVariables->setGeometry(QRect(20, 40, 171, 192));

        retranslateUi(MapVariableChooser);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapVariableChooser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapVariableChooser, SLOT(reject()));

        QMetaObject::connectSlotsByName(MapVariableChooser);
    } // setupUi

    void retranslateUi(QDialog *MapVariableChooser)
    {
        MapVariableChooser->setWindowTitle(QApplication::translate("MapVariableChooser", "Dialog", 0, QApplication::UnicodeUTF8));
        labelVariable->setText(QApplication::translate("MapVariableChooser", "Select Variable", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapVariableChooser: public Ui_MapVariableChooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPVARIABLECHOOSER_H
