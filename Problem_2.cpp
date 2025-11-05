#include<iostream>

using namespace std;

class Shape
{
    public:
        virtual void drawShape() = 0;
        // virtual ~Shape() {}
};

class Circle : public Shape
{
    public:
        void drawShape() override {cout<<"Drawing a Circle\n";}
};

class Square : public Shape
{
    public:
        void drawShape() override {cout<<"Drawing a Square\n";}
};

class Rectangle : public Shape
{
    public:
        // virtual ~Rectangle(){ delete }
        void drawShape() override {cout<<"Drawing a Rectangle\n";}
};

class ShapeFactory
{
    public:
        void drawShape(string shapeType)
        {         
            if(shapeType == "Circle"){
                Shape* sh(new Circle);
                sh->drawShape();
                delete sh;
            }
            else if(shapeType == "Square"){
                Shape* sh(new Square);
                sh->drawShape();
            }
            else if(shapeType == "Rectangle"){
                Shape* sh(new Rectangle);
                sh->drawShape();
            }
            else
                cout<<"Drawing "<<shapeType<<" is not supported\n";

        }
};

int main()
{
    int n;
    for(int i=0;i<5;i++)
    {
        string shapeType;

    }
}
