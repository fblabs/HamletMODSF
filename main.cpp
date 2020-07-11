#include "mainwindow.h"
#include <QApplication>
#define QT_NO_DEBUG_OUTPUT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    a.setApplicationName("hamlet MOD SF");
    a.setApplicationVersion("2.8.0");
    a.setOrganizationName("FBLABS");

    w.show();
    return a.exec();
}
