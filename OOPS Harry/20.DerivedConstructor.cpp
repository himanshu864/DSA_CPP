#include <iostream>
using namespace std;

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }
    void printDataBase1(void)
    {
        cout << "The value of data1 is " << data1 << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 class constructor called" << endl;
    }
    void printDataBase2(void)
    {
        cout << "The value of data2 is " << data2 << endl;
    }
};

class Derived : public Base2, public Base1
{
    int derived1, derived2;

public:
    // Derived(int a, int b, int c, int d):Base2(a),Base1(b){};    // Doesn't change order of constructor called
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }
    void printDataDerived(void)
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};

int main()
{
    Derived harry(1, 2, 3, 4);
    harry.printDataBase1();
    harry.printDataBase2();
    harry.printDataDerived();

    return 0;
}

// My example to understand better ig
// class A
// {
// protected:
//     int x;

// public:
//     int y;
//     A(int temp)
//     {
//         x = temp;
//         y = 2;
//     }
// };

// class B : public A
// {
// public:
//     B() : A(1)
//     {
//     }
//     void setxy(int xi, int yi)
//     {
//         x = xi;
//         y = yi;
//     }
//     void printx()
//     {
//         cout << x << endl;
//     }
// };

// int main()
// {
//     B beta;
//     beta.printx();
//     cout << beta.y << endl;
//     return 0;
// }

/*
- we can use constructor is derived class
- If base class constructor doesn't have any arguments, it will be classed automatically
and there is no need for constructor in derived class
- But if there are more than one arguments in base class constructor
derived class needs to pass arguments to base class constructor
- If both base and derived class have constructor, base class constructor is executed first

# Constructors in Multiple Inheritance
- base class constructors are called in the order they are declared

# Constructors in Multilevel Inheritance
- constructors are executed in the order of inheritance

# SPECIAL SYNTAX
- C++ supports an special syntax for passing arguments to multiple base classes
- The constructor of derived class receives all the arguments at once and then will pass the calls to the
    respective base classes
- The body is called after all the constructors are finished executing.

Derived_Constructor (arg1, arg2, arg3, ...) : Base1_Constructor(arg1, arg2), Base2_Constructor(arg3, arg4) {
    Constructor Body
};

# SPECIAL CASE OF VIRTUAL BASE CLASS
- The constructors of virtual base classes are invoked before an non-virtual base class
- If there are multiple virtual base classes, they're invoked in the order declared (as per previous rules)
- Any non-virtual base classes are then constructed before the derived class constructor is executed, this
    simple means firstly constructor of all virtual base classes are invoked, then comes turn of non-virtual
    base classes

Case1:
class B: public A{
    // Order of execution of constructor -> first A(), then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> first B(), then C(), then A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> first C(), then B(), then A()
}
*/