#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return;
        if (!grid[i][j] || visited[i][j])
            return;
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j - 1);
    }
    int totalIslands(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] && !visited[i][j])
                {
                    dfs(grid, visited, i, j);
                    ans++;
                }
        return ans;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        if (totalIslands(grid) != 1)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    if (totalIslands(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
        return 2;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << sol.minDays(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island
