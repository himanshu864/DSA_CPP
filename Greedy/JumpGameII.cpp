#include <iostream>
#include <vector>
using namespace std;

// TLE DP :: idk something wrong with my code
class Solution2
{
    bool helper(vector<int> &nums, vector<bool> &memo, int &ans, int jump, int i)
    {
        if (i + 2 > nums.size())
        {
            ans = min(ans, jump);
            return true;
        }
        if (memo[i])
            return false;

        bool flag = false;
        for (int j = nums[i]; j > 0; j--)
        {
            if (helper(nums, memo, ans, jump + 1, i + j))
                flag = true;
            else
                memo[i + j] = true;
        }
        return flag;
    }

public:
    int jump(vector<int> &nums)
    {
        int ans = nums.size();
        vector<bool> memo(nums.size(), false);
        helper(nums, memo, ans, 0, 0);
        return ans;
    }
};

// GOD MOD: My big brain greedy
/*
ans is the no. of jumps it's gonna take
initially it's zero for edge case size == 1
have to jump everytime we go out of range
keep updating max range, as we iterate
and update range to max range so far for least jumps possible
pretty smart greedy approach by yours truly
*/
class Solution
{
public:
    int jump(vector<int> &nums)
    {

        int ans = 0, range = 0, reach = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > range)
                ans++, range = reach;
            reach = max(reach, i + nums[i]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {9, 8, 2, 2, 0, 2, 2, 0, 4, 1, 5, 7, 9, 6, 6, 0, 6, 5, 0, 5};
    cout << sol.jump(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/jump-game-ii/
