#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

class MyString
{
    private:
        char* m_data;
        int m_length;
    public:
        MyString(const char* source = "")
        {
            m_length = strlen(source)+1;
            m_data = new char[m_length];

            for(int i=0;i<m_length;i++)
                m_data[i] = source[i];
        }

        MyString(const MyString& s)                             //copy constructor
            :m_data{s.m_data},m_length{s.m_length} {}

        MyString& operator=(const MyString& str)
        {
            if(this == &str)
                return *this;

            if(m_data)
                delete[] m_data;
            
            m_length = str.m_length;
            m_data = nullptr;

            if(m_length)
                m_data = new char[m_length];
            
            copy_n(str.m_data,m_length,m_data);

            return *this;
        }

        ~MyString(){delete[] m_data;}

        char* getString(){ return m_data;}
};      


int main()
{
    MyString s{"Hello world"};
    {
        MyString copy{s};
    }

    cout<<s.getString();
}