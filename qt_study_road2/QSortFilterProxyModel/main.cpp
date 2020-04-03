#include "MySortView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MySortView view;
    view.show();

    return app.exec();
}
