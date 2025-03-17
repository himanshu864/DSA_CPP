#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution
{
    // minimum k to make target zero
    int helper(int k, int target, int idx, vvi &queries, vvi &dp)
    {
        if (target == 0)
            return k;
        if (target < 0 || k == queries.size())
            return queries.size() + 1;
        if (dp[k][target] != -1)
            return dp[k][target];

        int l = queries[k][0], r = queries[k][1], val = queries[k][2];

        int pick = queries.size() + 1;
        if (idx >= l && idx <= r)
            pick = helper(k + 1, target - val, idx, queries, dp);
        int notpick = helper(k + 1, target, idx, queries, dp);
        return dp[k][target] = min(pick, notpick);
    }

public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        // for each num[i], minimum queries required to make it zero
        // take maximum of all of them or return -1 if anyone not possible
        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            vvi dp(queries.size() + 1, vi(nums[i] + 1, -1));
            ans = max(ans, helper(0, nums[i], i, queries, dp));
        }
        return ans > queries.size() ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vi nums = {2, 0, 2};
    vvi queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << sol.minZeroArray(nums, queries) << endl;
    return 0;
}

// https://leetcode.com/problems/zero-array-transformation-iv/
