#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> BFS(vector<vector<int>> &A, int i)
{
    vector<int> ans;
    int n = A.size() - 1;

    queue<int> q;
    q.push(i);
    vector<bool> visited(n + 1, false);
    visited[i] = true;
    while (q.size())
    {
        int x = q.front();
        ans.push_back(x);
        q.pop();

        for (int v = 1; v <= n; v++)
        {
            if (A[x][v] == 0 || visited[v])
                continue;
            q.push(v);
            visited[v] = true;
        }
    }
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
    vector<int> bfs = BFS(A, 5);
    for (int i : bfs)
        cout << i << " ";
    cout << endl;
    return 0;
}
