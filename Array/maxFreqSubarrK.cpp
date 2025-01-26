#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int ans = 0;
        int original = count(nums.begin(), nums.end(), k);
        for (int m = 1; m <= 50; m++)
        {
            if (m == k)
                continue;
            int gain = 0;
            for (int i : nums)
            {
                if (i == m)
                    gain++;
                else if (i == k)
                    gain--;
                gain = max(gain, 0);
                ans = max(ans, gain);
            }
        }
        return ans + original;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 2, 3, 4, 5, 5, 4, 3, 2, 2};
    int k = 10;
    cout << sol.maxFrequency(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-frequency-after-subarray-operation/
