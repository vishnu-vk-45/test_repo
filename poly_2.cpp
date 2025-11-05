#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point
{
    private:
        int m_x;
        int m_y;
    
    public:
        Point(int x,int y)
            :m_x{x},m_y{y}{}

        friend ostream& operator<<(ostream& out, const Point& p)
        {
            out<<"(Point("<<p.m_x<<", "<<p.m_y<<")";
            return out;
        }
};


class Shape
{
    public:
        virtual ostream& print(ostream& out)const = 0;

        friend ostream& operator<<(ostream& out, const Shape& s)
        {
            return s.print(out);
        }

        virtual ~Shape() = default;
};

class Triangle :public Shape
{
    private:
        Point m_p1;
        Point m_p2;
        Point m_p3;

    public:
        Triangle(const Point& p1, const Point& p2, const Point& p3)
            :m_p1{p1},m_p2{p2},m_p3{p3} {}

        ostream& print(ostream& out) const override
        {
            out<<"Triangle("<<m_p1<<", "<<m_p2<<", "<<m_p3<<")";
            return out;
        }

};


class Circle :public Shape
{
    private:
        Point m_p1;
        int m_radius;

    public:
        Circle(const Point& p1, int radius)
            :m_p1{p1},m_radius{radius} {}

        ostream& print(ostream& out) const override
        {
            out<<"Circle("<<m_p1<<", radius "<<m_radius<<")";
            return out;
        }

        const int getRadius() const {return m_radius; }

};

int getLargestRadius(vector<Shape*> v)
{
    int largestRadius = 0;
    for(auto* shape : v)
    {
        if(const auto* circle{dynamic_cast<Circle*>(shape)})
        {
            largestRadius = max(largestRadius,circle->getRadius());
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

	// print each shape in vector v on its own line here
    for(const auto* shape : v)
        cout<<*shape<<endl;


	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for(auto* shape : v)
        delete shape;

	return 0;
}