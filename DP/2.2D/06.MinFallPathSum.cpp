#include <iostream>
#include <vector>
using namespace std;

// Recursion - O(3^n) & O(n)
class Solution1
{
    int f(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        if (i == n)
            return 0;
        if (j < 0 || j == n)
            return INT_MAX;

        int mini = INT_MAX;
        mini = min(mini, f(grid, i + 1, j - 1));
        mini = min(mini, f(grid, i + 1, j));
        mini = min(mini, f(grid, i + 1, j + 1));
        return grid[i][j] + mini;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
            ans = min(ans, f(matrix, 0, i));
        return ans;
    }
};

// Memoization - O(n^2) & O(n^2)
class Solution2
{
    int f(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i == grid.size())
            return 0;
        if (j < 0 || j == grid.size())
            return INT_MAX;

        if (dp[i][j] == INT_MAX)
        {
            int mini = INT_MAX;
            mini = min(mini, f(grid, dp, i + 1, j - 1));
            mini = min(mini, f(grid, dp, i + 1, j));
            mini = min(mini, f(grid, dp, i + 1, j + 1));
            dp[i][j] = mini + grid[i][j];
        }
        return dp[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, INT_MAX));

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, f(matrix, dp, 0, i));
        return ans;
    }
};

// Inplace Tabulation - O(n^2) & O(1)
class Solution3
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++)
                matrix[i][j] +=
                    min({matrix[i + 1][j],
                         matrix[i + 1][max(0, j - 1)],
                         matrix[i + 1][min(n - 1, j + 1)]});
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};

int main()
{
    Solution1 sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9},
    };
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-falling-path-sum/
