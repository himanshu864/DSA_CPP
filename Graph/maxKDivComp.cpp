#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;

    long long dfs(int parent, vector<unordered_set<int>> &adj, vector<int> &values, int k)
    {
        long long component = values[parent];
        for (int child : adj[parent])
        {
            adj[child].erase(parent); // visited
            component += dfs(child, adj, values, k);
        }
        if (component % k == 0)
        {
            ans++;
            return 0;
        }
        return component;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<unordered_set<int>> adj(n);
        for (vector<int> e : edges)
        {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        dfs(0, adj, values, k);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values = {1, 8, 1, 4, 4};
    int k = 6;
    cout << sol.maxKDivisibleComponents(n, edges, values, k) << '\n';
    return 0;
}

// https://leetcode.com/problems/maximum-number-of-k-divisible-components/
