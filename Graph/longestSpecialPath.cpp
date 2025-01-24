#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans = {0, 1}; // {longest length, minimum size}
    vector<vector<pair<int, int>>> adj;
    vector<int> prefix;         // path prefix downwards
    unordered_map<int, int> mp; // map[value] = index_of_prefix

    void dfs(int node, int parent, int prev, vector<int> &nums)
    {
        // dynamically update prev w.r.t map
        int curr = prefix.size() - 1;
        int val = nums[node];
        int old_index = mp[val];
        if (mp.count(val))
            prev = mp[val] + 1;
        mp[val] = curr;

        // now update ans using sliding window
        int length = prefix[curr] - prefix[prev];
        int size = curr - prev + 1;
        if (length > ans[0])
        {
            ans[0] = length;
            ans[1] = size;
        }
        if (length == ans[0] && ans[1] > size)
            ans[1] = size;

        // explore children
        for (auto &[child, len] : adj[node])
            if (child != parent)
            {
                prefix.push_back(len + prefix.back());
                dfs(child, node, prev, nums);
                prefix.pop_back();
            }

        mp[val] = old_index;
    }

public:
    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
    {
        // build graph
        int n = edges.size() + 1;
        adj.resize(n);
        for (vector<int> e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // call recursion
        prefix.push_back(0);
        dfs(0, -1, 0, nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 4}, {2, 5, 6}};
    vector<int> nums = {2, 1, 2, 1, 3, 1};
    vector<int> ans = sol.longestSpecialPath(edges, nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/longest-special-path/
