#include <iostream>
using namespace std;

bool binary2d(int input[][4], int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;
    while (start <= end)
    {
        int idx = (start + end) / 2;
        int i = idx / col;
        int j = idx % col;
        if (input[i][j] == target)
            return true;
        else if (input[i][j] > target)
            end = idx - 1;
        else
            start = idx + 1;
    }
    return false;
}

bool linear2d(int input[][4], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (input[i][j] == target)
                return true;
    return false;
}

void print2d(int input[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << input[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int matrix[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    print2d(matrix, 3, 4);

    int target;
    cout << "Target: ";
    cin >> target;
    cout << "Linear Searching... : O(n*m): ";
    cout << linear2d(matrix, 3, 4, target) << endl;
    cout << "Binary Searching... : O(log(n*m)): ";
    cout << binary2d(matrix, 3, 4, target) << endl;
    return 0;
}

// https://leetcode.com/problems/search-a-2d-matrix/description/
