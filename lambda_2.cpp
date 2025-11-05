#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

struct Season
{
   string name;
   double averageTemp;
};


int main()
{
   array<Season,4> arr {
      { {"Spring", 285.0 },
        {"Summer", 296.0 },
	{"Fall", 288.0 },
	{"Winter", 263.0 }}
      };

   sort(arr.begin(),arr.end(),[](const Season& a, const Season& b) {
				return a.averageTemp<b.averageTemp;});


   for(const auto a : arr)
   {
 	cout<<a.name<<"\n";
   }


}
