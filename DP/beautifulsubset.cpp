#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    unordered_map<int, int> map;

    void helper(int &ans, vector<int> &output, vector<int> &nums, int k, int i)
    {
        if (i == nums.size())
        {
            ans++;
            return;
        }

        helper(ans, output, nums, k, i + 1); // not pick

        if (!map[nums[i]])
        {
            output.push_back(nums[i]);
            map[nums[i] - k]++;
            map[nums[i] + k]++;
            helper(ans, output, nums, k, i + 1); // pick
            map[nums[i] - k]--;
            map[nums[i] + k]--;
            output.pop_back();
        }
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = 0;
        vector<int> output;
        helper(ans, output, nums, k, 0);
        return ans - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 4, 6};
    int k = 2;
    cout << sol.beautifulSubsets(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/the-number-of-beautiful-subsets/
