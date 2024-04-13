#include <iostream>
using namespace std;

int exponent(int a, int b)
{
    int ans = 1;
    while (b--)
        ans *= a;
    return ans;
}

int fastexp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans *= a;
        a = a * a;
        b /= 2;
    }
    return ans;
}

int main()
{
    int a = 3;
    int b = 4;
    cout << a << " " << b << endl;
    cout << "a^b: " << exponent(a, b) << endl;
    cout << "a^b: " << fastexp(a, b) << endl;
    return 0;
}

double myPow(double x, int n)
{
    if (n < 0)
        return 1 / (x * myPow(x, -(n + 1)));
    if (n == 0)
        return 1;
    if (n == 2)
        return x * x;
    if (n % 2 == 0)
        return myPow(myPow(x, n / 2), 2);
    else
        return x * myPow(myPow(x, n / 2), 2);
}

// https://leetcode.com/problems/powx-n/
