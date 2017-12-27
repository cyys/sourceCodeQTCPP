#include <QCoreApplication>
#include"mp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mp mp;
    QStringList args;
        //args<<QObject::tr("G:/VS2013常用快捷键.txt");
    args<<QObject::tr("dir");
        mp.run("cmd.exe",args,1);
//        QProcess mp;
//        mp.start("notepad.exe",args);

    return a.exec();
}

