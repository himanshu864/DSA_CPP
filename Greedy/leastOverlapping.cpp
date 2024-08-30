#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// sort based on ending and then greedy to get least no. of overlapping intervals

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b)
             { return a[1] < b[1]; });
        int end = INT_MIN;
        for (auto v : intervals)
        {
            if (v[0] < end)
                ans++;
            else
                end = v[1];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {0, 5}};
    cout << sol.eraseOverlapIntervals(intervals);
    return 0;
}

// https://leetcode.com/problems/non-overlapping-intervals/
