#include <QCoreApplication>
#include <QDebug>
#include "myThread.h"

int main(int argc, char *argv[])
{
    qDebug() << "主线程: " << QThread::currentThreadId();

    myThread *child1 = new myThread(1);
    myThread *child2 = new myThread(2);

    child1->moveToThread(child1);
    //child2->moveToThread(child2);

    child1->start();
    child2->start();

    QCoreApplication app(argc, argv);
    app.exec();

    return 0;
}
