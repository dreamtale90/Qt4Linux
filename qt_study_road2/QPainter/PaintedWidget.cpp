#include "PaintedWidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPicture>

PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(800, 600);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
#if 0
    QPainter painter(this);
    painter.drawLine(80, 100, 650, 500);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);

    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

    QBrush brush(gradient);
    //brush.setStyle(Qt::SolidPattern);
    //brush.setStyle(Qt::Dense1Pattern);
    //brush.setStyle(Qt::Dense2Pattern);
    //brush.setStyle(Qt::Dense3Pattern);
    //brush.setStyle(Qt::Dense4Pattern);
    //brush.setStyle(Qt::Dense5Pattern);
    //brush.setStyle(Qt::Dense6Pattern);
    //brush.setStyle(Qt::Dense7Pattern);
    //brush.setStyle(Qt::CrossPattern);
    //brush.setStyle(Qt::TexturePattern);
    painter.setBrush(brush);
    painter.drawEllipse(50, 150, 400, 200);
        QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    QLinearGradient linearGradient(60, 50, 200, 200);
    linearGradient.setColorAt(0.2, Qt::white);
    linearGradient.setColorAt(0.6, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawRect(10, 10, 300, 400);
    painter.drawEllipse(50, 50, 200, 150);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int r = 150;
    QConicalGradient conicalGradient(0, 0, 0);

    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

    painter.translate(r, r);

    QBrush brush(conicalGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(0, 0), r, r);

        QPainter painter(this);
    painter.fillRect(10, 10, 50, 100, Qt::red);
    painter.save();
    painter.translate(100, 0); // 向右平移 100px
    painter.fillRect(10, 10, 50, 100, Qt::yellow);
    painter.restore();
    painter.save();
    painter.translate(300, 0); // 向右平移 300px
    painter.rotate(30); // 顺时针旋转 30 度
    painter.fillRect(10, 10, 50, 100, Qt::green);
    painter.restore();
    painter.save();
    painter.translate(400, 0); // 向右平移 400px
    painter.scale(2, 3); // 横坐标单位放大 2 倍，纵坐标放大 3 倍
    painter.fillRect(10, 10, 50, 100, Qt::blue);
    painter.restore();
    painter.save();
    painter.translate(600, 0); // 向右平移 600px
    painter.shear(0, 1); // 横向不变，纵向扭曲 1 倍
    painter.fillRect(10, 10, 50, 100, Qt::cyan);
    painter.restore();
#endif
//    QPainter painter(this);
//    //painter.setWindow(0, 0, 200, 200);
//
//    //painter.translate(200, 200);
//    //painter.setWindow(-160, -320, 320, 640);
//    //painter.fillRect(0, 0, 200, 200, Qt::red);
//    painter.setViewport(0, 0, 200, 200);
//    painter.fillRect(0, 0, 200, 200, Qt::red);
//
//painter.setViewport(0, 0, 400, 400);
//painter.fillRect(0, 0, 200, 200, Qt::red);
//
//painter.setViewport(0, 0, 200, 200);
//painter.fillRect(0, 0, 200, 200, Qt::green);
QPicture picture;
//painter.drawEllipse(10, 20, 80, 70); // 绘制一个椭圆
picture.load("./drawing.pic");
QPainter painter;
painter.begin(this);             // 在 picture 进行绘制
painter.drawPicture(0, 0, picture);
painter.end();                       // 绘制完成
//picture.save("drawing.pic");         // 保存 picture
}
