#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    vector<int> output;

public:
    void findSubset(int ind, vector<int> &nums)
    {
        ans.push_back(output); // Push each recursion level into ans (as each ith level contains subset of length (i+1))

        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;

            output.push_back(nums[i]);
            findSubset(i + 1, nums);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        findSubset(0, nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {1, 1, 2};
    vector<int> nums = {1, 2, 1};
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    for (vector<int> v : ans)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// TC : O(2^N * k)    [generating 2^N subsets] [k is average length of subsets putting into ans from ds]
// TC : O(2^N * k) + O(N)    [generating 2^N subsets] [k is average length of subsets] [O(N) is the auxilary space]
