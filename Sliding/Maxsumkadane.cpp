#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm:
// keep updating sum and maxi while iterating through the array
// BUT, restart subarray, when sum becomes negative.
int maxSubArray(vector<int> &nums)
{
    int maxi = nums[0];
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int maxSubArray2(vector<int> &nums)
{
    int ans = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum = max(nums[i], sum + nums[i]),
        ans = max(ans, sum);
    return ans;
}

int main()
{
    vector<int> nums = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}

// https://leetcode.com/problems/maximum-subarray/description/
