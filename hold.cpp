#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int n = nums.size();

        int x = 0;
        int prev = -1; // VIMPP big brain previous left to avoid counting already considered subarrays to the left
        while (x < n)
        {
            int i = x;
            while (i < n && nums[i] != minK && nums[i] != maxK) // find first max/min index
                i++;

            int j = i;
            while (j < n && nums[j] != (minK + maxK - nums[i])) // find the other one min/max index
                j++;

            // now that subarray is valid
            // and any subarray with that subarray in it, is also valid, hence count all to left and right
            ans += (i - prev) * (n - j); // edge case of j == n also handled
            prev = i;                    // just dont counting previous to the left to avoid recounting same subarrays
            x = j;                       // move iterator to second max/min as first and start process again to find second
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 2, 1, 4};
    cout << sol.countSubarrays(nums, *min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end())) << endl;
    return 0;
}
