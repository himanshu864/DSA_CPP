#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// HashMap remainder of Prefix Sum
// mp[mod] = index
// If two prefix sums have the same remainder when divided by k,
// the subarray between these two indices has a sum which is a multiple of 𝑘
// mp[0] = -1 ensures that if the sum up to any index is a multiple of 𝑘

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1; // easy to miss
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (!mp.count(sum % k))
                mp[sum % k] = i;
            else
            {
                if (i - mp[sum % k] > 1)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << sol.checkSubarraySum(nums, k) << endl;
    return 0;
}
