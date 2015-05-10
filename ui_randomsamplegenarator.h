/********************************************************************************
** Form generated from reading UI file 'randomsamplegenarator.ui'
**
** Created: Thu May 7 13:26:09 2015
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomSampleGenarator
{
public:
    QComboBox *comboBoxVariables;
    QPushButton *pushButtonNewVar;
    QLabel *Result;
    QLabel *equal;
    QComboBox *comboBoxDistributions;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *firstLabel;
    QLineEdit *firstParameter;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *secondLabel;
    QLineEdit *secondParameter;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *thirdLabel;
    QLineEdit *thirdParameter;
    QLabel *Distribution;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonApply;

    void setupUi(QDialog *RandomSampleGenarator)
    {
        if (RandomSampleGenarator->objectName().isEmpty())
            RandomSampleGenarator->setObjectName(QString::fromUtf8("RandomSampleGenarator"));
        RandomSampleGenarator->resize(394, 243);
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
        groupBox->setGeometry(QRect(10, 80, 371, 101));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 111, 41));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        firstLabel = new QLabel(verticalLayoutWidget);
        firstLabel->setObjectName(QString::fromUtf8("firstLabel"));

        verticalLayout->addWidget(firstLabel);

        firstParameter = new QLineEdit(verticalLayoutWidget);
        firstParameter->setObjectName(QString::fromUtf8("firstParameter"));

        verticalLayout->addWidget(firstParameter);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(130, 30, 111, 41));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        secondLabel = new QLabel(verticalLayoutWidget_2);
        secondLabel->setObjectName(QString::fromUtf8("secondLabel"));

        verticalLayout_2->addWidget(secondLabel);

        secondParameter = new QLineEdit(verticalLayoutWidget_2);
        secondParameter->setObjectName(QString::fromUtf8("secondParameter"));

        verticalLayout_2->addWidget(secondParameter);

        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(250, 30, 111, 41));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        thirdLabel = new QLabel(verticalLayoutWidget_3);
        thirdLabel->setObjectName(QString::fromUtf8("thirdLabel"));

        verticalLayout_3->addWidget(thirdLabel);

        thirdParameter = new QLineEdit(verticalLayoutWidget_3);
        thirdParameter->setObjectName(QString::fromUtf8("thirdParameter"));

        verticalLayout_3->addWidget(thirdParameter);

        Distribution = new QLabel(RandomSampleGenarator);
        Distribution->setObjectName(QString::fromUtf8("Distribution"));
        Distribution->setGeometry(QRect(200, 30, 61, 16));
        pushButtonCancel = new QPushButton(RandomSampleGenarator);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(300, 200, 81, 23));
        pushButtonApply = new QPushButton(RandomSampleGenarator);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setGeometry(QRect(210, 200, 81, 23));

        retranslateUi(RandomSampleGenarator);

        QMetaObject::connectSlotsByName(RandomSampleGenarator);
    } // setupUi

    void retranslateUi(QDialog *RandomSampleGenarator)
    {
        RandomSampleGenarator->setWindowTitle(QApplication::translate("RandomSampleGenarator", "Generate Random Sampel", 0, QApplication::UnicodeUTF8));
        pushButtonNewVar->setText(QApplication::translate("RandomSampleGenarator", "New Variable", 0, QApplication::UnicodeUTF8));
        Result->setText(QApplication::translate("RandomSampleGenarator", "Result", 0, QApplication::UnicodeUTF8));
        equal->setText(QApplication::translate("RandomSampleGenarator", "=", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RandomSampleGenarator", "Parameter", 0, QApplication::UnicodeUTF8));
        firstLabel->setText(QApplication::translate("RandomSampleGenarator", "label", 0, QApplication::UnicodeUTF8));
        secondLabel->setText(QApplication::translate("RandomSampleGenarator", "label", 0, QApplication::UnicodeUTF8));
        thirdLabel->setText(QApplication::translate("RandomSampleGenarator", "label", 0, QApplication::UnicodeUTF8));
        Distribution->setText(QApplication::translate("RandomSampleGenarator", "Distribution", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("RandomSampleGenarator", "cancel", 0, QApplication::UnicodeUTF8));
        pushButtonApply->setText(QApplication::translate("RandomSampleGenarator", "apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RandomSampleGenarator: public Ui_RandomSampleGenarator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMSAMPLEGENARATOR_H
