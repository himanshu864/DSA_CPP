#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // create adj list
        vector<vector<pair<int, int>>> adj(n + 1); // {node, weight}
        for (vector<int> e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> parent(n + 1);    // where does the node coming from
        vector<int> dist(n + 1, 1e9); // Shortest Dist. from 1 to node
        dist[1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1}); // {weight, node} for minHeap
        while (q.size())
        {
            int wt = q.top().first;
            int u = q.top().second;
            q.pop();
            for (pair<int, int> p : adj[u])
            {
                int v = p.first;
                int d = wt + p.second;
                if (d < dist[v])
                {
                    parent[v] = u;
                    dist[v] = d;
                    q.push({d, v});
                }
            }
        }
        if (!parent[n])
            return {-1};

        // Backtrack to where does node comes from
        vector<int> ans;
        for (int i = n; i; i = parent[i])
            ans.push_back(i);

        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1},
    };
    int n = 5;
    int m = 6;
    vector<int> ans = sol.shortestPath(n, m, edges);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
