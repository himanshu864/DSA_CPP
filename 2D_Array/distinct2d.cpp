#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    while (!nums.empty())
    {
        vector<int> row;
        vector<int> temp;
        row.push_back(nums.back());
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (row.back() != nums[i])
                row.push_back(nums[i]);
            else
                temp.push_back(nums[i]);
        }
        nums = temp;
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    // vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
    vector<int> nums = {1, 2, 3, 4, 1, 2, 2, 3};
    vector<vector<int>> mat = findMatrix(nums);
    for (vector<int> i : mat)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
