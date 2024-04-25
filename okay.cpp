#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        // My first fake submit
        // haven't dont graphs yet
        // don't wanna break 50 days streak
        unordered_map<int, vector<int>> graph;
        for (auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr == end)
                return 1;
            for (auto &node : graph[curr])
            {
                if (!visited[node])
                {
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << "stfu" << endl;
    return 0;
}

// https://leetcode.com/problems/find-if-path-exists-in-graph
