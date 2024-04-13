#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

// Space Complexity: O(1) : Only variables are created, hence constant
// Time Complexity: O(n^2) : For loop j = 1 to n; inside i = 0 to n - 1. Hence n^2.
// Both Best Case and Worst Case T.C will be O(n^2) because we still have to check min everytime
// Uses: When array/vector size is small
// Selection Sort is Unstable, because it doesn't preserve the order the elements.

int main()
{
    int arr[6] = {5, 1, 6, 3, 0, 2};
    selectionsort(arr, 6);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
