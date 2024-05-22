#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &arr, int i)
{
    int n = arr.size();
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            i = largest;
        }
        else
            break;
    }
}

vector<int> heapify(vector<int> &arr)
{
    vector<int> heap = arr;
    for (int x = heap.size() / 2 - 1; x >= 0; x--) // skip leaf nodes
        helper(heap, x);
    return heap;
}

int main()
{
    vector<int> arr = {5, 10, 30, 20, 35, 40, 15};
    vector<int> heap = heapify(arr);
    for (int i : heap)
        cout << i << " ";
    cout << endl;
    return 0;
}
