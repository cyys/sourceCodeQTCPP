#include "html.h"
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkRequest>
#include<QDebug>
#include<QTextCodec>
#include<QFile>
#include<QTextStream>
Html::Html(QObject *parent) : QObject(parent)
{
     qDebug()<<"init........................";
}

void Html::accessmanager(QString url){
    manager=new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply *)),
            this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(url)));
    qDebug()<<tr("access开始访问 ")<<url<<(" ........................");
}


void Html::replyFinished(QNetworkReply * reply){
//    QTextCodec * code=QTextCodec::codecForLocale();
    QByteArray ba=reply->readAll();
//    QString all= code->toUnicode(ba);
    reply->deleteLater();
    QFile file("E:\\Documents\\QT_Project\\t.html");
    file.open(QIODevice::WriteOnly);
    file.write(ba);
//    QTextStream out(&file);
//    out<<all;
    file.flush();
    file.close();
//    qDebug()<<all;
    delete manager;
    manager=NULL;
    qDebug()<<tr("access访问结束..");
}

Html::~Html(){
    if(manager!=NULL){
        delete manager;
        manager=NULL;

    }
    if(reply!=NULL){
        delete reply;
        reply=NULL;
    }
}

void Html::startRequest(QString url){
    manager=new QNetworkAccessManager(this);
    reply=manager->get(QNetworkRequest(QUrl(url)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),
            this,SLOT(updateDataProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
    file.setFileName("E:\\Documents\\QT_Project\\q.html");
    file.open(QIODevice::WriteOnly);
    qDebug()<<tr("reply开始访问 ")<<url<<(" ........................");
}

void Html::httpReadyRead(){
    file.write(reply->readAll());
    qDebug()<<tr("reply正在读取数据。。。");
}

void Html::updateDataProgress(qint64 readedSize, qint64 totalSize){
     qDebug()<<tr("reply 已读数据：")<<readedSize
            <<tr("总数据：")<<totalSize;
}

void Html::httpFinished(){
    file.flush();
    file.close();
    reply->deleteLater();
    delete reply;
    reply=NULL;
    delete manager;
    manager=NULL;
    qDebug()<<tr("reply访问结束.....");
}


