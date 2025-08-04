#include <iostream>
using namespace std;

int count = 0;

class Array
{
    int *data;

public:
    Array()
    {
        ::count++;
        cout << "Calling construtor for class n" << ::count << endl;
        data = new int[100];
    }
    ~Array()
    {
        cout << "Calling Destructor for class n" << ::count << endl;
        ::count--;
        delete[] data;
    }
    void setZero(int temp)
    {
        data[0] = temp;
    }
};

int main()
{
    cout << "Start of main()" << endl;
    cout << "Creating class n1" << endl;
    Array n1;
    for (int i = 1; i <= 2; i++)
    {
        cout << "Creating n2 inside loop " << i << endl;
        Array n2;
        cout << "End of loop " << i << endl;
    }
    cout << "End of main()" << endl;
    return 0;
}

/*

## Destructor : never takes an argument nor does it return anything
Also have same name as class and is preceded by a tilde(~).

Automatically called after class goes out of scope.
Usually used to destroy dynamically allocated memory

*/