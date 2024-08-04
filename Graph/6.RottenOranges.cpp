#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> fd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> rotten;

        // bfs with intial rotten
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 1)
                    fresh++;
                if (grid[r][c] == 2)
                    rotten.push({r, c});
            }

        // V.IMP fresh check
        while (rotten.size() && fresh)
        {
            ans++;
            for (int s = rotten.size(); s; s--)
            {
                for (auto d : fd)
                {
                    int nr = rotten.front().first + d.first;
                    int nc = rotten.front().second + d.second;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                    {
                        fresh--;
                        grid[nr][nc] = 2;
                        rotten.push({nr, nc});
                    }
                }
                rotten.pop();
            }
        }
        return fresh ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/rotting-oranges/
