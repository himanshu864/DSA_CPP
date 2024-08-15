#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    string dfs(vector<vector<int>> &grid, int i, int j, char c)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || !grid[i][j])
            return "";
        grid[i][j] = 0;
        string ans = "";
        ans += c;
        ans += dfs(grid, i + 1, j, 'D');
        ans += dfs(grid, i, j + 1, 'R');
        ans += dfs(grid, i - 1, j, 'U');
        ans += dfs(grid, i, j - 1, 'L');
        ans += " ";
        return ans;
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        unordered_set<string> maps;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j])
                {
                    string map = dfs(grid, i, j, '>');
                    maps.insert(map);
                }
        return maps.size();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
    };
    cout << sol.countDistinctIslands(grid) << endl;
    return 0;
}
