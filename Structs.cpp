#include <iostream>

struct IntPair
{
    int x;
    int y;

    void print()
    {
        std::cout<<"Pair("<<x<<", "<<y<<")\n";
    }

    bool isEqual(IntPair& pair)
    {
        if(x == pair.x && y == pair.y )
            return true;
        else
            return false;
    }
};


int main()
{
	IntPair p4 {1, 2};
	IntPair p3 {3, 4};

	std::cout << "p3: ";
	p3.print();

	std::cout << "p4: ";
	p4.print();


	std::cout << "p4 and p3 " << (p4.isEqual(p3) ? "are equal\n" : "are not equal\n");
	std::cout << "p4 and p4 " << (p4.isEqual(p4) ? "are equal\n" : "are not equal\n");

	return 0;
}