#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isCheap(long long n, long long k, int x)
    {
        long long ans = 0;
        // sum of all set bits at every x multiple index (1-indexed)
        for (long long i = x - 1; i < 62; i += x) // 63 is sign bit
        {
            long long total_bits = n + 1;          // 0 -> n
            long long cylicity = (1LL << (i + 1)); // size of cycle
            long long complete_cycles = total_bits / cylicity;
            ans += (complete_cycles * (cylicity >> 1)); // each cycle will have half Set bits

            long long partial_bits = total_bits % cylicity;
            long long partial_ones = partial_bits - (cylicity >> 1);
            if (partial_ones > 0) // first half will be zeros
                ans += partial_ones;

            if (ans > k) // pruning
                return false;
        }
        return ans <= k;
    }

public:
    long long findMaximumNumber(long long k, int x)
    {
        long long ans = 0;
        long long s = 0, e = 1e16;
        while (s <= e)
        {
            long long mid = s + ((e - s) >> 1);
            if (isCheap(mid, k, x))
            {
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    long long k = 7;
    int x = 2;
    cout << sol.findMaximumNumber(k, x) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/
