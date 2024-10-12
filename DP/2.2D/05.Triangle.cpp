#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
public:
    int minimumTotal(vector<vector<int>> &triangle, int row = 0, int index = 0)
    {
        if (row == triangle.size())
            return 0;
        int a = minimumTotal(triangle, row + 1, index);
        int b = minimumTotal(triangle, row + 1, index + 1);
        return triangle[row][index] + min(a, b);
    }
};

// Memoization
class Solution2
{
    int mod = 1e9 + 7;
    int f(vector<vector<int>> &t, vector<vector<int>> &dp, int r, int i)
    {
        if (r == t.size())
            return 0;
        if (dp[r][i] == mod)
        {
            int a = f(t, dp, r + 1, i);
            int b = f(t, dp, r + 1, i + 1);
            dp[r][i] = t[r][i] + min(a, b);
        }
        return dp[r][i];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle, int row = 0, int index = 0)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, mod));
        return f(triangle, dp, 0, 0);
    }
};

// I mean..
class Solution3
{
public:
    int minimumTotal(vector<vector<int>> &t)
    {
        int n = t.size();
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
        return t[0][0];
    }
};

int main()
{
    Solution1 sol;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal(triangle) << endl;
    return 0;
}

// https://leetcode.com/problems/triangle/
