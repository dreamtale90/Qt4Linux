#include "elecitem.h"
#include <QPainter>
#include <QDebug>

ElecItem::ElecItem(QObject *parent):
    QObject(parent)
{
    m_currStatus=false;
    m_close.load(":/img/close.png");
    m_open.load(":/img/open.png");

}

ElecItem::~ElecItem()
{

}

int ElecItem::getPicWidth() const
{
    return m_open.width();
}

void ElecItem::setStatus(const bool flag)
{
    m_currStatus=flag;
}


void ElecItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(m_currStatus){
        painter->drawPixmap(0,0,m_open.width(),m_open.height(),m_open);
    }
    else{
        painter->drawPixmap(0,0,m_open.width(),m_open.height(),m_close);
    }
}

QRectF ElecItem::boundingRect() const
{
    return QRectF(this->pos().x()+2,this->pos().y(),m_open.width()-4,m_open.height());
}
