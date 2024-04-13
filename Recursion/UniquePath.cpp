#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(vector<vector<int>> &ans, int m, int n, int row, int col)
{
    if (row == m - 1 || col == n - 1)
        return 1;
    if (ans[row][col] == 1)
        ans[row][col] = helper(ans, m, n, row + 1, col) + helper(ans, m, n, row, col + 1);
    return ans[row][col];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> ans(m, vector<int>(n, 1));
    return helper(ans, m, n, 0, 0);
}

int main()
{
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << endl;
    return 0;
}

// draw grid on paper and realise it's pascal
// https://leetcode.com/problems/unique-paths/

// can also try this variation
// https://leetcode.com/problems/unique-paths-ii/
