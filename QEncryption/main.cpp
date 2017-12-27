#include <QCoreApplication>
#include<QDebug>
#include<QCryptographicHash>
#include<QTextStream>
#include<QFile>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QChar ch('3');
    qDebug()<<ch;
    QTextStream out(stdout,QIODevice::WriteOnly);

    out<<"==========================="<<endl;


    QString text="1234";
    QString md5;
    QByteArray bt;
    bt.append(text);

    bt=QCryptographicHash::hash(bt,QCryptographicHash::Md5);
    md5.append(bt.toHex());

    out<<md5<<"  "<<md5.length()<<"   "<<bt.toHex().toUpper()<<endl;

    QCryptographicHash md(QCryptographicHash::Md5);
    bt.clear();
    bt.append(text);
    md.addData(bt);
    bt=md.result();
    md5.clear();
    md5.append(bt.toHex());
    qDebug()<<md5;


   QCryptographicHash md1(QCryptographicHash::Sha224);
   bt=QByteArray();
   bt.append(text);
   md1.addData(bt);
   bt=md1.result();
   md5=QString();
   md5.append(bt.toHex());
   out<<md5<<endl;

   //===================================================

//   QFile file("c:\\t.txt");
   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
//   if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
//       QTextStream out2(&file);
//       out2<<QObject::tr("京东快递0000AAAA")<<endl;
//       out2.flush();
//       file.close();

//   }

    QFile file1("c:\\t.txt");
    bool flag=file1.open(QIODevice::ReadOnly|QIODevice::Text);
    out<<flag<<endl;
    if(flag){
        QTextStream read2(&file1);
        QString txt;
        txt=read2.readLine();
        file1.close();
        out<<txt<<endl;

    }else{
        out<<"================"<<endl;
    }

    QTextEncoder encode(QTextCodec::codecForName("GBK"));
    QByteArray ba= encode.fromUnicode("k哈哈哈11");

    QString trp(ba);
    out<<trp<<endl;

    QTextDecoder decode(QTextCodec::codecForName("GBK"));
    trp=decode.toUnicode(ba);
    out<<trp<<endl;

    return a.exec();
}

