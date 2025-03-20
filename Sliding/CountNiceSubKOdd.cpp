#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 1;
        vector<int> left, right;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
            {
                left.push_back(count);
                count = 1;
            }
            else
                count++;
        }
        count = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] % 2)
            {
                right.push_back(count);
                count = 1;
            }
            else
                count++;
        }
        reverse(right.begin(), right.end());

        int ans = 0;
        int odds = left.size();
        for (int j = k - 1; j < odds; j++)
        {
            int i = j - k + 1;
            ans += left[i] * right[j];
        }
        return ans;
    }
};

class Solution2
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int ans = 0, prefix = 0;
        unordered_map<int, int> mp; // mp[prefixOdd] = count
        mp[0] = 1;
        for (int i : nums)
        {
            prefix += i % 2;
            ans += mp[prefix - k];
            mp[prefix]++;
        }
        return ans;
    }
};

class Solution3
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        auto atMost = [&](int x)
        {
            int ans = 0, i = 0, odd = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                odd += nums[j] % 2;
                while (odd > x)
                {
                    odd -= nums[i++] % 2;
                }
                ans += (j - i + 1);
            }
            return ans;
        };
        return atMost(k) - atMost(k - 1);
    }
};

int main()
{
    Solution3 sol;
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/count-number-of-nice-subarrays/
