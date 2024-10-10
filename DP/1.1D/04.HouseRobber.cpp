#include <iostream>
#include <vector>
using namespace std;

// Recursion - O(2^n) & O(n)
class Solution1
{
    int helper(vector<int> &nums, int i)
    {
        if (i < 0)
            return 0;
        int pick = nums[i] + helper(nums, i - 2);
        int notpick = helper(nums, i - 1);
        return max(pick, notpick);
    }

public:
    int rob(vector<int> &nums)
    {
        return helper(nums, nums.size() - 1);
    }
};

// Memoization - O(n) & O(n)
class Solution2
{
    int helper(vector<int> &nums, vector<int> &dp, int i)
    {
        if (i < 0)
            return 0;
        if (dp[i] == -1)
        {
            int pick = nums[i] + helper(nums, dp, i - 2);
            int notpick = helper(nums, dp, i - 1);
            dp[i] = max(pick, notpick);
        }
        return dp[i];
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return helper(nums, dp, nums.size() - 1);
    }
};

// Tabulation - O(n) & O(n)
class Solution3
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        return dp[n - 1];
    }
};

// Iterative - O(n) & O(1)
class Solution4
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main()
{
    Solution4 sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.rob(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/house-robber/
