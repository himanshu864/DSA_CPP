#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> &nums, vector<int> &op, int i, vector<vector<int>> &ans)
{
    if (i == nums.size())
    {
        ans.push_back(op);
        return;
    }
    helper(nums, op, i + 1, ans);
    op.push_back(nums[i]);
    helper(nums, op, i + 1, ans);
    op.pop_back();
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> op;
    helper(nums, op, 0, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    for (vector<int> v : subsets(nums))
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/subsets/
