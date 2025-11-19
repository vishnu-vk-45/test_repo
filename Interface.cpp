#include <string_view>
#include <cmath> // for sqrt()
#include<iostream>
using namespace std;

//Interface class for ErrorLog
class IErrorLog
{
public:
    virtual bool openLog(const string& filename) = 0;
    virtual bool closeLog() = 0;

    virtual bool writeError(const string& errorMessage) = 0;

    virtual ~IErrorLog() {} // make a virtual destructor in case we delete an IErrorLog pointer, so the proper derived destructor is called
};

class FileErrorLog : public IErrorLog
{
    public:
        bool openLog(const string& name) override {
            cout<<name<<" opened\n"; 
            return true;
        }
        bool closeLog() override {
            return true;
        }
        bool writeError(const string& message) override {
            cout<<message<<endl;
            return true;
        }
};


// double mySqrt(double value, IErrorLog& log)
// {
//     if (value < 0.0)
//     {
//         log.writeError("Tried to take square root of value less than 0");
//         return 0.0;
//     }

//     return std::sqrt(value);
// }

int main()
{
    FileErrorLog f{};
    // mySqrt(-1.0, f);
}