#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int ans = INT_MIN;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                int mini = INT_MAX;
                if (i == 0 && j == 0)
                    continue;
                if (i)
                    mini = min(mini, grid[i - 1][j]);
                if (j)
                    mini = min(mini, grid[i][j - 1]);

                ans = max(ans, grid[i][j] - mini);
                grid[i][j] = min(grid[i][j], mini);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {9, 5, 7, 3},
        {8, 9, 6, 1},
        {6, 7, 14, 3},
        {2, 5, 3, 1}};
    cout << sol.maxScore(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-difference-score-in-a-grid/
