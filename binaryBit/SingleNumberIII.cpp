#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // XOR all nums[i]
        long x = 0;
        for (int i : nums)
            x ^= i;

        // create a mask with that just the rightmost bit set
        long mask = (x & (x - 1)) ^ x;

        // separate all nums[i] with that bit set into bucket1, and rest into bucket2 using xor
        long bucket1 = 0, bucket2 = 0;
        for (int i : nums)
        {
            if ((i & mask) == 0)
                bucket1 ^= i;
            else
                bucket2 ^= i;
        }
        // since duplice, only unique distinct elements will remain
        return {(int)bucket1, (int)bucket2};
    }
};

signed main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = sol.singleNumber(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/single-number-iii/
