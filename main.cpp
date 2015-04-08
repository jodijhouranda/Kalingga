#include "mainwindow.h"
#include <QApplication>
#
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RInside R(argc,argv);
    MainWindow m(R);
    m.show();

    return a.exec();
}
