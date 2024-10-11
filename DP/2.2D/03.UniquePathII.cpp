#include <iostream>
#include <vector>
using namespace std;

// Recursion
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

// Memoization
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

// Tabulation ig
class Solution3
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<long>> dp(m, vector<long>(n, -1));

        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = 1;
                else if (grid[i][j] != 1)
                {
                    long down = (i + 1 < m) ? dp[i + 1][j] : 0;
                    long right = (j + 1 < n) ? dp[i][j + 1] : 0;
                    dp[i][j] = down + right;
                }
                else
                    dp[i][j] = 0;
            }
        return dp[0][0];
    }
};
;

int main()
{
    Solution1 sol;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    // vector<vector<int>> grid = {
    //     {0, 0},
    //     {1, 1},
    //     {0, 0},
    // };
    cout << sol.uniquePathsWithObstacles(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/unique-paths-ii/
