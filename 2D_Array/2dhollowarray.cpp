#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[100][100] = {0};
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int k = 1;
    while (k <= n * n)
    {
        for (int i = left; i <= right; i++)
            arr[top][i] = k++;
        top++;
        for (int i = top; i <= bottom; i++)
            arr[i][right] = k++;
        right--;
        for (int i = right; i >= left; i--)
            arr[bottom][i] = k++;
        bottom--;
        for (int i = bottom; i >= top; i--)
            arr[i][left] = k++;
        left++;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << arr[i][j] << "\t";
            else
                cout << " \t";
        }
        cout << endl;
    }
    return 0;
}
