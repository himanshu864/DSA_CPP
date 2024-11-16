#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (i && nums[i - 1] + 1 == nums[i])
                counter++;
            else
                counter = 1;

            if (counter >= k)
                ans[i - k + 1] = nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    int k = 3;
    vector<int> ans = sol.resultsArray(nums, k);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
