#include <QThread>
#include <QTimer>

//重写线程类中的run函数
class myThread: public QThread
{
    Q_OBJECT

public:
    myThread(int id);
    void run();

private slots:
    void timeout();

protected:
    QTimer* m_pTimer = NULL;
    int m_index;
};
