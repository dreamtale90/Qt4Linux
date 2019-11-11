#ifndef ELECITEM_H
#define ELECITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>

class ElecItem:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    ElecItem(QObject *parent=0);
    ~ElecItem();
    int getPicWidth()const;
    void setStatus(const bool flag);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;

private:
    QPixmap m_close;
    QPixmap m_open;

    bool m_currStatus;
};

#endif // ELECITEM_H
