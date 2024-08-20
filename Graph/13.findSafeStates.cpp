#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
visited[i]  => -1: Not Visited
            => 0 : Visited and is part of a cycle (i.e., not safe).
            => 1 : Visited and is safe.

If a node i is part of a cycle or leads to a node that is part of a cycle, it's marked as not safe.
If all adjacent nodes from i lead to safe nodes or are terminal nodes, then i is safe.
*/

class SolutionDFS
{
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int i)
    {
        if (visited[i] != -1)
            return visited[i] == 1;

        visited[i] = 0; // Rec Stack
        for (int v : graph[i])
            if (!dfs(graph, visited, v))
                return false;

        visited[i] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> ans;
        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++)
            if (dfs(graph, visited, i))
                ans.push_back(i);
        return ans;
    }
};

/*
1. reverse all the edges
2. Outdegree's now become indegree. Hence, now any node with 0 indegree is a terminal node
3. Perform a topoLogical sort on the reversed Graph and sort the result.

Here we are basically calc all terminal nodes and then backtracking to see which nodes lead to them
If any node has other edges which don't origin from terminal nodes, they aren't safe and won't be indegree 0
*/

class SolutionBFS
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;
        int V = graph.size();
        vector<int> outdegree(V);
        vector<vector<int>> revGraph(V);
        for (int v = 0; v < V; v++)
            for (int e : graph[v])
            {
                revGraph[e].push_back(v);
                outdegree[v]++;
            }

        queue<int> q;
        for (int v = 0; v < V; v++)
            if (outdegree[v] == 0)
                q.push(v);

        while (q.size())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int v : revGraph[x])
                if (--outdegree[v] == 0)
                    q.push(v);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    SolutionDFS sol;
    // vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/find-eventual-safe-states/
