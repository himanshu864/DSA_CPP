#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// calc prefix sum && map occurence of encounters prefixes
// prefix J - prefix I = Subarray sum from I to J == k
// Therefore, if (prefix J - k) exists in map. Subarray exists
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, pre = 0;
        unordered_map<int, int> map;
        map[0] = 1; // V.Imp for first element
        for (int i : nums)
        {
            pre += i;
            ans += map[pre - k];
            map[pre]++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, -9, 4, 1};
    int k = 1;
    cout << sol.subarraySum(nums, k);
    return 0;
}

// https://leetcode.com/problems/subarray-sum-equals-k/
