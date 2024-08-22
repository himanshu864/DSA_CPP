#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> miniCostSpanTree(vector<vector<int>> A)
{
    int n = A.size() - 1;                            // total no. of vertices
    vector<vector<int>> t(2, vector<int>(n - 1, 0)); // v - 1, edges
    vector<int> near(n + 1, INT_MAX);                // 1-indexed

    // find minimum cost edge
    int im = 0, jm = 0;
    int minEdge = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) // only check upper half. As we want t[0] to be smaller
            if (A[i][j] < minEdge)
            {
                minEdge = A[i][j];
                im = i;
                jm = j;
            }

    // mark first edge in spanning tree
    t[0][0] = im;
    t[1][0] = jm;
    // mark selected vertices 0 in near
    near[im] = 0;
    near[jm] = 0;

    // mark rest near array to find next minimum connected edge
    // by comparing dist b/w remaining vertices and (im, jm)
    for (int i = 1; i <= n; i++)
        if (near[i] != 0)
            near[i] = A[i][im] < A[i][jm] ? im : jm;

    // repeating steps
    for (int z = 1; z < n - 1; z++)
    {
        // find minimum connected edge
        minEdge = INT_MAX;
        for (int i = 1; i <= n; i++)
            if (near[i] != 0 && A[i][near[i]] < minEdge)
            {
                minEdge = A[i][near[i]];
                im = i;
            }

        // update spanning tree and near array
        t[0][z] = im;
        t[1][z] = near[im];
        near[im] = 0;

        for (int i = 1; i <= n; i++)
            if (near[i] != 0 && A[i][im] < A[i][near[i]])
                near[i] = im;
    }
    return t;
}

int main()
{
    vector<vector<int>> A = {
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 25, INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX},
        {INT_MAX, 25, INT_MAX, 12, INT_MAX, INT_MAX, INT_MAX, 10},
        {INT_MAX, INT_MAX, 12, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 8, INT_MAX, 16, INT_MAX, 14},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 16, INT_MAX, 20, 18},
        {INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX, 20, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 10, INT_MAX, 14, 18, INT_MAX, INT_MAX},
    };
    vector<vector<int>> t = miniCostSpanTree(A);
    for (auto e : t)
    {
        for (int v : e)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
