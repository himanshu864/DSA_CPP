#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    void explore(vector<vector<int>> &A, vector<bool> &connected, int i)
    {
        connected[i] = true;
        for (int v = 0; v < A.size(); v++)
            if (A[i][v] == 1 && !connected[v])
                explore(A, connected, v);
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> connected(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!connected[i])
            {
                explore(isConnected, connected, i);
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}

// https://leetcode.com/problems/number-of-provinces
