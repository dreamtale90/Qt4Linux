#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class ElecItem;
class QGraphicsLineItem;
class DirectItem;
class QGraphicsScene;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    ElecItem *m_elecItem;
    DirectItem *m_direcItem;
    QGraphicsLineItem *lineItem1;
    QGraphicsLineItem *lineItem2;
    QGraphicsLineItem *lineItem3;
    QGraphicsLineItem *lineItem4;
    QGraphicsLineItem *lineItem5;
    QGraphicsScene *scene;
};
#endif // WIDGET_H
