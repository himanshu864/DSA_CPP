#include <iostream>
#include <vector>
using namespace std;

/*
Brute force on Adj Matrix to find shortest Path from all nodes to all nodes
Basically find dist for each i -> j edge via all nodes
If any node has i -> i less then zero. There's a negative cycle
T.C : O(N^3)
*/

class Solution
{
    // if edge does exist -1.
    // Should convert -1 to INT_MAX to get shortest path via algorithm
    // this is a work around
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int k = 0; k < n; k++) // via
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (matrix[i][k] != -1 && matrix[k][j] != -1)
                        matrix[i][j] = min((matrix[i][j] == -1 ? (int)1e9 : matrix[i][j]), matrix[i][k] + matrix[k][j]);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
    sol.shortest_distance(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
