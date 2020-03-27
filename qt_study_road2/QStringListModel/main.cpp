#include "MyListView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyListView view;
    view.show();

    return app.exec();
}
