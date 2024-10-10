#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    // Same as house robber I
    int helper(vector<int> &nums, int start, int end)
    {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++)
        {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    // Circular Array. Hence, can't have both first and last together
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int including_first = helper(nums, 0, n - 2);
        int including_last = helper(nums, 1, n - 1);
        return max(including_first, including_last);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 2};
    cout << sol.rob(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/house-robber-ii/
