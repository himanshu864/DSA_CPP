#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    // curIndex, prev pick index, nums
    int f(int i, int j, vector<int> &nums)
    {
        if (i == nums.size())
            return 0;

        int notpick = f(i + 1, j, nums);
        int pick = 0;
        if (j == -1 || nums[i] > nums[j])
            pick = 1 + f(i + 1, i, nums);

        return max(pick, notpick);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return f(0, -1, nums);
    }
};

// Memoization
class Solution2
{
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == nums.size())
            return 0;

        if (dp[i][j + 1] == -1)
        {
            int notpick = f(i + 1, j, nums, dp);
            int pick = 0;
            if (j == -1 || nums[i] > nums[j])
                pick = 1 + f(i + 1, i, nums, dp);
            dp[i][j + 1] = max(pick, notpick);
        }
        return dp[i][j + 1];
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // dp cordinate shift for dp[j]; j == -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};

//  Tabulation
class Solution3
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // i is n + 1 for base case i == n
        // j is n + 1 for when no prev index j == -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--)
            for (int j = -1; j < i; j++) // prev index can't be greater than i
            {
                // Notice since dp[j] only depends on dp[j] or dp[i + 1] (which j can't be)
                // order of tabulation of j doesn't matter. Even in case of space optimization
                int notpick = dp[i + 1][j + 1];
                int pick = 0;
                if (j == -1 || nums[i] > nums[j])
                    pick = 1 + dp[i + 1][i + 1];
                dp[i][j + 1] = max(pick, notpick);
            }
        return dp[0][0];
    }
};

// Space Optimized Tabulation - O(n^2) & O(n)
class Solution4
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--)
            for (int j = -1; j < i; j++)
                if (j == -1 || nums[i] > nums[j])
                    dp[j + 1] = max(dp[j + 1], 1 + dp[i + 1]);
        return dp[0];
    }
};

// Different Solution from observation / intuition
// These above solutions work differently than what how you'd except
// You want to find LIS from all indices to end and store in a dp table
// traverse from last index to first and keep computing LIS
// Eg: last can only have one element.
// Second last can take last element if it's greater, hence dp[i] = 1 + dp[i + 1]
// Similarly calc for all indices. And return max
// O(n^2) & O(n)
class Solution5
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
                if (nums[i] < nums[j])
                    ans = max(ans, 1 + dp[j]);
            dp[i] = ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution3 sol;
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    // vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/longest-increasing-subsequence/
