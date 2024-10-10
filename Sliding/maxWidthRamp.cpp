#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        // pre-calculate max element to right
        vector<int> rmax(n);
        rmax[n - 1] = nums[n - 1];
        for (int i = n - 2, maxi = 0; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], nums[i]);

        // sliding window
        // move right pointer if there might exist larger number on right
        int i = 0, j = 1;
        while (j < n && i <= j)
        {
            if (nums[i] <= nums[j])
                ans = max(ans, j - i);
            if (rmax[j] >= nums[i])
                j++;
            else
                i++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {6, 0, 8, 2, 1, 5};
    cout << sol.maxWidthRamp(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-width-ramp/
