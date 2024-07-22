#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void helper(vector<vector<int>> &A, vector<int> &ans, vector<bool> &visited, int i)
{
    ans.push_back(i);
    visited[i] = true;
    for (int v = 1; v < A.size(); v++)
        if (A[i][v] == 1 && !visited[v])
            helper(A, ans, visited, v);
}

vector<int> DFS(vector<vector<int>> &A, int i)
{
    vector<int> ans;
    vector<bool> visited(A.size(), false);
    helper(A, ans, visited, i);
    return ans;
}

int main()
{
    vector<vector<int>> A = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
    };
    vector<int> dfs = DFS(A, 1);
    for (int i : dfs)
        cout << i << " ";
    cout << endl;
    return 0;
}
