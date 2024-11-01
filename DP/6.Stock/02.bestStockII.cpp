#include <iostream>
#include <vector>
using namespace std;

// can buy and sell one stock as many times as we want, for max profit

// Recursion
class Solution1
{
    int helper(int i, bool canBuy, vector<int> &prices)
    {
        if (i == prices.size())
            return 0;

        int pick = 0, notpick = 0;
        if (canBuy)
        {
            pick = helper(i + 1, false, prices) - prices[i];
            notpick = helper(i + 1, true, prices);
        }
        else
        {
            pick = helper(i + 1, true, prices) + prices[i];
            notpick = helper(i + 1, false, prices);
        }
        return max(pick, notpick);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return helper(0, true, prices);
    }
};

// Space Optimized Tabulation - O(N) & O(1)
class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(2);
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            vector<int> prev = dp;
            dp[1] = max(prev[0] - prices[i], prev[1]);
            dp[0] = max(prev[1] + prices[i], prev[0]);
        }
        return dp[1];
    }
};

// profit = sum of all (local peak - local valley)
// Greedy - O(N) & O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
