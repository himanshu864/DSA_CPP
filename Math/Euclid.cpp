#include <bits/stdc++.h>
using namespace std;

int euclid(int a, int b)
{
    if (b == 0)
        return a;
    return euclid(b, a % b);
}

int main()
{
    int a = 10;
    int b = 14;
    int gcd = euclid(a, b);
    int lcm = abs(a * b) / gcd;
    cout << a << " " << b << '\n';
    cout << "gcd: " << gcd << '\n';
    cout << "lcm: " << lcm << '\n';
    return 0;
}
