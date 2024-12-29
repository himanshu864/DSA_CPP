#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// Modular Exponentiation
int modExp(int a, int b)
{
    if (b == 0)
        return 1;

    if (b % 2)
        return (a * 1LL * modExp(a, b - 1)) % mod;

    int x = modExp(a, b / 2);
    return (x * 1LL * x) % mod;
}

// Iterative modExp
int itrModExp(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    int a = 12;
    int b = 11;
    cout << modExp(a, b) << endl;
    return 0;
}
