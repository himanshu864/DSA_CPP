#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);  // LIS from i to end
        vector<int> cnt(n); // count of LIS from i to end
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
                if (nums[i] < nums[j])
                    ans = max(ans, 1 + dp[j]);
            dp[i] = ans;

            // count how many dp[j]'s can be used to make dp[i]
            int count = 0;
            for (int j = i + 1; j < n; j++)
                if (nums[i] < nums[j] && dp[j] == dp[i] - 1)
                    count += cnt[j];
            cnt[i] = count == 0 ? 1 : count; // atleast one way
        }

        // count all subseq with length of LIS
        int maxi = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == maxi)
                ans += cnt[i];
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    // vector<int> nums = {5, 10, 5, 3};
    // vector<int> nums = {2, 2, 2, 2, 2};
    cout << sol.findNumberOfLIS(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
