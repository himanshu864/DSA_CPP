#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &A, vector<bool> &visited, vector<bool> &path, int v)
{
    // check cycle
    if (path[v])
        return true;
    // check visited
    if (visited[v])
        return false;

    // dfs on path
    path[v] = true;
    visited[v] = true;
    for (auto x : A[v])
        if (dfs(A, visited, path, x))
            return true;

    // visited but not on path anymore
    path[v] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // To prevent repeating dfs
    vector<bool> visited(n + 1, false);
    // To check if already visited same path. i.e. Recursive Stack. Hence Cyclic.
    vector<bool> path(n + 1, false);

    // Convert to Adjacency List
    vector<vector<int>> A(n + 1);
    for (auto e : edges)
        A[e.first].push_back(e.second);

    for (int v = 1; v <= n; v++)
        if (dfs(A, visited, path, v))
            return true;
    return false;
}

int main()
{
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    // int n = 10;
    // vector<pair<int, int>> edges = {{1, 2}, {4, 5}, {5, 9}, {5, 10}, {5, 1}, {5, 3}, {6, 7}};
    cout << detectCycleInDirectedGraph(n, edges) << endl;
    return 0;
}

// could use same array with 1 for visited and 2 for path.

// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
