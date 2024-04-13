#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = 0, x = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; // V.IMP to input initial count 0 at -1
        for (int i = 0; i < nums.size(); i++)
        {
            // prefix
            if (nums[i] == 1)
                x++;
            else
                x--;

            // compare if prefix has hit curr value before
            // else push curr prefix with index
            if (!mp.count(x))
                mp[x] = i;
            else
                ans = max(ans, i - mp[x]);
            // subarray will start from next of first index
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 1, 1, 0, 1, 0};
    cout << sol.findMaxLength(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/contiguous-array/
