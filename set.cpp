#include<iostream>
#include<set>
#include<array>
#include<vector>

using namespace std;

int main()
{
    array<int,5> arr{1,2,2,3,3};
    vector<char> v{'a','a','b','e','e'};

    set<char,greater<int>>s1 = {v.begin(),v.end()};

    set<char>::iterator it {s1.begin()};

    for(auto i: s1)
        cout<<i<<" ";
    cout<<endl;

    s1.clear();

    s1.insert('c');
    s1.emplace('d');
    s1.erase('d');

    

    for(auto i: s1)
        cout<<i<<" ";
    cout<<endl;

    cout<<s1.contains('d');
    
}