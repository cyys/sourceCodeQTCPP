#include <QCoreApplication>

#include<QDebug>
//#include<QStringList>
//#include<QString>
//#include<QStringBuilder>
#include<QtSql/QSqlDatabase>
#include<QLibrary>
#include<QtSql/QSqlQuery>
#include<QDateTime>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QStringList drivers= QSqlDatabase::drivers();
    foreach(QString s,drivers){
        qDebug()<<s;
    }

    //QString path="D:\\CYYS\\QTCreator\\5.5\\Src\\qtbase\\src\\plugins\\sqldrivers\\oci.dll";
    //QString path="E:\\Oracle\\app\\oracle\\product\\10.2.0\\server\\BIN\\oci.dll";

   // QLibrary lib(path);
   // lib.load();
    //qDebug()<<lib.isLoaded();

    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("oracle");
    db.setHostName("localhhost");
    db.setPort(1521);
    db.setUserName("system");
    db.setPassword("cy198612072100");
    if(!db.open()){
        qDebug()<<"====================";
    }

QSqlQuery q;
q.exec("select sysdate from dual");
    q.next();
    QDateTime aw=q.value(0).toDateTime();
    qDebug()<<aw.toString("yyyy-MM-dd HH:mm:ss");

    QStringList list;
    list.push_back("1111");
    list.push_back("22222");
    list.push_back("33333");
    //qDebug()<<list.back();



    foreach(QString s,list){
        qDebug()<<s;
    }


bool isSuccess=q.exec("create table QSqlQuery(name varchar(22))");
qDebug()<<isSuccess;


//lib.unload();
    db.close();
    return a.exec();
}

