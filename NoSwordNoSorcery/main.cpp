#include "mainwindow.h"

#include <QApplication>
#include <dungeongenerator.h>

int main(int argc, char *argv[])
{
    DungeonGenerator dungeonGenerator;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
