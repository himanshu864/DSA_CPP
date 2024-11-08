#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        vector<int> start(n); // Longest Increasing Subsequence from 0 -> i at start[i]
        for (int i = 0; i < n; i++)
        {
            int ans = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    ans = max(ans, 1 + start[j]);
            start[i] = ans;
        }

        vector<int> end(n); // Longest Decreasing Subsequence from i -> n - 1 at end[i]
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    ans = max(ans, 1 + end[j]);
            end[i] = ans;
        }

        vector<int> dp(n); // Let i be peak. From [0 -> i] increasing + [i -> n - 1] Decreasing - 1 (since i twice)
        for (int i = 0; i < n; i++)
            if (end[i] > 1 && start[i] > 1)
                dp[i] = end[i] + start[i] - 1;
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << sol.LongestBitonicSequence(nums.size(), nums) << endl;
    return 0;
}

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
