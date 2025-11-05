#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mutex_obj;

int a = 10;
int b = 10;
bool isTrue = true;

void foo()
{
    while(isTrue)
    {
        this_thread::sleep_for(2s);
        if(mutex_obj.try_lock())
        {
            ++a;
            cout<<"Inside try_lock foo: "<<a<<endl;
            mutex_obj.unlock();
            isTrue = false;
        }
    
        else
        {
            ++b;
            cout<<"b foo: "<<b<<endl;
        }
    }
}

void goo()
{
        mutex_obj.lock();
        ++a;
        cout<<"Inside lock goo: "<<a<<endl;
        this_thread::sleep_for(6s);
        mutex_obj.unlock();

}

int main()
{
    thread worker(foo);
    thread worker1(goo);

    cin.get();
    

    worker.join();
    worker1.join();
}