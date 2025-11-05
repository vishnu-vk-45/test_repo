#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

class MyString
{
    private:
        char* m_name;
        int m_length;
    
    public:
        MyString(const char* s ="")
        {
            m_length = strlen(s)+1;
            m_name = new char[m_length];

            for(int i=0;i<m_length;i++)
                m_name[i] = s[i];
        }

        ~MyString() {delete[] m_name;}

        MyString(const MyString& s)
        {

            m_length = s.m_length;

            if(s.m_name)
            {
                m_name = new char[m_length];
                copy_n(s.m_name,m_length,m_name);
            }

            else
                m_name = nullptr;
        }

        MyString& operator=(const MyString& s)
        {
            if(this == &s)
                return *this;

            delete[] m_name;
            m_length =  s.m_length;

            if(s.m_name)
            {
                m_name = new char[m_length];
                for(int i=0;i<m_length;i++)
                {
                    m_name[i] = s.m_name[i];
                }
            }
            else
                m_name = nullptr;

            return *this;
        }

        void getName()const {cout<<m_name<<endl;}
        void setName(const char name) {*m_name = name;}
};


int main()
{
    MyString str{"Hello"};
    
    MyString ms{str};
    
    MyString cs;
    cs = str;
    cs.getName();
    str.getName();

}