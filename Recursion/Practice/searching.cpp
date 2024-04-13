#include <iostream>
#include <vector>
using namespace std;

bool LinearSearch(int arr[], int n, int target)
{
    if (n == 0)
        return false;
    if (arr[0] == target)
        return true;
    return LinearSearch(arr + 1, n - 1, target);
}

bool bullshit(int arr[], int n, int target) // using while loops
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return false;
}

bool binarysearch(int arr[], int n, int target) // using recursion
{
    if (n <= 0)
        return false;

    int mid = (n - 1) / 2;
    if (arr[mid] == target)
        return true;
    else if (arr[mid] > target)
        return binarysearch(arr, mid, target);
    else
        return binarysearch(arr + mid + 1, n - mid - 1, target);
}

int helper(vector<int> &arr, int s, int e, int k) // for vector
{

    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return mid;
    else if (arr[mid] < k)
        return helper(arr, mid + 1, e, k);
    else
        return helper(arr, s, mid - 1, k);
}

int search(vector<int> &nums, int target)
{
    return helper(nums, 0, nums.size() - 1, target);
}

int main()
{
    // int arr[5] = {1, 3, 5, 6, 9};
    int arr[6] = {1, 3, 5, 6, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    cout << "Is present: " << LinearSearch(arr, n, target) << endl;
    cout << "Is present: " << bullshit(arr, n, target) << endl;
    cout << "Is present: " << binarysearch(arr, n, target) << endl;

    vector<int> nums = {3, 5, 7, 10, 15, 20, 25, 28, 31};
    cout << "For vector index: " << search(nums, target) << endl;

    return 0;
}
