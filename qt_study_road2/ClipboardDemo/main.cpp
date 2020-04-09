#include "ClipboardDemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ClipboardDemo demo;
    demo.show();

    return app.exec();
}
