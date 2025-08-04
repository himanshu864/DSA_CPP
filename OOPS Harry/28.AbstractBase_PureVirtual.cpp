#include <iostream>
#include <vector>
using namespace std;

// This is an abstract base class.
// A class becomes abstract when it contains at least one pure virtual function.
// You cannot create an object of an abstract class directly.
class Base
{
protected:
    int var_base;

public:
    // Constructors work normally in an abstract class.
    Base() : var_base(10) {};
    Base(int var) : var_base(var) {};

    // A pure virtual function is a function declared with '= 0'.
    // It has no implementation in the base class.
    // A function that is defined to be overriden. Inheritance necessary.
    virtual void display() = 0;
};

class Derived : public Base
{
protected:
    int var_derived;

public:
    Derived() : Base(20), var_derived(30) {};

    // Any concrete class that inherits from this abstract class MUST provide
    // an implementation for this function. This forces derived classes to
    // define their own 'display' behavior, ensuring a consistent interface.
    void display()
    {
        cout << "Variable of Base class: " << var_base << endl;
        cout << "Variable of Derived class: " << var_derived << endl;
    }
};

int main()
{
    Base *base_ptr;
    Derived obj_derived;
    base_ptr = &obj_derived;

    base_ptr->display();
    return 0;
}
