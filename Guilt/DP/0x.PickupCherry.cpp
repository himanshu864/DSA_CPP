#include <iostream>
#include <vector>
using namespace std;

// Backtracking Delhi + Memoize Hisar
class Solution
{
    // Recursive Funtion which backtracks from start to end while changing path
    // And then calls a memoized recursion, which returns max remaining pickup possible from end to start
    int delhi(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid[0].size();
        if (i == n || j == n || grid[i][j] == -1)
            return -1;

        bool cherry = false;
        if (grid[i][j])
        {
            grid[i][j] = 0;
            cherry = true;
        }

        int maxi = max(delhi(grid, i + 1, j), delhi(grid, i, j + 1));
        if (i == n - 1 && j == n - 1)
        {
            vector<vector<int>> dp(n, vector<int>(n, -2));
            dp[0][0] = 0;
            maxi = hisar(grid, dp, i, j);
        }

        if (maxi == -1)
            return -1;

        if (cherry)
            grid[i][j] = 1;
        return maxi + cherry;
    }

    int hisar(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0 || j < 0 || grid[i][j] == -1)
            return -1;

        if (dp[i][j] == -2)
        {
            int maxi = max(hisar(grid, dp, i - 1, j), hisar(grid, dp, i, j - 1));
            if (maxi == -1)
            {
                dp[i][j] = -1;
                return -1;
            }

            if (grid[i][j])
                maxi++;
            dp[i][j] = maxi;
        }
        return dp[i][j];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int ans = delhi(grid, 0, 0);
        if (ans == -1)
            return 0;
        return ans;
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> grid = {
    //     {0, 1, -1},
    //     {1, 0, -1},
    //     {1, 1, 1},
    // };
    // vector<vector<int>> grid = {
    //     {0, 0, 0},
    //     {-1, -1, 0},
    //     {0, 1, 1},
    // };
    // vector<vector<int>> grid = {{1}};
    // vector<vector<int>> grid = {
    //     {0, 0, 0, 1},
    //     {0, 0, 0, 1},
    //     {0, 0, 0, -1},
    //     {0, 1, 0, 0},
    // };
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1},
    };
    cout << sol.cherryPickup(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/cherry-pickup/
