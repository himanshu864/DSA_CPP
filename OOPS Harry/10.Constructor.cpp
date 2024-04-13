#include <iostream>
using namespace std;

class Complex
{
    int a;
    float b;

public:
    Complex() // Default Constructor - Neccessary when overloading
    {
        a = 0;
        b = 0;
    }
    Complex(int x, int y);
    Complex(int x, double y);
    Complex(int x);

    // Copy Constructor - Optional
    Complex(Complex &obj)
    {
        cout << "Copying..." << endl;
        a = obj.a;
        b = obj.b;
    }

    void printpls()
    {
        cout << "Real: " << a << " Complex: " << b << endl;
    }
};

Complex::Complex(int x, int y) // Parameterized Constructor
{
    // if argument have same name as objects; use this->a to refer to object;
    a = x;
    b = y;
}
Complex::Complex(int x, double y)
{
    a = x;
    b = y;
}
Complex::Complex(int x) // Constructor overloading example
{
    a = x;
    b = 0;
}

int main()
{
    Complex c1;
    c1.printpls();

    Complex c2(3, 4); // Implicit Call
    c2.printpls();

    Complex c3 = Complex(10, 20); // Explicit call
    c3.printpls();

    Complex c4(7);
    c4.printpls();

    Complex c5(5, 3.6);
    c5.printpls();

    Complex z1(c3);
    z1.printpls();

    Complex z2;
    z2 = c3;
    z2.printpls();

    Complex z3 = c3;
    z3.printpls();

    return 0;
}

/*
##Constructor is a special member function with the same name as the class
-Used to Initialize objects inside a class
-Automatically invoked when an ojbect is created

## Properties:
    1. Should be declared in public class
    2. Automatically invoked when objects are created
    3. Don't return anything, hence no return type
    4. Can't refer to their address

function overloading is an example of OOPS polymorphism : same name, different forms
Similarly we can create multiple functions with same name but different arguments
and compiler will choose the correct function to call based on passing arguments

Similarly we can overload constructors and compiler will automatically initialize objects accordingly

Can also use default arguments instead of overloading

In case of constructor overloading, it is crucial to declare blank/default constructor.
Otherwise compiler won't be able to decide constructors correctly

Copy Constructor, initialize an object using anothe object of same class
Compiler provides inbuild copy constructor

*/
