#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combination = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 0},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1},
};

// Recursion
class Solution1
{
    // max cherriesPickup possible from that row to bottom, if robots on j1 and j2
    int helper(vector<vector<int>> &grid, int row, int j1, int j2)
    {
        int n = grid[0].size();
        if (j1 < 0 || j2 < 0 || j1 == n || j2 == n || row == grid.size())
            return 0;

        int currCherries = grid[row][j1] + grid[row][j2];
        if (j1 == j2) // if both robo same cell. Only count once
            currCherries /= 2;

        int maxi = 0;
        for (vector<int> c : combination) // total 9 possibilities
            maxi = max(maxi, helper(grid, row + 1, j1 + c[0], j2 + c[1]));
        return currCherries + maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        return helper(grid, 0, 0, grid[0].size() - 1);
    }
};

// Memoizaton
class Solution2
{
    int helper(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row, int j1, int j2)
    {
        int n = grid[0].size();
        if (j1 < 0 || j2 < 0 || j1 == n || j2 == n || row == grid.size())
            return 0;

        if (dp[row][j1][j2] == -1)
        {
            int currCherries = grid[row][j1] + grid[row][j2];
            if (j1 == j2)
                currCherries /= 2;

            int maxi = 0;
            for (vector<int> c : combination)
                maxi = max(maxi, helper(grid, dp, row + 1, j1 + c[0], j2 + c[1]));
            dp[row][j1][j2] = currCherries + maxi;
        }
        return dp[row][j1][j2];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // memoize max cherryPickups for {row, j1, j2}
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(grid, dp, 0, 0, n - 1);
    }
};

// Tabulation
class Solution3
{
    bool isValid(int n, int a, int b)
    {
        return (a >= 0 && a < n && b >= 0 && b < n);
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int row = m - 1; row >= 0; row--)
            for (int j1 = 0; j1 < n; j1++)
                for (int j2 = 0; j2 < n; j2++)
                {
                    int currCherries = grid[row][j1] + grid[row][j2];
                    if (j1 == j2)
                        currCherries /= 2;

                    int maxi = 0;
                    for (vector<int> c : combination)
                        if (isValid(n, j1 + c[0], j2 + c[1]))
                            maxi = max(maxi, dp[row + 1][j1 + c[0]][j2 + c[1]]);
                    dp[row][j1][j2] = currCherries + maxi;
                }
        return dp[0][0][n - 1];
    }
};

// Space Optimization
class Solution4
{
    bool isValid(int n, int a, int b)
    {
        return (a >= 0 && a < n && b >= 0 && b < n);
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // tabulate max cherryPickups for {row, j1, j2}
        // base case for (m + 1)th row
        vector<vector<int>> prev(n, vector<int>(n, 0));

        for (int row = m - 1; row >= 0; row--)
        {
            vector<vector<int>> curr(n, vector<int>(n, 0));
            for (int j1 = 0; j1 < n; j1++)
                for (int j2 = 0; j2 < n; j2++)
                {
                    int currCherries = grid[row][j1] + grid[row][j2];
                    if (j1 == j2)
                        currCherries /= 2;

                    int maxi = 0;
                    for (vector<int> c : combination)
                        if (isValid(n, j1 + c[0], j2 + c[1]))
                            maxi = max(maxi, prev[j1 + c[0]][j2 + c[1]]);
                    curr[j1][j2] = currCherries + maxi;
                }
            prev = curr;
        }
        return prev[0][n - 1];
    }
};

int main()
{
    Solution4 sol;
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1},
    };
    cout << sol.cherryPickup(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/cherry-pickup-ii
