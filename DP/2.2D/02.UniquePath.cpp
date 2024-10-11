#include <iostream>
#include <vector>
using namespace std;

// Recursive
class Solution1
{
    int helper(int i, int j, int m, int n)
    {
        if (i == m - 1 || j == n - 1)
            return 1;
        return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
    }

public:
    int uniquePaths(int m, int n)
    {
        return helper(0, 0, m, n);
    }
};

// Memoization - O(m*n) && O(m*n)
class Solution2
{
    int helper(vector<vector<int>> &grid, int i, int j)
    {
        if (i == grid.size() - 1 || j == grid[0].size() - 1)
            return 1;
        if (grid[i][j] == -1)
            grid[i][j] = helper(grid, i + 1, j) + helper(grid, i, j + 1);
        return grid[i][j];
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        return helper(grid, 0, 0);
    }
};

// Tabulation - 6 minutes 10 seconds - O(m*n) && O(m*n)
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
        return grid[0][0];
    }
};

// Space Optimization - O(m * n) && O(n)
class Solution4
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);
        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                dp[j] += dp[j + 1];
        return dp[0];
    }
};

int main()
{
    Solution2 sol;
    int m = 3;
    int n = 7;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}

// https://leetcode.com/problems/unique-paths/
