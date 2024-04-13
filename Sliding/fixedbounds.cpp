#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int jbad = -1, jmin = -1, jmax = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
                jbad = i;
            if (nums[i] == minK)
                jmin = i;
            if (nums[i] == maxK)
                jmax = i;

            ans += max(0, min(jmax, jmin) - jbad);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1, maxK = 5;
    cout << sol.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}

// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
