#include "widget.h"
#include "ui_widget.h"
#include "elecitem.h"
#include <QGraphicsScene>
#include <QDebug>
#include "directitem.h"
#include <QGraphicsLineItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("CSDN IT1995");
    m_elecItem=new ElecItem;

    scene=new QGraphicsScene;
    scene->setSceneRect(QRectF(0,0,100,100));

    lineItem1=new QGraphicsLineItem;
    lineItem1->setLine(-200,65,m_elecItem->pos().x(),65);
    lineItem1->setPen(QPen(QBrush(QColor("black")),5));
    scene->addItem(lineItem1);

    lineItem2=new QGraphicsLineItem;
    lineItem2->setLine(-200,65,-200,-200);
    lineItem2->setPen(QPen(QBrush(QColor("black")),5));
    scene->addItem(lineItem2);

    lineItem3=new QGraphicsLineItem;
    lineItem3->setLine(-200,-200,200+m_elecItem->getPicWidth(),-200);
    lineItem3->setPen(QPen(QBrush(QColor("black")),5));
    scene->addItem(lineItem3);

    lineItem4=new QGraphicsLineItem;
    lineItem4->setLine(200+m_elecItem->getPicWidth(),-200,200+m_elecItem->getPicWidth(),65);
    lineItem4->setPen(QPen(QBrush(QColor("black")),5));
    scene->addItem(lineItem4);

    lineItem5=new QGraphicsLineItem;
    lineItem5->setLine(200+m_elecItem->getPicWidth(),65,m_elecItem->pos().x()+m_elecItem->getPicWidth(),65);
    lineItem5->setPen(QPen(QBrush(QColor("black")),5));
    scene->addItem(lineItem5);

    scene->addItem(m_elecItem);

    m_direcItem=new DirectItem;
    scene->addItem(m_direcItem);
    m_direcItem->setPos(-200,-200);
    ui->graphicsView->setScene(scene);

    m_direcItem->setMostUpLeft(QPoint(-200,-200));
    m_direcItem->setMostDownLeft(QPoint(-200,65));
    m_direcItem->setMostUpRight(QPoint(200+m_elecItem->getPicWidth(),-200));
    m_direcItem->setMostDownRight(QPoint(200+m_elecItem->getPicWidth(),65));
    startTimer(1);
}

Widget::~Widget()
{
    delete m_elecItem;
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    if(m_direcItem->pos().x()>=m_elecItem->pos().x()
            &&m_direcItem->pos().x()<=m_elecItem->pos().x()+m_elecItem->getPicWidth()
            &&m_direcItem->pos().y()==65){
        m_elecItem->setStatus(true);
    }
    else{
        m_elecItem->setStatus(false);
    }
    scene->update();
}
