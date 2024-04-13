#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int x)
    {
        id = x;
        salary = 123;
    }
    Employee() {} // automatically called when creating a derived class
};

/*
// Derived class syntax
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    // class members / methods / etc
}
*/

// Deriver from programmer
class Programmer : Employee // Private Inheritence
{
public:
    char lang;
    Programmer(int id)
    {
        lang = 'C';
        this->id = id;
    }
    void getID()
    {
        cout << id << endl;
    }
};

int main()
{
    Employee rahul(3), harry(5);
    cout << rahul.salary << endl;
    cout << harry.salary << endl;

    Programmer devop(4);
    cout << devop.lang << endl;
    // cout << devop.id << endl; // can't call public member id as privately inherited
    devop.getID();

    return 0;
}

/*

1. Visibility Mode : is private by default
2. Public Visibility Mode: Public members of base class become, public members of derived class
3. Private Visibility Mode: Public members of base class become private members of derived class
4. Private members of base class are never inherited

*/
