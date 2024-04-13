#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            swap(arr[j], arr[j - 1]);
}

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int card = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > card)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = card;
    }
}

// Uses: Adaptable, Stable, Better for Smaller arrays or Partially Sorted Arrays
// Space Complexity: O(1) : Constant
// Time Complexity: O(n^2) : Worst Case when array is in decreasing order.
// Best Case T.C. : O(n) : Already sorted hence only one comparision per round.

int main()
{
    int arr[6] = {5, 1, 6, 3, 0, 2};
    InsertionSort(arr, 6);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
