#include <iostream>
using namespace std;

// Forward declaration : To ensure compiler complex exists later
class Complex;

class Calculator
{
public:
    int sum(int i, int j)
    {
        return i + j;
    }

    // declare fn later as compiler doesn't know a, b yet
    int sumReal(Complex, Complex);
    int sumComplex(Complex, Complex);
};

class Complex
{
    int a, b;
    // Individually declaring member friend as function
    // friend int Calculator::sumReal(Complex, Complex);
    // friend int Calculator::sumComplex(Complex, Complex);

    // Declaring entire class as friend
    friend class Calculator;

public:
    void setNumber(int a1, int b1)
    {
        a = a1, b = b1;
    }
    void printNumber()
    {
        cout << "Complex Number: " << a << " + " << b << "i" << endl;
    }
};

int Calculator::sumReal(Complex c1, Complex c2)
{
    return c1.a + c2.a;
}

int Calculator::sumComplex(Complex c1, Complex c2)
{
    return c1.b + c2.b;
}

int main()
{
    Complex c1, c2;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    Calculator calc;
    cout << "Sum of Real part of c1 and c2: ";
    cout << calc.sumReal(c1, c2) << endl;
    cout << "Sum of Complex part of c1 and c2: ";
    cout << calc.sumComplex(c1, c2) << endl;

    return 0;
}
