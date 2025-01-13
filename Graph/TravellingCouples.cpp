#include <bits/stdc++.h>
using namespace std;

int C1, C2, C3; // cost of male, female, and couple ticket
int N, M;       // number of cities and trains
vector<vector<int>> adj;

int dijkstra(int start, int C, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (pq.size())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] <= cost)
            continue;
        dist[u] = cost;

        for (int v : adj[u])
            if (cost + C < dist[v])
                pq.push({cost + C, v});
    }
    return -1;
}

// Output: Minimum collective cost for Male at city[0] and Female at city[1] to reach city[N - 1]
void solve()
{
    // precompute shortest path from city[0] to all cities for male
    vector<int> male_cost(N, INT_MAX);
    dijkstra(0, C1, male_cost);

    // precompute shortest path from city[1] to all cities for female
    vector<int> female_cost(N, INT_MAX);
    dijkstra(1, C2, female_cost);

    // precompute shortest path from all cities to city[N - 1] as a couple
    vector<int> couple_cost(N, INT_MAX);
    dijkstra(N - 1, C3, couple_cost);

    // Return smallest collective cost M + F + C
    int ans = INT_MAX;
    for (int city = 0; city < N; city++)
        ans = min(ans, male_cost[city] + female_cost[city] + couple_cost[city]);
    cout << ans << endl;
}

int main()
{
    cin >> C1 >> C2 >> C3 >> N >> M;
    adj.resize(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve();
    return 0;
}
