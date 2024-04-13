#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// We need to pop all balloons with mini arrows
// So basically we can pop all overlapping points in sorted order, one by one
// Hence we need to iterate through each balloons in a sorted manner
// find all following balloons that overlap with it, and pop them all at once with a single shot
// Then iterate to next balloon will was just outside the overlapping region and start the process again

// We can easily find overlapping region when balloons are sorted
// as we just need to decrease the right end as we iterate
// if starting point of next balloon is smaller than (current smallest) right_end
// then that balloon definely overlaps, but its end might be even smaller
// hence, we need to update right_end and move to the next balloon
// until a balloon with its starting point exceeding current right end of overlapping region comes along
// then simply +1 to ans and start again

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int ans = 1, e = INT_MAX;
        for (vector<int> p : points)
        {
            if (p[0] > e)
                e = p[1], ans++;
            else
                e = min(e, p[1]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << sol.findMinArrowShots(points) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
