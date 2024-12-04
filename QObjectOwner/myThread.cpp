#include "myThread.h"
#include <QDebug>


myThread::myThread(int id)
{
    m_index = id;
}

//重写线程类中的run函数
void myThread::run()
{
    qDebug() << "myThread" << m_index << " 启动: " << QThread::currentThreadId();;

    if(!m_pTimer) {
        m_pTimer = new QTimer();
        m_pTimer->setInterval(1000);
        connect(m_pTimer, SIGNAL(timeout()), this, SLOT(timeout()));
        m_pTimer->start();
    }

    exec();
}

void myThread::timeout()
{
    qDebug() << "myThread" << m_index << " 定时器: " << QThread::currentThreadId();;
}
