#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<pair<int, int>>> adj; // a -> {b, w}

    // bfs to check if all nodes are reachable from 0
    // by only taking edges with weight <= mid
    bool isReachable(int mid)
    {
        int n = adj.size();
        int count = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            int u = q.front();
            q.pop();

            if (visited[u])
                continue;
            visited[u] = true;
            count++;

            for (auto &[v, w] : adj[u])
                if (w <= mid && !visited[v])
                    q.push(v);
        }
        return count == n;
    }

public:
    int minMaxWeight(int n, vector<vector<int>> &edges, int threshold)
    {
        // build a graph with reversed edges
        adj.resize(n);
        for (vector<int> e : edges)            // {a, b, w} a -> b
            adj[e[1]].push_back({e[0], e[2]}); // b -> a

        // Binary search to minimum maximum edge
        int ans = -1;
        int s = 1, e = 1e6;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isReachable(mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{1, 0, 1}, {2, 0, 2}, {3, 0, 1}, {4, 3, 1}, {2, 1, 1}};
    int threshold = 2;
    cout << sol.minMaxWeight(n, edges, threshold) << endl;
    return 0;
}

// https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/
