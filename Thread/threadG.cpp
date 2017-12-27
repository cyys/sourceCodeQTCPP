#include "threadG.h"
#include<iostream>
using namespace std;
//#include<QSemaphore>
//QSemaphore semaphore(2);
ThreadG::ThreadG()
{
  cout<<"==========================="<<endl;
}

void ThreadG::run(){
    QMutexLocker mutexLocker(&mutex);
    for(;i<10000;){
        i++;
        if(i%10==0){
            //this->sleep(3);

            cout<<i<<"****************************+++++++++"<<endl;
            waitCondition.wait(&mutex);
        }else{
            waitCondition.wakeAll();
        }
        //semaphore.acquire(1);

        //this->msleep(10);
// mutex.lock();

        cout<<i<<"+++++++++"<<endl;
        //mutex.unlock();
        //semaphore.release();
    }
}
int ThreadG::i=0;






