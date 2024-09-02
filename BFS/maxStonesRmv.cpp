#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// DFS: Connect stones and find islands
class Solution
{
    void dfs(vector<vector<int>> &stones, unordered_set<int> &visited, int s1)
    {
        visited.insert(s1);
        // stone with same row or column, group them into island
        for (int i = 0; i < stones.size(); i++)
            if (!visited.count(i))
                if (stones[s1][0] == stones[i][0] || stones[s1][1] == stones[i][1])
                    dfs(stones, visited, i);
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int numOfIslands = 0;
        unordered_set<int> visited;
        for (int i = 0; i < stones.size(); i++)
            if (!visited.count(i))
            {
                dfs(stones, visited, i); // Start DFS if the stone is not visited
                numOfIslands++;          // Increment the number of connected components
            }
        return stones.size() - numOfIslands;
    }
};

// Using DSU to connect stones and find components
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
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionSet(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};

class Solution2
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int m = 0;
        int n = 0;
        for (vector<int> s : stones)
        {
            m = max(m, s[0]);
            n = max(n, s[1]);
        }
        m++;
        n++;

        // Join rows and cols together by treating them as nodes
        // 0 to m - 1 => rows
        // m to m + n - 1 => cols
        DisjointSet dsu(m + n);

        // For each stone, connect his row and column
        // Since all stones on same row/columns will be of the same component
        for (vector<int> s : stones)
            dsu.unionSet(s[0], s[1] + m);

        int islands = 0;
        for (int i = 0; i < m + n; i++)
            if (dsu.find(i) == i && dsu.size[i] != 1) // do not count row/cols with no stones as islands
                islands++;
        return stones.size() - islands;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    cout << sol.removeStones(stones);
    return 0;
}

// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
