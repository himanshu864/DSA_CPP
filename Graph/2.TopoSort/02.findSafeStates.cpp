#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
1. reverse all the edges
2. Outdegree's now become indegree. Hence, now any node with 0 indegree is a terminal node
3. Perform a topoLogical sort on the reversed Graph and sort the result.

Here we are basically calc all terminal nodes and then backtracking to see which nodes lead to them
If any node has other edges which don't origin from terminal nodes, they aren't safe and won't be indegree 0
*/

class Solution
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
    Solution sol;
    // vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/find-eventual-safe-states/
