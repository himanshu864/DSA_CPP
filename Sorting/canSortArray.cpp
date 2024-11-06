#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int countBitset(int n)
    {
        int ans = 0;
        for (int i = n; i; i /= 2)
            if (i % 2)
                ans++;
        return ans;
    }

public:
    bool canSortArray(vector<int> &nums)
    {
        // split array into segments with equal bitsets
        int prevBitset = 0;
        int prevMaxi = 0;
        int currMaxi = 0;
        int currMini = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int currBitset = countBitset(nums[i]);
            if (prevBitset == currBitset)
            {
                currMini = min(currMini, nums[i]);
                currMaxi = max(currMaxi, nums[i]);
            }
            else
            {
                prevBitset = currBitset;
                prevMaxi = currMaxi;
                currMaxi = nums[i];
                currMini = nums[i];
            }
            if (currMini < prevMaxi)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {8, 4, 2, 30, 15};
    cout << sol.canSortArray(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/find-if-array-can-be-sorted/
