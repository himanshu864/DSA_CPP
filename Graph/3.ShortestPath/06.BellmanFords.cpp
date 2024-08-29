#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for (int i = 1; i < V; i++)     // n - 1 iteration
            for (vector<int> e : edges) // relax all edges
                if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];

        // do nth Iteration. If any edge relax. There's a negative cycle
        for (vector<int> e : edges)
            if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                return {-1};
        return dist;
    }
};

int main()
{
    Solution sol;
    int V = 3;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};
    int S = 2;
    // int V = 5;
    // vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 7}, {1, 2, 4}, {3, 4, -7}};
    // int S = 0;
    vector<int> ans = sol.bellman_ford(V, edges, S);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
