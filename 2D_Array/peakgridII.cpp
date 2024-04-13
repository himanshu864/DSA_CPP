#include <bits/stdc++.h>
using namespace std;

// T.C: NlogM
vector<int> findPeakGridII(vector<vector<int>> &mat)
{
    int s = 0;
    int e = mat[0].size() - 1;
    while (s <= e) // apply binary on columns
    {
        int col = (s + (e - s) / 2);

        int row = 0; // find row with maximum in that col
        int maxi = -1;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][col] > maxi)
            {
                maxi = mat[i][col];
                row = i;
            }
        }

        if (col > 0 && mat[row][col - 1] > mat[row][col])
            e = col - 1;
        else if (col < mat[0].size() - 1 && mat[row][col + 1] > mat[row][col])
            s = col + 1;
        else
            return {row, col};
    }
    return {-1, -1};
}

// my soln: Worst Case: O(M*N); Average: O(Log(M*N))
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int m = mat.size() - 1;
    int n = mat[0].size() - 1;
    int i = m / 2, j = n / 2;
    while (i >= 0 && i <= m && j >= 0 && j <= n)
    {
        if (i > 0 && mat[i - 1][j] > mat[i][j])
            i--;
        else if (i < m && mat[i + 1][j] > mat[i][j])
            i++;
        else if (j > 0 && mat[i][j - 1] > mat[i][j])
            j--;
        else if (j < n && mat[i][j + 1] > mat[i][j])
            j++;
        else
            break;
    }
    return {i, j};
}

int main()
{
    vector<vector<int>> mat = {{10, 20, 15}, {21, 12, 14}, {7, 16, 32}};
    for (int i : findPeakGrid(mat))
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/find-a-peak-element-ii/description/
