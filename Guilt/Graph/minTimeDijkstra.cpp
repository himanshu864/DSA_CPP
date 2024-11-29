#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// My misunderstood solution; TOC exam no time
class Solution69
{
    vector<int> dir = {0, 1, 0, -1, 0};

public:
    // -1 only if no move at beginning
    // otherwise we can simply go back and forward from where we came
    // and do a little +2 until neighbour's time smaller
    // but how memoize visited?
    // okay. I think dijkstra will work
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0});

        while (minHeap.size())
        {
            int t = minHeap.top()[0];
            int i = minHeap.top()[1];
            int j = minHeap.top()[2];
            minHeap.pop();

            if (i == m - 1 && j == n - 1)
                return t++;

            for (int k = 0; k < 4; k++)
            {
                int x = i + dir[k];
                int y = j + dir[k + 1];
                if (x >= 0 && y >= 0 && x < m && y < n)
                {
                    int newT = t;
                    if (t < grid[x][y])
                        newT = grid[x][y] + (grid[x][y] % 2 != t % 2);

                    if (visited[x][y] > newT)
                    {
                        visited[x][y] = newT;
                        minHeap.push({newT, x, y});
                    }
                }
            }
        }
        return -1;
    }
};

// Correct solution
class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        // Check if the starting points are blocked
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({grid[0][0], 0, 0}); // Start at top-left corner
        while (!pq.empty())
        {
            // Get the current time, row, and column
            int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();

            // Check if we've reached the bottom-right corner
            if (row == m - 1 && col == n - 1)
                return time;

            // Mark the current cell as visited
            if (visited[row][col])
                continue;
            visited[row][col] = true;

            // Explore the neighboring cells
            for (auto dr : dirs)
            {
                int r = row + dr[0], c = col + dr[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;

                // Calculate the time required to reach the neighboring cell
                int wait = (grid[r][c] - time) % 2 == 0;
                pq.push({max(grid[r][c] + wait, time + 1), r, c});
            }
        }
        return -1; // We couldn't reach the bottom-right corner.
                   // We will never actually encounter this in practice.
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 3, 2},
        {5, 1, 2, 5},
        {4, 3, 8, 6},
    };
    cout << sol.minimumTime(grid) << endl;
    return 0;
}
