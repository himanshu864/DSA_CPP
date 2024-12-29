#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    long long ans = 0;
    vector<int> output;

    void f(int i, vector<int> &nums)
    {
        if (output.size() == 4)
        {
            if (nums[output[0]] * 1LL * nums[output[2]] == nums[output[1]] * 1LL * nums[output[3]])
                ans = (ans + 1) % mod;
            return;
        }
        if (i >= (int)nums.size())
            return;

        f(i + 1, nums);

        output.push_back(i);
        f(i + 2, nums);
        output.pop_back();
    }

public:
    long long numberOfSubsequences(vector<int> &nums)
    {
        f(0, nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 3, 4, 3, 4, 3, 4};
    cout << sol.numberOfSubsequences(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/count-special-subsequences/
