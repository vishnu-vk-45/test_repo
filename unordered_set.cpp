#include<iostream>
#include<unordered_set>

using namespace std;


auto print_set =[](unordered_multiset<int>s1){
    for(auto i: s1)
        cout<<i<<" ";
    cout<<endl;
};


int main()
{
    // unordered_set<int>us{1,2,8,3,4,5,4,3};
    unordered_multiset<int>us{1,2,8,3,4,5,4,3};

    print_set(us);

}