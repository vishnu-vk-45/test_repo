#include<iostream>
#include<vector>

using namespace std;

struct Time
{
    int hr;
    int min;

    friend ostream& operator<<(ostream& out,const Time& t)
    {
        out<<t.hr<<":"<<t.min<<endl;
        return out;
    }
};

class Gear
{
    private:
       vector<pair<int,Time>> gear; 

    public:
        vector<pair<int,Time>>& getGearTime()
        {
            int x;
            int hr{10},min{0};

            while(min <= 30)
            {
                cin>>x;
                gear.emplace_back(x, Time{hr,min});

                min += 2;
            }

            return gear;

        }
};


