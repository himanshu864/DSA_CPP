#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        int n = routes.size(); // total routes

        vector<unordered_set<int>> bus_stops_at_route(n);
        unordered_map<int, vector<int>> routes_at_bus_stop;
        for (int route = 0; route < n; route++)
        {
            // map what bus_stops are at route
            bus_stops_at_route[route].insert(routes[route].begin(), routes[route].end());

            // map which routes can we take at bus_stop
            for (int bus_stop : routes[route])
                routes_at_bus_stop[bus_stop].push_back(route);
        }

        // Build route to route graph
        vector<unordered_set<int>> adj(n);
        for (auto &[bus_stop, route_list] : routes_at_bus_stop)
            for (int i = 0; i < route_list.size(); i++)
                for (int j = i + 1; j < route_list.size(); j++)
                {
                    adj[route_list[i]].insert(route_list[j]);
                    adj[route_list[j]].insert(route_list[i]);
                }

        // bfs on routes
        vector<bool> visited(n);
        queue<pair<int, int>> q; // {route_no, bus_count}
        for (int route : routes_at_bus_stop[source])
            q.push({route, 1});

        while (q.size())
        {
            auto [route, bus_count] = q.front();
            q.pop();

            if (bus_stops_at_route[route].count(target))
                return bus_count;

            if (visited[route])
                continue;
            visited[route] = true;

            for (int r : adj[route])
                if (!visited[r])
                    q.push({r, bus_count + 1});
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}}; // 1-indexed
    int source = 1;
    int target = 6;
    cout << sol.numBusesToDestination(routes, source, target) << endl;
    return 0;
}

// NOT OPTIMAL

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        // Map each bus stop to the list of routes that pass through it
        unordered_map<int, vector<int>> routes_at_stop;
        for (int route = 0; route < (int)routes.size(); ++route)
            for (int stop : routes[route])
                routes_at_stop[stop].push_back(route);

        // BFS
        queue<pair<int, int>> bfs; // {current_stop, buses_taken}
        bfs.push({source, 0});

        unordered_set<int> visited_stops = {source};
        unordered_set<int> visited_routes;

        while (bfs.size())
        {
            int current_stop = bfs.front().first;
            int buses_taken = bfs.front().second;
            bfs.pop();

            if (current_stop == target)
                return buses_taken;

            for (int route : routes_at_stop[current_stop])
            {
                if (visited_routes.count(route))
                    continue;
                visited_routes.insert(route);

                // Explore all stops in the current route
                for (int stop : routes[route])
                    if (!visited_stops.count(stop))
                    {
                        visited_stops.insert(stop);
                        bfs.push({stop, buses_taken + 1});
                    }
            }
        }

        return -1;
    }
};