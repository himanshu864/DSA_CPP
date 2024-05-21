#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void helper(vector<int> &heap, int i)
{
    while (i && heap[i] > heap[(i - 1) / 2])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void create(vector<int> &heap)
{
    for (int i = 1; i < heap.size(); i++)
        helper(heap, i);
}

int main()
{
    vector<int> arr = {10, 20, 30, 25, 5, 40, 35};
    create(arr);
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
