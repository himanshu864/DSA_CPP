#include <bits/stdc++.h>
using namespace std;

int N, M; // nodes and edges
vector<vector<pair<int, int>>> adj;

/*
# 0-1 BFS

- Observe, default bfs has at max 2 levels inside the queue.
- Level x is in the front used to push level x + 1 nodes to the back
- But If an edge is 0 - weighted. We'll push it in the front, since it's in the same level
*/

// Output: Minimum no. of edges to reverse to reach [N - 1] from node [0]
void solve()
{
    vector<bool> visited(N);
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while (q.size())
    {
        auto [u, level] = q.front();
        q.pop_front();

        if (u == N - 1)
        {
            cout << level << endl;
            return;
        }

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : adj[u])
            if (!visited[v])
            {
                if (w == 1)
                    q.push_back({v, level + 1});
                else
                    q.push_front({v, level});
            }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        adj.clear();
        adj.resize(N);
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--; // 0-indexed
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1}); // reversed edge is 1-weighted for bfs
        }
        solve();
    }
    return 0;
}
