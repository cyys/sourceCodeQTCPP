#ifndef THREADG_H
#define THREADG_H
#include<QThread>
#include<QMutex>
#include<QMutexLocker>
#include<QWaitCondition>

class ThreadG : public QThread
{

public:
    ThreadG();

    void run();
    static int i;

private:
    QMutex mutex;
    QWaitCondition waitCondition;


};

#endif // THREADG_H
