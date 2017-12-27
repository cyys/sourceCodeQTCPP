#include <QCoreApplication>
#include"html.h"
#include<QHostInfo>
#include<QDebug>
#include<QtNetwork/QtNetWork>
#include<QList>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    Html h;
//    h.accessmanager();
//    Html hl;
//    hl.startRequest();

    QString hostName=QHostInfo::localHostName();
    qDebug()<<hostName;

    QHostInfo hostInfo=QHostInfo::fromName(hostName);


    foreach (QHostAddress a, hostInfo.addresses()) {
        qDebug()<<a;
    }


     QList<QNetworkInterface> allInterfaces
             = QNetworkInterface::allInterfaces();

     foreach (QNetworkInterface i, allInterfaces) {
         qDebug()<<i;
     }

    return a.exec();
}

