#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

struct Student
{
    string name;
    int points;
};

struct Teacher
{
    string name;
    
};


int main()
{
    array<Student,8> arr {
        {{ "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 }}    
    };

    auto best = max_element(arr.begin(),arr.end(),[](const Student& a, const Student& b){
                                                        return a.points<b.points;});

    cout<<best->name<<" is the best student";
}