#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    int f(int i, int j, vector<int> &cuts)
    {
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
            ans = min(ans, cuts[j] - cuts[i] + f(i, k, cuts) + f(k, j, cuts));
        return ans == INT_MAX ? 0 : ans;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return f(0, cuts.size() - 1, cuts);
    }
};

// Memoization
class Solution2
{
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (dp[i][j] == -1)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
                ans = min(ans, cuts[j] - cuts[i] + f(i, k, cuts, dp) + f(k, j, cuts, dp));
            dp[i][j] = ans == INT_MAX ? 0 : ans;
        }
        return dp[i][j];
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return f(0, cuts.size() - 1, cuts, dp);
    }
};

// Tabulation
class Solution3
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m));
        for (int i = m - 2; i >= 0; i--)
            for (int j = i + 1; j < m; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    ans = min(ans, cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                dp[i][j] = ans == INT_MAX ? 0 : ans;
            }
        return dp[0][m - 1];
    }
};

int main()
{
    Solution3 sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << sol.minCost(n, cuts) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
