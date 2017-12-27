#include "mp.h"
#include<QDebug>
#include<QTextCodec>
#include<QString>
#include<QStringList>
Mp::Mp(QObject *parent) : QObject(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
        qDebug()<<QObject::tr("构造。。。。。")<<endl;
}

void Mp::run(QString name,QStringList args,int model){
    if(model==0)
        myPross.start(name);
    else
        myPross.start(name,args);
    connect(&myPross,SIGNAL(readyRead())
                      ,this,SLOT(showResult()));
    connect(&myPross,&QProcess::stateChanged,
                    this,&Mp::showState);
    connect(&myPross,SIGNAL(error(QProcess::ProcessError)),
                    this,SLOT(showError(QProcess::ProcessError)));
    connect(&myPross,SIGNAL(finished(int,QProcess::ExitStatus))
            ,this,SLOT(showFinish(int,QProcess::ExitStatus)));


}

void Mp::showResult(){
    qDebug()<<QObject::tr("结果:")
            <<QString(myPross.readAll())<<endl;
}

void Mp::showState(QProcess::ProcessState state){
    qDebug()<<QObject::tr("**运行状态:");
    if(state==QProcess::NotRunning)
        qDebug()<<QObject::tr("结束运行**");
    else if(state==QProcess::Starting)
        qDebug()<<QObject::tr("正在开启**");
    else
        qDebug()<<QObject::tr("运行中**");
}

void Mp::showError(QProcess::ProcessError error){
    qDebug()<<QObject::tr("运行出错：")<<
              myPross.errorString()
            <<QObject::tr("错误：")<<error;
}


void Mp::showFinish(int exitCode, QProcess::ExitStatus exitStatus){
    qDebug()<<QObject::tr("运行结束：")
           <<exitCode<<"  "
           <<QObject::tr("退出状态：")<<exitStatus;
}
