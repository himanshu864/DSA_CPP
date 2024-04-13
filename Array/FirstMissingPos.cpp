#include <iostream>
#include <vector>
using namespace std;

// Put 1, 2, 3 on their correct postion (i - 1)th
// We can't use extra space, hence iterate and swap until correct
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] >= 1 && nums[i] <= nums.size() &&
                   nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;

        return nums.size() + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/first-missing-positive/
