#include <iostream>
#include <vector>
using namespace std;

// At most k transactions. No simulatenous.

// Using same logic as bestStockIII.cpp
class Solution
{
public:
    int maxProfit(int k, vector<int> &p)
    {
        int l = 2 * k - 1; // at most k buys and k sells
        vector<int> dp(l + 1);
        for (int i = p.size() - 1; i >= 0; i--)
        {
            for (int x = 0; x < l; x++)
            {
                if (x % 2 == 0)
                    dp[x] = max(dp[x], dp[x + 1] - p[i]); // first buy
                else
                    dp[x] = max(dp[x], dp[x + 1] + p[i]); // then sell
            }
            dp[l] = max(dp[l], p[i]); // can only sell kth stock
        }
        // Notice: dp = max(dp, ...) and 1D Tabulation,
        // takes care of skipping possibility
        return dp[0];
    }
};

int main()
{
    Solution sol;
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << sol.maxProfit(k, prices) << endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
