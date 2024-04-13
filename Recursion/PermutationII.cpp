#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// efficient swapping solution buy NOT passing nums by reference!
// DOUBT: Why not &nums, and why need to sort, how working, draw tree pls
void helper(vector<int> nums, vector<vector<int>> &ans, int x)
{
    if (x == nums.size() - 1)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = x; i < nums.size(); i++)
    {
        if (nums[i] == nums[x] && i != x)
            continue;
        swap(nums[x], nums[i]);
        helper(nums, ans, x + 1);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

/*
// My solution: Basically permuting frequencies
void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, vector<int> &freq, int x)
{
    if (x == nums.size())
    {
        ans.push_back(output);
        return;
    }
    for (int i = 0; i < 21; i++)
    {
        if (freq[i] > 0)
        {
            freq[i]--;
            output.push_back(i - 10);
            helper(nums, ans, output, freq, x + 1);
            output.pop_back();
            freq[i]++;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    vector<int> freq(21, 0);
    for (int i : nums)
        freq[i + 10]++;
    helper(nums, ans, output, freq, 0);
    return ans;
}
*/

int main()
{
    vector<int> nums = {1, 1, 2, 2};
    for (vector<int> i : permuteUnique(nums))
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/permutations-ii/
