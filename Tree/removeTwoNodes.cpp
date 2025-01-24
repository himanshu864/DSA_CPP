#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<int, int>> &edges, int n)
{
    int ans = 0;
    vector<vector<int>> adj(n); // build graph
    vector<int> degree(n);      // count degrees
    for (auto [u, v] : edges)
    {
        u--, v--; // 1-indexed
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // find max degree
    int first = 0;
    for (int i = 0; i < n; i++)
        first = max(first, degree[i]);

    // find all nodes with max degree
    vector<int> maxNodes;
    for (int i = 0; i < n; i++)
        if (degree[i] == first)
            maxNodes.push_back(i);

    // for first two maxNode
    for (int z = 0; z < min(2, (int)maxNodes.size()); z++)
    {
        int u = maxNodes[z];
        // remove that node and update it's neighbor degree
        degree[u] = 0;
        for (int v : adj[u])
            degree[v]--;

        // find second maxDegree
        int second = 0;
        for (int d : degree)
            second = max(second, d);

        // update total no. of components
        ans = max(ans, first + second - 1);

        // backtrack degree by adding that node with edges
        degree[u] = first;
        for (int v : adj[u])
            degree[v]++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> edges;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        solve(edges, n);
    }
    return 0;
}

// https://codeforces.com/problemset/problem/2063/C
