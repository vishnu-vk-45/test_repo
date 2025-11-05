#include<iostream>
#include<array>
#include<forward_list>
using namespace std;

int main()  
{
    forward_list list1{1,2,3,4,5};
    forward_list list2{10,9,6,8};
    
    // list1.emplace_front(6);
    // array arr {11,12,13};
    // list1.assign(arr.begin(),arr.end());

    // cout<<list1.front();
    
    // cout<<list1.max_size();

    // list1.pop_front();

    // list1.insert_after(list1.begin(),3,9);
    list1.sort(greater<int>());
    list2.sort();
    list1.merge(list2);
    
    // list1.remove_if([](int n){return n>5;});

    // cout<<"elements removed: "<<count1<<endl;


    for(auto i: list1)
    cout<<i<<" ";
    cout<<endl;

    

    // for(auto i: list2)
    // cout<<i<<" ";
    // cout<<endl;
}