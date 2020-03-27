#include "MyFileSystemWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyFileSystemWidget view;
    view.show();

    return app.exec();
}
