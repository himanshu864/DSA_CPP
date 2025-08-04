#include <iostream>
#include <vector>
using namespace std;

class Base
{
protected:
    int var_base;

public:
    Base() : var_base(10) {};
    Base(int var) : var_base(var) {};

    // The 'virtual' keyword enables runtime polymorphism.
    // It tells the compiler to decide which function to call at runtime,
    // based on the actual object type, not the pointer type.
    virtual void display()
    {
        cout << "Variable of Base class: " << var_base << endl;
    }
};

class Derived : public Base
{
protected:
    int var_derived;

public:
    Derived() : Base(20), var_derived(30) {};

    // This function overrides the virtual function in the Base class.
    // The 'override' keyword (C++11 and later) is good practice to ensure
    // you are correctly overriding a base class function.
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

    // Because 'display()' is virtual, the program will call the
    // Derived class's version of the function at runtime.
    // This is the core of polymorphism.
    base_ptr->display();
    return 0;
}

/*
Rules:
1. They cannot be static.
2. They are accessed by object pointers.
3. Virtual functions can be a friend of another class.
4. A virtual function in base class might not be used.
5. A virtual function in base class doesn't need to be refined in derived class

Eg:

int main()
{
    Base obj_base;
    obj_base.display();
}

Above code will code display() function of base class, even through virtual.

*/