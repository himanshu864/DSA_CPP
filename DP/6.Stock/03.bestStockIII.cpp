#include <iostream>
#include <vector>
using namespace std;

/*
0 -> buy first
1 -> sell first
2 -> buy second
3 -> sell second
*/

// Recursion - O(n) & O(n)
class Solution1
{
public:
    int maxProfit(vector<int> &p, int i = 0, int x = 0)
    {
        if (i == p.size())
            return 0;

        int ans = maxProfit(p, i + 1, x); // skip

        if (x == 0)
            ans = max(ans, maxProfit(p, i + 1, 1) - p[i]); // buy first
        else if (x == 2)
            ans = max(ans, maxProfit(p, i + 1, 3) - p[i]); // sell first
        else if (x == 1)
            ans = max(ans, maxProfit(p, i + 1, 2) + p[i]); // buy second
        else
            ans = max(ans, p[i]); // sell second

        return ans;
    }
};

// Optimized Tabulation - O(n) & O(1)
class Solution2
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<int> dp(4);
        for (int i = p.size() - 1; i >= 0; i--)
            for (int x = 0; x < 4; x++)
            {
                if (x == 0)
                    dp[x] = max(dp[x], dp[1] - p[i]);
                else if (x == 2)
                    dp[x] = max(dp[x], dp[3] - p[i]);
                else if (x == 1)
                    dp[x] = max(dp[x], dp[2] + p[i]);
                else
                    dp[x] = max(dp[x], p[i]);
            }
        return dp[0];
    }
};

int main()
{
    Solution2 sol;
    vector<int> prices = {3, 3, 5, 0, 3, 1, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
