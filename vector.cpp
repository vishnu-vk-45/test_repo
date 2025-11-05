#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int>v,x,y,z;
    auto a = {1,2,3,4};
    v = a;

    vector<int> g;
    // g.reserve(10);
    g = {5,6,7,8,9} ;
    // g.clear();
    // g.erase(g.begin(),g.end());
    g.shrink_to_fit();

    g.insert(g.begin()+2,100);
    // g.emplace(g.begin()+2,100);

    // for(vector<int>::iterator it = g.begin(); it != g.end();)
    // {
    //     if(*it % 2 != 0)
    //         it = g.erase(it);
    //     else
    //         it++;
    // }


    g.shrink_to_fit();
    cout<<g.size()<<" "<<g.capacity();
    cout<<endl;
    g.resize(10);

    auto print_vector_v = [&](){
        for_each(v.begin(),v.end(),[](auto x){cout<<x<<" ";});
    };
    auto print_vector_x = [&](){
        for_each(g.begin(),g.end(),[](auto x){cout<<x<<" ";});
    };

    // x = move(v);
    // y.assign(5,'a');
    // y.assign('a','b','c','d');
    

    // print_vector_x();
    // cout<<endl;

    // g.resize(5);
    print_vector_x();
    cout<<endl;

    // cout<<x[1];
    // cout<<x.front()<<" "<<x.back();
    //cout<<boolalpha<<x.empty();
    // cout<<v.size()<<" "<<v.capacity()<<" "<<x.size()<<" "<<x.capacity()<<endl;
    // cout<<g.size()<<" "<<g.capacity()<<endl;
    // cout<<uppercase<<hex<<g.max_size();

    
    // g.swap(v);
    // print_vector_x();
    // cout<<endl;
    // print_vector_v();
    while(not g.empty())
    {
        g.pop_back();
        print_vector_x();
        cout<<endl;
        
    }
    
    cout<<endl;

}