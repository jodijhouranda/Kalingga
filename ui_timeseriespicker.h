/********************************************************************************
** Form generated from reading UI file 'timeseriespicker.ui'
**
** Created: Thu Jun 18 16:38:52 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESERIESPICKER_H
#define UI_TIMESERIESPICKER_H

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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TimeSeriesPicker
{
public:
    QComboBox *comboBoxVariable;
    QLabel *label;
    QListWidget *listWidgetTimes;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButtonSlectAll;
    QComboBox *comboBoxVariableID;
    QLabel *label_3;

    void setupUi(QDialog *TimeSeriesPicker)
    {
        if (TimeSeriesPicker->objectName().isEmpty())
            TimeSeriesPicker->setObjectName(QString::fromUtf8("TimeSeriesPicker"));
        TimeSeriesPicker->resize(215, 426);
        comboBoxVariable = new QComboBox(TimeSeriesPicker);
        comboBoxVariable->setObjectName(QString::fromUtf8("comboBoxVariable"));
        comboBoxVariable->setGeometry(QRect(60, 40, 141, 22));
        label = new QLabel(TimeSeriesPicker);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 47, 13));
        listWidgetTimes = new QListWidget(TimeSeriesPicker);
        listWidgetTimes->setObjectName(QString::fromUtf8("listWidgetTimes"));
        listWidgetTimes->setGeometry(QRect(10, 90, 191, 271));
        listWidgetTimes->setDragEnabled(false);
        listWidgetTimes->setSelectionMode(QAbstractItemView::MultiSelection);
        label_2 = new QLabel(TimeSeriesPicker);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 47, 13));
        buttonBox = new QDialogButtonBox(TimeSeriesPicker);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 400, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButtonSlectAll = new QPushButton(TimeSeriesPicker);
        pushButtonSlectAll->setObjectName(QString::fromUtf8("pushButtonSlectAll"));
        pushButtonSlectAll->setGeometry(QRect(10, 370, 75, 23));
        comboBoxVariableID = new QComboBox(TimeSeriesPicker);
        comboBoxVariableID->setObjectName(QString::fromUtf8("comboBoxVariableID"));
        comboBoxVariableID->setGeometry(QRect(60, 10, 141, 22));
        label_3 = new QLabel(TimeSeriesPicker);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 47, 13));

        retranslateUi(TimeSeriesPicker);

        QMetaObject::connectSlotsByName(TimeSeriesPicker);
    } // setupUi

    void retranslateUi(QDialog *TimeSeriesPicker)
    {
        TimeSeriesPicker->setWindowTitle(QApplication::translate("TimeSeriesPicker", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TimeSeriesPicker", "Variable", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TimeSeriesPicker", "Times ", 0, QApplication::UnicodeUTF8));
        pushButtonSlectAll->setText(QApplication::translate("TimeSeriesPicker", "Select All", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TimeSeriesPicker", "ID", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimeSeriesPicker: public Ui_TimeSeriesPicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESERIESPICKER_H
