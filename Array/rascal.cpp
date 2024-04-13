#include <iostream>
#include <vector>
using namespace std;

// pascal
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int rth = 0; rth < numRows; rth++)
    {
        vector<int> row(rth + 1, 1);
        for (int i = 1; i < rth; i++)
            row[i] = ans[rth - 1][i - 1] + ans[rth - 1][i];
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> triange = generate(n);
    for (vector<int> row : triange)
    {
        for (int i = n; i > 0; i--)
            cout << " ";
        n--;
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/pascals-triangle/
