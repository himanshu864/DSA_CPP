#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        // 0. dp[i][j] is the max size square possible from (i, j) as it's bottom right
        // 1. Copy first col and row, since only size one possible
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = matrix[i][0];
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        // 2. Tabulation for maxSize square possible
        int r = 0, c = 0;
        while (++r < m && ++c < n)
        {
            for (int i = r; i < m; i++)
                if (matrix[i][c])
                    dp[i][c] = 1 + min({dp[i - 1][c], dp[i][c - 1], dp[i - 1][c - 1]});

            for (int j = c; j < n; j++)
                if (matrix[r][j])
                    dp[r][j] = 1 + min({dp[r - 1][j], dp[r][j - 1], dp[r - 1][j - 1]});
        }

        // 3. ans will be sum of all squares
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += dp[i][j];
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1},
    };
    cout << sol.countSquares(matrix) << endl;
    return 0;
}

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
