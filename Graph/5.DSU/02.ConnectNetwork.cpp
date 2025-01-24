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

// Using DSU on total no. of components
class Solution1
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int totalEdges = connections.size();
        int requiredEdges = n - 1;
        if (totalEdges < requiredEdges)
            return -1;

        DisjointSet dsu(n);
        for (vector<int> e : connections)
            dsu.unionSet(e[0], e[1]);

        int noOfIslands = 0;
        for (int i = 0; i < n; i++)
            if (dsu.find(i) == i)
                noOfIslands++;

        return noOfIslands - 1;
    }
};

// Finding extra connections using DSU
class Solution2
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int totalEdges = connections.size();
        int requiredEdges = n - 1;
        if (totalEdges < requiredEdges)
            return -1;

        // find extra connections using DSU
        int extra = 0;
        DisjointSet DSU(n);
        for (vector<int> edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            if (DSU.find(u) == DSU.find(v))
                extra++;
            else
                DSU.unionSet(u, v);
        }

        // solve problem statement
        int correct = totalEdges - extra;
        int missing = requiredEdges - correct;
        return missing;
    }
};

int main()
{
    Solution1 sol;
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
