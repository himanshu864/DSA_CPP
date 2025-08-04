#include <iostream>
#include <vector>
using namespace std;

class Base
{
public:
    int var_base;

    void display()
    {
        cout << "Variable of Base class: " << var_base << endl;
    }
};

class Derived : public Base
{
public:
    int var_derived;

    void display()
    {
        cout << "Variable of Base class: " << var_base << endl;
        cout << "Variable of Derived class: " << var_derived << endl;
    }
};

int main()
{

    /* Pointer of base class can point to derived class object */
    Base *base_ptr;
    Derived obj_derived;
    base_ptr = &obj_derived;

    /* But it will only be able to access inherited members */
    base_ptr->var_base = 20;
    // base_ptr->var_derived = 30;  <- throws an error

    /*
    When a function exists in both Base and Derived classes,
    the Base pointer will call the Base version of the function.
    This is an example of static binding also known as early binding.
    */
    base_ptr->display();
    return 0;
}
