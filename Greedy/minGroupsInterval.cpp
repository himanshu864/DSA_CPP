#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Minimum no. of groups == maximum number of overlapping intervals at any given point
Hence line sweep through the intervals by sorting starting and ending points
++overlapping if a new starting point, and --overlapping if ending point
here, if case if starting == ending. Priorities starting, since they intersect
*/

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> start;
        priority_queue<int, vector<int>, greater<int>> end;
        for (vector<int> i : intervals)
        {
            start.push(i[0]);
            end.push(i[1]);
        }
        int overlap = 0;
        while (start.size())
        {
            if (start.top() <= end.top())
            {
                overlap++;
                start.pop();
            }
            else
            {
                overlap--;
                end.pop();
            }
            ans = max(ans, overlap);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << sol.minGroups(intervals) << endl;
    return 0;
}

// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
