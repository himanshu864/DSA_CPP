#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int ans = 0;

        // convert edges to adj matrix
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
            adj[i][i] = 0;
        for (vector<int> e : edges)
        {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }

        // Floyd warsheet Algo
        // find shortest path from all nodes to all nodes via all nodes
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        // find city with least no. of cities who's dist other cities <= threshold
        int minCities = n;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (adj[i][j] <= distanceThreshold)
                    count++;
            if (count <= minCities)
            {
                minCities = count;
                ans = i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    cout << sol.findTheCity(n, edges, distanceThreshold);
    return 0;
}

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
