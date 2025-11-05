#include<iostream>
#include<cstring>
using namespace std;


class Mystring
{
    private:
        char* m_name;
        int m_length;
    public:
        Mystring() = default;

        Mystring(const char* source = "")
            {
                m_length  = strlen(source)+1;
                m_name = new char[m_length];

                for(int i=0;i<m_length;i++)
                    m_name[i] = source[i];
            }

        Mystring(const Mystring& e)
            :m_length{e.m_length}
            ,m_name{e.m_name}{}

        Mystring& operator=(const Mystring& e)
        {
            if(this == &e)
                return *this;
            m_length = e.m_length;
            m_name = e.m_name;
            return *this;
        }

        // friend ostream& operator<<(ostream& out, const Mystring& e)
        // {
        //     out<<e.m<<"/"<<e.m_denominator<<endl;
        //     return out;
        // }

        char* getString() { return m_name; }
        int getLength() { return m_length; }
};


int main()
{
    Mystring hello{"Hello world"};
    {
        Mystring copy{hello};
    }

    cout<<hello.getString();

}