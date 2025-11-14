#include<iostream>
#include<cstring>
#include<array>
#include<algorithm>
using namespace std;



 

int main()
{
    // using loop = array<int,4>;
    array<int,4> arr{1,2,3,4};
    array a{8,3,4,5};

    sort(a.begin(),a.end(),greater<int>());
    for_each(a.begin(),a.end(),[](int x){cout<<x<<" ";});

    array <int,2>b{1};
    b.fill(1);
    for_each(b.begin(),b.end(),[](int x){cout<<x<<" ";});

    
    // cout<<arr.front()<<endl;
    // cout<<arr.back();

    // cout<<arr.size();
    // auto p = arr.data();
    // for(int i=0;i<arr.size()-1;i++)
    // {
    //     cout<<p[i]<<" ";
    // }
    
    
    sort(arr.begin(),arr.end(),[](int a,int b){return a<b;});
    
    
    // cout<<boolalpha<<arr.empty();
    // cout<<arr.max_size()<<" "<<arr.size();
    
    arr.swap(a);
    for_each(arr.begin(),arr.end(),[](int x){cout<<x<<" ";});
    for_each(a.begin(),a.end(),[](int x){cout<<x<<" ";});

    // cout<<get<5>(a);

    auto p = arr.begin();
    cout<<p[1];
    
}
