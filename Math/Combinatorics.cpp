#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// Modular Factor x Inverse for small r
// n <= 10^9 and r <= 20
class Combinatorics1
{
    int mult(int a, int b)
    {
        return (a * 1LL * b) % mod;
    }

    int modExp(int a, int b)
    {
        if (b == 0)
            return 1;
        if (b & 1)
            return mult(a, modExp(a, b - 1));
        int x = modExp(a, b >> 1);
        return mult(x, x);
    }
    int inverse(int x)
    {
        return modExp(x, mod - 2);
    }

public:
    int nCr(int n, int r)
    {
        r = min(r, n - r);
        int num = 1, den = 1;
        for (int i = 1; i <= r; i++)
        {
            num = mult(num, n - i + 1);
            den = mult(den, i);
        }
        return (num * 1LL * inverse(den)) % mod;
    }
};

// Basic nCr without Modular for small n
// n <= 40
class Combinatorics2
{
public:
    int nCr(int n, int r)
    {
        int ans = 1;
        for (int i = 1; i <= min(r, n - r); i++)
        {
            ans *= (n - i + 1);
            ans /= i;
        }
        return ans;
    }
};

// Pascal for non-prime Modulo
// n <= 1000
class Combinatorics3
{
    int dp[1001][1001];

public:
    int nCr(int n, int r, int m)
    {
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= i; j++)
                dp[i][j] = ((j ? dp[i - 1][j - 1] : 0) + dp[i - 1][j]) % m;
        return dp[n][r];
    }
};

// Precomputation for query
// n, q, r <= 10^6
class Combinatorics4
{
    vector<int> fact, invFact;

    int mult(int a, int b)
    {
        return (a * 1LL * b) % mod;
    }
    int modExp(int a, int b)
    {
        int ans = 1;
        while (b > 0)
        {
            if (b & 1)
                ans = mult(ans, a);
            a = mult(a, a);
            b >>= 1;
        }
        return ans;
    }
    int inverse(int a)
    {
        return modExp(a, mod - 2);
    }

public:
    Combinatorics4(int n)
    {
        fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = mult(fact[i - 1], i);

        invFact.resize(n + 1);
        invFact[n] = inverse(fact[n]);
        for (int i = n - 1; i >= 0; i--)
            invFact[i] = mult(invFact[i + 1], i + 1);
    }

    int nCr(int n, int r)
    {
        return mult(fact[n], mult(invFact[r], invFact[n - r]));
    }
};

int main()
{
    Combinatorics1 sol1;
    cout << sol1.nCr(1e5, 20) << "\n";

    Combinatorics2 sol2;
    cout << sol2.nCr(40, 20) << "\n";

    Combinatorics3 sol3;
    cout << sol3.nCr(1000, 500, 1e9) << "\n";

    Combinatorics4 sol4(1e5);
    cout << sol4.nCr(1e5, 1000) << "\n";
    return 0;
}
