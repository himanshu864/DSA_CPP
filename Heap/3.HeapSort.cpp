#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void insertHeap(vector<int> &arr, int i)
{
    while (i && arr[i] > arr[(i - 1) / 2])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteHeap(vector<int> &heap, int n)
{
    swap(heap[0], heap[n]); // VIP
    for (int i = 0; i < n;)
    {
        int a = 2 * i + 1, b = 2 * i + 2;
        if (heap[a] < heap[b])
            swap(a, b);

        if (a < n && heap[i] < heap[a])
        {
            swap(heap[i], heap[a]);
            i = a;
        }
        else if (b < n && heap[i] < heap[b])
        {
            swap(heap[i], heap[b]);
            i = b;
        }
        else
            break;
    }
}

void heapSort(vector<int> &arr)
{
    // Create heap by inserting one by one
    for (int i = 1; i < arr.size(); i++)
        insertHeap(arr, i);

    // Delete one by one with swapping
    for (int n = arr.size() - 1; n > 0; n--)
        deleteHeap(arr, n);
}

int main()
{
    vector<int> arr = {5, 2, 1, 3, 6, 7, 4};

    heapSort(arr);

    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
