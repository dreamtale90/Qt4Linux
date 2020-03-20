#include "PaintedWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PaintedWidget widget;
    widget.resize(400, 400);
    widget.show();

    return app.exec();
}
