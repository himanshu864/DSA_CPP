#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = INT_MAX;
    vector<int> output;

    int breakingTime(vector<int> &nums, int k)
    {
        int x = 1;
        int t = 0;
        for (double i : nums)
        {
            t += ceil(i / x);
            x += k;
        }
        return t;
    }

    void helper(vector<int> &nums, int k)
    {
        if (output.size() == nums.size())
        {
            // find time req for each permutation
            ans = min(ans, breakingTime(output, k));
            return;
        }
        // find all permutations
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] != -1)
            {
                int temp = nums[i];
                nums[i] = -1; // mark visited
                output.push_back(temp);
                helper(nums, k);
                output.pop_back();
                nums[i] = temp;
            }
    }

public:
    int findMinimumTime(vector<int> &strength, int k)
    {
        helper(strength, k);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> strength = {3, 4, 1};
    int k = 1;
    cout << sol.findMinimumTime(strength, k) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-time-to-break-locks-i/
