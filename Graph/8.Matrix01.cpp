#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                    q.push({i, j});

        int x = 0;
        while (q.size())
        {
            for (int s = q.size(); s; s--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (i < 0 || i == m || j < 0 || j == n)
                    continue;
                if (ans[i][j] <= x)
                    continue;
                ans[i][j] = x;
                q.push({i + 1, j});
                q.push({i, j + 1});
                q.push({i - 1, j});
                q.push({i, j - 1});
            }
            x++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1}};

    vector<vector<int>> ans = sol.updateMatrix(mat);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
