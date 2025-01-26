#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> adj;
    vector<int> cyclicity;

    int bt(int u, int depth)
    {
        if (cyclicity[u] == -1)
            return -1;
        if (cyclicity[u])
            return depth - cyclicity[u];

        cyclicity[u] = depth;
        int size = -1;
        for (int v : adj[u])
            size = max(size, bt(v, depth + 1));
        return cyclicity[u] = size;
    }

    int dfs(int u)
    {
        int ans = 0;
        for (int v : adj[u])
            if (cyclicity[v] == -1)
                ans = max(ans, dfs(v));
        return ans + 1;
    }

public:
    int maximumInvitations(vector<int> &favorite)
    {
        // Build graph with reversed edges for easy DFS
        int n = favorite.size();
        adj.resize(n);
        for (int i = 0; i < n; i++)
            adj[favorite[i]].push_back(i);

        // Mark nodes with their cyclicity. Cyclic nodes -> size of cycle
        // 0 for unvisited. -1 for extra. 2 for couples.
        cyclicity.resize(n);
        for (int i = 0; i < n; i++)
            if (!cyclicity[i])
                bt(i, 1);

        int maxCycleSize = *max_element(cyclicity.begin(), cyclicity.end());

        // dfs on couples to add longest extra paths per node
        int coupleExtra = 0;
        for (int i = 0; i < n; i++)
            if (cyclicity[i] == 2)
                coupleExtra += dfs(i);

        return max(maxCycleSize, coupleExtra);
    }
};

int main()
{
    Solution sol;
    vector<int> favorite = {2, 2, 1, 2};
    // vector<int> favorite = {1, 2, 0, 4, 5, 6, 3, 8, 7, 7, 9, 7};
    // vector<int> favorite = {6, 4, 4, 5, 0, 3, 3};
    cout << sol.maximumInvitations(favorite) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
