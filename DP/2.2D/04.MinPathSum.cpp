#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
public:
    int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i == m || j == n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return grid[m - 1][n - 1];

        return grid[i][j] + min(minPathSum(grid, i + 1, j), minPathSum(grid, i, j + 1));
    }
};

// Memoization - O(m * n) & O(m + n)
class Solution2
{
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i == grid.size() || j == grid[0].size())
            return INT_MAX;

        if (dp[i][j] == -1)
            dp[i][j] = grid[i][j] + min(helper(grid, dp, i + 1, j), helper(grid, dp, i, j + 1));
        return dp[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        return helper(grid, dp, 0, 0);
    }
};

// Tabulation - O(m * n) & O(m + n)
class Solution3
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 0; // so that dp[m - 1][n - 1] doesn't become INT_MAX + bottom right

        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        return dp[0][0];
    }
};

// Space Optimization - O(m * n) & O(n)
class Solution4
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 0;

        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};

// Inplace - O(m * n) & O(1)
class Solution5
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = m - 2; i >= 0; i--)
            grid[i][n - 1] += grid[i + 1][n - 1];

        for (int j = n - 2; j >= 0; j--)
            grid[m - 1][j] += grid[m - 1][j + 1];

        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
        return grid[0][0];
    }
};

int main()
{
    Solution1 sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    cout << sol.minPathSum(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-path-sum/
