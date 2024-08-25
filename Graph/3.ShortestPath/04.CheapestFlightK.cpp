#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Smart to put stops first and then cost inside minHeap
Makes sure that smallest levels pop first
And then based on cost for optimization
*/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // convert edges to adj list
        vector<vector<pair<int, int>>> adj(n); // {city, cost}
        for (vector<int> f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        // memoization
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // {stops, cost, city}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, src});
        while (q.size())
        {
            int stops = q.top()[0];
            if (stops > k)
                break;

            int cost = q.top()[1];
            int u = q.top()[2];
            q.pop();

            for (pair<int, int> p : adj[u])
            {
                int v = p.first;
                int c = p.second;
                if (dist[v] > cost + c)
                {
                    dist[v] = cost + c;
                    q.push({stops + 1, cost + c, v});
                }
            }
        }
        return dist[dst] != 1e9 ? dist[dst] : -1;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200},
    };
    int src = 0;
    int dst = 3;
    int k = 1;
    cout << sol.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}

// https://leetcode.com/problems/cheapest-flights-within-k-stops/
