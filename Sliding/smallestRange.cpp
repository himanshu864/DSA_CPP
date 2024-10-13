#include <iostream>
#include <vector>
#include <set>
using namespace std;

// I don't understand the neetcode solution

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> ans;
        int k = nums.size();
        int minRange = INT_MAX;

        vector<int> idx(k);      // to keep track of k-pointers
        set<pair<int, int>> set; // to sort k-pointers and get min-max

        for (int i = 0; i < k; i++)
            set.insert({nums[i][0], i});

        while (true)
        {
            int a = set.begin()->first;
            int i = set.begin()->second;
            int b = set.rbegin()->first;

            if (b - a < minRange)
            {
                minRange = b - a;
                ans = {a, b};
            }
            if (++idx[i] == nums[i].size())
                break;

            set.erase(set.begin());
            set.insert({nums[i][idx[i]], i});
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30},
    };
    vector<int> range = sol.smallestRange(nums);
    cout << range[0] << " " << range[1] << endl;
    return 0;
}

// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
