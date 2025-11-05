#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex m;
int a{};

void foo(int id)
{
    unique_lock<mutex>ul(m);
    // ul.lock();
    for(int i=0;i<10;i++)
    {
        ++a;
        cout<<id<<": "<<a<<endl;
    }
    // ul.unlock();
}


void foo1(int id)
{
    unique_lock<mutex>ul(m,defer_lock);
    ul.lock();
    ul.try_lock_for(2s);
    for(int i=0;i<10;i++)
    {
        ++a;
        cout<<id<<": "<<a<<endl;
    }
    ul.unlock();
}


int main()
{
    thread worker1(foo,1);
    thread worker2(foo,2);

    worker1.join();
    worker2.join();
}