#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool isZeroArray(int k, vector<int> &nums, vector<vector<int>> &q)
    {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (int i = 0; i < k; i++)
        {
            diff[q[i][0]] += q[i][2];
            diff[q[i][1] + 1] -= q[i][2];
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += diff[i];
            if (count < nums[i])
                return false;
        }
        return true;
    }

public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int ans = -1;
        int s = 0;
        int e = queries.size();
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isZeroArray(mid, nums, queries))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << sol.minZeroArray(nums, queries) << endl;
    return 0;
}

// https://leetcode.com/problems/zero-array-transformation-ii/
