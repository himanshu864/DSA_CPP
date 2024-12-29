#include <bits/stdc++.h>
using namespace std;

// Recursive Fast Exponentiation
int recFastExp(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2)
        return a * recFastExp(a, b - 1);
    int x = recFastExp(a, b / 2);
    return x * x;
}

// Iterative Fast Exponentiation
int itrFastExp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2)
            ans *= a;
        a = a * a;
        b /= 2;
    }
    return ans;
}

// Inverse Exponentiation
double myPow(double x, int n)
{
    if (n < 0)
        return 1.0 / myPow(x, -n);
    if (n == 0)
        return 1;
    if (n == 2)
        return x * x;
    return (n % 2 ? x : 1) * myPow(myPow(x, n / 2), 2);
}

int main()
{
    int a = 3;
    int b = 4;
    cout << a << " " << b << endl;
    cout << "a^b: " << itrFastExp(a, b) << endl;
    return 0;
}

// https://leetcode.com/problems/powx-n/
