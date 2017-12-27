#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Dialog w;
    //QObject::connect(&w,&Dialog::pppdInof,&w,&Dialog::p);




    w.show();
    w.getInfo();



    return a.exec();
}
