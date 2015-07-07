#include "moranplugins.h"
#include "dialog.h"

QString MoranPLugins::getPluginTittle() const{

    return "Moran I";
}

QString MoranPLugins::getPluginType() const{
    return "Analysis";
}
void MoranPLugins::runPluginDialog(VariableView *vv, ResultView *result, RInside &rconn,QWidget* parent) const{
  Dialog* mydialog = new Dialog(vv,result,rconn,parent);
  mydialog->show();
}

void MoranPLugins::addResultDialog(QStackedWidget *widget, QAction *action) const{
  MoranPLugins::widget = widget;
  MoranPLugins::action = action;
}

QStackedWidget* MoranPLugins::widget;
QAction* MoranPLugins::action;

void MoranPLugins::showResultDialog(){
    widget->setCurrentIndex(3);
    action->setVisible(true);
}

QT_BEGIN_NAMESPACE
//! [9]

Q_EXPORT_PLUGIN2(klg_moranplugins, MoranPLugins)

//! [9]
QT_END_NAMESPACE
