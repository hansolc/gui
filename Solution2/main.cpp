#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    cout << "a";
    w.show();
    cout << "b";
    return a.exec();
}
