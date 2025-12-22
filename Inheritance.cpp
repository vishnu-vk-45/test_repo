#include<iostream>
using namespace std;

class Base
{
    private:
        int m_x,m_y;
    public:
        Base(int x, int y)
            :m_x(x),m_y(y){}

        void getx_m()
        {
            cout<<m_x<<" "<<m_y<<endl;
        }

};

class Child : public Base
{
    public:
        Child()
            :Base{5,10}{}
        // void getx_m() override 
        // {
            
        // }
         
};




