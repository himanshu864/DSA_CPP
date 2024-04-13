#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    // part if subarray sum > mid(possible smallest sum), if parts > k, not possible
    bool isPossible(vector<int> nums, int k, int mid)
    {
        int parts = 1;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum + nums[i] <= mid)
                sum += nums[i];
            else
            {
                if (parts++ == k)
                    return false;
                sum = nums[i];
            }
        }
        return true;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int s = *max_element(nums.begin(), nums.end());
        int e = 0;
        for (int i = 0; i < nums.size(); i++)
            e += nums[i];
        int ans = e;
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
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << sol.splitArray(nums, k);
    return 0;
}

// https://leetcode.com/problems/split-array-largest-sum/
