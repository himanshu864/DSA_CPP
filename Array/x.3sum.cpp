#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i && nums[i] == nums[i - 1])
            continue;
        int target = -nums[i];
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[j] + nums[k];
            if (sum == target)
            {
                ans.push_back({nums[i], nums[j++], nums[k--]});
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
            else if (sum > target)
                k--;
            else
                j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0, 0, 0, 0};
    for (vector<int> i : threeSum(nums))
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/3sum/
