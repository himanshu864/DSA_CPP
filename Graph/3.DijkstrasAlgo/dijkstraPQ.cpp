#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest distance of all the vertices
// from the source vertex S of Weight Undirected Graph
class Solution
{
public:
    // Using Priority Queue
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, 1e9);
        ans[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, S});
        while (minHeap.size())
        {
            int wt = minHeap.top().first;
            int u = minHeap.top().second;
            minHeap.pop();
            for (vector<int> v : adj[u])
                if (wt + v[1] < ans[v[0]])
                {
                    ans[v[0]] = wt + v[1];
                    minHeap.push({wt + v[1], v[0]});
                }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int V = 6;
    vector<vector<int>> adj[] = {
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{2, 6}, {3, 2}, {4, 3}},
    };
    int S = 0;
    vector<int> ans = sol.dijkstra(V, adj, S);
    for (int i : ans)
        cout << i << " ";
    return 0;
}
