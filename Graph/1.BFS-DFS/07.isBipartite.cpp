#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> visited(V, -1);

        // Check each component of the graph
        for (int v = 0; v < V; v++)
        {
            if (visited[v] != -1)
                continue;
            queue<int> q;
            q.push(v);
            visited[v] = 1; // Starting color

            // Start BFS
            while (q.size())
            {
                int node = q.front();
                int color = visited[node];
                q.pop();
                for (auto x : graph[node])
                {
                    if (visited[x] == color) // if adj same color
                        return false;
                    if (visited[x] == -1)
                    {
                        q.push(x);
                        visited[x] = !color; // alternate color
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> graph = {
        {},
        {2, 4, 6},
        {1, 4, 8, 9},
        {7, 8},
        {1, 2, 8, 9},
        {6, 9},
        {1, 5, 7, 8, 9},
        {3, 6, 9},
        {2, 3, 4, 6, 9},
        {2, 4, 5, 6, 7, 8},
    };
    cout << (sol.isBipartite(graph) ? "Yes" : "No") << endl;
    return 0;
}

// https://leetcode.com/problems/is-graph-bipartite/
