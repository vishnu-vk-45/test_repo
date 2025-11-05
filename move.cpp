#include<iostream>
#include<utility>
using namespace std;

template<typename T>
void swapT(T& a, T& b)
{
    T temp{move(a)};
    a = move(b);
    b = move(temp);
}

int main()
{
    string a = "Hello";
    string b = "Vishnu";

    swapT(a,b);

    cout<<a<<" "<<b;
}