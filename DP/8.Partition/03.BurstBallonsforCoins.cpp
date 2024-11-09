#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    /*
    this is clearly a partition DP problem
    but we can't seem to solve f(i, k) and f(k, j) independently
    since they both depend on each other

    That's why we think in reverse
    Any of them could be the last remaining guy
    for that k, ans = (1 * k * 1) + f(0, k - 1) + f(k + 1, n - 1)
    now obverse that for 2nd last pop, there must be nums[k] as a value
    hence for left partition, right out of bounds is nums[k] and vice versa for right on its left
    hence they are independent. There for partition dp success

    */

    // (i, j) is the range of indices from which we can choose which ballon should have burst for max ans
    // and left and right of this ballon doesn't lie in the range. Instead are [i - 1] and [j + 1]
    // V. Imp and Hard to notice
    int f(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;

        int ans = 0;
        for (int k = i; k <= j; k++)
            ans = max(ans, nums[i - 1] * nums[k] * nums[j + 1] + f(i, k - 1, nums) + f(k + 1, j, nums));
        return ans;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        // out of bounds
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return f(1, nums.size() - 2, nums);
    }
};

// Memoization
class Solution2
{
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] == -1)
        {
            int ans = 0;
            for (int k = i; k <= j; k++)
                ans = max(ans, nums[i - 1] * nums[k] * nums[j + 1] + f(i, k - 1, nums, dp) + f(k + 1, j, nums, dp));
            dp[i][j] = ans;
        }
        return dp[i][j];
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n - 1, vector<int>(n - 1, -1));
        return f(1, n - 2, nums, dp);
    }
};

// Tabulation
class Solution3
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 2; i >= 1; i--)
            for (int j = i; j < n - 1; j++)
                for (int k = i; k <= j; k++)
                    dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
        return dp[1][n - 2];
    }
};

int main()
{
    Solution3 sol;
    vector<int> nums = {3, 1, 5, 8};
    cout << sol.maxCoins(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/burst-balloons/
