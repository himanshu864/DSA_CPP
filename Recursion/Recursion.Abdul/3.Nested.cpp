#include <iostream>
using namespace std;

int fn(int n)
{
    if (n > 100)
        return n - 10;
    else
        return fn(fn(n + 11));
}

int main()
{
    cout << fn(96) << endl;
    cout << fn(-3) << endl;
    cout << fn(102) << endl;
    cout << fn(200) << endl;
    return 0;
}

// Nested: a recursive fn will pass parameter as a recursive call
// any value below 100 will print 91 and will print n - 10 for above
