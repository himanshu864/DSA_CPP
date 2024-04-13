#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // if (grid[i][j] > k)
                //     break;

                if (i)
                    grid[i][j] += grid[i - 1][j];
                if (j)
                    grid[i][j] += grid[i][j - 1];
                if (i && j)
                    grid[i][j] -= grid[i - 1][j - 1];

                if (grid[i][j] <= k)
                    ans++;
                // else
                // break;
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
    int k = 20;
    cout << sol.countSubmatrices(grid, k) << endl;
    return 0;
}
