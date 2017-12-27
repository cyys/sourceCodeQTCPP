#ifndef QXMLSAX_H
#define QXMLSAX_H
#include<QXmlDefaultHandler>
#include<QString>
#include<QList>

class QXmlSax:public QXmlDefaultHandler
{
public:
    QXmlSax();
    QList<QString> list;
    QString t;
    bool characters(const QString &s);
};

#endif // QXMLSAX_H
