#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    int atmostDiff(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size(), i = 0;
        unordered_map<int, int> freq;

        for (int j = 0; j < n; j++)
        {
            freq[nums[j]]++;

            while (freq.size() > k)
            {
                ans += (j - i + 1);
                if (--freq[nums[i++]] == 0)
                    freq.erase(nums[i - 1]);
            }
        }
        return ans + ((n - i + 1) * (n - i + 2)) / 2;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmostDiff(nums, k) - atmostDiff(nums, k - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/subarrays-with-k-different-integers/
