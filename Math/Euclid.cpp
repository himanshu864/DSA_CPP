#include <iostream>
using namespace std;

int euclid(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main()
{
    int a = 10;
    int b = 14;
    int gcd = euclid(a, b);
    int lcm = (a * b) / gcd;
    cout << a << " " << b << endl;
    cout << "gcd: " << gcd << endl;
    cout << "lcm: " << lcm << endl;
    return 0;
}
