#include <iostream>
#include <vector>
using namespace std;

// Constant Space complexity:
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // Check if the first row contains any zero
    for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0)
        {
            firstRowHasZero = true;
            break;
        }

    // Check if the first column contains any zero
    for (int i = 0; i < m; i++)
        if (matrix[i][0] == 0)
        {
            firstColHasZero = true;
            break;
        }

    // Use the first row and first column to mark rows and columns that should be set to zero
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

    // Set zeros based on marks in the first row and first column
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    // Set zeros in the first row if needed
    if (firstRowHasZero)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;

    // Set zeros in the first column if needed
    if (firstColHasZero)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
}

// My solution of Space Complexity: O(m + n)
void setZeroplz(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> rowcheck(m, false);
    vector<bool> colcheck(n, false);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0)
                rowcheck[i] = colcheck[j] = true;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (rowcheck[i] || colcheck[j])
                matrix[i][j] = 0;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 1}, {2, 0, 4}, {4, 5, 6}, {2, 1, 9}};
    for (auto row : matrix)
    {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
    setZeroplz(matrix);
    cout << "After setting zero: " << endl;
    for (auto row : matrix)
    {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
