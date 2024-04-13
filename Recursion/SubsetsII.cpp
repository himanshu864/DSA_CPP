#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int x)
{
    if (x == nums.size())
    {
        ans.push_back(output);
        return;
    }
    output.push_back(nums[x]);
    helper(nums, ans, output, x + 1);
    output.pop_back();
    x++;
    while (x < nums.size() && nums[x] == nums[x - 1])
        x++;
    helper(nums, ans, output, x);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    sort(nums.begin(), nums.end());
    helper(nums, ans, output, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2};
    for (vector<int> v : subsetsWithDup(nums))
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/subsets-ii/
