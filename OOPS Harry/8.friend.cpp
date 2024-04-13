#include <iostream>
using namespace std;

class Complex
{
    // private data
    int a, b;

public:
    void setNumber(int a1, int b1)
    {
        a = a1, b = b1;
    }
    void printNumber()
    {
        cout << "Complex Number: " << a << " + " << b << "i" << endl;
    }
    // written permission (not declaration)
    friend Complex fuksumn(Complex c1, Complex c2);
};

// need permission to access private data
Complex fuksumn(Complex c1, Complex c2)
{
    Complex c3;
    c3.setNumber(c1.a + c2.a, c1.b + c2.b);
    return c3;
}

int main()
{
    Complex c1, c2, c3;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    c3 = fuksumn(c1, c2);
    c3.printNumber();

    return 0;
}

/*
Compiler acts as police and doesn't allow non-member functions to access private data
But functions can have class declare them as friend to allow access to private/protected data

## Properties of friend function
1. Not in the scope of class
2. Can not be call from object of that class. i.e. c3.fuksumn(c1, c2) -> invalid
3. Can be involved without the help of objects
4. Usually contains objects as arguments
5. Can be declared inside public/part of class
6. Can't access members directly, need object_name.member_name. i.e. cout << a; -> invalid

*/
