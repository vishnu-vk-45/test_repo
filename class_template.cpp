#include <iostream>
#include<utility>


template <typename T,typename U>
void print(std::pair<T,U> p)
{
    std::cout << '[' << p.first << ", " << p.second << ']';
    // return p.first;
}

int main()
{
    std::pair<int, double> p1{ 1, 2.3 }; // a pair holding an int and a double
    std::pair<double, int> p2{ 4.5, 6 }; // a pair holding a double and an int
    std::pair<int, int> p3{ 7, 8 };      // a pair holding two ints
    // Shape s{2,5};
    // std::cout<<
    print(p2);

    return 0;
}