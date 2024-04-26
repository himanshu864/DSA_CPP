// If in case of multiple inheritance having following inheritance path (A&B->C), both A and B have a function
// with same name, then if a function with same name is called in C, then it would belong to which class A or B
// This is known as Ambiguity Resolution in Inheritance

#include <iostream>
using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "How are you?" << endl;
    }
};

class Base2
{
public:
    void greet()
    {
        cout << "Kaise ho?" << endl;
    }
};

class Derived : public Base1, public Base2
{
    int a;

public:
    // Method to resolve ambiguity (using scope resolution operator)
    void greet()
    {
        Base2 ::greet(); // It shopuld use greet() of class Base2
    }
};

class B
{
public:
    void say()
    {
        cout << "Hello world" << endl;
    }
};

class D : public B
{
    int a;
    // D's new say() method will override base class's say() method
public:
    // Ambiguity is resolved all by itself
    // If we write a function with same name as in base class, then it gets overridden by derived class
    void say()
    {
        cout << "Hello my beautiful people" << endl;
    }
    // If the above part wasn't there, then it inherits say of Base class B,
    // and if we define say method in this class, then it overrides
};

int main()
{
    // Ambiguity 1 (Real Ambiguity Resolution)
    Base1 base1obj;
    Base2 base2obj;
    base1obj.greet();
    base2obj.greet();
    Derived d;
    d.greet(); // greet() is declared in both classes Base1 & Base2 (which one to inherit)

    // Ambibuity 2
    B b;
    b.say();
    D e;
    e.say(); // class D overwrites say() function of class B

    return 0;
}