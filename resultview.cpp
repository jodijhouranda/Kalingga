#include "resultview.h"
#include <QSplitter>
#include <QDebug>
#include <QSizePolicy>

ResultView::ResultView(QWidget* parent)
{
    QSplitter* splitter = new QSplitter(this);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setGeometry(QRect(0, 0, 1365,620));
    splitter->setOrientation(Qt::Horizontal);
    splitter->setHandleWidth(3);
    tree  = new QTreeWidget(this);
    tree->setHeaderLabel("Result List");
    stackedWidget = new QStackedWidget(this);
    stackedWidget->setMinimumWidth(300);
    splitter->addWidget(tree);
    splitter->addWidget(stackedWidget);
    splitter->setStretchFactor(1,1);
   connect(tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(changeStacketWidget(QTreeWidgetItem*,int)));

}

ResultView::~ResultView()
{

}

void ResultView::changeStacketWidget(QTreeWidgetItem* item,int col){
    if (tree->indexOfTopLevelItem(item->parent())==-1) {
        int r = tree->indexOfTopLevelItem(item);
        qDebug() << indexGenerator(r);
        stackedWidget->setCurrentIndex(stackedWidget->indexOf(map[indexGenerator(r)]));
    }else{
        int r = tree->indexOfTopLevelItem(item->parent());
        int c = item->parent()->indexOfChild(item);
        qDebug() << indexGenerator(r,c);
        stackedWidget->setCurrentIndex(stackedWidget->indexOf(map[indexGenerator(r,c)]));
    }

}

void ResultView::setResultViewItem(ResultViewItem* item){
    QTreeWidgetItem* root = new QTreeWidgetItem();
    tree->addTopLevelItem(root);
    root->setText(0,item->getTittle());
    if(item->getTreeList().count()==1){
        int r = tree->indexOfTopLevelItem(root);
        map.insert(indexGenerator(r),item->getResultWidgets().at(0));
        stackedWidget->addWidget(item->getResultWidgets().at(0));
    }else {
        iterateTreeItems(item->getTreeList(),item->getResultWidgets(),root);
    }


}

void ResultView::iterateTreeItems(QStringList listItem, QList<QWidget*> listWidget, QTreeWidgetItem* root){

    for (int i = 0; i < listItem.count(); ++i) {
        QTreeWidgetItem* child = new QTreeWidgetItem();
        child->setText(0,listItem.at(i));
        root->addChild(child);
        int r = tree->indexOfTopLevelItem(root);
        int c = root->indexOfChild(child);
        map.insert(indexGenerator(r,c) , listWidget.at(i));
        stackedWidget->addWidget(listWidget.at(i));
    }
}

QString ResultView::indexGenerator(int ridx, int cidx){
    QString idx = QString::number(ridx) +" "+QString::number(cidx);
    return idx;
}

QString ResultView::indexGenerator(int ridx){
    QString idx = QString::number(ridx);
    return idx;
}
