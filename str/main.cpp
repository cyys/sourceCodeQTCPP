#include <QCoreApplication>
#include<QString>
#include<QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str="chenying";
    qDebug()<<str.startsWith("chen")
           <<str.endsWith("ying")
          <<str.indexOf("eny")
         <<str.length();

    str=str.append(" are wuhan %1").arg(180).append(" ee");
    qDebug()<<str;
   /* str=*/str.replace("ee","99");
    qDebug()<<str<<str.left(3).right(2);


    return a.exec();
}

