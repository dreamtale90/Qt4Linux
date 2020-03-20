#include <QApplication>
#include <QLabel>
#include <QPainter>
#include <QPixmap>

#if 0
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QLabel *label = new QLabel();
    QPixmap *pixmap = new QPixmap(argv[1]);
    label->setPixmap(0, 0, *pixmap);

    label->show();
    return app.exec();
}
#endif
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 300, 300);
    scene.addLine(0, 0, 150, 150);

    QGraphicsView view(&scene);
    view.setWindowTitle("Graphics View");
    //view.resize(500, 500);
    view.show();

    return app.exec();
}
