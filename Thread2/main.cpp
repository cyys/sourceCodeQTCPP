#include <QCoreApplication>
#include<QThread>
#include"threadg2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadG2 work;
    QThread thread;
    work.moveToThread(&thread);
    QObject::connect(&work,&ThreadG2::startTask,&work,&ThreadG2::doTask);
    QObject::connect(&work,&ThreadG2::endTask,&thread,&QThread::quit);
    QObject::connect(&thread,&QThread::finished,&work,&ThreadG2::stopTask);
    thread.start();
    work.startWork();

    return a.exec();
}

