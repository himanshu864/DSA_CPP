#include <iostream>
#include <vector>
using namespace std;

/*
DSU : Disjoint Set Union => find() & union()
Initially consider all nodes to be separate
And every node is a parent of himselves

Then connect them based on the size of their component
And only connect components - Join ultimate parents based on size/rank

Path Compression: Whenever find ultimate parent.
Recursively join children nodes to ultimate parent
Making find() operation almost constant

Time Complexity : O(4α) -> Almost Constant
*/

class DisjointSet
{
    vector<int> rank, size, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        // path compression
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // size better
    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
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
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    cout << ((ds.findUPar(3) == ds.findUPar(7)) ? "Same" : "Not same") << endl;
    ds.unionBySize(3, 7);
    cout << ((ds.findUPar(3) == ds.findUPar(7)) ? "Same" : "Not same") << endl;
    return 0;
}
