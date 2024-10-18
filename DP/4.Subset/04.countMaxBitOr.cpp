#include <iostream>
#include <vector>
using namespace std;

// Concise recursion - O(2^n) & O(n)
class Solution1
{
    // number of subsets from nums[0 -> i] with BitOR == maxi
    int helper(vector<int> &nums, int maxi, int output, int i)
    {
        if (i < 0)
            return output == maxi;
        int pick = helper(nums, maxi, output | nums[i], i - 1);
        int notpick = helper(nums, maxi, output, i - 1);
        return pick + notpick;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxi = 0;
        for (int i : nums)
            maxi |= i;
        return helper(nums, maxi, 0, nums.size() - 1);
    }
};

// Memoization - O(n * maxi) & O(n * maxi)
class Solution2
{
    int helper(vector<int> &nums, int maxi, vector<vector<int>> &dp, int i, int output)
    {
        if (i < 0)
            return output == maxi;
        if (dp[i][output] == -1)
        {
            int pick = helper(nums, maxi, dp, i - 1, output | nums[i]);
            int notpick = helper(nums, maxi, dp, i - 1, output);
            dp[i][output] = pick + notpick;
        }
        return dp[i][output];
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxi = 0;
        for (int i : nums)
            maxi |= i;
        vector<vector<int>> dp(nums.size(), vector<int>(maxi + 1, -1));
        return helper(nums, maxi, dp, nums.size() - 1, 0);
    }
};

// Space Optimized Tabulation - O(n * maxi) * O(maxi)
class Solution3
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 0;
        for (int i : nums)
            maxi |= i;

        // dp[output] represents number of subsets with bitOR == output for arr[0->i]
        vector<int> prev(maxi + 1);
        prev[0] = 1; // OR of empty subset is 0

        // process each element
        for (int i = 0; i < n; i++)
        {
            vector<int> curr = prev; // Carry over the previous values for non-pick case
            for (int output = 0; output <= maxi; output++)
                if ((output | nums[i]) <= maxi)
                    curr[output | nums[i]] += prev[output]; // Update output for new OR
            prev = curr;
        }
        return prev[maxi];
    }
};

// First try efficient Backtracking - O(2^n) & O(n)
class Solution4
{
    int ans = 0, maxi = 0;
    // backtracks all subsets OR's from 0 -> n. and ++ for maxi
    void helper(vector<int> &nums, int output, int i)
    {
        if (i == nums.size())
        {
            if (output == maxi)
                ans++;
            return;
        }
        helper(nums, output, i + 1);
        helper(nums, output | nums[i], i + 1);
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        for (int i : nums)
            maxi |= i;
        helper(nums, 0, 0);
        return ans;
    }
};

int main()
{
    Solution4 sol;
    vector<int> nums = {3, 2, 1, 5};
    cout << sol.countMaxOrSubsets(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
