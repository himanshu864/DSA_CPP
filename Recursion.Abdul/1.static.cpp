#include <iostream>
using namespace std;

int fn(int n)
{
    if (n < 1)
        return 0;
    return fn(n - 1) + n;
}

int func(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return func(n - 1) + x;
    }
    return 0;
}

int func2(int n)
{
    static int x = 0;
    if (n > 0)
        return func2(n - 1) + x++;
    return 0;
}

int func3(int n)
{
    static int x = 0;
    if (n > 0)
        return func3(n - 1) + ++x;
    return 0;
}

int main()
{
    int a = 5;
    cout << fn(a) << endl;
    cout << func(a) << endl;
    cout << func2(a) << endl;
    cout << func3(a) << endl;
    return 0;
}

// static variables are stored in code section while compiling and aren't created again but modified.
// draw recursion try to understand
