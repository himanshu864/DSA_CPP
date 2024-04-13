#include <iostream>
using namespace std;

int main()
{
    // Define the dimensions of the matrix
    int row;
    cout << "Enter rows: ";
    cin >> row;
    int col;
    cout << "Enter cols: ";
    cin >> col;

    // Dynamically allocate memory for the matrix
    int **mat = new int *[row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new int[col];
    }

    // Input values for the matrix
    cout << "Enter elements: ";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> mat[i][j];

    // Output the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // Deallocate the memory for the matrix
    for (int i = 0; i < row; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}

/*
int main()
{
    int row = 3;
    int cols[3] = {2, 4, 3};

    int **mat = new int *[row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new int[cols[i]];
    }

    int count = 1;
    for (int i = 0; i < row; i++)
    {
        int col = cols[i];
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = count++;
            cout << mat[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
        delete[] mat[i];
    delete[] mat;
    return 0;
}
*/
