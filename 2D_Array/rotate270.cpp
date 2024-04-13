#include <iostream>
#include <vector>
using namespace std;

void inplaceRotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++)
            swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (n / 2); j++)
            swap(matrix[i][j], matrix[i][n - j - 1]);
}

int main()
{
    // vector<vector<int>> matrix =
    //     {
    //         {1, 2, 3, 4},
    //         {5, 6, 7, 8},
    //         {9, 10, 11, 12},
    //         {13, 14, 15, 16}};
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (auto row : matrix)
    {
        for (int i : row)
            cout << i << '\t';
        cout << endl;
    }

    inplaceRotate(matrix);

    cout << "After Rotation --> " << endl;
    for (auto row : matrix)
    {
        for (int i : row)
            cout << i << '\t';
        cout << endl;
    }
    return 0;
}
