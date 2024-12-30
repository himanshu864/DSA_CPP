#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7;
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
    int inverse(int a)
    {
        return modExp(a, mod - 2);
    }
    int fact(int n)
    {
        int ans = 1;
        for (int i = 2; i <= n; i++)
            ans = mult(ans, i);
        return ans;
    }

public:
    int countGoodArrays(int n, int m, int k)
    {
        // Combination
        int ans = m;
        for (int i = 0; i < n - k - 1; i++)
            ans = mult(ans, m - 1);

        // Permutation
        ans = mult(ans, fact(n - 1));
        ans = mult(ans, inverse(fact(k)));
        ans = mult(ans, inverse(fact(n - k - 1)));
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.countGoodArrays(3, 2, 1) << endl;
    return 0;
}

// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
