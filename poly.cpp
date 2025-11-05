#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Shape
{
    public:
        virtual ostream& print(ostream& out) const  = 0;
        friend ostream& operator<<(ostream& out,const Shape& s)
        {
             return s.print(out);
        }
        virtual ~Shape() = default;

};

class Point
{
    private:
        int m_x;
        int m_y;
    
    public:
        Point(int x, int y)
            :m_x{x}, m_y{y} {}

        friend ostream& operator<<(ostream& out, const Point& p)
        {
            return out<<"Point("<<p.m_x<<", "<<p.m_y<<")";
        }
};

class Triangle : public Shape
{
    private:
        Point m_p1;
        Point m_p2;
        Point m_p3;
    
    public:
        Triangle(const Point& a,const Point& b,const Point& c)
            : m_p1{a}, m_p2{b}, m_p3{c} {}

        ostream& print(ostream& out) const override
        {
            out<<"Triangle("<<m_p1<<", "<<m_p2<<", "<<m_p3<<")";
            return out;
        }


};

class Circle : public Shape
{
    private:
        Point m_p;
        int m_radius;

    public:
        Circle(const Point& p, int radius)
            :m_p{p}, m_radius{radius} {}

        ostream& print(ostream& out) const override
        {
            out<<"Circle("<<m_p<<", radius "<<m_radius<<")";
            return out;
        }

        const int getRadius() const {return m_radius;}
};
    
int getLargestRadius(const vector<Shape*>v)
{
    int largestRadius = 0;

    for(const auto* shape : v)
    {
        if(auto* c{dynamic_cast<const Circle*>(shape)})
        {
            largestRadius = max(largestRadius, c->getRadius());
        }
    }

    return largestRadius;
}


int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

    for(const auto* i: v)
    {
        cout<<*i<<endl;
    }

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	for(auto*   i : v)
        delete i;

	return 0;
}
