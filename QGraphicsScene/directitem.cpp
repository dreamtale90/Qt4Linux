#include "directitem.h"
#include <QPainter>
#include <QDebug>

DirectItem::DirectItem(QObject *parent)
    :QObject(parent)
{
    m_pic.load(":/img/power.png");
    startTimer(2);
    flag=right;
}

void DirectItem::setMostUpLeft(const QPoint data)
{
    mostUpLeft=data;
}

void DirectItem::setMostDownLeft(const QPoint data)
{
    mostDownLeft=data;
}

void DirectItem::setMostUpRight(const QPoint data)
{
    mostUpRight=data;
}

void DirectItem::setMostDownRight(const QPoint data)
{
    mostDownRight=data;
}

void DirectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),m_pic);
}

QRectF DirectItem::boundingRect() const
{
    qreal adjust =2;
    return QRectF(-m_pic.width()/2-adjust,-m_pic.height()/2-adjust,m_pic.width()+adjust*2,m_pic.height()+adjust*2);
}

void DirectItem::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    if(this->pos().x()>=mostUpLeft.x()&&this->pos().x()<=mostUpRight.x()&&flag==right){
        this->setPos(pos().x()+1,pos().y());
        if(pos().x()==mostUpRight.x()){
            flag=down;
        }
    }
    else if(this->pos().y()>=mostUpRight.y()&&this->pos().y()<=mostDownRight.y()&&flag==down){
        this->setPos(pos().x(),pos().y()+1);
        if(pos().y()==mostDownLeft.y()){
            flag=left;
        }
    }
    else if(this->pos().x()-1<=mostDownRight.x()&&this->pos().x()>=mostDownLeft.x()&&flag==left){
        this->setPos(pos().x()-1,pos().y());
        if(pos().x()==mostDownLeft.x()){
            flag=up;
        }
    }
    else if(flag==up){
        setPos(pos().x(),pos().y()-1);
        if(pos().y()==mostUpLeft.y()){
            flag=right;
        }
    }
}
