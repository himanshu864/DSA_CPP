#include <iostream>
#include <vector>
using namespace std;

// At most 2 transactions

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

        if (x == 3)
            ans = max(ans, p[i]); // sell second
        else if (x % 2 == 0)
            ans = max(ans, maxProfit(p, i + 1, x + 1) - p[i]); // first buy
        else
            ans = max(ans, maxProfit(p, i + 1, x + 1) + p[i]); // then sell

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
        {
            for (int x = 0; x < 3; x++)
            {
                if (x % 2 == 0)
                    dp[x] = max(dp[x], dp[x + 1] - p[i]);
                else
                    dp[x] = max(dp[x], dp[x + 1] + p[i]);
            }
            dp[3] = max(dp[3], p[i]);
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
