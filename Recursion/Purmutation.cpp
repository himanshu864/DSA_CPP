#include <iostream>
#include <vector>
using namespace std;

// space optimized using swapping since distinct values
void helper(vector<int> &nums, vector<vector<int>> &ans, int x)
{
    if (x == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = x; i < nums.size(); i++)
    {
        swap(nums[x], nums[i]);
        helper(nums, ans, x + 1);
        swap(nums[x], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

// use extra space(mapping) to store which outputted values
// void mappingpls(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &flag, int x)
// {
//     if (x == nums.size())
//     {
//         ans.push_back(temp);
//         return;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (flag[i])
//         {
//             flag[i] = false;
//             temp.push_back(nums[i]);
//             mappingpls(nums, ans, temp, flag, x + 1);
//             temp.pop_back(); // remember to revert change
//             flag[i] = true;  // backtracking fr
//         }
//     }
// }

// vector<vector<int>> permute(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     vector<int> temp;
//     vector<bool> flag(nums.size(), true);
//     mappingpls(nums, ans, temp, flag, 0);
//     return ans;
// }

int main()
{
    vector<int> nums = {1, 2, 3};
    for (vector<int> i : permute(nums))
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/permutations/
