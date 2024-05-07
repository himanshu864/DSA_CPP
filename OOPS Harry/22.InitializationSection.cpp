// Initialization Section is just a way to give values to data members of the class
// It is also known as Initialization List

#include <iostream>
using namespace std;

/*
Syntax for initialization list in constructor:
constructor (argumnent-list) : initialization-section {
    assignment + other code;
}

class Test {
    int a;
    int b;

public:
    Test(int i, int j) : a(i), b(j) {
        // constructor body
    }
};

Above code assigns a=i & b=j

*/

class Test
{
    int a; // a is declared before b, so a should be initializd before b
    int b;

public:
    // Test(int i, int j) : a(i), b(j)   // This also works well enough
    // Test(int i, int j) : a(i), b(i+j)   // This also works well enough
    // Test(int i, int j) : a(i), b(2*j)   // This also works well enough
    // Test(int i, int j) : a(i), b(a+j)    // This also works well enough

    // Test(int i, int j) : b(j), a(i+b)   // a is declared before b, so it should be initialized before b
    // This will give error bcoz a is initilized first (till then b contains garbage value)
    // To get correct value of this, you need to declare b before a

    Test(int i, int j) : a(i)
    { // This also works well
        b = j;
        cout << "Constructor Executed" << endl;
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
    }
};

int main()
{
    Test t(4, 6);
    return 0;
}