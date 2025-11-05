#include<set>
#include<iostream>
#include<vector>

using namespace std;

auto print_set =[](multiset<int>s1){
    for(auto i: s1)
        cout<<i<<" ";
    cout<<endl;
};


int main()
{
    vector<int>v {1,1,3,4,2,3,4,5,6};
    multiset<int> s1{v.begin(),v.end()};

    print_set(s1);

    s1.emplace_hint(s1.begin(),10);
    s1.erase(10);

    print_set(s1);

    // cout<<s1.count(1);
    auto it = s1.find(10);
    if(it != s1.end())
        cout<<"Found";
    else
        cout<<"Not found";
    
}