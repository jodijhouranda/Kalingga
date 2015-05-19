/********************************************************************************
** Form generated from reading UI file 'computevariable.ui'
**
** Created: Tue May 19 14:43:15 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTEVARIABLE_H
#define UI_COMPUTEVARIABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ComputeVariable
{
public:
    QGroupBox *groupBox;
    QComboBox *comboBoxVariables;
    QListWidget *listWidgetVariables;
    QLabel *label;
    QPushButton *pushButtonNewVar;
    QGroupBox *computationTool;
    QPushButton *pushButton1;
    QPushButton *pushButton1_2;
    QPushButton *pushButton1_3;
    QPushButton *pushButton1_4;
    QPushButton *pushButton1_5;
    QPushButton *pushButton1_6;
    QPushButton *pushButton1_7;
    QPushButton *pushButton1_8;
    QPushButton *pushButton1_9;
    QPushButton *pushButtonplus;
    QPushButton *pushButtonsubtract;
    QPushButton *pushButtonMultiply;
    QPushButton *pushButtonDevide;
    QPushButton *pushButtonPoint;
    QPushButton *pushButton1_0;
    QPushButton *pushButtondelete;
    QListWidget *listWidgetfunction;
    QLabel *label_2;
    QPushButton *pushButtonlbrac;
    QPushButton *pushButtonrbrac;
    QComboBox *comboBoxFGroup;
    QPushButton *pushButtondelete_2;
    QPushButton *pushButton_2;
    QTextEdit *formulaText;
    QLabel *label_5;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonApply;

    void setupUi(QDialog *ComputeVariable)
    {
        if (ComputeVariable->objectName().isEmpty())
            ComputeVariable->setObjectName(QString::fromUtf8("ComputeVariable"));
        ComputeVariable->resize(696, 348);
        ComputeVariable->setSizeGripEnabled(false);
        groupBox = new QGroupBox(ComputeVariable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 291));
        comboBoxVariables = new QComboBox(groupBox);
        comboBoxVariables->setObjectName(QString::fromUtf8("comboBoxVariables"));
        comboBoxVariables->setGeometry(QRect(10, 50, 201, 22));
        listWidgetVariables = new QListWidget(groupBox);
        listWidgetVariables->setObjectName(QString::fromUtf8("listWidgetVariables"));
        listWidgetVariables->setGeometry(QRect(10, 80, 201, 191));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 47, 13));
        pushButtonNewVar = new QPushButton(groupBox);
        pushButtonNewVar->setObjectName(QString::fromUtf8("pushButtonNewVar"));
        pushButtonNewVar->setGeometry(QRect(130, 20, 81, 23));
        computationTool = new QGroupBox(ComputeVariable);
        computationTool->setObjectName(QString::fromUtf8("computationTool"));
        computationTool->setGeometry(QRect(280, 130, 401, 171));
        pushButton1 = new QPushButton(computationTool);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(90, 30, 41, 31));
        pushButton1_2 = new QPushButton(computationTool);
        pushButton1_2->setObjectName(QString::fromUtf8("pushButton1_2"));
        pushButton1_2->setGeometry(QRect(130, 30, 41, 31));
        pushButton1_3 = new QPushButton(computationTool);
        pushButton1_3->setObjectName(QString::fromUtf8("pushButton1_3"));
        pushButton1_3->setGeometry(QRect(170, 30, 41, 31));
        pushButton1_4 = new QPushButton(computationTool);
        pushButton1_4->setObjectName(QString::fromUtf8("pushButton1_4"));
        pushButton1_4->setGeometry(QRect(90, 60, 41, 31));
        pushButton1_5 = new QPushButton(computationTool);
        pushButton1_5->setObjectName(QString::fromUtf8("pushButton1_5"));
        pushButton1_5->setGeometry(QRect(130, 60, 41, 31));
        pushButton1_6 = new QPushButton(computationTool);
        pushButton1_6->setObjectName(QString::fromUtf8("pushButton1_6"));
        pushButton1_6->setGeometry(QRect(170, 60, 41, 31));
        pushButton1_7 = new QPushButton(computationTool);
        pushButton1_7->setObjectName(QString::fromUtf8("pushButton1_7"));
        pushButton1_7->setGeometry(QRect(90, 90, 41, 31));
        pushButton1_8 = new QPushButton(computationTool);
        pushButton1_8->setObjectName(QString::fromUtf8("pushButton1_8"));
        pushButton1_8->setGeometry(QRect(130, 90, 41, 31));
        pushButton1_9 = new QPushButton(computationTool);
        pushButton1_9->setObjectName(QString::fromUtf8("pushButton1_9"));
        pushButton1_9->setGeometry(QRect(170, 90, 41, 31));
        pushButtonplus = new QPushButton(computationTool);
        pushButtonplus->setObjectName(QString::fromUtf8("pushButtonplus"));
        pushButtonplus->setGeometry(QRect(50, 30, 41, 31));
        pushButtonsubtract = new QPushButton(computationTool);
        pushButtonsubtract->setObjectName(QString::fromUtf8("pushButtonsubtract"));
        pushButtonsubtract->setGeometry(QRect(50, 60, 41, 31));
        pushButtonMultiply = new QPushButton(computationTool);
        pushButtonMultiply->setObjectName(QString::fromUtf8("pushButtonMultiply"));
        pushButtonMultiply->setGeometry(QRect(50, 90, 41, 31));
        pushButtonDevide = new QPushButton(computationTool);
        pushButtonDevide->setObjectName(QString::fromUtf8("pushButtonDevide"));
        pushButtonDevide->setGeometry(QRect(50, 120, 41, 31));
        pushButtonPoint = new QPushButton(computationTool);
        pushButtonPoint->setObjectName(QString::fromUtf8("pushButtonPoint"));
        pushButtonPoint->setGeometry(QRect(90, 120, 41, 31));
        pushButton1_0 = new QPushButton(computationTool);
        pushButton1_0->setObjectName(QString::fromUtf8("pushButton1_0"));
        pushButton1_0->setGeometry(QRect(130, 120, 81, 31));
        pushButtondelete = new QPushButton(computationTool);
        pushButtondelete->setObjectName(QString::fromUtf8("pushButtondelete"));
        pushButtondelete->setGeometry(QRect(10, 120, 41, 31));
        listWidgetfunction = new QListWidget(computationTool);
        listWidgetfunction->setObjectName(QString::fromUtf8("listWidgetfunction"));
        listWidgetfunction->setGeometry(QRect(230, 60, 161, 91));
        label_2 = new QLabel(computationTool);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 10, 47, 13));
        pushButtonlbrac = new QPushButton(computationTool);
        pushButtonlbrac->setObjectName(QString::fromUtf8("pushButtonlbrac"));
        pushButtonlbrac->setGeometry(QRect(10, 60, 41, 31));
        pushButtonrbrac = new QPushButton(computationTool);
        pushButtonrbrac->setObjectName(QString::fromUtf8("pushButtonrbrac"));
        pushButtonrbrac->setGeometry(QRect(10, 90, 41, 31));
        comboBoxFGroup = new QComboBox(computationTool);
        comboBoxFGroup->setObjectName(QString::fromUtf8("comboBoxFGroup"));
        comboBoxFGroup->setGeometry(QRect(230, 30, 161, 22));
        pushButtondelete_2 = new QPushButton(computationTool);
        pushButtondelete_2->setObjectName(QString::fromUtf8("pushButtondelete_2"));
        pushButtondelete_2->setGeometry(QRect(10, 30, 41, 31));
        pushButton_2 = new QPushButton(ComputeVariable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 80, 31, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/images/zoom.png);"));
        formulaText = new QTextEdit(ComputeVariable);
        formulaText->setObjectName(QString::fromUtf8("formulaText"));
        formulaText->setGeometry(QRect(280, 20, 401, 111));
        formulaText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        formulaText->setReadOnly(false);
        formulaText->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_5 = new QLabel(ComputeVariable);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 0, 81, 20));
        pushButtonCancel = new QPushButton(ComputeVariable);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(600, 310, 81, 23));
        pushButtonApply = new QPushButton(ComputeVariable);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setGeometry(QRect(510, 310, 81, 23));
        groupBox->raise();
        computationTool->raise();
        pushButton_2->raise();
        label_5->raise();
        pushButtonCancel->raise();
        pushButtonApply->raise();
        formulaText->raise();

        retranslateUi(ComputeVariable);

        QMetaObject::connectSlotsByName(ComputeVariable);
    } // setupUi

    void retranslateUi(QDialog *ComputeVariable)
    {
        ComputeVariable->setWindowTitle(QApplication::translate("ComputeVariable", "Calculate Variable", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ComputeVariable", "Variable", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ComputeVariable", "Result", 0, QApplication::UnicodeUTF8));
        pushButtonNewVar->setText(QApplication::translate("ComputeVariable", "New Variable", 0, QApplication::UnicodeUTF8));
        computationTool->setTitle(QApplication::translate("ComputeVariable", "Computation Tool", 0, QApplication::UnicodeUTF8));
        pushButton1->setText(QApplication::translate("ComputeVariable", "1", 0, QApplication::UnicodeUTF8));
        pushButton1_2->setText(QApplication::translate("ComputeVariable", "2", 0, QApplication::UnicodeUTF8));
        pushButton1_3->setText(QApplication::translate("ComputeVariable", "3", 0, QApplication::UnicodeUTF8));
        pushButton1_4->setText(QApplication::translate("ComputeVariable", "4", 0, QApplication::UnicodeUTF8));
        pushButton1_5->setText(QApplication::translate("ComputeVariable", "5", 0, QApplication::UnicodeUTF8));
        pushButton1_6->setText(QApplication::translate("ComputeVariable", "6", 0, QApplication::UnicodeUTF8));
        pushButton1_7->setText(QApplication::translate("ComputeVariable", "7", 0, QApplication::UnicodeUTF8));
        pushButton1_8->setText(QApplication::translate("ComputeVariable", "8", 0, QApplication::UnicodeUTF8));
        pushButton1_9->setText(QApplication::translate("ComputeVariable", "9", 0, QApplication::UnicodeUTF8));
        pushButtonplus->setText(QApplication::translate("ComputeVariable", "+", 0, QApplication::UnicodeUTF8));
        pushButtonsubtract->setText(QApplication::translate("ComputeVariable", "-", 0, QApplication::UnicodeUTF8));
        pushButtonMultiply->setText(QApplication::translate("ComputeVariable", "*", 0, QApplication::UnicodeUTF8));
        pushButtonDevide->setText(QApplication::translate("ComputeVariable", "/", 0, QApplication::UnicodeUTF8));
        pushButtonPoint->setText(QApplication::translate("ComputeVariable", ".", 0, QApplication::UnicodeUTF8));
        pushButton1_0->setText(QApplication::translate("ComputeVariable", "0", 0, QApplication::UnicodeUTF8));
        pushButtondelete->setText(QApplication::translate("ComputeVariable", "c", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ComputeVariable", "Function", 0, QApplication::UnicodeUTF8));
        pushButtonlbrac->setText(QApplication::translate("ComputeVariable", "(", 0, QApplication::UnicodeUTF8));
        pushButtonrbrac->setText(QApplication::translate("ComputeVariable", ")", 0, QApplication::UnicodeUTF8));
        pushButtondelete_2->setText(QApplication::translate("ComputeVariable", "^", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
        label_5->setText(QApplication::translate("ComputeVariable", "Formula View", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("ComputeVariable", "cancel", 0, QApplication::UnicodeUTF8));
        pushButtonApply->setText(QApplication::translate("ComputeVariable", "apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ComputeVariable: public Ui_ComputeVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTEVARIABLE_H
