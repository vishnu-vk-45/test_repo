#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
#include "Random.h"


using namespace std;

int main()
{
    cout<<"Start where? ";
    int start;
    cin>>start;
    cout<<"How many? ";
    int limit;
    cin>>limit;

    int multiplier = Random::get(2,4);
    cout<<"I generated "<<limit<<" square numbers. Do you know what each number is after multiplying it by "<<multiplier<<"?"<<endl;

    vector<int> square_values;

    for(int i{1};i<=limit;i++)
    {
        square_values.push_back((start*start) * multiplier);
        start++;
    }
    
    bool isWin = false;
    bool isWrong = false;
    for(auto i: square_values)
        cout<<i<<" ";
    cout<<endl;

    


    while(!isWrong)
    {

        int guess;
        cout<<">";
        cin>>guess;

        auto checkguess {[=](auto a){
            return guess == a;}};

        auto checkmin {[=](auto a,auto b){
            return abs(a-guess) < abs(b-guess);}};
    
        auto found {find_if(square_values.begin(),square_values.end(),(checkguess))};
    
        if(found != square_values.end())
        {
            square_values.erase(found);
            if(square_values.size() == 0)
                cout<<"Nice! You found all numbers, good job!";
            else
                cout<<"Nice! "<<square_values.size()<<" number(s) left."<<endl;
        }
        else
        {
            auto close = min_element(square_values.begin(),square_values.end(),(checkmin));
    
            cout<<guess<<" is wrong! Try "<<*close<<" next time.";
            isWrong = true;
        }
    }
}