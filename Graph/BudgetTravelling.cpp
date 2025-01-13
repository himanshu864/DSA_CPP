#include <bits/stdc++.h>
using namespace std;

int N, M;              // Number of cities and roads
vector<vector<int>> W; // Roads: {u, v, fuel_cost}
vector<int> COST;      // Cost of refueling at each city
int A, B, C;           // Source city, destination city, tank capacity

int solve()
{
    // Build adjacency list
    vector<vector<pair<int, int>>> adj(N);
    for (const vector<int> &e : W)
    {
        adj[e[0]].emplace_back(e[1], e[2]);
        adj[e[1]].emplace_back(e[0], e[2]);
    }

    // Dijkstra's algorithm with fuel state
    vector<vector<int>> visited(N, vector<int>(C + 1, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({0, 0, A}); // {cost, fuel_in_tank, current_city}

    // Dijkstra
    while (pq.size())
    {
        int current_cost = pq.top()[0];
        int fuel_left = pq.top()[1];
        int city = pq.top()[2];
        pq.pop();

        // If we reached the destination city with lowest cost
        if (city == B)
            return current_cost;

        // Prune if this state was already visited with a lower cost
        if (current_cost >= visited[city][fuel_left])
            continue;
        visited[city][fuel_left] = current_cost;

        // Explore neighbors
        for (auto [next_city, fuel_cost] : adj[city])
            if (fuel_left >= fuel_cost)
                pq.push({current_cost, fuel_left - fuel_cost, next_city});

        // Refuel at the current city
        int refuel_cost = current_cost;
        int new_fuel = fuel_left;
        while (new_fuel < C)
        {
            new_fuel++;
            refuel_cost += COST[city];
            if (refuel_cost < visited[city][new_fuel])
                pq.push({refuel_cost, new_fuel, city});
        }
    }

    return -1; // If no path exists
}

int main()
{
    cin >> N >> M;
    W.resize(M);
    for (int i = 0; i < M; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        W[i] = {u - 1, v - 1, d}; // 0-indexing
    }

    COST.resize(N);
    for (int i = 0; i < N; i++)
        cin >> COST[i];

    cin >> A >> B >> C;
    A--, B--; // 0-indexing

    cout << solve() << endl;
    return 0;
}
