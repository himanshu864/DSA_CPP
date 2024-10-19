#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Recursion
class Solution1
{
    int f(int i, int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 0;
        if (i < 0)
            return 1e9;
        int take = coins[i] <= amount ? f(i, amount - coins[i], coins) + 1 : INT_MAX;
        int notake = f(i - 1, amount, coins);
        return min(take, notake);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = f(coins.size() - 1, amount, coins);
        return ans < 1e9 ? ans : -1;
    }
};

// Memoization - O(n * amount) & O(n * amount)
class Solution2
{
    // dp[i][amount] are minCoins required to sum amount from coins[0->i]
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (i < 0)
            return 1e9;
        if (dp[i][amount] == -1)
        {
            int take = INT_MAX;
            if (coins[i] <= amount)
                take = f(i, amount - coins[i], coins, dp) + 1;
            int notake = f(i - 1, amount, coins, dp);
            dp[i][amount] = min(take, notake);
        }
        return dp[i][amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;
        int ans = f(n - 1, amount, coins, dp);
        return ans < 1e9 ? ans : -1;
    }
};

// Tabulation - O(n * amount) & O(n * amount)
class Solution3
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // zero coins required for amount = 0
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;

        // can only take amount / coins[0] with only 0th coin
        for (int j = 1; j <= amount; j++)
            dp[0][j] = j % coins[0] ? 1e9 : j / coins[0];

        for (int i = 1; i < n; i++)
            for (int j = 1; j <= amount; j++)
            {
                int take = coins[i] <= j ? dp[i][j - coins[i]] + 1 : INT_MAX;
                int notake = dp[i - 1][j];
                dp[i][j] = min(take, notake);
            }

        return dp[n - 1][amount] < 1e9 ? dp[n - 1][amount] : -1;
    }
};

// Space Optimization - O(n * amount) & O(amount)
// Holy shit dude
class Solution4
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i : coins)
            for (int j = 1; j <= amount; j++)
                if (i <= j)
                    dp[j] = min(dp[j - i] + 1, dp[j]);
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};

int main()
{
    Solution4 sol;
    vector<int> coins = {1, 3, 5};
    int amount = 8;
    // vector<int> coins = {3, 5};
    // int amount = 7;
    cout << sol.coinChange(coins, amount) << endl;
    return 0;
}

// https://leetcode.com/problems/coin-change/
