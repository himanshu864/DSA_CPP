#include <bits/stdc++.h>
using namespace std;

/*
    based on Fermat's little theorem
    for any prime mod with gcd(a, mod) == 1
    a^(m - 1) % m = 1
*/
int mod = 1e9 + 7;

int modExp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}

int modInv(int a)
{
    return modExp(a, mod - 2);
}

int main()
{
    return 0;
}
