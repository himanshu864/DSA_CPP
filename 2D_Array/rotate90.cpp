#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // imagine a block toppling to right.
    // the bottom right corner will be the pivot.
    // hence invert the matrix from top left to bottom right
    // corner (transpose),
    // and then mirror the matrix left to right.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (n / 2); j++)
            swap(matrix[i][j], matrix[i][n - j - 1]);
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/rotate-image/
