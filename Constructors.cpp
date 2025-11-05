#include<iostream>
using namespace std;

class Base
{
    private:
        int m_x,m_y;
    public:
        Base(){cout<<"Default constructor\n";}                   // default constructor

        Base(int x,int y)                                         //Parameterized constructor     
            : m_x{x},m_y{y}{cout<<"Parameterized constructor\n";}

        Base(const Base& base)                                         //Copy constructor
            :Base(50,100){cout<<"copy constructor\n";};
                  
            
        void Print() {cout<<m_x<<" "<<m_y<<endl;}

        
        
};

int set_xValue() {return 15;}
int set_yValue() {return 25;}


int main()
{
    Base b{};
    b.Print();
    Base b1(5,10);
    b1.Print();
    Base b2 = {10,20};
    b2.Print();
    Base b3{set_xValue(),set_yValue()};
    b3.Print();
    Base b4(b1);
    b4.Print();

    

}