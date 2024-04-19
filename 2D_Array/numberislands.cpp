#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i == -1 || j == -1 || i == grid.size() || j == grid[0].size())
            return;
        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        bfs(grid, i + 1, j);
        bfs(grid, i, j + 1);
        bfs(grid, i - 1, j);
        bfs(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    ans++;
                }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '0'}, {'0', '0', '1'}};
    cout << sol.numIslands(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/number-of-islands/
