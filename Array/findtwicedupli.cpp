#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// use given array as hashmap, to check if previously occured
// iterate through all of em and switch 1-indexed element
// if already switched, push index
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[abs(nums[i]) - 1] *= -1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = sol.findDuplicates(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/find-all-duplicates-in-an-array/
