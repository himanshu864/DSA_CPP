#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    vector<pair<int, int>> adj[200];
    vector<int> dijkstra(int n, int src, int dist)
    {
        vector<int> dis(n + 1, 1e9 + 10);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dis[src] = 0;
        vector<int> vis(n + 10, 0);
        while (pq.size())
        {
            auto [wt, node] = pq.top();
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            for (auto &[current_node, current_wt] : adj[node])
            {
                if (dis[current_node] > current_wt + wt)
                {
                    dis[current_node] = current_wt + wt;
                    pq.push({dis[current_node], current_node});
                }
            }
        }
        return dis;
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int src, int dest, int target)
    {
        // convert edges to adj list but still -1 edges
        for (auto &it : edges)
        {
            if (it[2] == -1)
                continue;
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // check if without modifiable edges there exists a path where shortest path is < target
        vector<int> dist = dijkstra(n, src, dest);
        if (dist[dest] < target)
            return {};

        // if shortest path == target, convert all modifiable edges to infinity
        if (dist[dest] == target)
        {
            for (auto &it : edges)
                if (it[2] == -1)
                    it[2] = 2e9;
            return edges;
        }

        // keep converting all modifiable edges to 1 and then if at any point
        // there becomes a path who's Shortestpath is <= target.
        // in that case simply add (target - shortestPath) to that edge
        // and remaining modifiable edges to infinity
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (w == -1)
            {
                edges[i][2] = 1;
                adj[u].push_back({v, 1});
                adj[v].push_back({u, 1});
                vector<int> dis = dijkstra(n, src, dest);
                if (dis[dest] <= target)
                {
                    edges[i][2] += (target - dis[dest]);
                    for (int j = i + 1; j < edges.size(); j++)
                        if (edges[j][2] == -1)
                            edges[j][2] = 2e9;
                    return edges;
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, -1}};
    int source = 0;
    int destination = 2;
    int target = 6;
    vector<vector<int>> ans = sol.modifiedGraphEdges(n, edges, source, destination, target);
    for (vector<int> e : ans)
    {
        for (int i : e)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/modify-graph-edge-weights/
