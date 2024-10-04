#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int ans = nums.size();
        long long sum = 0;
        for (int i : nums)
            sum += i;
        int x = sum % p; // extra remainder
        if (x == 0)
            return 0;
        // we need to find the smallest subarray with remainder x
        // coz if we remove that, our remaining array will be divible by p

        // to do that, prefix remainders and check if curr remainder - any previous remainder = x
        // hence look for curr remainder - x in the map.
        // Where we store it with the rightmost index for smallest subarray.
        unordered_map<int, int> map;
        map[0] = -1;
        long long pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre = (pre + nums[i]) % p; // current remainder
            int t = (pre - x + p) % p; // target prefixed remainder I
            if (map.count(t))
                ans = min(ans, i - map[t]);
            map[pre] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    // int p = 11;
    cout << sol.minSubarray(nums, p) << endl;
    return 0;
}

// https://leetcode.com/problems/make-sum-divisible-by-p/
