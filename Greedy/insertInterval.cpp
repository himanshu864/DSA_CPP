#include <iostream>
#include <vector>
using namespace std;

// Too good official
// empty, before, after, no overlapping, everything is concisely covered using while(i < n  //){//}
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);

        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        ans.push_back(newInterval);

        while (i < n)
            ans.push_back(intervals[i++]);
        return ans;
    }
};

// my edging
class Solution2
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        if (intervals.empty())
            return {newInterval};

        int n = intervals.size();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (newInterval[0] > intervals[i][1]) // newInterval is yet to come
                ans.push_back({intervals[i][0], intervals[i][1]});
            else if (newInterval[1] < intervals[i][0]) // newInterval is gone
            {
                if (!flag) // if no overlapping
                {
                    ans.push_back({newInterval[0], newInterval[1]});
                    flag = true;
                }
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            else // if overlapping
            {
                int s = intervals[i][0];
                if (newInterval[0] < intervals[i][0]) // if newInterval starts before current
                    s = newInterval[0];

                while (i < n && newInterval[1] > intervals[i][1]) // if newInterval covers entire intervals
                    i++;

                if (i == n) // if newInterval extends after all intervals
                    ans.push_back({s, newInterval[1]});
                else if (newInterval[1] < intervals[i][0]) // if newInterval ends before start of next interval (covers some)
                {
                    ans.push_back({s, newInterval[1]});
                    ans.push_back({intervals[i][0], intervals[i][1]});
                }
                else // if newInterval's end lies on current interval
                    ans.push_back({s, intervals[i][1]});
                flag = true;
            }
        }
        if (intervals[n - 1][1] < newInterval[0]) // if newInterval starts after end of all intervals
            ans.push_back(newInterval);
        return ans;
    }
};

int main()
{
    Solution sol;
    // Solution2 sol;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {13, 16}};
    vector<int> newInterval = {4, 8};
    // vector<int> newInterval = {0, 0};
    // vector<int> newInterval = {11, 12};
    // vector<int> newInterval = {18, 20};
    // vector<int> newInterval = {0, 18};
    // vector<int> newInterval = {4, 7};
    // vector<int> newInterval = {4, 19};

    vector<vector<int>> merged = sol.insert(intervals, newInterval);
    for (vector<int> i : merged)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/insert-interval/
