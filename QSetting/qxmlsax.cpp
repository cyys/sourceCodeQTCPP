#include "qxmlsax.h"
#include<QDebug>

QXmlSax::QXmlSax()
{

}

bool QXmlSax::characters(const QString &s){
    list.push_front(s);

    qDebug()<<"";
    //qDebug()<<"==="<<list;

}

