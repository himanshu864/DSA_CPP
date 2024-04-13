#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int> &arr, int s, int e)
{
    if (s >= e) // to check array has more than one elements
        return;
    int pivot = arr[s]; // choose any element as pivot
    int i = s;
    int j = e;
    while (i < j)
    {
        while (i <= j && arr[i] <= pivot) // all smaller elements to left
            i++;
        while (i <= j && arr[j] > pivot) // all equal or greater to right
            j--;
        if (i < j) // swap when both are problems and haven't crossed each other
            swap(arr[i], arr[j]);
    }
    swap(arr[s], arr[j]);     // to place pivot in it's right position
    QuickSort(arr, s, j - 1); // j is the partitioning index
    QuickSort(arr, j + 1, e); // sort both partitions recursively
}

// int partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[low];
//     int i = low;
//     int j = high;

//     while (i < j)
//     {
//         while (arr[i] <= pivot && i <= high - 1)
//             i++;
//         while (arr[j] > pivot && j >= low + 1)
//             j--;
//         if (i < j)
//             swap(arr[i], arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }

// void qs(vector<int> &arr, int low, int high)
// {
//     if (low < high)
//     {
//         int j = partition(arr, low, high);
//         qs(arr, low, j - 1);
//         qs(arr, j + 1, high);
//     }
// }

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    // vector<int> arr = {6, 1, 5, 2, 4, 3};
    QuickSort(arr, 0, arr.size() - 1);
    for (int i : arr)
        cout << i << " ";
    return 0;
}
