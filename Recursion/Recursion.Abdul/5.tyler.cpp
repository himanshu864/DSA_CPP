#include <iostream>
using namespace std;

double person(double x, double n, double i = 1, double curr = 1)
{
    if (n == 0)
        return 1;
    curr *= (x / i++); // my dumbass tail-recursion
    return curr + person(x, n - 1, i, curr);
}

double e(double x, double n)
{
    static double p = 1, f = 1;
    if (n == 0)
        return 1;
    double shift = e(x, n - 1); // notice this is head-recursion
    p *= x;
    f *= n;
    return (p / f) + shift;
}

int main()
{
    double x = 1;
    double n = 10;
    cout << e(x, n) << endl;
    cout << person(x, n) << endl;
    return 0;
}

// this is tyler series where e^x = 1 + x/1 + x^2/2! + x^3/3! + ... n terms
// I know n is the no. of terms, but this is how we're solving stfu
