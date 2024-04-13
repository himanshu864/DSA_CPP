#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        for (int j = 1; j <= (2 * n - 1); j++)
        {
            int a = i, b = j, mini, org;
            if (a > n)
                a = (2 * n - i);
            if (b > n)
                b = (2 * n - j);

            mini = min(a, b);
            org = (n + 1 - mini);
            cout << org;
        }
        cout << endl;
    }
    return 0;
}

// int main()
// {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//     int arr[100][100] = {0};
//     int top = 0, bottom = 2 * n - 2, left = 0, right = 2 * n - 2;
//     int k = n;
//     while (k > 0)
//     {
//         for (int i = left; i <= right; i++)
//             arr[top][i] = k;
//         top++;
//         for (int i = top; i <= bottom; i++)
//             arr[i][right] = k;
//         right--;
//         for (int i = right; i >= left; i--)
//             arr[bottom][i] = k;
//         bottom--;
//         for (int i = bottom; i >= top; i--)
//             arr[i][left] = k;
//         left++;
//         k--;
//     }

//     for (int i = 0; i < 2 * n - 1; i++)
//     {
//         for (int j = 0; j < 2 * n - 1; j++)
//             cout << arr[i][j];
//         cout << endl;
//     }
//     return 0;
// }
