#include<iostream>

using namespace std;

class Ball
{
    private:
        int m_id;

    public:
        Ball(int id)
            : m_id{id} {}
        
        auto& add(int id) { m_id += id; return *this;}
        Ball& mul(int id) {m_id *= id; return *this;}

    
        void print() const {cout<<m_id;}


};

int main()
{
    Ball vicky{1};
    vicky.add(6).mul(2);
    vicky.print();

    
}