#include<iostream>
using namespace std;

int main()
{
    int** arr{new int*[5]};
    for(int i{0};i<5;i++)
        arr[i] = new int[2];

    for(int i{0};i<5;i++)
        {
            for(int j=0;j<3;j++)
            {
                arr[i][j] = i+j+1;
            }
        }

        for(int i{0};i<5;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<arr[i][j]<<" ";
            }

            cout<<"\n";
        }

        for(int i{0};i<5;i++)
            delete[]arr[i];

        delete[] arr;

}