#include <iostream>
#include <vector>
#include <queue>
#include <set>
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
            {
                int dist = wt + v[1];
                if (dist < ans[v[0]])
                {
                    ans[v[0]] = dist;
                    minHeap.push({dist, v[0]});
                }
            }
        }
        return ans;
    }
    // Using ordered set
    vector<int> dijkstra2(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, 1e9);
        ans[S] = 0;
        set<pair<int, int>> set;
        set.insert({0, S});
        while (set.size())
        {
            auto it = *(set.begin());
            int u = it.second;
            int wt = it.first;
            set.erase(it);

            for (vector<int> v : adj[u])
            {
                int dist = wt + v[1];
                int node = v[0];
                if (dist < ans[node])
                {
                    if (ans[node] != 1e9) // erase already visited paths
                        set.erase({ans[node], node});
                    ans[node] = dist;
                    set.insert({dist, node});
                }
            }
        }
        return ans;
    }
};

// Time Complexity : E logV

// Very little efficiency difference b/w priority queue and ordered set
// set is used to erase already existing paths. Hence we save future paths. But erase takes logN. So hard to tell.
// Both are pretty much same

// a normal queue takes too much time since it might explore longer paths first and then second.

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
    vector<int> ans = sol.dijkstra2(V, adj, S);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
