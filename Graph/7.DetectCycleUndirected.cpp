#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bfs
class Solution
{
    bool helper(vector<bool> &visited, vector<int> adj[], int i)
    {
        queue<pair<int, int>> q;
        q.push({i, -1});
        visited[i] = true;
        while (q.size())
        {
            int x = q.front().first;
            int d = q.front().second;
            q.pop();
            for (int e : adj[x])
            {
                if (e == d)
                    continue;
                if (visited[e])
                    return true;
                q.push({e, x});
                visited[e] = true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i] && helper(visited, adj, i))
                return true;
        return false;
    }
};

// dfs
class Solution2
{
    bool helper(vector<bool> &visited, vector<int> adj[], int i, int parent)
    {
        if (visited[i])
            return true;
        visited[i] = true;
        for (int x : adj[i])
        {
            if (x == parent)
                continue;
            if (helper(visited, adj, x, i))
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i] && helper(visited, adj, i, -1))
                return true;
        return false;
    }
};

int main()
{
    Solution sol;
    int V = 5, E = 5;
    vector<int> adj[V] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    cout << "cycle " << (sol.isCycle(V, adj) ? "yes" : "no") << endl;
    return 0;
}
