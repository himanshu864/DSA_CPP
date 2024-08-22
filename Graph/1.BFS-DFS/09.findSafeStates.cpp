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

class Solution
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

int main()
{
    Solution sol;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    // vector<vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/find-eventual-safe-states/
