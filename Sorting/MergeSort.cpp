#include <iostream>
#include <vector>
using namespace std;

void merge2sorted(vector<int> &arr, int s, int mid, int e) // iterative
{
    // requires extra space to store halves
    vector<int> first(arr.begin() + s, arr.begin() + mid + 1);
    vector<int> second(arr.begin() + mid + 1, arr.begin() + e + 1);

    int x = s;
    int i = 0, j = 0;
    // 2 way merge them into original array
    while (i < first.size() && j < second.size())
        arr[x++] = (first[i] <= second[j]) ? first[i++] : second[j++];
    while (i < first.size())
        arr[x++] = first[i++];
    while (j < second.size())
        arr[x++] = second[j++];
}

void mergesort(vector<int> &arr, int s, int e) // recursive
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);       // first array is split into n single element arrays
    mergesort(arr, mid + 1, e);   // at call time
    merge2sorted(arr, s, mid, e); // then the sorted halfs are merged at return time
}

int main()
{
    vector<int> arr = {5, 2, 7, 1, 3, 10, 9, 4};
    mergesort(arr, 0, arr.size() - 1);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/sort-an-array/
