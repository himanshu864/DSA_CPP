#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// My sliding window inspired by Queue
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int ans = 0;
        int i = 0, j = 0; // window from i to j - 1, empty if i==j
        int x = 1;        // product of window
        while (j < nums.size())
        {
            // increasing window if nums[j] can be multiplied
            if (nums[j] * x < k)
                x *= nums[j++];
            // if window empty and can't increase window
            else if (i == j && nums[j] >= k)
                i++, j++;
            // decreasing window, pop front queue and update x
            else
            {
                // add subarrays starting from front, before popping
                ans += j - i;
                x /= nums[i++];
            }
        }
        // add remaining valid subarrays inside window
        // no. of subarrays = n + (n - 1) + .. 2 + 1;
        ans += (j - i) * (j - i + 1) / 2;
        return ans;
    }
};

// Concise
class Solution2
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int ans = 0, x = 1;
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            x *= nums[j];
            while (i <= j && x >= k)
                x /= nums[i++];
            ans += j - i + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/subarray-product-less-than-k/
