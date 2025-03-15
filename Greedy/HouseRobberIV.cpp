#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // is possible to k houses that are non-adj and <= mid
    bool isPossible(vector<int> &nums, int k, int mid)
    {
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] <= mid)
            {
                k--;
                i++;
            }
        return k <= 0;
    }

public:
    int minCapability(vector<int> &nums, int k)
    {
        int ans = 0;
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(nums, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 5, 9};
    int k = 2;
    cout << sol.minCapability(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/house-robber-iv/
