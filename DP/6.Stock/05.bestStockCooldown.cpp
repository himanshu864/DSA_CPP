#include <iostream>
#include <vector>
using namespace std;

// One stock. Infinite Transations. No overlapping. But one day cooldown require after selling.

// Memoization
class Solution1
{
    int f(int i, bool buy, vector<int> &p, vector<vector<int>> &dp)
    {
        if (i + 1 > p.size())
            return 0;

        if (dp[i][buy] == -1)
        {
            int ans = f(i + 1, buy, p, dp);

            if (buy)
                ans = max(ans, f(i + 1, false, p, dp) - p[i]);
            else
                ans = max(ans, f(i + 2, true, p, dp) + p[i]);

            dp[i][buy] = ans;
        }
        return dp[i][buy];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, true, prices, dp);
    }
};

// Tabulation
class Solution2
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<int>> dp(p.size() + 2, vector<int>(2));
        for (int i = p.size() - 1; i >= 0; i--)
        {
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] - p[i]);
            dp[i][0] = max(dp[i + 1][0], dp[i + 2][1] + p[i]);
        }
        return dp[0][true];
    }
};

// Space Optimization
class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<int> prev1(2), prev2(2), curr(2);
        for (int i = p.size() - 1; i >= 0; i--)
        {
            curr[1] = max(prev1[1], prev1[0] - p[i]);
            curr[0] = max(prev1[0], prev2[1] + p[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[1];
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
