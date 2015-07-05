#include "resultview.h"
#include <QSplitter>
#include <QDebug>
#include <QSizePolicy>
#include <QMenu>
#include <QScrollArea>
ResultView::ResultView(QWidget* parent)
{
    QSplitter* splitter = new QSplitter(this);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setGeometry(QRect(0, 0, 1365,685));
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
    tree->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tree, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenuRequested(QPoint)));
}
void ResultView::onCustomContextMenuRequested(const QPoint& pos) {
    QMenu *menu = new QMenu();
    QAction* closeAction = new QAction(tr("Close"),this);
    connect(closeAction , SIGNAL(triggered()),this,SLOT(closeWidget()));
    menu->addAction(closeAction);
    menu->exec(tree->viewport()->mapToGlobal(pos));
   }

   void ResultView::closeWidget(){
       if (tree->indexOfTopLevelItem(tree->currentItem()->parent())==-1) {
           tree->takeTopLevelItem(tree->currentIndex().row());
           stackedWidget->removeWidget(stackedWidget->currentWidget());
       }else {
           if (tree->currentItem()->parent()->childCount()==1) {
               stackedWidget->removeWidget(stackedWidget->currentWidget());
               tree->takeTopLevelItem(tree->indexOfTopLevelItem(tree->currentItem()->parent()));
           }else {
               tree->currentItem()->parent()->removeChild(tree->currentItem());
               stackedWidget->removeWidget(stackedWidget->currentWidget());
           }

       }
       reindex();
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

void ResultView::reindex(){
    map.clear();
    int idx = 0;
    for (int i = 0; i < tree->topLevelItemCount(); ++i) {

        int ch = tree->topLevelItem(i)->childCount();
        if (ch>0) {
            for (int j = 0; j < ch; ++j) {
                qDebug()<<indexGenerator(i,j);
                map.insert(indexGenerator(i,j),stackedWidget->widget(idx));
                idx++;
            }
        }else {
            map.insert(indexGenerator(i),stackedWidget->widget(idx));
            qDebug()<<indexGenerator(i);
            idx++;
        }
    }

}

