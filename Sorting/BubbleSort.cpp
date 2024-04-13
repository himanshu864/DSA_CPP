#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool noSwap = true;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                noSwap = false;
            }
        }
        if (noSwap) // for best case: O(n) : Already sorted since no swaps were made
            break;
    }
}

// Space Complexity: O(1) : Only variables are created, hence constant
// Time Complexity: O(n^2) : For loop j = 1 to n; inside i = 0 to n - i. Hence n^2.
// Best case time complexity O(n) is already sorted
// Bubble Sort is Stable, we basically shift largest element to right, hence relative order is preserved.
// Comparision Based, In-place sorting Algorithm

int main()
{
    int arr[6] = {5, 1, 6, 3, 0, 2};
    // int arr[6] = {1, 2, 3, 4, 5, 6};
    BubbleSort(arr, 6);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
