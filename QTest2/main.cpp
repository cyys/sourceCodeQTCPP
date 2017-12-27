#include "dialog.h"
#include <QApplication>
#include<QColorDialog>
#include<QMessageBox>
#include<QWizardPage>
#include<QWidget>
#include<QLabel>
#include<QHBoxLayout>
#include<QStatusBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    w.show();
//    QColorDialog c;/* QColorDialog c;*/
c.show();
QWidget *q=new QWidget;
q->show();

QLabel la;
la.setText(QObject::tr("============================="));
la.show();

QHBoxLayout lay;
lay.addWidget(&w);


QMessageBox::about(NULL,QObject::tr("s dd等等"),QObject::tr("waewaefa考文科女"));

    return a.exec();
}
