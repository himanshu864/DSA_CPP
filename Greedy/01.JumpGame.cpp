#include <iostream>
#include <vector>
using namespace std;

// Recursion - No point in DP
class Solution1
{
public:
    int jump(vector<int> &nums, int i = 0)
    {
        if (i >= nums.size() - 1)
            return 0;
        int ans = 1e9;
        for (int j = 1; j <= nums[i]; j++)
            ans = min(ans, jump(nums, i + j) + 1);
        return ans;
    }
};

// Greedy - GOD MOD
/*
To find minimum no. of jumps we need to take to reach last index
We're gonna start from i = 0, and note the farthest index we can reach from that first jump
Once we pass that index, we know for sure we had to make another jump. hence, ans++
And we're gonna again note the farthest index we can reach from that index with our 2nd jump
To note the farthest index we can reach, we'll be carrying maxReach just like JumpGameI
And finally return no. of mini jumps once we can reach farther than or equal to the last index
*/
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int curReach = 1;
        int curEnd = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curReach = max(curReach - 1, nums[i]);
            if (--curEnd == 0)
            {
                curEnd = curReach;
                jumps++;
            }
        }
        return jumps;
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
