#include <iostream>
#include <vector>
using namespace std;

/*

this keyword is a special pointer that refers to the current instance of a class.
It is implicitly passed to non-static member functions of a class and points to the object on which the member function was invoked.

*/

class A
{
    int a;

public:
    A &set_data(int a)
    {
        this->a = a;
        return *this;
    }
    void get_data()
    {
        cout << a << endl;
    }
};

int main()
{
    A obj;
    obj.set_data(4).get_data();
    return 0;
}
