#include <iostream>
#include <vector>
using namespace std;

// One stock. Infinite Transations. No overlapping. But tax on each transaction.

class Solution
{
public:
    int maxProfit(vector<int> &p, int tax)
    {
        vector<int> dp(2);
        for (int i = p.size() - 1; i >= 0; i--)
        {
            vector<int> prev = dp;
            dp[1] = max(prev[1], prev[0] - p[i] - tax);
            dp[0] = max(prev[0], prev[1] + p[i]);
        }
        return dp[1];
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << sol.maxProfit(prices, fee) << endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
