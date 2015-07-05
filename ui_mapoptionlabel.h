/********************************************************************************
** Form generated from reading UI file 'mapoptionlabel.ui'
**
** Created: Sat 4. Jul 14:10:40 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPTIONLABEL_H
#define UI_MAPOPTIONLABEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapOptionLabel
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget_2;
    QWidget *textPage;
    QLabel *label_9;
    QLabel *label_16;
    QComboBox *comboBox_2;
    QLabel *label_17;
    QComboBox *comboBox_3;
    QLabel *label_18;
    QSpinBox *spinBox;
    QLabel *label_19;
    QComboBox *comboBox_4;
    QLabel *label_20;
    QSlider *horizontalSlider_2;
    QLabel *label_21;
    QComboBox *comboBox_5;
    QSplitter *splitter_31;
    QSplitter *splitter_29;
    QLabel *label_23;
    QSpinBox *spinBox_2;
    QSplitter *splitter_30;
    QLabel *label_24;
    QSpinBox *spinBox_3;
    QLabel *label_22;
    QWidget *formatingPage;
    QLabel *label_10;
    QLabel *label_30;
    QCheckBox *checkBox_2;
    QLabel *label_31;
    QSpinBox *spinBox_4;
    QLabel *label_32;
    QComboBox *comboBox_9;
    QLabel *label_33;
    QSpinBox *spinBox_5;
    QWidget *bufferPage;
    QLabel *label_11;
    QCheckBox *checkBox_3;
    QSpinBox *spinBox_13;
    QLabel *label_34;
    QLabel *label_36;
    QSlider *horizontalSlider_3;
    QLabel *label_35;
    QComboBox *comboBox_11;
    QWidget *backgroundPage;
    QLabel *label_12;
    QCheckBox *checkBox_4;
    QLabel *label_38;
    QComboBox *comboBox_12;
    QLabel *label_39;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QLabel *label_40;
    QSlider *horizontalSlider_4;
    QLabel *label_41;
    QComboBox *comboBox_13;
    QLabel *label_42;
    QComboBox *comboBox_14;
    QLabel *label_43;
    QSpinBox *spinBox_8;
    QWidget *shadowPage;
    QLabel *label_13;
    QCheckBox *checkBox_5;
    QLabel *label_37;
    QComboBox *comboBox_15;
    QLabel *label_44;
    QSpinBox *spinBox_10;
    QLabel *label_45;
    QSpinBox *spinBox_11;
    QLabel *label_46;
    QSlider *horizontalSlider_5;
    QLabel *label_47;
    QSpinBox *spinBox_9;
    QLabel *label_48;
    QComboBox *comboBox_16;
    QListWidget *listWidget_2;
    QLabel *label_8;
    QLabel *label_29;
    QComboBox *comboBox_8;
    QSplitter *splitter_19;
    QLabel *label_7;
    QTextEdit *textEdit;

    void setupUi(QWidget *MapOptionLabel)
    {
        if (MapOptionLabel->objectName().isEmpty())
            MapOptionLabel->setObjectName(QString::fromUtf8("MapOptionLabel"));
        MapOptionLabel->resize(519, 451);
        gridLayout = new QGridLayout(MapOptionLabel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(MapOptionLabel);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 110, 331, 21));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 110, 31, 21));
        stackedWidget_2 = new QStackedWidget(groupBox_3);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(120, 150, 371, 261));
        textPage = new QWidget();
        textPage->setObjectName(QString::fromUtf8("textPage"));
        label_9 = new QLabel(textPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 0, 91, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);
        label_16 = new QLabel(textPage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 30, 22, 16));
        comboBox_2 = new QComboBox(textPage);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 30, 131, 20));
        label_17 = new QLabel(textPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 58, 24, 16));
        comboBox_3 = new QComboBox(textPage);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(90, 60, 131, 20));
        label_18 = new QLabel(textPage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 90, 19, 16));
        spinBox = new QSpinBox(textPage);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(90, 90, 131, 20));
        label_19 = new QLabel(textPage);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 120, 31, 16));
        comboBox_4 = new QComboBox(textPage);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(90, 120, 131, 20));
        label_20 = new QLabel(textPage);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 150, 66, 16));
        horizontalSlider_2 = new QSlider(textPage);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(90, 150, 261, 19));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_21 = new QLabel(textPage);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 180, 51, 16));
        comboBox_5 = new QComboBox(textPage);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(90, 180, 131, 20));
        splitter_31 = new QSplitter(textPage);
        splitter_31->setObjectName(QString::fromUtf8("splitter_31"));
        splitter_31->setGeometry(QRect(90, 210, 131, 40));
        splitter_31->setOrientation(Qt::Vertical);
        splitter_29 = new QSplitter(splitter_31);
        splitter_29->setObjectName(QString::fromUtf8("splitter_29"));
        splitter_29->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(splitter_29);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        splitter_29->addWidget(label_23);
        spinBox_2 = new QSpinBox(splitter_29);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        splitter_29->addWidget(spinBox_2);
        splitter_31->addWidget(splitter_29);
        splitter_30 = new QSplitter(splitter_31);
        splitter_30->setObjectName(QString::fromUtf8("splitter_30"));
        splitter_30->setOrientation(Qt::Horizontal);
        label_24 = new QLabel(splitter_30);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        splitter_30->addWidget(label_24);
        spinBox_3 = new QSpinBox(splitter_30);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        splitter_30->addWidget(spinBox_3);
        splitter_31->addWidget(splitter_30);
        label_22 = new QLabel(textPage);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 210, 37, 16));
        stackedWidget_2->addWidget(textPage);
        formatingPage = new QWidget();
        formatingPage->setObjectName(QString::fromUtf8("formatingPage"));
        label_10 = new QLabel(formatingPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 0, 131, 16));
        label_10->setFont(font);
        label_30 = new QLabel(formatingPage);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 30, 111, 17));
        checkBox_2 = new QCheckBox(formatingPage);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 130, 161, 22));
        label_31 = new QLabel(formatingPage);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(20, 60, 53, 16));
        spinBox_4 = new QSpinBox(formatingPage);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(90, 60, 111, 20));
        label_32 = new QLabel(formatingPage);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(20, 90, 47, 16));
        comboBox_9 = new QComboBox(formatingPage);
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));
        comboBox_9->setGeometry(QRect(90, 90, 111, 20));
        label_33 = new QLabel(formatingPage);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(40, 160, 69, 16));
        spinBox_5 = new QSpinBox(formatingPage);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(123, 160, 81, 20));
        stackedWidget_2->addWidget(formatingPage);
        bufferPage = new QWidget();
        bufferPage->setObjectName(QString::fromUtf8("bufferPage"));
        label_11 = new QLabel(bufferPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 0, 91, 16));
        label_11->setFont(font);
        checkBox_3 = new QCheckBox(bufferPage);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 30, 151, 22));
        spinBox_13 = new QSpinBox(bufferPage);
        spinBox_13->setObjectName(QString::fromUtf8("spinBox_13"));
        spinBox_13->setGeometry(QRect(110, 60, 81, 22));
        label_34 = new QLabel(bufferPage);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(30, 60, 19, 16));
        label_36 = new QLabel(bufferPage);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(30, 130, 66, 16));
        horizontalSlider_3 = new QSlider(bufferPage);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(110, 130, 241, 20));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_35 = new QLabel(bufferPage);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(30, 100, 25, 16));
        comboBox_11 = new QComboBox(bufferPage);
        comboBox_11->setObjectName(QString::fromUtf8("comboBox_11"));
        comboBox_11->setGeometry(QRect(108, 100, 81, 20));
        stackedWidget_2->addWidget(bufferPage);
        backgroundPage = new QWidget();
        backgroundPage->setObjectName(QString::fromUtf8("backgroundPage"));
        label_12 = new QLabel(backgroundPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 0, 91, 16));
        label_12->setFont(font);
        checkBox_4 = new QCheckBox(backgroundPage);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 30, 151, 22));
        label_38 = new QLabel(backgroundPage);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(30, 60, 30, 16));
        comboBox_12 = new QComboBox(backgroundPage);
        comboBox_12->setObjectName(QString::fromUtf8("comboBox_12"));
        comboBox_12->setGeometry(QRect(110, 60, 121, 20));
        label_39 = new QLabel(backgroundPage);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(30, 90, 53, 16));
        spinBox_6 = new QSpinBox(backgroundPage);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(110, 90, 61, 20));
        spinBox_7 = new QSpinBox(backgroundPage);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(180, 90, 51, 20));
        label_40 = new QLabel(backgroundPage);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(30, 120, 66, 16));
        horizontalSlider_4 = new QSlider(backgroundPage);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(113, 120, 231, 19));
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        label_41 = new QLabel(backgroundPage);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(30, 150, 40, 16));
        comboBox_13 = new QComboBox(backgroundPage);
        comboBox_13->setObjectName(QString::fromUtf8("comboBox_13"));
        comboBox_13->setGeometry(QRect(110, 150, 121, 20));
        label_42 = new QLabel(backgroundPage);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(30, 180, 60, 16));
        comboBox_14 = new QComboBox(backgroundPage);
        comboBox_14->setObjectName(QString::fromUtf8("comboBox_14"));
        comboBox_14->setGeometry(QRect(110, 180, 121, 20));
        label_43 = new QLabel(backgroundPage);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(30, 210, 63, 16));
        spinBox_8 = new QSpinBox(backgroundPage);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(110, 210, 121, 20));
        stackedWidget_2->addWidget(backgroundPage);
        shadowPage = new QWidget();
        shadowPage->setObjectName(QString::fromUtf8("shadowPage"));
        label_13 = new QLabel(shadowPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 0, 101, 16));
        label_13->setFont(font);
        checkBox_5 = new QCheckBox(shadowPage);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(10, 30, 161, 22));
        label_37 = new QLabel(shadowPage);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(30, 60, 56, 16));
        comboBox_15 = new QComboBox(shadowPage);
        comboBox_15->setObjectName(QString::fromUtf8("comboBox_15"));
        comboBox_15->setGeometry(QRect(110, 60, 91, 20));
        label_44 = new QLabel(shadowPage);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(30, 90, 31, 16));
        spinBox_10 = new QSpinBox(shadowPage);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setGeometry(QRect(110, 90, 91, 20));
        label_45 = new QLabel(shadowPage);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(30, 120, 50, 16));
        spinBox_11 = new QSpinBox(shadowPage);
        spinBox_11->setObjectName(QString::fromUtf8("spinBox_11"));
        spinBox_11->setGeometry(QRect(110, 120, 91, 20));
        label_46 = new QLabel(shadowPage);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(30, 150, 66, 16));
        horizontalSlider_5 = new QSlider(shadowPage);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setGeometry(QRect(110, 150, 241, 20));
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        label_47 = new QLabel(shadowPage);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(30, 180, 25, 16));
        spinBox_9 = new QSpinBox(shadowPage);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setGeometry(QRect(110, 180, 91, 20));
        label_48 = new QLabel(shadowPage);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(30, 210, 25, 16));
        comboBox_16 = new QComboBox(shadowPage);
        comboBox_16->setObjectName(QString::fromUtf8("comboBox_16"));
        comboBox_16->setGeometry(QRect(110, 210, 91, 20));
        stackedWidget_2->addWidget(shadowPage);
        listWidget_2 = new QListWidget(groupBox_3);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(20, 150, 101, 261));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 110, 22, 16));
        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(20, 20, 95, 16));
        comboBox_8 = new QComboBox(groupBox_3);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setGeometry(QRect(130, 20, 69, 20));
        splitter_19 = new QSplitter(groupBox_3);
        splitter_19->setObjectName(QString::fromUtf8("splitter_19"));
        splitter_19->setGeometry(QRect(20, 50, 58, 16));
        splitter_19->setOrientation(Qt::Vertical);
        label_7 = new QLabel(splitter_19);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        splitter_19->addWidget(label_7);
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 50, 361, 51));

        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);


        retranslateUi(MapOptionLabel);

        stackedWidget_2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MapOptionLabel);
    } // setupUi

    void retranslateUi(QWidget *MapOptionLabel)
    {
        MapOptionLabel->setWindowTitle(QApplication::translate("MapOptionLabel", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MapOptionLabel", "Label", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MapOptionLabel", "set", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MapOptionLabel", "Text Style", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MapOptionLabel", "Font", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MapOptionLabel", "Style", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MapOptionLabel", "Size", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MapOptionLabel", "Colour", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MapOptionLabel", "Transparency", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MapOptionLabel", "Type Case", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MapOptionLabel", "Letter", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MapOptionLabel", "word", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MapOptionLabel", "Spacing", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MapOptionLabel", "Text Formatting", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MapOptionLabel", "Multiple Line", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MapOptionLabel", "Formatted number", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MapOptionLabel", "Line Height", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MapOptionLabel", "Alignment", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MapOptionLabel", "Decimal places", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MapOptionLabel", "Text Buffer", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MapOptionLabel", "Draw text buffer", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MapOptionLabel", "Size", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MapOptionLabel", "Transparency", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MapOptionLabel", "Color", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MapOptionLabel", "Background", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("MapOptionLabel", "Draw Background", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MapOptionLabel", "Shape", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MapOptionLabel", "Offset X, Y", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MapOptionLabel", "Transparency", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MapOptionLabel", "Fill Color", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MapOptionLabel", "Border Color", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MapOptionLabel", "Border Width", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MapOptionLabel", "Drop Shadow", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MapOptionLabel", "Draw drop shadow", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MapOptionLabel", "Draw under", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("MapOptionLabel", "Offset", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MapOptionLabel", "Blur radius", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("MapOptionLabel", "Transparency", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("MapOptionLabel", "Scale", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("MapOptionLabel", "Color", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MapOptionLabel", "Text", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MapOptionLabel", "Formating", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MapOptionLabel", "Buffer", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_2->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MapOptionLabel", "Background", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_2->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MapOptionLabel", "Shadow", 0, QApplication::UnicodeUTF8));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        label_8->setText(QApplication::translate("MapOptionLabel", "Text", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MapOptionLabel", "Label this layer with", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MapOptionLabel", "Text sample", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapOptionLabel: public Ui_MapOptionLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPTIONLABEL_H
