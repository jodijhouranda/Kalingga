/********************************************************************************
** Form generated from reading UI file 'randomsamplegenerator.ui'
**
** Created: Wed Apr 29 21:15:42 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMSAMPLEGENERATOR_H
#define UI_RANDOMSAMPLEGENERATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_randomSampleGenerator
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *Result;
    QComboBox *comboBoxVariables;
    QPushButton *pushButtonNewVar;
    QLabel *equal;
    QComboBox *comboBoxVariables_2;
    QLabel *Distribution;
    QGroupBox *groupBox;

    void setupUi(QDialog *randomSampleGenerator)
    {
        if (randomSampleGenerator->objectName().isEmpty())
            randomSampleGenerator->setObjectName(QString::fromUtf8("randomSampleGenerator"));
        randomSampleGenerator->resize(370, 222);
        buttonBox = new QDialogButtonBox(randomSampleGenerator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 170, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Result = new QLabel(randomSampleGenerator);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setGeometry(QRect(10, 20, 47, 13));
        comboBoxVariables = new QComboBox(randomSampleGenerator);
        comboBoxVariables->setObjectName(QString::fromUtf8("comboBoxVariables"));
        comboBoxVariables->setGeometry(QRect(10, 40, 151, 22));
        pushButtonNewVar = new QPushButton(randomSampleGenerator);
        pushButtonNewVar->setObjectName(QString::fromUtf8("pushButtonNewVar"));
        pushButtonNewVar->setGeometry(QRect(80, 10, 81, 23));
        equal = new QLabel(randomSampleGenerator);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setGeometry(QRect(170, 40, 47, 13));
        QFont font;
        font.setPointSize(12);
        equal->setFont(font);
        comboBoxVariables_2 = new QComboBox(randomSampleGenerator);
        comboBoxVariables_2->setObjectName(QString::fromUtf8("comboBoxVariables_2"));
        comboBoxVariables_2->setGeometry(QRect(190, 40, 151, 22));
        Distribution = new QLabel(randomSampleGenerator);
        Distribution->setObjectName(QString::fromUtf8("Distribution"));
        Distribution->setGeometry(QRect(190, 20, 61, 16));
        groupBox = new QGroupBox(randomSampleGenerator);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 331, 81));

        retranslateUi(randomSampleGenerator);
        QObject::connect(buttonBox, SIGNAL(accepted()), randomSampleGenerator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), randomSampleGenerator, SLOT(reject()));

        QMetaObject::connectSlotsByName(randomSampleGenerator);
    } // setupUi

    void retranslateUi(QDialog *randomSampleGenerator)
    {
        randomSampleGenerator->setWindowTitle(QApplication::translate("randomSampleGenerator", "Dialog", 0, QApplication::UnicodeUTF8));
        Result->setText(QApplication::translate("randomSampleGenerator", "Result", 0, QApplication::UnicodeUTF8));
        pushButtonNewVar->setText(QApplication::translate("randomSampleGenerator", "New Variable", 0, QApplication::UnicodeUTF8));
        equal->setText(QApplication::translate("randomSampleGenerator", "=", 0, QApplication::UnicodeUTF8));
        Distribution->setText(QApplication::translate("randomSampleGenerator", "Distribution", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("randomSampleGenerator", "Parameter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class randomSampleGenerator: public Ui_randomSampleGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMSAMPLEGENERATOR_H
