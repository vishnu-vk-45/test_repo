#include<iostream>
#include<cstring>
using namespace std;

class Mystring
{
    private:
        char* m_name;
        int m_length;

    public:
        Mystring(const char* source = "")
        {
            m_length = strlen(source)+1;
            m_name = new char[m_length];

            for(int i{0};i<m_length;i++)
                m_name[i] = source[i];
        }

        Mystring(const Mystring& hello)
        {
            delete m_name;
            if(hello.m_name)
            {
                m_length = hello.m_length;
                m_name = new char[m_length];

                for(int i{0};i<m_length;i++)
                    m_name[i] = hello.m_name[i];
            }

            else
                m_name = nullptr;
        }

        Mystring& operator=(const Mystring& hello)
        {
            if(this == &hello)
                return *this;

            delete m_name;

            if(hello.m_name)
            {
                m_length = hello.m_length;
                m_name = new char[m_length];

                for(int i=0;i<m_length;i++)
                    m_name[i] = hello.m_name[i];

            }

            else
                m_name = nullptr;

            return *this;
        }


        ~Mystring()
        {
            delete[] m_name;
        }

        char* getString() { return m_name; }
        int getLength() { return m_length; }
};

int main()
{
    Mystring hello{"Hello world"};
    Mystring copy(hello);

    cout<<hello.getString();
}