#ifndef RESULTVIEW_H
#define RESULTVIEW_H
#include <resultviewitem.h>
#include<QWidget>
#include<QTreeWidget>
#include<variableview.h>
#include <QStackedWidget>
#include <QMap>
#include <resultindex.h>

class ResultView : public QWidget
{
    Q_OBJECT
public:
    ResultView(QWidget* parent=0);
    VariableView* vv;

    ~ResultView();
    void setResultViewItem(ResultViewItem* item);
private:
    QTreeWidget* tree;
    QStackedWidget* stackedWidget;
    QString indexGenerator(int ridx , int cidx);
    QString indexGenerator(int ridx);
    void iterateTreeItems(QStringList listItem, QList<QWidget*> listWidget, QTreeWidgetItem* root);
     QMap <QString ,QWidget*> map;
private slots :
   void changeStacketWidget(QTreeWidgetItem* item ,int col);

};

#endif // RESULTVIEW_H
