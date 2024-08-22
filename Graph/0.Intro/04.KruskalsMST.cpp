#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class MST
{
    int find(vector<int> &set, int u)
    {
        while (set[u] > 0)
            u = set[u];
        return u;
    }

public:
    vector<vector<int>> kruskal(vector<vector<int>> &edges, int v)
    {
        int e = edges[0].size();
        vector<vector<int>> t(2, vector<int>(v - 1, 0));
        vector<bool> included(e, false);
        vector<int> set(v + 1, -1);

        int m = 0;
        while (m < v - 1)
        {
            // find next possible minimum cost edge, that isn't included
            int minEdge = INT_MAX, col;
            for (int i = 0; i < e; i++)
                if (!included[i] && edges[2][i] < minEdge)
                {
                    minEdge = edges[2][i];
                    col = i;
                }

            included[col] = true;

            // Make sure no cycles are formed
            int x = edges[0][col];
            int y = edges[1][col];

            // find x and y heads
            int xh = find(set, x);
            int yh = find(set, y);

            // if same heads, means will form cycle
            if (xh == yh)
                continue;

            // else weighted union
            if (set[xh] < set[yh])
            {
                set[xh] += set[yh];
                set[yh] = xh;
            }
            else
            {
                set[yh] += set[xh];
                set[xh] = yh;
            }

            t[0][m] = x;
            t[1][m++] = y;

            for (auto s : set)
                cout << s << "\t";
            cout << endl;
        }
        return t;
    }
};

int main()
{
    MST algo;
    vector<vector<int>> edges = {
        {1, 1, 2, 2, 3, 4, 4, 5, 5},
        {2, 6, 3, 7, 4, 5, 7, 6, 7},
        {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    int v = 7;
    vector<vector<int>> t = algo.kruskal(edges, v);
    for (auto i : t)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
