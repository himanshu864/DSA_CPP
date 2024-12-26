#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution1
{
    int f(vector<int> &A, int t, int i)
    {
        if (i < 0)
            return t == 0;
        return f(A, t + A[i], i - 1) + f(A, t - A[i], i - 1);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return f(nums, target, nums.size() - 1);
    }
};

// Memoization - O(n * 4001) & O(n * 4001)
class Solution2
{
    // dp[i][t] is no. of ways to eval target with nums[0->i]
    // since target can be [-1000, 1000] and sum(nums) can also be [-1000, 1000]
    // hence target +- nums can be [-2000, 2000], hence dp[n][4001]
    int f(vector<int> &A, int t, vector<vector<int>> &dp, int i)
    {
        if (i < 0)
            return t == 0;
        if (dp[i][t + 2000] == -1)
            dp[i][t + 2000] = f(A, t + A[i], dp, i - 1) + f(A, t - A[i], dp, i - 1);
        return dp[i][t + 2000];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(4001, -1));
        return f(nums, target, dp, nums.size() - 1);
    }
};

// Tabulation - O(n * 4001) & O(n * 4001)
class Solution3
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size(), maxi = 0;
        vector<vector<int>> dp(n + 1, vector<int>(4001));
        dp[0][2000] = 1; // 1-indexed for n and 2000-indexed for target
        for (int i = 0; i < nums.size(); i++)
        {
            maxi += nums[i];
            for (int t = 2000 - maxi; t <= 2000 + maxi; t++)
                dp[i + 1][t] = dp[i][t - nums[i]] + dp[i][t + nums[i]];
        }
        return dp[n][target + 2000];
    }
};

// Space Optimization - O(n * 4001) & O(4001)
class Solution4
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<int> prev(4001);
        prev[2000] = 1;
        int maxi = 0;
        for (int i : nums)
        {
            vector<int> curr(4001);
            maxi += i;
            for (int t = 2000 - maxi; t <= 2000 + maxi; t++)
                curr[t] = prev[t - i] + prev[t + i];
            prev = curr;
        }
        return prev[target + 2000];
    }
};

/*
Since we want to find out different ways to add or minus each element in nums
eg : 1 1 1 1 1
     + - + - +

We are basically dividing them into two partitions with given difference == target
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

    S1 - S2 = target
    S1 + S2 = totalSum
 => S1 = (target + totalSum) / 2

Therefore, our question boils down to the number of subsets with sum == S1
./03.CountSubsetSum.cpp
*/

// Most Optimized - O(n * totalSum) & O(totalSum)
class Solution5
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 || totalSum < abs(target))
            return 0;

        int sum = (totalSum + target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int s = sum; s >= num; s--)
                dp[s] += dp[s - num];
        return dp[sum];
    }
};

int main()
{
    Solution5 sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}

// https://leetcode.com/problems/target-sum/
