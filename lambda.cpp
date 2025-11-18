#include<iostream>
#include<functional>
using namespace std;

int add1(int a, int b, int(*add)(int,int))
{
  return add(a,b);
}

int add2(int a, int b, const function<int(int,int)>& add)
{
  return add(a,b);
}

template<typename T>
int add4(int a,int b, const T& add)
{
  return add(a,b);
}


int main()
{
  auto isEven {
    [](int a, int b) {
      return a+b;
    }
  };


  cout<<add1(5,10,isEven)<<endl;
  cout<<add2(5,10,isEven)<<endl;
  cout<<add4(5,10,isEven)<<endl;

}