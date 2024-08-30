#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
MST - Minimum (Cost) Spanning Tree
An undirected weighted graph with N vertices and N - 1 edges
And whos edges sum is minimum
*/

// Optimized
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        vector<bool> visited(V, false); // keep track of whos all edges have been pushed
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0});

        int edges = V; // (n - 1) edges for MST + 1 dummy pop
        while (edges)
        {
            int wt = q.top()[0];
            int u = q.top()[1];
            q.pop();

            if (visited[u])
                continue;

            edges--;
            ans += wt;
            visited[u] = 1;
            for (vector<int> v : adj[u])
                if (!visited[v[0]])
                    q.push({v[1], v[0]});
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int V = 3;
    vector<vector<int>> adj[V] = {
        {{1, 5}, {2, 1}},
        {{0, 5}, {2, 3}},
        {{0, 1}, {1, 3}},
    };
    cout << sol.spanningTree(V, adj);
    return 0;
}

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
