#include <iostream>
#include <vector>
using namespace std;

void helpswap(vector<int> &arr, int x)
{
    if (x == 0 || arr[x] >= arr[x - 1])
        return;
    swap(arr[x - 1], arr[x]);
    helpswap(arr, x - 1);
}

void sortpls(vector<int> &arr, int x)
{
    if (x == arr.size())
        return;
    helpswap(arr, x);
    sortpls(arr, x + 1);
}

int main()
{
    vector<int> arr = {4, 1, 2, 5, 3};
    // vector<int> arr = {5, 4, 3, 2, 1};
    sortpls(arr, 1);
    for (int i : arr)
        cout << i << " ";
    return 0;
}
