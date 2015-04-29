/********************************************************************************
** Form generated from reading UI file 'randomsamplegenarator.ui'
**
** Created: Wed Apr 29 22:33:33 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMSAMPLEGENARATOR_H
#define UI_RANDOMSAMPLEGENARATOR_H

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
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomSampleGenarator
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBoxVariables;
    QPushButton *pushButtonNewVar;
    QLabel *Result;
    QLabel *equal;
    QComboBox *comboBoxDistributions;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayoutPar;
    QLabel *Distribution;

    void setupUi(QDialog *RandomSampleGenarator)
    {
        if (RandomSampleGenarator->objectName().isEmpty())
            RandomSampleGenarator->setObjectName(QString::fromUtf8("RandomSampleGenarator"));
        RandomSampleGenarator->resize(368, 214);
        buttonBox = new QDialogButtonBox(RandomSampleGenarator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(130, 160, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBoxVariables = new QComboBox(RandomSampleGenarator);
        comboBoxVariables->setObjectName(QString::fromUtf8("comboBoxVariables"));
        comboBoxVariables->setGeometry(QRect(10, 50, 151, 22));
        pushButtonNewVar = new QPushButton(RandomSampleGenarator);
        pushButtonNewVar->setObjectName(QString::fromUtf8("pushButtonNewVar"));
        pushButtonNewVar->setGeometry(QRect(80, 20, 81, 23));
        Result = new QLabel(RandomSampleGenarator);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setGeometry(QRect(10, 30, 47, 13));
        equal = new QLabel(RandomSampleGenarator);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setGeometry(QRect(170, 50, 47, 13));
        QFont font;
        font.setPointSize(12);
        equal->setFont(font);
        comboBoxDistributions = new QComboBox(RandomSampleGenarator);
        comboBoxDistributions->setObjectName(QString::fromUtf8("comboBoxDistributions"));
        comboBoxDistributions->setGeometry(QRect(200, 50, 151, 22));
        groupBox = new QGroupBox(RandomSampleGenarator);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 341, 81));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 321, 51));
        horizontalLayoutPar = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayoutPar->setObjectName(QString::fromUtf8("horizontalLayoutPar"));
        horizontalLayoutPar->setContentsMargins(0, 0, 0, 0);
        Distribution = new QLabel(RandomSampleGenarator);
        Distribution->setObjectName(QString::fromUtf8("Distribution"));
        Distribution->setGeometry(QRect(200, 30, 61, 16));

        retranslateUi(RandomSampleGenarator);
        QObject::connect(buttonBox, SIGNAL(accepted()), RandomSampleGenarator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RandomSampleGenarator, SLOT(reject()));

        QMetaObject::connectSlotsByName(RandomSampleGenarator);
    } // setupUi

    void retranslateUi(QDialog *RandomSampleGenarator)
    {
        RandomSampleGenarator->setWindowTitle(QApplication::translate("RandomSampleGenarator", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButtonNewVar->setText(QApplication::translate("RandomSampleGenarator", "New Variable", 0, QApplication::UnicodeUTF8));
        Result->setText(QApplication::translate("RandomSampleGenarator", "Result", 0, QApplication::UnicodeUTF8));
        equal->setText(QApplication::translate("RandomSampleGenarator", "=", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RandomSampleGenarator", "Parameter", 0, QApplication::UnicodeUTF8));
        Distribution->setText(QApplication::translate("RandomSampleGenarator", "Distribution", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RandomSampleGenarator: public Ui_RandomSampleGenarator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMSAMPLEGENARATOR_H
