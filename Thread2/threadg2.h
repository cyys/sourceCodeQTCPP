#ifndef THREADG2_H
#define THREADG2_H
#include<QObject>

class ThreadG2:public QObject
{
    Q_OBJECT
public:
    ThreadG2();
    void startWork();
signals:
    void startTask();
    void endTask();
public  slots:
    void doTask();
   void stopTask();

};

#endif // THREADG2_H
