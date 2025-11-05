#include<iostream>

using namespace std;

double Fraction(double a, double b)
{
    if(b<=0)
        throw "Cannot carry out division";
    return a/b;
}

int main()
{
    double a, b;
    cin>>a>>b;

    try
    {
        double result = Fraction(a,b);   
        cout<<result;
    }

    // catch(const char* exception)
    // {
    //     cerr<<"Error :"<<exception;
    // }

    // catch(...)
    // {
    //     cout<<"Caught an exception";
    // }

    #ifndef NDEBUG
    catch(...) {}

    #else
        catch(DummyException) {}

    #endif
}