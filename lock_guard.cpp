#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
mutex mutex_obj;
int a = 0;

void goo(int id)
{
    lock_guard<mutex> lg(mutex_obj);
    for(int i=0;i<10;i++)
    {
        ++a;
        cout<<id<<": "<<a<<endl;
    }
 
}

int main()
{
    thread worker(goo,1);
    thread worker1(goo,2);
    worker.join();
    worker1.join();
}