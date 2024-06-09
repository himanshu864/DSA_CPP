#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// prefix modulus of sum in hashmap
// pre-calc [0] = 1, since empty subarray sum = 0;
// indexes with same prefix modes, have subarray with sum divisible by k
// Could total subarrays by starting from first occurance of that prefix(skipping it)

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;

        for (int i : nums)
        {
            sum += i % k;
            sum = (sum + k) % k;
            prefix[sum]++;
        }

        for (int i = 0; i < k; i++)
        {
            if (prefix.count(i))
            {
                int x = --prefix[i];
                ans += (x * (x + 1)) / 2;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    // vector<int> nums = {-1, -81, -13, 0};
    // int k = 9;
    cout << sol.subarraysDivByK(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/subarray-sums-divisible-by-k
