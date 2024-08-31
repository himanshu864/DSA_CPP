#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionSet(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // convert adj[] to edges
        vector<vector<int>> edges; // {wt, u, v}
        for (int u = 0; u < V; u++)
        {
            for (vector<int> x : adj[u])
            {
                int v = x[0];
                int wt = x[1];
                if (u < v) // Only add one direction
                    edges.push_back({wt, u, v});
            }
        }

        // Sort them based on weight
        sort(edges.begin(), edges.end());

        // union all edges and add edges from different components to MST
        int ans = 0;
        DisjointSet dsu(V);
        for (vector<int> e : edges)
        {
            if (dsu.find(e[1]) != dsu.find(e[2]))
                ans += e[0];
            dsu.unionSet(e[1], e[2]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int V = 3;
    vector<vector<int>> adj[V] = {
        {{1, 5}, {2, 1}},
        {{0, 5}, {2, 3}},
        {{0, 1}, {1, 3}},
    };
    cout << sol.spanningTree(V, adj);
    return 0;
}
