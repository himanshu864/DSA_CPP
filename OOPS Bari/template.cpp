#include <iostream>
using namespace std;

template <class T> // change all necessary datatypes to T
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b); // declare here want functions outside class
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) // Use Arithmetic:: to refer to class and pass <T> argument
{
    this->a = a; // *this* is used to refer to class *a* because both have same names
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> x(5, 3);
    cout << x.add() << endl;

    Arithmetic<float> f(5.23, 2.65);
    cout << f.sub() << endl;
    return 0;
}

// templates are used so that we don't need to create different functions for different date types
