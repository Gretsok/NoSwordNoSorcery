#include "mainwindow.h"

#include <QApplication>
#include <dungeongenerator.h>
#include <dungeonview2d.h>

int main(int argc, char *argv[])
{
    DungeonGenerator dungeonGenerator;

    QApplication a(argc, argv);
    DungeonView2D dungeonView;

    MainWindow w;

    w.show();
    a.exec();


    return 0;
}
