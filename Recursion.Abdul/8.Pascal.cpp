#include <iostream>
#include <vector>
using namespace std;

int ncr(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row;
        for (int j = 0; j <= i; j++)
            row.push_back(ncr(i, j));
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int n = 6;
    int r = 3;
    cout << ncr(n, r) << endl;

    int numsRow = 7;
    for (vector<int> x : generate(numsRow))
    {
        for (int y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/pascals-triangle/
