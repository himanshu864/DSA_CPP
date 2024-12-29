#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    long long ncr(int n, int r)
    {
        long long ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = (ans * 1LL * n--) % mod;
            ans /= i;
        }
        return ans;
    }

    long long powd(int a, int b)
    {
        long long ans = 1;
        while (b--)
            ans = (ans * 1LL * a) % mod;
        return ans;
    }
    // (n - 1)C(k) * m * (m - 1)^(n - k - 1)
public:
    int countGoodArrays(int n, int m, int k)
    {
        long long permutation = ncr(n - 1, k);
        long long combination = (m * 1LL * powd(m - 1, n - k - 1)) % mod;
        cout << permutation << " " << combination << endl;
        return int(permutation * combination) % mod;
    }
};

int main()
{
    Solution sol;
    // cout << sol.countGoodArrays(3, 2, 1) << endl;
    cout << sol.countGoodArrays(4, 2, 2) << endl;
    return 0;
}

// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
