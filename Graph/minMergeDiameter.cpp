#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Calculate maxHeight of the tree from the given node
    int dfs(int node, int parent, vector<unordered_set<int>> &adj, int &diameter)
    {
        int firstMaxHeight = 0, secondMaxHeight = 0;
        for (int neighbor : adj[node])
            if (neighbor != parent)
            {
                int height = dfs(neighbor, node, adj, diameter);
                if (height > firstMaxHeight)
                {
                    secondMaxHeight = firstMaxHeight;
                    firstMaxHeight = height;
                }
                else if (height > secondMaxHeight)
                    secondMaxHeight = height;
            }
        // Update diameter to find maximum (height1 + height2) for each node
        diameter = max(diameter, firstMaxHeight + secondMaxHeight);
        return firstMaxHeight + 1;
    }

    vector<unordered_set<int>> adjList(vector<vector<int>> &edges)
    {
        vector<unordered_set<int>> adj(edges.size() + 1);
        for (vector<int> edge : edges)
        {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        return adj;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        auto adj1 = adjList(edges1);
        auto adj2 = adjList(edges2);

        // Compute diameters for both trees
        int diameter1 = 0, diameter2 = 0;
        dfs(0, -1, adj1, diameter1);
        dfs(0, -1, adj2, diameter2);

        // Compute the minimum diameter of the merged tree
        int mergedDiameter = 1 + (diameter1 + 1) / 2 + (diameter2 + 1) / 2;

        // Return actual diameter to be maximum of all three diameters
        return max({diameter1, diameter2, mergedDiameter});
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}};
    vector<vector<int>> edges2 = {{0, 1}};
    cout << sol.minimumDiameterAfterMerge(edges1, edges2) << endl;
    return 0;
}

// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/
