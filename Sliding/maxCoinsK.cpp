#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumCoins(vector<vector<int>> &coins, int k)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());

        // use sliding window to calculate max coins in k sized window that starts at current interval
        long long ans = 0, count = 0;
        int end = 0;
        int i = 0;
        for (int curr = 0; curr < n; curr++)
        {
            // shrink by removing prev interval
            if (curr > 0)
                count -= (coins[curr - 1][2] * 1LL * (coins[curr - 1][1] - coins[curr - 1][0] + 1));

            // expand
            int newEnd = coins[curr][0] + k - 1;
            for (; i < n; i++)
            {
                int l = coins[i][0], r = coins[i][1], c = coins[i][2];

                if (end >= l) // remove partial
                    count -= (c * 1LL * (end - l + 1));

                if (newEnd > r) // add entire
                    count += (c * 1LL * (r - l + 1));
                else
                {
                    if (newEnd >= l) // add partial
                        count += (c * 1LL * (newEnd - l + 1));
                    break;
                }
            }
            end = newEnd;
            ans = max(ans, count);
        }

        // now do the same sliding for ending at current interval
        count = 0;
        i = n - 1;
        int start = coins[i][1] + 1;
        for (int curr = n - 1; curr >= 0; curr--)
        {
            if (curr < n - 1)
                count -= (coins[curr + 1][2] * 1LL * (coins[curr + 1][1] - coins[curr + 1][0] + 1));

            int newStart = coins[curr][1] - (k - 1);
            for (; i >= 0; i--)
            {
                int l = coins[i][0], r = coins[i][1], c = coins[i][2];

                if (start <= r)
                    count -= (c * 1LL * (r - start + 1));

                if (newStart < l)
                    count += (c * 1LL * (r - l + 1));
                else
                {
                    if (newStart <= r)
                        count += (c * 1LL * (r - newStart + 1));
                    break;
                }
            }
            start = newStart;
            ans = max(ans, count);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> coins = {{8, 10, 1}, {1, 3, 2}, {5, 6, 4}};
    cout << sol.maximumCoins(coins, 4) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/
