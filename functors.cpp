#include<iostream>

using namespace std;

class Increment
{
    private:
        int num;
    public:
        Increment(int a)
            :num{a}{}

        int operator()(int x){return x+num;};

};

