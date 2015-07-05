/********************************************************************************
** Form generated from reading UI file 'mapvariabletypechooser.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPVARIABLETYPECHOOSER_H
#define UI_MAPVARIABLETYPECHOOSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_MapVariableTypeChooser
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelType;
    QLabel *labelVariable;
    QListWidget *listWidgetVariables;
    QComboBox *comboBox;

    void setupUi(QDialog *MapVariableTypeChooser)
    {
        if (MapVariableTypeChooser->objectName().isEmpty())
            MapVariableTypeChooser->setObjectName(QString::fromUtf8("MapVariableTypeChooser"));
        MapVariableTypeChooser->resize(212, 352);
        buttonBox = new QDialogButtonBox(MapVariableTypeChooser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 310, 151, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        labelType = new QLabel(MapVariableTypeChooser);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setGeometry(QRect(20, 20, 81, 16));
        labelVariable = new QLabel(MapVariableTypeChooser);
        labelVariable->setObjectName(QString::fromUtf8("labelVariable"));
        labelVariable->setGeometry(QRect(20, 80, 81, 16));
        listWidgetVariables = new QListWidget(MapVariableTypeChooser);
        listWidgetVariables->setObjectName(QString::fromUtf8("listWidgetVariables"));
        listWidgetVariables->setGeometry(QRect(20, 100, 171, 192));
        comboBox = new QComboBox(MapVariableTypeChooser);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 40, 171, 22));

        retranslateUi(MapVariableTypeChooser);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapVariableTypeChooser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapVariableTypeChooser, SLOT(reject()));

        QMetaObject::connectSlotsByName(MapVariableTypeChooser);
    } // setupUi

    void retranslateUi(QDialog *MapVariableTypeChooser)
    {
        MapVariableTypeChooser->setWindowTitle(QApplication::translate("MapVariableTypeChooser", "Dialog", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("MapVariableTypeChooser", "Select Type", 0, QApplication::UnicodeUTF8));
        labelVariable->setText(QApplication::translate("MapVariableTypeChooser", "Select Variable", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapVariableTypeChooser: public Ui_MapVariableTypeChooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPVARIABLETYPECHOOSER_H
