#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();
        // Min-heap to process cells by height in increasing order
        // use pair<int, pair<int,int>> for optimization
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        // Push boundaries
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    minHeap.push({heightMap[i][j], {i, j}});
                    heightMap[i][j] = -1;
                }

        // BFS
        int ans = 0;
        int level = 0;
        while (minHeap.size())
        {
            auto [h, coords] = minHeap.top();
            auto [r, c] = coords;
            minHeap.pop();

            // Update water level to the maximum height encountered so far
            level = max(level, h);

            for (auto [x, y] : dir)
            {
                int i = r + x;
                int j = c + y;
                if (i >= 0 && i < m && j >= 0 && j < n && heightMap[i][j] != -1)
                {
                    // cell with height smaller than level will trap water
                    ans += max(level - heightMap[i][j], 0);
                    minHeap.push({heightMap[i][j], {i, j}});
                    heightMap[i][j] = -1; // visited
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heightMap = {
        {12, 13, 1, 12},
        {13, 4, 13, 12},
        {13, 8, 10, 12},
        {12, 13, 12, 12},
        {13, 13, 13, 13},
    };
    cout << sol.trapRainWater(heightMap) << endl;
    return 0;
}

// https://leetcode.com/problems/trapping-rain-water-ii/
