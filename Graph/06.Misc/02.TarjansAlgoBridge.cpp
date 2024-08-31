#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int timer = 0;
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &time, vector<int> &low, int p, int i)
    {
        visited[i] = 1;
        time[i] = timer;
        low[i] = timer++;
        for (int v : adj[i])
        {
            if (v == p) // ignore parent vertex
                continue;

            if (!visited[v])
            {
                dfs(adj, visited, time, low, i, v);
                low[i] = min(low[i], low[v]);

                // check if v can reach i without this edge
                if (low[v] > time[i])
                    ans.push_back({i, v}); // bridge
            }
            else // take low if visited
                low[i] = min(low[i], low[v]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // convert edges to adj
        vector<vector<int>> adj(n);
        for (vector<int> e : connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n);
        vector<int> time(n);
        vector<int> low(n);

        // DFS
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(adj, visited, time, low, -1, i);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> ans = sol.criticalConnections(n, connections);
    for (auto i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/critical-connections-in-a-network/
