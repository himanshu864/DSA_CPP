#include <iostream>
#include <vector>
using namespace std;

// this question might look like a simple sliding window at first, but...
// There's a huge catch when goal is 0. [0, 0, 0, 0, 0] is gonna have 15 such subarrays
// also 1, 0, 1, 0, 1 has 4 subarrays with goal = 2. which is complicated to find using normal sliding window
// that's why we easily find subarrays with sum less then or equal to goal
// and subtract it with same atmost(goal - 1)
// It's kinda complicated, watch a video

class Solution
{
public:
    int atmost(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int ans = 0;
        int sum = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum > goal)
                sum -= nums[i++];
            ans += (j - i + 1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    // vector<int> nums = {0, 0, 0, 0, 0};
    int goal = 2;
    // int goal = 0;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}

// https://leetcode.com/problems/binary-subarrays-with-sum/
