#include<iostream>
#include<cstring>
using namespace std;

class Entity
{
    char* m_name{};
    int m_length;
    
    public:
        Entity(const char* name ="")
        {

        }
};

int main()
{
    int x = 5;
    int& ref = x;

    int* ptr = &x;
    

    int y = 10;
    ptr = &y;
    ref = y;

    cout<<ref<<"\n"<<x;


}