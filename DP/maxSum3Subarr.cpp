#include <bits/stdc++.h>
using namespace std;

// Prefix Suffix + 3 pointers
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        // Calculate subarray sums using Sliding window
        int n = nums.size() - k + 1;
        vector<int> subSum(n);
        for (int i = 0, sum = 0; i < n + k - 1; i++)
        {
            sum += nums[i];
            if (i - k >= 0)
                sum -= nums[i - k];
            if (i - k + 1 >= 0)
                subSum[i - k + 1] = sum;
        }

        // Calculate prefix max indices
        vector<int> prefix(n);
        for (int i = 1; i < n; i++)
            prefix[i] = (subSum[i] > subSum[prefix[i - 1]]) ? i : prefix[i - 1];

        // Calculate suffix max indices
        vector<int> suffix(n);
        suffix.back() = n - 1;
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = (subSum[i] >= subSum[suffix[i + 1]]) ? i : suffix[i + 1];

        // Find the maximum sum of three subarrays
        vector<int> ans(3);
        int maxSum = 0;
        for (int mid = k; mid < n - k; mid++)
        {
            int l = prefix[mid - k];
            int r = suffix[mid + k];
            int sum = subSum[l] + subSum[mid] + subSum[r];
            if (sum > maxSum)
            {
                maxSum = sum;
                ans = {l, mid, r};
            }
        }
        return ans;
    }
};

// Genius DP
class Solution2
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        // Calculate subarray sums using Sliding window
        int n = nums.size() - k + 1;
        vector<int> subSum(n);
        for (int i = 0, sum = 0; i < n + k - 1; i++)
        {
            sum += nums[i];
            if (i - k >= 0)
                sum -= nums[i - k];
            if (i - k + 1 >= 0)
                subSum[i - k + 1] = sum;
        }

        // Bottom up DP to find maxSum from index i and picked subarr's count
        vector<vector<int>> dp(n, vector<int>(3, -1));
        for (int i = n - 1; i >= 0; i--)
            for (int count = 0; count < 3; count++)
            {
                int pick = subSum[i] + (i + k < n && count < 2 ? dp[i + k][count + 1] : 0);
                int notpick = i + 1 < n ? dp[i + 1][count] : 0;
                dp[i][count] = max(pick, notpick);
            }
        int maxSum = dp[0][0];

        // Backtrack to find indices of first 3 subarrays whos sum lead to maxSum
        vector<int> ans(3);
        int i = 0, count = 0;
        while (i < n)
        {
            int pick = subSum[i] + (i + k < n && count < 2 ? dp[i + k][count + 1] : 0);
            if (pick == maxSum)
            {
                maxSum -= subSum[i];
                ans[count++] = i;
                i += k;
            }
            else
                i++;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;
    vector<int> ans = sol.maxSumOfThreeSubarrays(nums, k);
    for (int i : ans)
        cout << i << " ";
    cout << '\n';
    return 0;
}

// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
