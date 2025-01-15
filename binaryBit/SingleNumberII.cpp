#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // count freq of all 32 bits
        vector<int> freq(32);
        for (int i : nums)
            for (int bit = 0; bit < 32; bit++)
                if (i & (1 << bit))
                    freq[bit]++;

        // build a bitch
        int ans = 0;
        for (int bit = 0; bit < 32; bit++)
            if (freq[bit] % 3)
                ans += 1 << bit;
        cout << endl;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 5, 5, 6, 4, 4, 4};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/single-number-ii/
