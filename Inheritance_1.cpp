#include<iostream>
using namespace std;


class Fruit
{
    private:
        string m_name;
        string m_color;

    public:
        Fruit(const string& name = "",const string& color = "")
            : m_name{name}, m_color{color} {}

        const string& getName() { return m_name;}
        const string& getColor() { return m_color;}

    
};

class Apple :public Fruit
{
    protected:
        Apple(const string& name,const string& color)
            : Fruit(name,color) {}

    public:
        Apple(const string& color) :Fruit("apple",color) {}
};

class Banana : public Fruit
{
    public:
        Banana()
            : Fruit("banana","yellow") {}
};

class GrannySmith : public Apple
{
    public:
        GrannySmith(): Apple("granny smith apple", "green") {}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}