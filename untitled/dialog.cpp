#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Dialog::close);
}

Dialog::~Dialog()
{
    delete ui;
}





void Dialog::p(){
//void Dialog::on_pushButton_clicked(){
    cout<<"=================++++++++++++++++++========"<<endl;
}

