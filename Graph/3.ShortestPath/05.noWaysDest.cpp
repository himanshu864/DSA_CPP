#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // convert to adj
        vector<vector<pair<int, int>>> adj(n); // city a -> {city b, time}
        for (vector<int> &e : roads)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Dijkstra's algorithm
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> paths(n);
        paths[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0}); // {time, city}

        while (q.size())
        {
            long long time = q.top().first;
            int city = q.top().second;
            q.pop();

            if (time > dist[city])
                continue;

            for (pair<int, int> &v : adj[city])
            {
                int newCity = v.first;
                long long totalTime = time + v.second;

                if (totalTime == dist[newCity])
                    paths[newCity] = (paths[newCity] + paths[city]) % mod;

                if (totalTime < dist[newCity])
                {
                    dist[newCity] = totalTime;
                    paths[newCity] = paths[city];
                    if (newCity != n - 1)
                        q.push({totalTime, newCity});
                }
            }
        }
        return paths[n - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int n = 7;
    cout << sol.countPaths(n, roads);
    return 0;
}

// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
