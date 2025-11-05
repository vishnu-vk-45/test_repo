#include<iostream>
using namespace std;

class A
{
    private:
        int m_x;

    public:
        A(int x) : m_x{x} {}

        virtual ~A() = default;
        virtual int  getName() const { return m_x;}
        

};