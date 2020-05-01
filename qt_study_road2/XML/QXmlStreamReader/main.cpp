// !!! Qt 5
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.readFile("books.xml");
    w.show();

    return app.exec();
}
