#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Note: test case

* . *
* . *
* . *

Here if add land at 0,1
islands decrease from 2 to 1

* * *
* . *
* . *

But if we add land at 2,1
island count remains the same.
Since both side are same island, so only unique counts

* * *
* . *
* * *

*/

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
        return parent[node] = find(parent[node]); // Path compression
    }

    void unionSet(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;

        // Union by size
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
    /*
    Intuition: Every land initially adds an island
    But it forms a new connected with any neighbouring island, count decreases
    */
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
    {
        vector<int> ans;
        int islands = 0;
        DisjointSet dsu(n * m);
        vector<vector<int>> land(n, vector<int>(m, 0));

        for (vector<int> a : q)
        {
            islands++; // Adding new land initially increases island count
            land[a[0]][a[1]] = 1;
            for (auto &[x, y] : dir)
            {
                int r = a[0] + x, c = a[1] + y;
                int u = a[0] * m + a[1]; // Current position as 1D index

                if (r >= 0 && c >= 0 && r < n && c < m && land[r][c])
                {                      // Valid and adjacent land
                    int v = r * m + c; // Neighboring position as 1D index
                    if (dsu.find(u) != dsu.find(v))
                    {
                        dsu.unionSet(u, v); // Union the current and neighboring cells
                        islands--;          // Merge reduces island count
                    }
                }
            }
            ans.push_back(islands); // Record the current number of islands
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    int m = 3;
    vector<vector<int>> q = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}};
    vector<int> ans = sol.numOfIslandsII(n, m, q);

    for (int i : ans)
        cout << i << " ";

    return 0;
}
