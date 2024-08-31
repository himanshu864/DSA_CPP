#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    stack<int> finishTime;
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, bool push, int u)
    {
        visited[u] = true;
        for (int v : adj[u])
            if (!visited[v])
                dfs(adj, visited, push, v);
        if (push)
            finishTime.push(u);
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        int ans = 0;
        // Sort edges based on finishing time
        vector<bool> visited(V, false);
        for (int u = 0; u < V; u++)
            if (!visited[u])
                dfs(adj, visited, true, u);

        // reverse edges
        vector<vector<int>> revAdj(V);
        for (int v = 0; v < V; v++)
        {
            visited[v] = false;
            for (int u : adj[v])
                revAdj[u].push_back(v);
        }

        // DFS
        while (finishTime.size())
        {
            int u = finishTime.top();
            finishTime.pop();
            if (visited[u])
                continue;
            dfs(revAdj, visited, false, u);
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int V = 5;
    vector<vector<int>> adj = {
        {2, 3},
        {0},
        {1},
        {4},
        {},
    };
    cout << sol.kosaraju(V, adj);
    return 0;
}

// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
