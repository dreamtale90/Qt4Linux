#ifndef DIRECTITEM_H
#define DIRECTITEM_H

#include <QObject>
#include <QPoint>
#include <QGraphicsItem>
#include <QPixmap>

#define Direction int

class DirectItem:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    enum{up,down,left,right};
    DirectItem(QObject *parent=0);

    void setMostUpLeft(const QPoint data);
    void setMostDownLeft(const QPoint data);
    void setMostUpRight(const QPoint data);
    void setMostDownRight(const QPoint data);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    void timerEvent(QTimerEvent *event);

private:
    QPixmap m_pic;

    //存4个边界左上，左下，右上，右下
    QPoint mostUpLeft,mostDownLeft,mostUpRight,mostDownRight;
    Direction flag;
};

#endif // DIRECTITEM_H
