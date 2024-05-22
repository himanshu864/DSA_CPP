#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void deleteHeap(vector<int> &heap)
{
    int n = heap.size() - 1;
    // delete root, by replacing it with last element
    swap(heap[0], heap[n]);
    heap.pop_back();

    int i = 0;
    while (i < n)
    {
        // compare children
        int a = 2 * i + 1, b = 2 * i + 2;
        // make a the greater one
        if (heap[a] < heap[b])
            swap(a, b);

        // swap root with greater node and repeat
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

int main()
{
    vector<int> heap = {40, 35, 30, 15, 10, 25, 5};
    deleteHeap(heap);

    for (int i : heap)
        cout << i << " ";
    cout << endl;
    return 0;
}
