#include "mainwindow.h"

#include <QApplication>
#include <dungeongenerator.h>
#include <dungeonview2d.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();
    a.exec();


    return 0;
}
