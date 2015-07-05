/********************************************************************************
** Form generated from reading UI file 'mapoption.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPTION_H
#define UI_MAPOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QStackedWidget>

QT_BEGIN_NAMESPACE

class Ui_MapOption
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;

    void setupUi(QDialog *MapOption)
    {
        if (MapOption->objectName().isEmpty())
            MapOption->setObjectName(QString::fromUtf8("MapOption"));
        MapOption->resize(696, 501);
        buttonBox = new QDialogButtonBox(MapOption);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 460, 671, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(MapOption);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 121, 441));
        stackedWidget = new QStackedWidget(MapOption);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 10, 531, 441));

        retranslateUi(MapOption);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapOption, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapOption, SLOT(reject()));

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MapOption);
    } // setupUi

    void retranslateUi(QDialog *MapOption)
    {
        MapOption->setWindowTitle(QApplication::translate("MapOption", "Dialog", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MapOption", "General", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MapOption", "Style", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MapOption", "Label", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MapOption", "Default Style", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MapOption: public Ui_MapOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPTION_H
