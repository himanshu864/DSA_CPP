#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    vector<int> ans;
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int i)
    {
        if (visited[i] != -1)
            return visited[i] == 1;

        visited[i] = 2; // Loading
        for (int v : graph[i])
            if (!dfs(graph, visited, v))
            {
                visited[i] = 0;
                return false;
            }

        ans.push_back(i);
        visited[i] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++)
            dfs(graph, visited, i);

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
