#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Kind of tricky problem and optimization
We want to carry Maximum Abs Difference of a Path
And store MinEffect of that hill.

Also use minHeap for optimization
Also if we reach destination from priority queue.
That will be the answer, since no one faster than that.
*/

class Solution
{
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});
        while (q.size())
        {
            int r = q.top()[1];
            int c = q.top()[2];
            if (r == m - 1 && c == n - 1)
                return q.top()[0];
            q.pop();
            for (vector<int> d : dir)
            {
                int x = r + d[0];
                int y = c + d[1];
                if (x == -1 || x == m || y == -1 || y == n)
                    continue;

                int maxAbs = max(effort[r][c], abs(heights[x][y] - heights[r][c]));
                if (effort[x][y] > maxAbs)
                {
                    q.push({maxAbs, x, y});
                    effort[x][y] = maxAbs;
                }
            }
        }
        return effort[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> heights = {
    //     {1, 2, 2},
    //     {3, 8, 2},
    //     {5, 3, 5},
    // };

    vector<vector<int>> heights = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5},
    };
    cout << sol.minimumEffortPath(heights);
    return 0;
}

// https://leetcode.com/problems/path-with-minimum-effort/
