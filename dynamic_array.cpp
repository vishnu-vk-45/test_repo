#include <iostream>
#include<algorithm>
using namespace std;

void getLength(size_t& length)
{
    cout<<"How many names you wish to enter? ";
    cin>>length;

}

void getNames(string* name, size_t length)
{
    for(int i=0;i<length;i++)
    {
        cout<<"Enter name #"<<i+1<<": ";
        getline(cin>>ws,name[i]);
    }
}

void printNames(string* name,size_t length)
{
    for(int i=0;i<length;i++)
    {
        cout<<name[i]<<endl;
    }
}

int main()
{
    
    size_t length;
    getLength(length);
    
    string* name {new string[length] {}};

    getNames(name,length);

    sort(name,name+length);

    printNames(name,length);

    delete[] name;

    
}