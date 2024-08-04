#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int orangesrotting(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        while (true)
        {
            vector<pair<int, int>> rotten;
            for (int r = 0; r < m; r++)
                for (int c = 0; c < n; c++)
                    if (grid[r][c] == 2)
                        rotten.push_back({r, c});

            bool flag = true;
            for (auto p : rotten)
            {
                int r = p.first, c = p.second;
                if (grid[p.first][p.second] == 2)
                {
                    if (r > 0 && grid[r - 1][c] == 1)
                        grid[r - 1][c] = 2, flag = false;
                    if (c > 0 && grid[r][c - 1] == 1)
                        grid[r][c - 1] = 2, flag = false;
                    if (r + 1 < m && grid[r + 1][c] == 1)
                        grid[r + 1][c] = 2, flag = false;
                    if (c + 1 < n && grid[r][c + 1] == 1)
                        grid[r][c + 1] = 2, flag = false;
                }
            }
            if (flag)
                break;
            ans++;
        }

        for (auto i : grid)
            for (int j : i)
                if (j == 1)
                    return -1;
        return ans;
    }
};

int main()
{
    solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << sol.orangesrotting(grid) << endl;
    return 0;
}
