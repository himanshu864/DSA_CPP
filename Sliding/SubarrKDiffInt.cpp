#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int atmost(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> last; // map last occurrence
        for (int i = 0, j = 0; j < (int)nums.size(); j++)
        {
            last[nums[j]] = j;
            while ((int)last.size() > k)
            {
                if (last[nums[i]] == i)
                    last.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
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
