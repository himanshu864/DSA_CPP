#include <iostream>
#include <vector>
using namespace std;

// here array is biotonic = increasing then decreasing
// also distinct elements
int peakIndexInMountainArray(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int main()
{
    vector<int> mountainArray = {1, 3, 5, 9, 12, 9, 6, 4, 3, 1};
    cout << "Given Array: ";
    for (int i : mountainArray)
        cout << i << " ";
    cout << endl;

    int peakIndex = peakIndexInMountainArray(mountainArray);
    cout << "The peak index in the mountain array is: " << peakIndex << endl;

    return 0;
}

// https://leetcode.com/problems/peak-index-in-a-mountain-array/