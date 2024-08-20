#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    void dfs(vector<vector<pair<int, int>>> &adj, vector<int> &visited, int output, int i)
    {
        if (visited[i] != -1 && visited[i] <= output)
            return;
        visited[i] = output;
        for (pair<int, int> v : adj[i])
            dfs(adj, visited, output + v.second, v.first);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // convert to Adj. List
        vector<vector<pair<int, int>>> adj(N);
        for (vector<int> e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        vector<int> visited(N, -1);
        dfs(adj, visited, 0, 0);
        return visited;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}};
    int N = 4;
    int M = edges.size();
    vector<int> ans = sol.shortestPath(N, M, edges);
    for (int i : ans)
        cout << i << " ";
    return 0;
}
