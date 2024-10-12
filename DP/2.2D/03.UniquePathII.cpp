#include <iostream>
#include <vector>
using namespace std;

// Recursion - Time : O(2^(m + n)) & Space - O(m + n)
class Solution1
{
    int helper(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m || j == n)
            return 0;
        if (grid[i][j] == 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        return helper(grid, i + 1, j) + helper(grid, i, j + 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        return helper(grid, 0, 0);
    }
};

// Memoization - Time : O(m * n) & Space : O(m + n) - stack
class Solution2
{
    int helper(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m || j == n)
            return 0;
        if (grid[i][j] == -1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (grid[i][j] == 0)
            grid[i][j] = helper(grid, i + 1, j) + helper(grid, i, j + 1);
        return grid[i][j];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    grid[i][j] = -1;
        return helper(grid, 0, 0);
    }
};

// Tabulation - Time : O(m * n) & Space : O(m + n) - dp
class Solution3
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1));
        dp[m - 1][n] = 1; // so that dp[m - 1][n - 1] = down + right = 0 + 1 = 1
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (grid[i][j] != 1)
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        return dp[0][0];
    }
};

// Space Optimization - Time : O(m * n) & Space : O(n)
class Solution4
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<long> dp(n + 1);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] += dp[j + 1];
            }
        return dp[0];
    }
};

int main()
{
    Solution4 sol;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    cout << sol.uniquePathsWithObstacles(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/unique-paths-ii/
