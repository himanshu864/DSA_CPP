#include <iostream>
#include <cmath>
using namespace std;

class Simple
{
    int a;
    int b;

public:
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "a + b: " << a + b << endl;
        cout << "a - b: " << a - b << endl;
        cout << "a * b: " << a * b << endl;
        if (b)
            cout << "a / b: " << a / b << endl;
    }
};

class Scientific
{
    int a;
    int b;

public:
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "a ^ b: " << pow(a, b) << endl;
        cout << "log(a): " << log(a) << " log(b): " << log(b) << endl;
        cout << "sqrt(a): " << sqrt(a) << " sqrt(b): " << sqrt(b) << endl;
        cout << "sin(a): " << sin(a) << " sin(b): " << sin(b) << endl;
    }
};

class Hybrid : public Simple, public Scientific
{
    int a;
    int b;

public:
    void set(int x, int y)
    {
        Simple::set(x, y);
        Scientific::set(x, y);
    }

    void display()
    {
        Simple::display();
        Scientific::display();
    }
};

int main()
{
    Hybrid c;
    c.set(12, 5);
    c.display();
    return 0;
}

/*
QUESTION - Create 2 classes:
1. SimpleCalculator - Takes input of 2 numbers using a utility function and performs +, -, *, / and displays the
    result using another function.
2. ScientificCalculator - Takes input of 2 numbers using a utility function and performs any 4 scientific
    operation of your choice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes.
    Q1 What type of inheritance are you using ?
    Q2 What mode of inheritance are you using ?
    Q3 Create an object of HybridCalculator and display results of simple and scientific calculator
    Q4 How is code reusability implemented ?
*/