#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    // If in sorted order -> {a, b, c, d}
    // b % a == 0 && c % b == 0 && d % c == 0
    // then all of them divide each other
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // Tabulate LDS for all subarrays from start to ith index
        int n = nums.size();
        sort(nums.begin(), nums.end()); // subset - order doesn't matter
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            int maxi = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0)
                    maxi = max(maxi, 1 + dp[j]);
            dp[i] = maxi;
        }

        // print LDS of complete array
        int maxi = *max_element(dp.begin(), dp.end());
        int temp = -1;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
            if (dp[i] == maxi && (temp == -1 || temp % nums[i] == 0))
            {
                maxi--;
                temp = nums[i];
                ans.push_back(nums[i]);
            }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 8, 4, 1, 5, 2, 3, 25};
    // vector<int> nums = {1, 2, 3, 4, 5, 8, 10, 25};
    vector<int> ans = sol.largestDivisibleSubset(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/largest-divisible-subset/
