#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long ans = LLONG_MAX;
        int n = grid[0].size();
        vector<long long> prefix(n), suffix(n);
        // calculate suffix sum for first row
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += grid[0][i];
            suffix[i] = sum;
        }
        // calculate prefix sum for second row
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += grid[1][i];
            prefix[i] = sum;
        }

        // the point where robo one switches lanes,
        // is the point from where robo two either picks up either
        // upper left over or lower left out elements
        for (int i = 0; i < n; i++)
        {
            long long upper = i > 0 ? prefix[i - 1] : 0;
            long long lower = i + 1 < n ? suffix[i + 1] : 0;
            ans = min(ans, max(upper, lower));
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {3, 3, 1},
        {8, 5, 2},
    };
    // vector<vector<int>> grid = {
    //     {20, 3, 20},
    //     {20, 10, 13},
    // };
    cout << sol.gridGame(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/grid-game/
