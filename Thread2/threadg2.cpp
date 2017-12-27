#include "threadg2.h"
#include<iostream>
using namespace std;

ThreadG2::ThreadG2()
{

}

void ThreadG2::doTask(){
    for(int k=0;k<5000;k++){
        cout<<k<<"++++"<<endl;
    }
    emit endTask();
}

void ThreadG2::startWork(){
    emit startTask();
}

void ThreadG2::stopTask(){
    for(int k=0;k<5000;k++){
        cout<<k<<"===="<<endl;
    }
}

