#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS via Toposort
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> A(n + 1);
    for (auto &e : edges)
        A[e.first].push_back(e.second);

    vector<int> topoSort;
    vector<int> indegree(n + 1);
    for (int v = 1; v <= n; v++)
        for (int u : A[v])
            indegree[u]++;

    queue<int> q;
    for (int v = 1; v <= n; v++)
        if (indegree[v] == 0)
            q.push(v);

    while (q.size())
    {
        int v = q.front();
        q.pop();
        topoSort.push_back(v);
        for (int u : A[v])
            if (--indegree[u] == 0)
                q.push(u);
    }
    return topoSort.size() != n;
}

int main()
{
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    cout << detectCycleInDirectedGraph(n, edges) << endl;
    return 0;
}

// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
