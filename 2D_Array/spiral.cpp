#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols)
{
    int r = 0, rx = (nRows - 1), c = 0, cx = (nCols - 1);
    for (int k = 0; r <= rx && c <= cx; k++)
    {
        if (k % 4 == 0)
        {
            for (int j = c; j <= cx; j++)
                cout << input[r][j] << " ";
            r++;
        }
        else if (k % 4 == 1)
        {
            for (int i = r; i <= rx; i++)
                cout << input[i][cx] << " ";
            cx--;
        }
        else if (k % 2 == 0)
        {
            for (int j = cx; j >= c; j--)
                cout << input[rx][j] << " ";
            rx--;
        }
        else
        {
            for (int i = rx; i >= r; i--)
                cout << input[i][c] << " ";
            c++;
        }
    }
}

/*
void spiralPrint(int **input, int nRows, int nCols)
{
    int r = 0, rx = nRows - 1;
    int c = 0, cx = nCols - 1;
    while(r <= rx && c <= cx)
    {
        for(int i = c; i <= cx; i++)
            cout << input[r][i] << " ";
        r++;

        for(int i = r; i <= rx; i++)
            cout << input[i][cx] << " ";
        cx--;

        if(r <= rx)
        {
            for(int i = cx; i >= c; i--)
                cout << input[rx][i] << " ";
            rx--;
        }
        if(c <= cx)
        {
            for(int i = rx; i >= r; i--)
                cout << input[i][c] << " ";
            c++;
        }
    }
}
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        return 0;
    }
}