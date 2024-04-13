#include <iostream>
#include <vector>
using namespace std;

// Easy Mod DP with memoization
class Solution2
{
public:
    bool helper(vector<int> &nums, vector<bool> &memo, int i)
    {
        if (i + 2 > nums.size())
            return true;
        if (memo[i])
            return false;

        for (int j = nums[i]; j > 0; j--) // important for greedy and not TLE
        {
            if (helper(nums, memo, i + j))
                return true;
            else
                memo[i + j] = true;
        }
        return false;
    }

    bool canJump(vector<int> &nums)
    {
        vector<bool> memo(nums.size(), false);
        for (int i : nums)
            if (i == 0)
                return helper(nums, memo, 0);
        return true;
    }
};

// GOD MOD: Greedy using concise big brain automatic edge case handling. Genius
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int i = 0;
        for (int reach = 0; i < nums.size() && i <= reach; i++)
            reach = max(reach, i + nums[i]);
        return i == nums.size();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << sol.canJump(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/jump-game/
