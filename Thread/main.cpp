#include <QCoreApplication>
#include"threadG.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ThreadG *t=new ThreadG;
    t->start();

    ThreadG *t1=new ThreadG;
    t1->start();
//for(int k=0;k<100000;k++){
//    cout<<k<<"+++++++++"<<endl;
//}
    return a.exec();
}

