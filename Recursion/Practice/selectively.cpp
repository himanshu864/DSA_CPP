#include <iostream>
#include <vector>
using namespace std;

int findMinIdx(vector<int> &arr, int idx, int j, int n)
{
    if (j > n - 1)
        return idx;

    if (arr[idx] > arr[j])
        idx = j;
    return findMinIdx(arr, idx, j + 1, n);
}

void helper(vector<int> &arr, int i, int n)
{
    if (i > n - 2)
        return;

    int minIndex = findMinIdx(arr, i, i + 1, n);
    swap(arr[i], arr[minIndex]);
    helper(arr, i + 1, n);
}

void selectively(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return;
    helper(arr, 0, n);
}

void selectionitr(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    // vector<int> arr = {5, 1, 2, 4, 3};
    vector<int> arr = {5, 4, 3, 2, 1};
    selectively(arr);
    for (int i : arr)
        cout << i << " ";
    return 0;
}
