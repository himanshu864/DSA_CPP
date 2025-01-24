#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

class Combinatorics
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
    Combinatorics(int n)
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

class Solution
{
public:
    int minMaxSums(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        Combinatorics C(n);

        for (int i = 0; i < n; i++)
        {
            int front = n - 1 - i;
            for (int r = 0; r <= min(k - 1, front); r++)
                ans = (ans + (nums[i] * 1LL * C.nCr(front, r)) % mod) % mod;

            int back = i;
            for (int r = 0; r <= min(k - 1, back); r++)
                ans = (ans + (nums[i] * 1LL * C.nCr(back, r)) % mod) % mod;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 2;
    cout << sol.minMaxSums(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/
