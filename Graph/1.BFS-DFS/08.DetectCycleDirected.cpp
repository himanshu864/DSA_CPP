#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(vector<vector<int>> &A, vector<int> &state, int v)
{
    // If the node is currently in the recursion stack, it's a cycle
    if (state[v] == 1)
        return true;

    // If the node is fully processed, it's safe
    if (state[v] == 2)
        return false;

    // Mark the node as visited (entering recursion stack)
    state[v] = 1;

    for (int x : A[v])
        if (dfs(A, state, x))
            return true;

    // Mark the node as fully processed (exiting recursion stack)
    state[v] = 2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> A(n + 1);
    for (auto &e : edges)
        A[e.first].push_back(e.second);

    // State vector to track visited and path
    vector<int> state(n + 1, 0);

    for (int v = 1; v <= n; v++)
        if (state[v] == 0 && dfs(A, state, v))
            return true;

    return false;
}

int main()
{
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    cout << detectCycleInDirectedGraph(n, edges) << endl;
    return 0;
}

// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
