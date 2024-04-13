#include <iostream>
#include <algorithm>
using namespace std;

void swapplease(int arr[], int i, int n)
{
    if (i == n)
        return;
    if (arr[i - 1] > arr[i])
        swap(arr[i - 1], arr[i]);
    swapplease(arr, i + 1, n);
}

void sortplease(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;
    swapplease(arr, 1, n);
    sortplease(arr, n - 1);
}

int main()
{
    int arr[6] = {5, 1, 2, 0, 4, 3};
    int n = 6;
    sortplease(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
