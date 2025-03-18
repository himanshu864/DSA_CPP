#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int ans = 1;
        vector<int> lastSeen(32, -1);
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            for (int k = 0; k < 32; k++)
            {
                // if k-th bit is not set, skip
                if (!(nums[j] & (1 << k)))
                    continue;

                // adjust left pointer
                if (lastSeen[k] != -1)
                    i = max(i, lastSeen[k] + 1);
                lastSeen[k] = j;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

class Solution2
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int ans = 0;
        int common = 0;
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            while ((common & nums[j]) != 0)
                common ^= nums[i++];
            common |= nums[j];

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution2 sol;
    vector<int> nums = {1, 3, 8, 48, 10};
    cout << sol.longestNiceSubarray(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/longest-nice-subarray/
