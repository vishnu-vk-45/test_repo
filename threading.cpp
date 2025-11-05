#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

bool isTrue = false;

void foo()
{
    // cout<<"thread id: "<<this_thread::get_id()<<endl;
    // while(!isTrue)
    // {
    //     cout<<"Waiting\n";
    //     this_thread::sleep_for(1s);
    // }
}

void foo1()
{
    // while(!isTrue)
    // {
    //     cout<<"Verde\n";
    //     this_thread::sleep_for(1s);
    // }

}


int main()
{
    thread worker(foo);
    thread worker1(foo1);
    
    cout<<"thread1 id: "<<worker.get_id()<<endl;
    cout<<"thread2 id: "<<worker1.get_id()<<endl;

    this_thread::sleep_for(1s);

    // swap(worker,worker1);
    worker.swap(worker1);

    cout<<"thread1 id: "<<worker.get_id()<<endl;
    cout<<"thread2 id: "<<worker1.get_id()<<endl;

    cin.get();
    // worker.detach();
    // cout<<"Is joinable:(worker.joinable()?"Yes":"No")<<endl;
    isTrue = true;
    

    worker.join();
    worker1.join();

    
    // cout<<"thread id upon exit: "<<worker.get_id()<<endl;

}