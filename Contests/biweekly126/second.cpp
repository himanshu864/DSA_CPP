#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<long long> ans;

        vector<bool> mark(nums.size(), true); // true is unmarked

        long long total = 0;
        for (int i : nums)
            total += i;

        for (vector<int> q : queries)
        {
            int x = q[0];
            if (mark[x])
            {
                mark[x] = false;
                total -= nums[x];
            }
            int k = q[1];
            while (k > 0)
            {
                int mini = INT_MAX;
                for (int i = 0; i < nums.size(); i++)
                    if (mark[i] && nums[i] < mini)
                        mini = nums[i];

                int prev = k;
                for (int i = 0; i < nums.size() && k > 0; i++)
                {
                    if (mark[i] && nums[i] == mini)
                    {
                        mark[i] = false;
                        total -= mini;
                        k--;
                    }
                }
                if (prev == k)
                    break;
            }
            ans.push_back(total);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 2, 3, 1};
    vector<vector<int>> queries = {{1, 2}, {3, 3}, {4, 2}};
    vector<long long> ans = sol.unmarkedSumArray(nums, queries);
    for (long long i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// nums = [], queries = [[1,2],[3,3],[4,2]]
