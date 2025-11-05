#include<iostream>

using namespace std;

class Car
{
    protected:
        bool m_isSedan;
        int m_seats;

    public:
        Car(bool isSedan, int seats)
            :m_isSedan{isSedan}, m_seats{seats} {}
        
        bool getIsSedan() const {return m_isSedan;}
        int getSeats() const {return m_seats;}

        virtual string getMileage() = 0;

};


class Wagnor : public Car
{   
    
    
    private:
        int m_mileage;

    public:
        Wagnor(int mileage)
            :Car{false,4},m_mileage{mileage}{}

        string getMileage() { 
            string s = to_string(m_mileage);
            s += " kmpl";
            return s;
        }
};

class HondaCity : public Car
{   
    
    
    private:
        int m_mileage;

    public:
        HondaCity(int mileage)
            :Car{true,4},m_mileage{mileage}{}

        string getMileage() { 
            string s = to_string(m_mileage);
            s += " kmpl";
            return s;
        }
};

class InnovaCrysta : public Car
{   
    
    
    private:
        int m_mileage;

    public:
        InnovaCrysta(int mileage)
            :Car{false,6},m_mileage{mileage}{}

        string getMileage() { 
            string s = to_string(m_mileage);
            s += " kmpl";
            return s;
        }
};


int main()
{
    
    int n,mileage;
    cin>>n>>mileage;
    
    if(n==0){
        Wagnor w(mileage);
        cout<<std::boolalpha<<w.getIsSedan()<<endl;
        cout<<w.getSeats()<<endl;
        cout<<w.getMileage();
    }
    else if(n==1){
        HondaCity hc(mileage);
        cout<<std::boolalpha<<hc.getIsSedan()<<endl;
        cout<<hc.getSeats()<<endl;
        cout<<hc.getMileage();
    }
    else if(n==2)
    {
        InnovaCrysta ic(mileage);
        cout<<std::boolalpha<<ic.getIsSedan()<<endl;
        cout<<ic.getSeats()<<endl;
        cout<<ic.getMileage();
    }

    


    


}
