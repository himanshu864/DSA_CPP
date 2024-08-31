#include <iostream>
#include <vector>
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

// DSU
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        DisjointSet dsu(V);

        // union all undirected edges from adj matrix
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (isConnected[i][j])
                    dsu.unionSet(i, j);

        // no. of islands will be the no. of ultimate parents
        int ans = 0;
        for (int i = 0; i < V; i++)
            if (dsu.find(i) == i)
                ans++;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };
    cout << sol.findCircleNum(isConnected);
    return 0;
}

// https://leetcode.com/problems/number-of-provinces/
