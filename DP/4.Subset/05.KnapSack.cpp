#include <iostream>
#include <vector>
using namespace std;

// Recursion - O(2^n)
class Solution1
{
public:
    // W -> remaining capacity
    int knapSack(int W, vector<int> &wt, vector<int> &val, int i = 0)
    {
        if (i == wt.size())
            return 0;
        int pick = wt[i] <= W ? val[i] + knapSack(W - wt[i], wt, val, i + 1) : 0;
        int notpick = knapSack(W, wt, val, i + 1);
        return max(pick, notpick);
    }
};

// Memoization - O(n * W) & O(n * W)
class Solution2
{
    // dp[i][w] represents maximum value that can be robbed with arr[0->i] and remaining capacity = w
    vector<vector<int>> dp;
    int f(int W, vector<int> &wt, vector<int> &val, int i)
    {
        if (i < 0)
            return 0;
        if (dp[i][W] == -1)
        {
            int pick = wt[i] <= W ? val[i] + f(W - wt[i], wt, val, i - 1) : 0;
            int notpick = f(W, wt, val, i - 1);
            dp[i][W] = max(pick, notpick);
        }
        return dp[i][W];
    }

public:
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int n = wt.size();
        dp.resize(n, vector<int>(W + 1, -1)); // 1-indexed for base case
        return f(W, wt, val, n - 1);
    }
};

// Tabulation - O(n * W) & O(n * W)
class Solution3
{
public:
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1)); // 1-indexed for base case
        for (int i = 0; i < n; i++)
            for (int w = 0; w <= W; w++)
            {
                int pick = wt[i] <= w ? val[i] + dp[i][w - wt[i]] : 0;
                int notpick = dp[i][w];
                dp[i + 1][w] = max(pick, notpick);
            }
        return dp[n][W];
    }
};

// Even more Space Optimization - O(n * W) & O(W)
class Solution4
{
public:
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int n = wt.size();
        vector<int> prev(W + 1);
        for (int i = 0; i < n; i++)
            for (int w = W; w >= 0; w--)
            {
                int pick = wt[i] <= w ? val[i] + prev[w - wt[i]] : 0;
                int notpick = prev[w];
                prev[w] = max(pick, notpick);
            }
        return prev[W];
    }
};

int main()
{
    Solution4 sol;
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    int W = 8;
    cout << sol.knapSack(W, wt, val) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

/*
If each item can be taken any number of times.

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<int> dp(W + 1);
        for (int i = 0; i < N; i++)
            for (int w = wt[i]; w <= W; w++)
                dp[w] = max(val[i] + dp[w - wt[i]], dp[w]);
        return dp[W];
    }
};

// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/