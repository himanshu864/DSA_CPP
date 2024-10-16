#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Recursion
class Solution1
{
    // To partition array with equal sum. both subsets must have totalSum / 2 sum.
    // Hence simply check if possible to make a subset with sum = totalSum / 2
    bool helper(vector<int> &arr, int i, int sum)
    {
        if (sum < 0)
            return false;
        if (sum == 0)
            return true;
        if (i == 0)
            return arr[i] == sum;
        return helper(arr, i - 1, sum) || helper(arr, i - 1, sum - arr[i]);
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2)
            return false;
        return helper(nums, nums.size() - 1, totalSum / 2);
    }
};

// Memoization - O(n * sum) & O(n * sum)
class Solution2
{
    bool helper(vector<int> &arr, vector<vector<int>> &dp, int i, int sum)
    {
        if (sum < 0)
            return false;
        if (dp[i][sum] == -1)
        {
            if (sum == 0)
                dp[i][sum] = true;
            else if (i == 0)
                dp[0][sum] = arr[0] == sum;
            else
                dp[i][sum] = helper(arr, dp, i - 1, sum) || helper(arr, dp, i - 1, sum - arr[i]);
        }
        return dp[i][sum];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2)
            return false;

        vector<vector<int>> dp(nums.size(), vector<int>((totalSum / 2) + 1, -1));
        return helper(nums, dp, nums.size() - 1, totalSum / 2);
    }
};

// Space Optimized Tabulation - O(n * sum) && O(sum)
class Solution3
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2)
            return false;
        int sum = totalSum / 2;

        vector<bool> prev(sum + 1, false);
        prev[0] = true;

        // can go out of bounds
        if (sum >= nums[0])
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(sum + 1, false);
            prev[0] = true;
            for (int s = 1; s <= sum; s++)
            {
                bool pick = (s >= nums[i]) ? prev[s - nums[i]] : false;
                bool notpick = prev[s];
                curr[s] = pick || notpick;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

int main()
{
    Solution3 sol;
    vector<int> nums = {1, 5, 11, 5};
    // vector<int> nums = {1, 2, 3, 5};
    // vector<int> nums = {100};
    cout << sol.canPartition(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/partition-equal-subset-sum/
