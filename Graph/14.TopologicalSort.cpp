#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// DFS
class SolutionDfs
{
    vector<int> ans;
    void dfs(vector<int> adj[], vector<int> &visited, int u)
    {
        if (visited[u])
            return;

        visited[u] = 1;
        for (int v : adj[u])
            dfs(adj, visited, v);

        ans.push_back(u);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        for (int v = 0; v < V; v++)
            dfs(adj, visited, v);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Kahn's Algorithm
class SolutionBfs
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<int> indegree(V);
        for (int v = 0; v < V; v++)
            for (int u : adj[v])
                indegree[u]++;

        queue<int> q;
        for (int v = 0; v < V; v++)
            if (indegree[v] == 0)
                q.push(v);

        while (q.size())
        {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for (int u : adj[v])
                if (--indegree[u] == 0)
                    q.push(u);
        }
        return ans;
    }
};

int main()
{
    SolutionBfs sol;
    int V = 6;
    vector<int> adj[V] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<int> ans = sol.topoSort(V, adj);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://www.geeksforgeeks.org/problems/topological-sort/1
