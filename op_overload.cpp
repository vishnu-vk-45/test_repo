#include<iostream>
using namespace std;


class Fraction
{
    private:
        int m_numerator;
        int m_denominator;
    public:
        Fraction(int x, int y=1)
            :m_numerator{x},m_denominator{y} {}
        
        void print() const {cout<<m_numerator<<"/"<<m_denominator<<endl;}

        friend Fraction operator*(const Fraction& f1, const Fraction& f2)
        {
            Fraction fnew{(f1.m_numerator*f2.m_numerator),(f1.m_denominator*f2.m_denominator)};
            return fnew;
        }

        // friend Fraction operator*(const Fraction& f, int n)
        // {
        //     Fraction fnew{(f.m_numerator*n),f.m_denominator};
        //     return fnew;
        // }

        // friend Fraction operator*(int n, const Fraction& f )
        // {
        //     Fraction fnew{(f.m_numerator*n),f.m_denominator};
        //     return fnew;
        // }
};


int main()
{
    
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;

}