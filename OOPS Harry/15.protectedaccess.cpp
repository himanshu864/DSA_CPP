#include <iostream>
using namespace std;

class Base
{
protected: // protected means : just like private variable, but it can be inherited
    int a;

private:
    int b;
};

/*
VISIBILITY MODES :
                        PUBLIC DERIVATION       PRIVATE DERIVATION      PROTECTED DERIVATION
1. private members        Not inherited           Not inherited           Not inherited
2. protected members      Protected               Private                 Protected
3. public members         Public                  Private                 Protected

Trick to Remember :
# private members never inherited
# public derivation : everything remains same as it was in base class
# private derivation : everything private
# protected derivation : everything protected
*/

class Derived : protected Base
{
public:
    // can access protected
    void geta()
    {
        cout << a << endl;
    }
    // can't access b as private
    // void getb()
    // {
    //     cout << b << endl;
    // }
};

int main()
{
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since 'a' is protected in both base as well as derived class
    d.geta();
    // d.getb();
    return 0;
}
