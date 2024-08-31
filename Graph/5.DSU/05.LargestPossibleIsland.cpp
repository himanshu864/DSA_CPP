#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DisjointSet
{
    vector<int> parent;

public:
    vector<int> size;
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
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        // Step 1 : Connect all lands to form islands using DSU
        int n = grid.size();
        DisjointSet dsu(n * n);
        int countOnes = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                {
                    countOnes++;
                    for (auto &[x, y] : dir)
                    {
                        int r = i + x;
                        int c = j + y;
                        if (r >= 0 && c >= 0 && r < n && c < n && grid[r][c])
                            dsu.unionSet(i * n + j, r * n + c);
                    }
                }

        // Step 2 : If only one island, can only increase size by one
        int islands = 0;
        for (int i = 0; i < n * n; i++) // only check land if root island
            if (grid[i / n][i % n] && dsu.find(i) == i)
                islands++;
        if (islands == 1)
            return max(n * n, countOnes + 1);

        // Step 3 : Temperary union all 0's to get largest possible island
        int ans = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!grid[i][j])
                {
                    unordered_set<int> visited;
                    int currSize = 1;
                    for (auto &[x, y] : dir)
                    {
                        int r = i + x;
                        int c = j + y;
                        if (r < 0 || c < 0 || r >= n || c >= n || !grid[r][c])
                            continue;
                        int root = dsu.find(r * n + c);
                        if (!visited.count(root))
                        {
                            visited.insert(root);
                            currSize += dsu.size[root];
                        }
                    }
                    ans = max(ans, currSize);
                }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 1},
    };
    cout << sol.largestIsland(grid);
    return 0;
}

// https://leetcode.com/problems/making-a-large-island/
