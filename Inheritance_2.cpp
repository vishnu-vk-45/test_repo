#include<iostream>
using namespace std;

class Fruit
{
    private:
        string m_name;
        string m_color;

    public:
        Fruit(const string& name, const string& color)
            :m_name{name},m_color{color}{}
        
        const string& getName() const { return m_name;}
        const string& getColor() const { return m_color;}
};


class Apple : public Fruit
{
    private:
        double m_fibre;
    
    public:
        Apple(const string& name, const string& color, double fibre)
            : Fruit(name,color),m_fibre{fibre}{}

        double getFibre() const  {return m_fibre;}
        
};

ostream& operator<<(ostream& out, const Apple& a)
{
    out<<"Apple("<<a.getName()<<", "<<a.getColor()<<", "<<a.getFibre()<<")";
    return out;
}


class Banana : public Fruit
{
    public:
        Banana(const string& name, const string& color)
            : Fruit(name,color) {}
};


ostream& operator<<(ostream& out, const Banana& b)
{
    out<<"Banana("<<b.getName()<<", "<<b.getColor()<<")";
    return out;
}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}