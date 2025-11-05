#include <iostream>
#include <string>

using namespace std;

class Ball
{
    private:
        string m_color{"black"};
        float m_radius{10.0};
    
    public:

        Ball(const string& color = "black",float radius = 10.0)
            : m_color(color),m_radius{radius}
        {}

        Ball(const Ball& ball)
            :m_color(ball.m_color),m_radius(ball.m_radius)
        {
            cout<<"Copy constructor called"<<endl;
            
        }

        void getValue() const
        {
            cout<<m_color<<" "<<m_radius<<endl;
        }
};

void printBall(Ball b)
{
    b.getValue();
}

Ball generateBall(string name, float color)
{
    Ball b(name,color);
    return b;
}

int main()
{
    
    Ball blueTwenty{ generateBall("blue", 20.0)};
    // printBall(blueTwenty);

    return 0;
}