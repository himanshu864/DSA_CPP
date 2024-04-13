#include <iostream>
using namespace std;

// Approach 1: Find Pivot, Find on which line target lies, and apply binary search on that.
int findPivot(int arr[], int n)
{
    if (arr[0] < arr[n - 1]) // if array is not rotated, pivot = 0
        return 0;

    int s = 0, e = n - 1;
    while (s < e)
    {
        int x = (s + (e - s) / 2);
        if (arr[x] >= arr[0]) // >= is important for pivot = 1
            s = x + 1;
        else
            e = x;
    }
    return s;
}

int binarySearch(int arr[], int a, int b, int target)
{
    while (a <= b)
    {
        int mid = (a + (b - a) / 2);
        if (arr[mid] < target)
            a = mid + 1;
        else if (arr[mid] > target)
            b = mid - 1;
        else
            return mid;
    }
    return -1;
}

int love(int arr[], int n, int target)
{
    int ans = -1;

    int pivot = findPivot(arr, n);
    cout << "Pivot of array: " << arr[pivot] << endl;

    int start = 0, end = n - 1;
    if (target >= arr[pivot] && target <= arr[end])
        ans = binarySearch(arr, pivot, end, target);
    else
        ans = binarySearch(arr, 0, pivot - 1, target);

    return ans;
}

int main()
{
    int arr[5] = {4, 5, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int target;
    cin >> target;
    cout << love(arr, n, target);
    return 0;
}

// Approach 2: Keep checking and eliminated sorted halfs
int strive(int arr[], int n, int target)
{
    int ans = -1;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (arr[mid] == target)
            return mid;

        if (arr[s] <= arr[mid])
        {
            if (arr[s] <= target && target < arr[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if (arr[mid] < target && target <= arr[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return ans;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/