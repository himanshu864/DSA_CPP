#include <iostream>
#include <vector>
#include <set>
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // Minimum no. of edges we need to change is order to make graph connected
        // => (Total no. of components - 1);
        // becoz we'll require 2 edges to join 3 components(disjoint sets)
        // And we'll check if it's possible to remove that many edges by finding extra edges from connections
        // that do not make up the MST
        // Use MST to achieve that
        DisjointSet dsu(n);
        int extraEdges = 0;
        for (vector<int> e : connections)
        {
            if (dsu.find(e[0]) == dsu.find(e[1]))
                extraEdges++;
            dsu.unionSet(e[0], e[1]);
        }

        int noOfIslands = 0;
        for (int i = 0; i < n; i++)
            if (dsu.find(i) == i)
                noOfIslands++;

        if (noOfIslands - 1 > extraEdges)
            return -1;

        return noOfIslands - 1;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << sol.makeConnected(n, connections);
    return 0;
}

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
