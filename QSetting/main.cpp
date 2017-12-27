#include <QCoreApplication>
#include<QSettings>
#include<QDebug>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
#include<QtXml/QDomDocument>
#include<QFile>
#include<QXmlSimpleReader>
#include"qxmlsax.h"
#include<QXmlDeclHandler>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings info("C:\\hsrv.txt",QSettings::IniFormat);
    qDebug()<<info.value("test/name").toString()
           <<info.value("test/age").toInt();

    QJsonDocument doc=
    QJsonDocument::fromJson("[1,2,3]");
    QJsonArray arry= doc.array();
    qDebug()<<arry.at(0).toInt();

    QDomDocument doc1;
    QFile file("C:\\web.xml");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"fail";
    }
    doc1.setContent(&file);
   QDomNode node=doc1.firstChild();
   QDomElement e=node.toElement();
   qDebug()<<e.tagName()<<e.text();
   qDebug()<<qPrintable(node.nodeName())<<"  "<<qPrintable(node.nodeValue());
   node=node.toElement().firstChild();
    qDebug()<<qPrintable(node.nodeName())
           <<"  "<<qPrintable(node.nodeValue());
 e=node.toElement();
qDebug()<<e.tagName()<<e.text();

file.close();

QFile file1("C:\\web.xml");
if(!file1.open(QIODevice::ReadOnly)){
    qDebug()<<"fail";
}

    QXmlInputSource in(&file1);
    QXmlSimpleReader read;

    QXmlSax *handle=new QXmlSax;

    read.setContentHandler(handle);
    read.setErrorHandler(handle);
    read.parse(in);

 qDebug()<<"================================";
    foreach (QString s, handle->list) {
    qDebug()<<s;
    }

    qDebug()<<handle->t;

file1.close();


    QDomDocument doc2;
    doc2.setContent(QByteArray("<A>ssssss</A>"));
    qDebug()<<doc2.firstChild().toElement().text();

    return a.exec();
}

