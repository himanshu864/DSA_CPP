#include <bits/stdc++.h>
using namespace std;

/*
Two Big brain Techniques:

1. Use of monotonic deques to find max / mini for current window
2. Shifting of left pointer by popping smaller index
*/

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        long long ans = 0;
        deque<int> mini, maxi;
        int n = nums.size();
        for (int i = 0, j = 0; j < n; j++)
        {
            // add right element to monotonic deques
            while (maxi.size() && nums[maxi.back()] < nums[j])
                maxi.pop_back(); // we don't care about smaller elements in maxi
            maxi.push_back(j);

            while (mini.size() && nums[mini.back()] > nums[j])
                mini.pop_back(); // we don't care about larger elements in mini
            mini.push_back(j);

            // shift left pointer until subarray valid
            // left = popped_index + 1
            while (nums[maxi.front()] - nums[mini.front()] > 2)
            {
                if (maxi.front() < mini.front())
                {
                    i = maxi.front() + 1;
                    maxi.pop_front();
                }
                else if (mini.front() < maxi.front())
                {
                    i = mini.front() + 1;
                    mini.pop_front();
                }
                else
                {
                    i = maxi.front() + 1;
                    maxi.pop_front();
                    mini.pop_front();
                }
            }

            // count all valid subarr ending at index 'j'
            ans += (j - i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 4, 2, 4};
    // vector<int> nums = {65, 66, 67, 66, 66, 65, 64, 65, 65, 64};
    cout << sol.continuousSubarrays(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/continuous-subarrays/
