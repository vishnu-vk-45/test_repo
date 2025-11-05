#include<bitset>
#include<iostream>
#include<cstdint>

using namespace std;

int main()
{
    uint8_t bits {0b10001000};
    cout<<bitset<8>(bits)<<endl;;

    uint8_t mask3{0b0000'1000};

    bits &= ~mask3;

    cout<<bitset<8>{bits}<<endl;

    bits |= mask3;
    cout<<bitset<8>{bits}<<endl;

    bits ^= mask3;
    cout<<bitset<8>{bits}<<endl;

    // if(bits & mask3)
    //     cout<<"True";
    // else
    //     cout<<"False";

    bits |= mask3;

    auto bits1 = static_cast<bitset<8>>(bits);
    cout<<boolalpha<<bits1.test(3);

    

}