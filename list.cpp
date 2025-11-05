#include<iostream>
#include<forward_list>
#include<list>

using namespace std;

auto print_list = [](list<int>l1){
    for(auto i: l1)
        cout<<i<<" ";
    cout<<endl;
};

// auto great = [](int n){return n<2;};

int main()
{

    list<int> l1;
    list<int> l2{40,50,60,70};
    // forward_list<int> fl {1,2,3,4,3,5,6};
    // l1.assign(fl.begin(),fl.end());

    // l1.remove_if([](int n){return n>2;});
    // l1.pop_back();
    // l1.push_back(19);
    // l1.pop_front();
    // l1.push_front(20);
    // l1.remove(3);
    // l1.unique();
    // l1.sort(less<int>());

    // l1.emplace_back(10);
    // l1.emplace_front(100);

    // l1.sort();
    // l1.unique();

    // // l1.merge(l2);
    // auto it = l1.begin();
    // advance(it,2);

    // l1.splice(l1.end(),l2);

    list<int>::const_iterator it = l2.cbegin();
    list<int>::iterator it1 = l2.end();
    

    
    print_list(l1);
    
}