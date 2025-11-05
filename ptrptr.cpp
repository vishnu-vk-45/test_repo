#include<iostream>
#include<functional>

using namespace std;

using ArithmeticFunction = std::function<int(int,int)> ;

int getInt();
char getOp();
ArithmeticFunction getArithmeticFunction(char);
int add(int,int);
int subtract(int,int);
int multiply(int,int);
int divide(int,int);



int main()
{
    int a {getInt()};
    char op {getOp()};
    int b {getInt()};

    ArithmeticFunction operation = getArithmeticFunction(op);

    // cout<<a<<" "<<op<<" "<<b<<" = "<<(getArithmeticFunction(op)(a,b));
    cout<<a<<" "<<op<<" "<<b<<" = "<<operation(a,b);

}


int getInt()
{
    cout<<"Enter an integer: ";
    int x;
    cin>>x;
    return x;
}

char getOp()
{
    char op;

    do
    {
        cout<<"Enter the operation('+','-','*','/'): ";
        cin>>op;
    }
    while(op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int a,int b)
{
    return (a+b);
}

int subtract(int a,int b)
{
    return (a-b);
}

int multiply(int a,int b)
{
    return (a*b);
}

int divide(int a,int b)
{
    return (a/b);
}

ArithmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
        case '+': return &add;
        case '-': return &subtract;
        case '*': return &multiply;
        case '/': return &divide;
            
        default:
            return nullptr;
    }
}