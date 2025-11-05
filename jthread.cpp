#include<iostream>
#include<thread>

using namespace std;

bool isTrue = false;

void foo(int x)
{
    // cout<<"thread id: "<<this_thread::get_id()<<endl;
    while(!isTrue)
    {
        cout<<x++<<endl;
        this_thread::sleep_for(1s);
    }
}

void foo1()
{
    while(!isTrue)
    {
        cout<<"Verde\n";
        this_thread::sleep_for(1s);
    }

}


int main()
{
    jthread worker1(foo,1);
    cout<<"thread id: "<<worker1.get_id()<<endl;
    
    jthread worker2(foo1);
    cout<<"thread2 id: "<<worker2.get_id()<<endl;

    cin.get();
    isTrue = true;
    
}