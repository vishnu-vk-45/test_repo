#include<iostream>
#include<memory>
using namespace std;

class Resource
{
    public:
        Resource(){cout<<"Rescource accquired\n";}
        ~Resource(){cout<<"Resource destroyed\n";}
};

int main()
{
    // Resource* res{new Resource};
    auto ptr{make_shared<Resource>()};
    auto ptr1{ptr};
    auto ptr2{ptr};
}